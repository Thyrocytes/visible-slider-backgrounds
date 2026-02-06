#include <Geode/Geode.hpp>
#include <Geode/modify/Slider.hpp>

#include <string.h>

class $modify(Slider) {
	bool init(cocos2d::CCNode* target, cocos2d::SEL_MenuHandler handler, const char* bar, const char* groove, const char* thumb, const char* thumbSel, float scale) {
		if (!Slider::init(target, handler, bar, groove, thumb, thumbSel, scale)) return false;

		this->runAction(geode::cocos::CallFuncExt::create(static_cast<geode::Function<void()>>([this]() {
			if (strncmp(static_cast<const char*>(this->getID()), static_cast<const char*>("position-slider"), 15)) return;
			this->updateBar();

			bool isScaleControl = geode::cast::typeinfo_cast<GJScaleControl*>(this->getParent());

			if (isScaleControl) m_sliderBar->setPositionY(2.f);
			m_sliderBar->setVisible(!geode::Mod::get()->getSettingValue<bool>("opposite-day"));
		})));

		return true;
	}
};
