#include "pch.h"
#include <iostream>
#include<memory>
#include "Singleton.h"
#include"ExternalInterface.h"
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
	// �C���X�^���X�m�F�E�쐬
	if (!instance) {
		instance = shared_helper<Singleton>::make_shared();
	}

	// �O���C���^�[�t�F�[�X�m�F�E�쐬
	if (!externalInterface) {
		bindExternalInterface<ExternalInterface>();
	}

	std::cout << "getInstance " << instance << " " << Singleton::externalInterface << std::endl;
	return instance;
}

/*
�O���C���^�[�t�F�[�X�̊m�F����
*/
bool Singleton::check(std::string id) {
	return Singleton::externalInterface->check(id);
}

Singleton::Singleton()
{
	std::cout << "Singleton" << std::endl;

	Singleton::externalInterface = nullptr;
}
Singleton::~Singleton()
{
	// ������Ɏ��g�̃A�h���X���o�͂���
	std::cout << "~Singleton" << this << " " << Singleton::externalInterface << std::endl;
}

// ������
std::shared_ptr<Singleton> Singleton::instance = 0;
std::shared_ptr<IExternalInterface> Singleton::externalInterface = 0;


