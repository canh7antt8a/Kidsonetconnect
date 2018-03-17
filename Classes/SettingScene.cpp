//
//  SettingScene.cpp
//  PikachuSpace
//
//  Created by Hoang Nguyen on 2/25/17.
//
//

#include "SettingScene.h"
#include "HomeScene.h"
#include "SimpleAudioEngine.h"
static std::string items[3] = {"Fruit","Alphabet","Candy"};
SettingScene::~SettingScene()
{
    
}
Scene* SettingScene::createSettingScene()
{
    auto scene = Scene::create();
    auto layer = SettingScene::create();
    scene->addChild(layer);
    return scene;
}
bool SettingScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    winSize = Director::getInstance()->getWinSize();
    auto background =  Sprite::create("bgGameScene.png");
    background->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(background,1);
    
    settingLayer =  Sprite::create("seeting_layer.png");
    settingLayer->setPosition(Vec2(winSize.width/2, winSize.height/2));
    this->addChild(settingLayer,2);
    
    indexSelect = UserDefault::getInstance()->getIntegerForKey("Item",1);
    
    this->createUISettingScene();
    return true;
}
void SettingScene::createUISettingScene()
{
    /*button back*/
    ui::Button* btnBack = ui::Button::create("buttonBack1.png","","",ui::Widget::TextureResType::LOCAL);
    btnBack->setPosition(Vec2(btnBack->getContentSize().width, winSize.height - btnBack->getContentSize().height));
    btnBack->setTag(1246);
    btnBack->addClickEventListener(CC_CALLBACK_1(SettingScene::btnClickButtonSettingScene,this));
    this->addChild(btnBack,1000);
    
    this->createModelChoose();
}

void SettingScene::createModelChoose()
{
    if(!arrayCheckBox.empty())
    {
        arrayCheckBox.clear();
    }
    for (int i = 0; i < 3; i++)
    {
        cocos2d::ui::CheckBox* _checkBox = cocos2d::ui::CheckBox::create("selected01.png", "selected01.png", "selected02.png", "selected01.png", "selected01.png");
        _checkBox->setPosition(Vec2(settingLayer->getPositionX() + settingLayer->getContentSize().width*0.24, settingLayer->getPositionY() + settingLayer->getContentSize().height*0.2 - (_checkBox->getContentSize().height + 60)*i));
        _checkBox->setTag(i+1);
        if(i == indexSelect -1)
        {
            _checkBox->setSelected(true);
        }else
        {
            _checkBox->setSelected(false);
        }
        _checkBox->addEventListener(CC_CALLBACK_2(SettingScene::selectedEvent, this));
        arrayCheckBox.push_back(_checkBox);
        this->addChild(_checkBox, 100);
        
        /*
         Label
         */
        Label* label = Label::createWithTTF(items[i], "GROBOLD.ttf", 48);
        label->setTextColor(Color4B::ORANGE);
        label->setPosition(Vec2(settingLayer->getPositionX(),_checkBox->getPositionY()));
        this->addChild(label,100);
        
        /*
         Sprite
         */
        char bufferName[512] = {0};
        sprintf(bufferName,"item%d.png",i);
        Sprite* icon = Sprite::create(bufferName);
        icon->setPosition(Vec2(label->getPositionX() - settingLayer->getContentSize().width/4,_checkBox->getPositionY()));
        this->addChild(icon,100);
    }
}

void SettingScene::checkWhenChooseCheckBox(int tag)
{
    UserDefault::getInstance()->setIntegerForKey("Item", tag);
    for (int i = 0; i < arrayCheckBox.size(); i++)
    {
        cocos2d::ui::CheckBox* _checkBox = arrayCheckBox.at(i);
        if(_checkBox->getTag() != tag)
        {
            _checkBox->setSelected(false);
        }
    }
}

void SettingScene::unCheckWhenChooseCheckBox(int tag)
{
    UserDefault::getInstance()->setIntegerForKey("Item", tag );
    for (int i = 0; i < arrayCheckBox.size(); i++)
    {
        cocos2d::ui::CheckBox* _checkBox = arrayCheckBox.at(i);
        if(_checkBox->getTag() == tag)
        {
            _checkBox->setSelected(true);
        }
    }
}

void SettingScene::selectedEvent(Ref* pSender,cocos2d::ui::CheckBox::EventType type)
{
    int tag = ((ui::Button*)pSender)->getTag();
    switch (type)
    {
        case cocos2d::ui::CheckBox::EventType::SELECTED:
            this->checkWhenChooseCheckBox(tag);
            break;
        case cocos2d::ui::CheckBox::EventType::UNSELECTED:
            this->unCheckWhenChooseCheckBox(tag);
            break;
        default:
            break;
    }
    
}

void SettingScene::btnClickButtonSettingScene(Ref* pSender)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundClick.mp3");
    Director::getInstance()->replaceScene(HomeScene::createHomeScene());
}

void SettingScene::onEnter()
{
    Layer::onEnter();
    EventListenerKeyboard *keyboardEvent = EventListenerKeyboard::create();
    keyboardEvent->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event*){
        if(keyCode == EventKeyboard::KeyCode::KEY_BACK){
            Director::getInstance()->replaceScene(HomeScene::createHomeScene());
        }
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardEvent, this);
}
void SettingScene::onExit()
{
    Layer::onExit();
    Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this);
    
}
