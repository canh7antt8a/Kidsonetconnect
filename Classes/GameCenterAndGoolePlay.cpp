//
//  GameCenterAndGoolePlay.cpp
//  OnlyColor
//
//  Created by Nguyen Chi Hoang on 3/19/17.
//
//


#include "cocos2d.h"
#include "GameCenterAndGoolePlay.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSWrapper.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "AdmodAndroid.h"
#endif


static GameCenterAndGoolePlay _sbManager;
GameCenterAndGoolePlay* GameCenterAndGoolePlay::getInstance()
{
    return &_sbManager;
}
void GameCenterAndGoolePlay::showAchievementsGoogleAndApple()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    IOSWrapper::getInstance()->showAchiment();
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    AdmodAndroid::showAchimentGoolgle();
#endif
}

void GameCenterAndGoolePlay::postAchievementGoogleAndApple( int levelGoogle){
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    AdmodAndroid::unlockAchimentGoogle(levelGoogle);
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    if(levelGoogle == 1){
        IOSWrapper::getInstance()->unlockAchimnet("grp.kidsonet.2", 2);
    }
    if(levelGoogle == 4){
        IOSWrapper::getInstance()->unlockAchimnet("grp.kidsonet.6", 6);
    }
    if(levelGoogle == 8){
        IOSWrapper::getInstance()->unlockAchimnet("grp.kidsonet.8", 8);
    }
    if(levelGoogle == 12){
        IOSWrapper::getInstance()->unlockAchimnet("grp.kidsonet.10", 10);
    }
    if(levelGoogle == 15){
        IOSWrapper::getInstance()->unlockAchimnet("grp.kidsonet.15", 15);
    }
#endif
}
