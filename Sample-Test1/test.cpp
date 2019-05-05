#include "pch.h"
#include "../ConsoleApplication1/Singleton.h"
#include<memory>
#include<strstream>
#include "ExternalInterfaceStub.h"

/*
�C���X�^���X�擾���\�b�h�������A�h���X��Ԃ����m�F
*/
TEST(TestCaseName, TestName) {
    auto ins1 = Singleton::getInstance().lock();
    auto ins2 = Singleton::getInstance().lock();

    // ����A�h���X���H
    EXPECT_EQ(ins1, ins2);
}

/*
�O���C���^�[�t�F�[�X�̒l�����������m�F
*/
TEST(TestCaseName, ExternalInterfaceTest) {

    auto ins1 = Singleton::getInstance().lock();

    // �O���C���^�[�t�F�[�X�ݒ�
    Singleton::bindExternalInterface<ExternalInterfaceStub>();
    ExternalInterfaceStub::returnValue = true;

    // �O���C���^�[�t�F�[�X�̌��ʂ��m�F
    EXPECT_EQ(false, ins1->check("123"));
}
