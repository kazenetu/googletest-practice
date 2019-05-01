#pragma once

#ifndef IExternalInterface_h
#define IExternalInterface_h

#include <iostream>

/*
外部インターフェース用スーパークラス
*/
class IExternalInterface
{
public:
	virtual bool check(std::string id) = 0;
};

#endif