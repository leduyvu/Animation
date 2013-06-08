//
//  HelloWorldScene.cpp
//  game2
//
//  Created by macbook_006 on 13/06/08.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "string.h"
using namespace cocos2d;
using namespace CocosDenshion;

#define PTM_RATIO 32
USING_NS_CC;
enum {
    kTagParentNode = 1,
};



HelloWorld::HelloWorld()
{
    setTouchEnabled( true );
    setAccelerometerEnabled( true );

    CCSize s = CCDirector::sharedDirector()->getWinSize();
    // init physics
    //this->initPhysics();

    CCSpriteBatchNode *parent = CCSpriteBatchNode::create("blocks.png", 100);
    m_pSpriteTexture = parent->getTexture();

    //addChild(parent, 0, kTagParentNode);


   // addNewSpriteAtPosition(ccp(s.width/2, s.height/2));

    CCLabelTTF *label = CCLabelTTF::create("Tap screen", "Marker Felt", 32);
    addChild(label, 0);
    gau = CCSprite::create("bear1.png");
    label->setColor(ccc3(0,0,255));
    label->setPosition(ccp( s.width/2, s.height-50));
    leg = CCSprite::create("chan.png");
    leg->setAnchorPoint(ccp(0, 0)); 
    body = CCSprite::create("nguoi.png");
    leg->setPosition(ccp(200, 150));
    body->setPosition(ccp(160, 193));
    gau->setPosition(ccp(160, 193));
    addChild(gau);
    //addChild(leg);
   // addChild(body);
    scheduleUpdate();
    float update = 1;
    this->schedule(schedule_selector(HelloWorld::run), update);
}

HelloWorld::~HelloWorld()
{
    delete world;
    world = NULL;
    
    //delete m_debugDraw;
}


void HelloWorld::update(float dt)
{
    if (i<100)
    {
        i++;
            }else
        i=0;

}
void HelloWorld::run(float i)
{
    CCAnimation *animation = CCAnimation::create();
    for (int i = 1; i < 9; i++)
    {
        std::stringstream ss;
        ss << "bear" << i  << ".png";
        
        std::string name = ss.str();
        
        animation->addSpriteFrameWithFileName(name.c_str());
    }
    animation->setDelayPerUnit(2.8f / 14.0f);
    animation->setRestoreOriginalFrame(true);
    CCAnimate *action = CCAnimate::create(animation);
    gau->runAction(action);

}


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new HelloWorld();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
