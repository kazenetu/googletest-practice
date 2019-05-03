#pragma once

#ifndef Singleton_h
#define Singleton_h

#include<memory>
#include"IExternalInterface.h"
#include"ExternalInterface.h"

/*
シングルトンクラス
*/
class Singleton
{
public:
	/*
	インスタンス取得
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
	インスタンス
	*/
	static std::shared_ptr<Singleton> instance;

	/*
	スマートポインタ shared_ptrヘルパークラス
	*/
	template<typename T>
	friend class shared_helper;

	/*
	外部インターフェース
	*/
	static std::shared_ptr<IExternalInterface> externalInterface;

	Singleton();
	~Singleton();
};

#endif // Singleton_h
