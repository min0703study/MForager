#pragma once
#include "SingletonBase.h"

class Logger: public SingletonBase<Logger>
{
public:
	HRESULT init(void);
};
