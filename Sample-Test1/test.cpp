#include "pch.h"
#include "../ConsoleApplication1/Singleton.h"
#include<memory>
#include<strstream>

/*
�C���X�^���X�擾���\�b�h�������A�h���X��Ԃ����m�F
*/
TEST(TestCaseName, TestName) {
	auto ins1 = Singleton::getInstance().lock();
	auto ins2 = Singleton::getInstance().lock();

	// ����A�h���X���H
	EXPECT_EQ(ins1 ,ins2);
}