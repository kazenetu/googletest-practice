#include "pch.h"
#include <iostream>
#include<memory>
#include "Singleton.h"
/*
�X�}�[�g�|�C���^ shared_ptr�w���p�[�N���X
*/
template<typename T>
class shared_helper {
	private:
		friend T;

		struct entity : public T
		{
			template<typename... Args>
			entity(Args&&... args) : T(std::forward<Args>(args)...) { }
		};

		template<typename... Args>
		static std::shared_ptr<T> make_shared(Args&&... args)
		{
			return std::make_shared<entity>(std::forward<Args>(args)...);
		}
};

/*
�C���X�^���X�擾
*/
std::weak_ptr<Singleton> Singleton::getInstance()
{
	if (!instance) {
		instance = shared_helper<Singleton>::make_shared();
	}
	std::cout << "getInstance " << instance << std::endl;
	return instance;
}

Singleton::Singleton()
{
	std::cout << "Singleton" << std::endl;
}
Singleton::~Singleton()
{
	// ������Ɏ��g�̃A�h���X���o�͂���
	std::cout << "~Singleton" << this << std::endl;
}

std::shared_ptr<Singleton> Singleton::instance = 0;

