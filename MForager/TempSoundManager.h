#pragma once
#include "Stdafx.h"
#include "SingletonBase.h"

// ������ ���� ��� ���̺귯��
// PlaySound()�� ����ϱ� ����
#include <mmsystem.h>
// mciSendString()�� ����ϱ� ����
// mci : Media Control Interface : ��ġ������ �����
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
