#include "Stdafx.h"
#include "MapTool.h"
#include "MainGame.h"

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

GameNode* _gm;

//min �߰� - extern
int _winsizeX, _winsizeY;
int _winRealSizeX, _winRealSizeY;

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow) {

	_hInstance = hInstance;
	
	ULONG_PTR gpToken;
	Gdiplus::GdiplusStartupInput gpsi;
	if (GdiplusStartup(&gpToken, &gpsi, NULL) != Gdiplus::Status::Ok) return 0;


	/*
	DEVMODE dm;

	dm.dmBitsPerPel = 32;
	dm.dmPelsWidth = 1980;
	dm.dmPelsHeight = 1080;
	dm.dmDisplayFrequency = 60;

	dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

	if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
	{
		ChangeDisplaySettings(&dm, 0);
	}
	*/

	_winsizeX = WINSIZE_X;
	_winsizeY = WINSIZE_Y;


	_winRealSizeX = _winsizeX - 15;
	_winRealSizeY = _winsizeY - 40;

	_gm = new MapTool;

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WINSTYLE,
		20,
		20,
		WINSIZE_X,
		WINSIZE_Y,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL
	);

	if (FAILED(_gm->init())) {
		return 0;
	};

	ShowWindow(_hWnd, nCmdShow);

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	_gm->release();
	UnregisterClass(WINNAME, _hInstance);
	Gdiplus::GdiplusShutdown(gpToken);
	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _gm->MainProc(hWnd, iMessage, wParam, lParam);
}