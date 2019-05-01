#pragma once

#ifndef Singleton_h
#define Singleton_h

#include<memory>

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

	Singleton();
	~Singleton();
};

#endif // Singleton_h
