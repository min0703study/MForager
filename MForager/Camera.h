#pragma once
class Camera
{
public:
	UIPOS* _cameraPos;

	Camera(PointF pt, int width, int height) : _cameraPos(new UIPOS(pt, width, height)) {};
	~Camera() {
		delete _cameraPos->_rc;
		delete _cameraPos->_pt;
		delete _cameraPos;
	}
};

