#pragma once
#include "FixedUI.h"
#include "Bundlable.h"

#include "SelectAnimation.h"
class Toolbar : public FixedUI
{
private:
	Bundlable* _item;
public:
	Toolbar(
		Bundlable* item,
		PointF pt,
		const int width,
		const int height
	) : FixedUI(pt, width, height, new SelectAnimation), _item(item){
	
	};

	void playFixed(HDC hdc) override;
};

