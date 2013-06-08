//
//  HelloWorldScene.h
//  game2
//
//  Created by macbook_006 on 13/06/08.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"

USING_NS_CC;
class HelloWorld : public cocos2d::CCLayer {
public:
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    
   // void initPhysics();
    // adds a new sprite at a given coordinate
    //void addNewSpriteAtPosition(cocos2d::CCPoint p);

    //virtual void draw();
    //virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    void update(float dt);
    void run(float i);
    
private:
    CCSprite *leg;
    CCSprite * body;
    CCSprite *gau;
    b2World* world;
    int i =0;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
};

#endif // __HELLO_WORLD_H__
