#pragma once
#ifndef ExternalInterface_h
#define ExternalInterface_h

#include <iostream>
#include "IExternalInterface.h"

/*
�O���C���^�[�t�F�[�X�p�T�u�N���X
*/
class ExternalInterface :public IExternalInterface
{
public:
	bool check(std::string id);
};

/*
�`�F�b�N����
*/
inline bool ExternalInterface::check(std::string id)
{
	// TODO ��������

	return false;
}
#endif