/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
/**
 * Required to modify the MenuLayer class
 */
#include <Geode/modify/MenuLayer.hpp>

/**
 * Brings cocos2d and all Geode namespaces 
 * to the current scope.
 */
using namespace geode::prelude;

/**
 * `$modify` lets you extend and modify GD's 
 * classes; to hook a function in Geode, 
 * simply $modify the class and write a new 
 * function definition with the signature of 
 * the one you want to hook.
 */
class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init())
            return false;
		auto menu = static_cast<cocos2d::CCMenu*>(this->getChildByID("bottom-menu"));
		auto ngbutt = static_cast<CCMenuItemSpriteExtra*>(this->getChildByID("bottom-menu")->getChildByID("newgrounds-button"));
		ngbutt->setVisible(false);
		menu->removeChildByID("newgrounds-button");
		menu->updateLayout(); 
        return true;
	}
};
