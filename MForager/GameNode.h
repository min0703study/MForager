#pragma once

#define UPDATE_TIMER_ID		1
#define RENDER_TIMER_ID		2

class GameNode
{
private:
	HDC _hdc;
protected:
	bool _isManagerInit;
	POINT _currentPt;

	string _backBufferKey;
	ImageBase* _backBuffer;

	ImageBase* getBackBuffer(void) { return _backBuffer; }
	string getBackBufferKey(void) { return _backBufferKey; }

public:
	HDC getMemDc() { return getBackBuffer()->getMemDC(); }
	HDC getHdc() { return _hdc; }
public:
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void update(void);
	virtual void release(void);
	virtual void render(void);
	
	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	GameNode() {};
	virtual ~GameNode() {};
protected:
	virtual void addTimer(int sec, int timerId);
	virtual void deleteTimer(int timerId);

	//message event
	virtual void clickEvent(POINT& pt, bool isClickDown);
	virtual void keyboardDownEvent(HWND& hWnd, WPARAM& wParam);
	virtual void timerEvent(int timerId);
	virtual void mouseMoveEvent(POINT& pt);

};

