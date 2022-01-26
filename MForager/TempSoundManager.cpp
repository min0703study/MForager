#include "Stdafx.h"
#include "TempSoundManager.h"

HRESULT TempSoundManager::init()
{
	return S_OK;
}

void TempSoundManager::addMp3FileWithKey(string key, string fileName)
{
	string first = "open \"";
	string end = "\" type mpegvideo alias ";
	string finalQuery = first + fileName + end + key;

	const char* str = finalQuery.c_str();

	//mciSendString():���� ��ġ�� ���ɾ �����Ͽ� �ʿ��� ��ġ�� ������Ű�� �Լ�
	//���ڿ� ���ɾ�, ��ȯ�� ���ڿ�, ��ȯ�� ����, �ڵ� �ݹ�

	mciSendString(str, NULL, 0, NULL);

}

void TempSoundManager::addwaveFileWithKey(string key, string fileName)
{
	string first = "open \"";
	string end = "\" type waveaudio alias ";
	string finalQuery = first + fileName + end + key;

	const char* str = finalQuery.c_str();

	//mciSendString():���� ��ġ�� ���ɾ �����Ͽ� �ʿ��� ��ġ�� ������Ű�� �Լ�
	//���ڿ� ���ɾ�, ��ȯ�� ���ڿ�, ��ȯ�� ����, �ڵ� �ݹ�

	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::playEffectSoundWave(char * fileName)
{
	// ���� �̸�.wav, �ڵ� (NULL->���ϸ��� ����Ѵ�), sound: �ɼ� | �ɼ� | �ɼ�
	// SND_ASYNC : ����ϸ鼭 ���� �ڵ� ����(�񵿱��� �÷���) SND_LOOP�� ������ ���ڵ� ���� �ȵ�
	PlaySound(fileName, NULL, SND_ASYNC);         // | SND_LOOP | SND_NODEFAULT�� ������ �Ʒ��� ����� ������ ����
}


void TempSoundManager::playSoundWithKey(string key)
{
	string first = "play ";
	string finalQuery = first + key;

	const char* str = finalQuery.c_str();
	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::stopMp3withKey(string key)
{
	string first = "stop ";
	string finalQuery = "";
	finalQuery = first + key;

	const char* str = finalQuery.c_str();
	mciSendString(str, NULL, 0, NULL);
}