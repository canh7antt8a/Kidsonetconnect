//
//  PikachuObject.cpp
//  PikachuConnect
//
//  Created by NguyenHoang on 8/18/16.
//
//

#include "PikachuObject.h"
#include "GameDefine.h"
#define SCALE_OBJECT 1.36
#define MAX_ARRAY 36
enum{
    z_Order_bgNode = 0,
    z_Order_Character = 1,
};


/**
 Type Kids
*/
static std::string item3[MAX_ARRAY] = {"item2_1.png","item2_2.png","item2_3.png","item2_4.png","item2_5.png","item2_6.png",
    "item2_7.png","item2_8.png","item2_9.png","item2_10.png","item2_11.png","item2_12.png",
    "item2_13.png","item2_14.png","item2_15.png","item2_16.png","item2_17.png","item2_18.png",
    "item2_19.png","item2_20.png","item2_21.png","item2_22.png","item2_23.png","item2_24.png",
    "item2_25.png","item2_26.png","item2_27.png","item2_28.png","item2_29.png","item2_30.png",
    "item2_31.png","item2_32.png","item2_33.png","item2_34.png","item2_35.png","item2_36.png"};

static std::string item2[MAX_ARRAY] = {"item6_1.png","item6_2.png","item6_3.png","item6_4.png","item6_5.png","item6_6.png","item6_7.png","item6_8.png","item6_9.png","item6_10.png","item6_11.png","item6_12.png","item6_13.png","item6_14.png","item6_15.png","item6_16.png","item6_17.png","item6_18.png","item6_19.png","item6_20.png","item6_21.png","item6_22.png","item6_23.png","item6_24.png","item6_25.png","item6_26.png","item6_27.png","item6_28.png","item6_29.png","item6_30.png","item6_31.png","item6_32.png","item6_33.png","item6_34.png","item6_35.png","item6_36.png"};

static std::string item1[MAX_ARRAY] = {"item4_1.png","item4_2.png","item4_3.png","item4_4.png","item4_5.png","item4_6.png","item4_7.png","item4_8.png","item4_9.png","item4_10.png","item4_11.png","item4_12.png","item4_13.png","item4_14.png","item4_15.png","item4_16.png","item4_17.png","item4_18.png","item4_19.png","item4_20.png","item4_21.png","item4_22.png","item4_23.png","item4_24.png","item4_25.png","item4_26.png","item4_27.png","item4_28.png","item4_29.png","item4_30.png","item4_31.png","item4_32.png","item4_33.png","item4_34.png","item4_35.png","item4_36.png"};


PikachuObject::PikachuObject()
{
    
}
PikachuObject::~PikachuObject()
{
    
}

void PikachuObject::runActionStartGame()
{
    
}


void PikachuObject::createUIObjectWithModel(int model)
{
    CCLOG("Model 1111111------ %d", model);
    this->model = model;
    if (model == 1)
    {
        bgNode = Sprite::create("bgAnimal1.png");
        bgNode->setPosition(this->getPosition());
        this->addChild(bgNode,z_Order_bgNode);
        character = Sprite::createWithSpriteFrameName(item1[type]);
    }
    if (model == 2)
    {
        bgNode = Sprite::create("bgAnimal2.png");
        bgNode->setPosition(this->getPosition());
        this->addChild(bgNode,z_Order_bgNode);
        character = Sprite::createWithSpriteFrameName(item2[type]);
    }
    if(model == 3)
    {
        bgNode = Sprite::create("bgAnimal1.png");
        bgNode->setPosition(this->getPosition());
        this->addChild(bgNode,z_Order_bgNode);
        character = Sprite::createWithSpriteFrameName(item3[type]);
    }
    character->setPosition(Vec2(this->getPositionX() - 10, this->getPositionY() + 10));
    character->setScale(SCALE_OBJECT);
    this->addChild(character,z_Order_Character);
    if (valueVisiable == TAG_PIKACHU_VISIABLE)
    {
        character->setVisible(true);
        bgNode->setVisible(true);
    }
    else
    {
        character->setVisible(false);
        bgNode->setVisible(false);
    }
    
    
}
void PikachuObject::updateUI(int type)
{
    
    if (model == 1)
    {
        if(character)
        {
            character->setSpriteFrame(item1[type]);
        }
    }
    if (model == 2)
    {
        if(character)
        {
            character->setSpriteFrame(item2[type]);
        }
    }
    if(model == 3)
    {
        if(character)
        {
            character->setSpriteFrame(item3[type]);
        }
    }
}
void PikachuObject::setTagObject(int tagObject)
{
    this->tagObject = tagObject;
}
int PikachuObject::getTagObject()
{
    return tagObject;
}

void PikachuObject::actionWhenClick()
{
    auto action1 = ScaleTo::create(0.08f, 0.8f);
    auto action2 = DelayTime::create(0.02f);
    auto sequence = Sequence::create(action1, action2, NULL);
    bgNode->runAction(sequence);
}
void PikachuObject::effectWhenDieObject()
{
    bgNode->setVisible(false);
    character->setVisible(false);
}
void PikachuObject::backToStartObject()
{
    bgNode->runAction(ScaleTo::create(0.1f, 1.0f));
}

void PikachuObject::hidePikachu()
{
    bgNode->setVisible(false);
    character->setVisible(false);
}
void PikachuObject::updateNewPosition(const Vec2& position)
{
    this->setPosition(position);
    if(bgNode)
    {
        bgNode->setPosition(this->getPosition());
    }
    if(character)
    {
        character->setPosition(Vec2(this->getPositionX() - 10, this->getPositionY() + 10));
    }
}
void PikachuObject::setValueVisiable(int valueVisiable)
{
    this->valueVisiable = valueVisiable;
}
int PikachuObject::getValueVisiable()
{
    return valueVisiable;
}
void PikachuObject::update(float dt)
{
    if(this->getValueVisiable() ==  TAG_PIKACHU_HIDDEN)
    {
        bgNode->setVisible(false);
        character->setVisible(false);
    }
    else
    {
        bgNode->setVisible(true);
        character->setVisible(true);
    }
}

void PikachuObject::onEnter()
{
    Node::onEnter();
}
void PikachuObject::onExit()
{
    Node::onExit();
}
void PikachuObject::setVisiableSprite()
{
    if(bgNode->isVisible() == false)
    {
        bgNode->setVisible(true);
    }
    if(character->isVisible() == false)
    {
        character->setVisible(true);
    }
}
void PikachuObject::updateZorder(int newZoder)
{
    
}

void PikachuObject::objectWhenPause()
{
    
    if(bgNode)
    {
        bgNode->setLocalZOrder(10001);
    }
    if(character)
    {
        character->setLocalZOrder(10000);
    }
    
}
void PikachuObject::objectWhenPlay()
{
    
    if(bgNode)
    {
        bgNode->setLocalZOrder(10000);
    }
    if(character)
    {
        character->setLocalZOrder(10001);
    }
    
}


