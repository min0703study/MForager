#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	GameNode::init(true);
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
	RND->init();

	_isManagerInit = managerInit;

	_backBufferKey = "backBuffer";
	_backBuffer = IMAGEMANAGER->addImage(_backBufferKey, WINSIZE_X, WINSIZE_Y);

	_hdc = GetDC(_hWnd);
	setlocale(LC_ALL, "Korean");

	SetTimer(_hWnd, UPDATE_TIMER_ID, 10, NULL);
	//SetTimer(_hWnd, RENDER_TIMER_ID, 1000 / FPS, NULL);

	_currentPt = { 0,0 };

	if (_isManagerInit) {
		IMAGEMANAGER->init();
	}

	return S_OK;
}

void GameNode::release(void)
{
	KillTimer(_hWnd, UPDATE_TIMER_ID);
	KillTimer(_hWnd, RENDER_TIMER_ID);

	//SAFE_DELETE(_backBuffer);

	RND->releaseSingleton();

	if (_isManagerInit) {
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
	}
}

void GameNode::update(void) {

}

void GameNode::keyboardDownEvent(HWND& hWnd, WPARAM& wParam)
{
}

void GameNode::addTimer(int sec, int timerId)
{
	SetTimer(_hWnd, timerId, sec * 1000, NULL);
}

void GameNode::deleteTimer(int timerId)
{
	KillTimer(_hWnd, timerId);
}

LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_TIMER:
		if (wParam == UPDATE_TIMER_ID) {
			this->update();
			InvalidateRect(_hWnd, NULL, false);
		}
		else {
			this->timerEvent(wParam);
		}

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		render();
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		_currentPt.x = LOWORD(lParam);
		_currentPt.y = HIWORD(lParam);
		mouseMoveEvent(_currentPt);
		break;
	case WM_KEYDOWN:
		keyboardDownEvent(hWnd, wParam);
		break;
	case WM_LBUTTONDOWN:
		clickEvent(_currentPt, true);
		break;
	case WM_LBUTTONUP:
		clickEvent(_currentPt, false);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void GameNode::render()
{
	//렌더링 event
}

void GameNode::clickEvent(POINT& pt, bool isClickDown)
{
	//클릭 event
}

void GameNode::timerEvent(int timerId)
{
	//timer event
}

void GameNode::mouseMoveEvent(POINT & pt)
{
	//마우스 이동 이벤트
}

