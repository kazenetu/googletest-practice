#include "pch.h"
#include "../ConsoleApplication1/Singleton.h"
#include<memory>
#include<strstream>

/*
インスタンス取得メソッドが同じアドレスを返すか確認
*/
TEST(TestCaseName, TestName) {
	auto ins1 = Singleton::getInstance().lock();
	auto ins2 = Singleton::getInstance().lock();

	// 同一アドレスか？
	EXPECT_EQ(ins1 ,ins2);
}