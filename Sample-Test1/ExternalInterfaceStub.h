#pragma once
#ifndef ExternalInterfaceStub_h
#define ExternalInterfaceStub_h

#include <iostream>
#include "../ConsoleApplication1/IExternalInterface.h"

/*
�O���C���^�[�t�F�[�X�p�T�u�N���X
*/
class ExternalInterfaceStub :public IExternalInterface
{
public:
    bool check(std::string id);

    static bool returnValue;
};

/*
�`�F�b�N����
*/
inline bool ExternalInterfaceStub::check(std::string id)
{
    // TODO ��������

    return returnValue;
}

// ������
bool ExternalInterfaceStub::returnValue = false;

#endif