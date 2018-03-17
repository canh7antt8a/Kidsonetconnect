//
//  HomeScene.hpp
//  PikachuConnect
//
//  Created by NguyenHoang on 8/18/16.
//
//

#ifndef HomeScene_h
#define HomeScene_h

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;


class HomeScene : public Layer{
public:
    Size winSize;
    ui::Button* btnSoudOff;
    ui::Button* btnSoundOn;
    ui::Button* btnHelp ;
    ui::Button* btnStart;
    ui::Button* btnChart;
    ui::ScrollView* scrollView;
    Layer*  chartLayer ;
    Sprite* bgchart;
    ui::Button* btnTheme;
    bool isHelp;
public:
    static Scene* createHomeScene();
    HomeScene();
    virtual ~HomeScene();
    void createUIHomeScene();
    void btnClickButtonHomeScene(Ref* pSender);
    void onEnter();
    void onExit();
    void createHelpGame();
    void createChartGame();
    
    void createMenuButtonWithHeight();
    virtual void update(float dt);
    
};



#endif /* HomeScene_h */
