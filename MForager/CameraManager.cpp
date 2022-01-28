#include "Stdafx.h"
#include "CameraManager.h"

HRESULT CameraManager::init()
{
	_camera = new Camera;

	_camera->_xSize = CAMERASIZE_X;
	_camera->_ySize = CAMERASIZE_Y;
	_camera->_startPt = { 0,0 };
	_camera->_rcCamera = RectMake( 0, 0, CAMERASIZE_X ,CAMERASIZE_Y);

	return S_OK;
}

void CameraManager::release()
{
}

void CameraManager::update()
{
}

void CameraManager::render(HDC hdc)
{
}

void CameraManager::moveCameraX(float x)
{
	_camera->_startPt.x += x;

	_camera->_rcCamera.left += x;
	_camera->_rcCamera.right += x;
}

void CameraManager::moveCameraY(float y)
{
	_camera->_startPt.y += y;

	_camera->_rcCamera.top += y;
	_camera->_rcCamera.bottom += y;
}
