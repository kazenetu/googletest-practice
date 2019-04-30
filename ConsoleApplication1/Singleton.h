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
	static std::weak_ptr<Singleton> getInstance();

protected:
	static std::shared_ptr<Singleton> instance;

	template<typename T>
	friend class shared_helper;

	Singleton();
	~Singleton();
};

#endif // Singleton_h
