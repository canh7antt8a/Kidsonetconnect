//
//  AdmobIOSWrapper.m
//  PikachuSpace
//
//  Created by Hoang Nguyen on 1/27/17.
//
//

#import "IOSWrapper.h"
#import "AdmobIOS.h"
#import "GameCenterIOS.h"

static IOSWrapper _IOSWrapper;

IOSWrapper* IOSWrapper::getInstance() {
    return &_IOSWrapper;
}

void IOSWrapper::init(const std::string &bannerId, const std::string &interstitialId) {
    NSString *banner = [NSString stringWithUTF8String:bannerId.data()];
    NSString* interstitial = [NSString stringWithUTF8String:interstitialId.data()];
    [[AdmobIOS sharedAdmob] setBannerId:banner];
    [[AdmobIOS sharedAdmob] setInterstitialId:interstitial];
}

bool IOSWrapper::isShowAdmodStatus()
{
    return [[AdmobIOS sharedAdmob] callAdmod];
}

void IOSWrapper::showBanner(int position) {
    [[AdmobIOS sharedAdmob] showBannerInPostion:position];
}

void IOSWrapper::hideBanner() {
    [[AdmobIOS sharedAdmob] hideBanner];
}

void IOSWrapper::loadInterstitial() {
    [[AdmobIOS sharedAdmob] loadInterstitial];
}

void IOSWrapper::showInterstitial() {
    [[AdmobIOS sharedAdmob] showInterstitial];
}


void IOSWrapper::showAchiment()
{
    [[GameCenterIos shared] login];
    [[GameCenterIos shared] showAchievements];
}
void IOSWrapper::unlockAchimnet(const char* idName, int numberPerCen)
{
    [[GameCenterIos shared] postScore:idName score:[NSNumber numberWithInt:numberPerCen]];
}
