#pragma once
#include "Camera.h"

class CameraManager
{
private:
public:
	Camera* _camera;
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void moveCameraX(float x);
	void moveCameraY(float y);

	RECT getRcCamera() { return _camera->_rcCamera; }
	POINTF getCurPt() { return _camera->_startPt; }

};

