#include "pch.h"
#include <iostream>
#include<memory>
#include "Singleton.h"
#include"ExternalInterface.h"
/*
スマートポインタ shared_ptrヘルパークラス
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
インスタンス取得
*/
std::weak_ptr<Singleton> Singleton::getInstance()
{
	// インスタンス確認・作成
	if (!instance) {
		instance = shared_helper<Singleton>::make_shared();
	}

	// 外部インターフェース確認・作成
	if (!externalInterface) {
		bindExternalInterface<ExternalInterface>();
	}

	std::cout << "getInstance " << instance << " " << Singleton::externalInterface << std::endl;
	return instance;
}

/*
外部インターフェースの確認処理
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
	// 解放時に自身のアドレスを出力する
	std::cout << "~Singleton" << this << " " << Singleton::externalInterface << std::endl;
}

// 初期化
std::shared_ptr<Singleton> Singleton::instance = 0;
std::shared_ptr<IExternalInterface> Singleton::externalInterface = 0;


