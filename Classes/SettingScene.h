//
//  SettingScene.h
//  PikachuSpace
//
//  Created by Hoang Nguyen on 2/25/17.
//
//

#ifndef SettingScene_h
#define SettingScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class SettingScene : public Layer
{
    
public:
    Size winSize ;
    cocos2d::ui::TextField* textFieldName;
    Sprite* imaginPut;
    ui::Button* btn_ok;
    Sprite*  settingLayer;
    std::vector<cocos2d::ui::CheckBox*> arrayCheckBox;
    int indexSelect;
public:
    static Scene* createSettingScene();
    CREATE_FUNC(SettingScene);
    virtual bool init();
    virtual ~SettingScene();
    void createUISettingScene();
    void btnClickButtonSettingScene(Ref* pSender);
    
    void createModelChoose();
    void selectedEvent(Ref* pSender,cocos2d::ui::CheckBox::EventType type);
    
    void unCheckWhenChooseCheckBox(int tag);
    void checkWhenChooseCheckBox(int tag);
    void onEnter();
    void onExit();
};
#endif /* SettingScene_h */
