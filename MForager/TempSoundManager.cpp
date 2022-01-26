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

	//mciSendString():현재 장치에 명령어를 전송하여 필요한 장치를 구동시키는 함수
	//문자열 명령어, 반환값 문자열, 반환될 길이, 핸들 콜백

	mciSendString(str, NULL, 0, NULL);

}

void TempSoundManager::addwaveFileWithKey(string key, string fileName)
{
	string first = "open \"";
	string end = "\" type waveaudio alias ";
	string finalQuery = first + fileName + end + key;

	const char* str = finalQuery.c_str();

	//mciSendString():현재 장치에 명령어를 전송하여 필요한 장치를 구동시키는 함수
	//문자열 명령어, 반환값 문자열, 반환될 길이, 핸들 콜백

	mciSendString(str, NULL, 0, NULL);
}

void TempSoundManager::playEffectSoundWave(char * fileName)
{
	// 파일 이름.wav, 핸들 (NULL->파일명을 사용한다), sound: 옵션 | 옵션 | 옵션
	// SND_ASYNC : 재생하면서 다음 코드 실행(비동기적 플래그) SND_LOOP만 적으면 뒤코드 실행 안됨
	PlaySound(fileName, NULL, SND_ASYNC);         // | SND_LOOP | SND_NODEFAULT도 들어가지만 아래에 기능이 있으니 제외
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