#pragma once

#ifndef Singleton_h
#define Singleton_h

#include<memory>
#include"IExternalInterface.h"
#include"ExternalInterface.h"

/*
�V���O���g���N���X
*/
class Singleton
{
public:
	/*
	�C���X�^���X�擾
	*/
	static std::weak_ptr<Singleton> getInstance();

	template<typename T>
	static void bindExternalInterface()
	{
		externalInterface = std::make_shared<T>();
	}

	bool check(std::string id);
protected:
	/*
	�C���X�^���X
	*/
	static std::shared_ptr<Singleton> instance;

	/*
	�X�}�[�g�|�C���^ shared_ptr�w���p�[�N���X
	*/
	template<typename T>
	friend class shared_helper;

	/*
	�O���C���^�[�t�F�[�X
	*/
	static std::shared_ptr<IExternalInterface> externalInterface;

	Singleton();
	~Singleton();
};

#endif // Singleton_h
