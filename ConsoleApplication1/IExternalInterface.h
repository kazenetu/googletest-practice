#pragma once

#ifndef IExternalInterface_h
#define IExternalInterface_h

#include <iostream>

/*
�O���C���^�[�t�F�[�X�p�X�[�p�[�N���X
*/
class IExternalInterface
{
public:
	virtual bool check(std::string id) = 0;
};

#endif