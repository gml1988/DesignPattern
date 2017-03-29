//����ÿһ��ConcreteProduct��AbstractFactory�����ж�Ӧ��Product��Interface
//Ȼ��ͬ��ConcreteFactory�Ϳ��Զ���ÿһ��ConcreteProduct�в�ͬ�Ĵ���
//�����ڲ�ͬ�ĳ�������ͬһ����Ʒ�������϶���һ����������ͬһ��

#pragma once

namespace DesignPattern
{
	//AbstractProductA��AbstractProductB�ǲ�ͬ���͵Ĳ�Ʒ��Ļ���
	//�����ڡ����֡��͡����ᡱ
	class AbstractProductA
	{
	public:
		virtual ~AbstractProductA(){};
	protected:
		AbstractProductA(){};
	};

	class AbstractProductB
	{
	public:
		virtual ~AbstractProductB(){};
	protected:
		AbstractProductB(){};
	};

	//Factory����������ͬ��Ʒ��Ĳ�Ʒ�����ǲ�ͬ��ConcreteFactory���Զ���ĳһ�ض��Ĳ�Ʒ��
	//������ͬһ���Ͳ�Ʒ�Ĳ�ͬʵ��
	class AbstractFactory
	{
	public:
		AbstractFactory(){};
		virtual ~AbstractFactory(){};
	public:
		AbstractProductA * CreateProductA();
		AbstractProductB * CreateProductB();
	};

}