#pragma once
#ifndef ExternalInterface_h
#define ExternalInterface_h

#include <iostream>
#include "IExternalInterface.h"

/*
外部インターフェース用サブクラス
*/
class ExternalInterface :public IExternalInterface
{
public:
    bool check(std::string id);
};

/*
チェック処理
*/
inline bool ExternalInterface::check(std::string id)
{
    // TODO 処理実装

    return false;
}
#endif