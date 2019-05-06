#pragma once
#ifndef ExternalInterfaceStub_h
#define ExternalInterfaceStub_h

#include <iostream>
#include "../ConsoleApplication1/IExternalInterface.h"

/*
外部インターフェース用サブクラス
*/
class ExternalInterfaceStub :public IExternalInterface
{
public:
    bool check(std::string id);

    static bool returnValue;
};

/*
チェック処理
*/
inline bool ExternalInterfaceStub::check(std::string id)
{
    // TODO 処理実装

    return returnValue;
}

// 初期化
bool ExternalInterfaceStub::returnValue = false;

#endif