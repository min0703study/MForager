#pragma once
#include "Stdafx.h"
#include "SingletonBase.h"

// 윈도우 내장 재생 라이브러리
// PlaySound()를 사용하기 위해
#include <mmsystem.h>
// mciSendString()을 사용하기 위해
// mci : Media Control Interface : 장치관리자 입출력
#include <mciapi.h>

#pragma comment(lib, "Winmm.lib")

class TempSoundManager : public SingletonBase <TempSoundManager>
{
public:
	HRESULT init();
	void addMp3FileWithKey(string key, string fileName);
	void addwaveFileWithKey(string key, string fileName);
	void playEffectSoundWave(char* fileName);
	void playSoundWithKey(string key);
	void stopMp3withKey(string key);

	TempSoundManager() {}
	~TempSoundManager() {}
};
