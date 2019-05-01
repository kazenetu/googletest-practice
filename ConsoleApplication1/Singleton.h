#pragma once

#ifndef Singleton_h
#define Singleton_h

#include<memory>

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

	Singleton();
	~Singleton();
};

#endif // Singleton_h
