#include "pch.h"
#include "../ConsoleApplication1/Singleton.h"
#include<memory>
#include<strstream>
#include "ExternalInterfaceStub.h"

/*
インスタンス取得メソッドが同じアドレスを返すか確認
*/
TEST(TestCaseName, TestName) {
    auto ins1 = Singleton::getInstance().lock();
    auto ins2 = Singleton::getInstance().lock();

    // 同一アドレスか？
    EXPECT_EQ(ins1, ins2);
}

/*
外部インターフェースの値が正しいか確認
*/
TEST(TestCaseName, ExternalInterfaceTest) {

    auto ins1 = Singleton::getInstance().lock();

    // 外部インターフェース設定
    Singleton::bindExternalInterface<ExternalInterfaceStub>();
    ExternalInterfaceStub::returnValue = true;

    // 外部インターフェースの結果を確認
    EXPECT_EQ(true, ins1->check("123"));
}
