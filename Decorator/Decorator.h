//Decorator��ConcreteComponent��ͬ�̳�һ��Component������࣬�������߾�����ͬ�Ķ��⹫���Ľӿ�
//Decorator�� *** ����һ��ָ��Component��ָ�� ***����ָ���ֵ���Ա�ʵ����Ϊ��ͬ��ConcreteComponent
//�����Ļ���һ���̶����͵�ConcreteDecorator���ԶԲ�ͬ�������ConcreteComponent������ͬ����������
//���������ı߿򣬻��߶������������Խ�����ͬ��͸����
//��ConcreteComponent�п����в�ͬ�Ķ�Component��Operation��ʵ�֣����ǲ�ͬ��Decorator���ԶԲ�ͬ��
//Component��Operation�������һЩ���Σ����Ƕ���Ĳ���

#pragma once	

namespace DesignPattern
{
	class Component
	{
	public:
		Component(){};
		virtual ~Component(){};
	public:
		virtual void Operation() = 0;
	};

	class ConcreteComponentA : public Component
	{
	public:
		ConcreteComponentA(){};
		virtual ~ConcreteComponentA(){};
	public:
		virtual void Operation();
	};

	class ConcreteComponentB : public Component
	{
	public:
		ConcreteComponentB(){};
		virtual ~ConcreteComponentB(){};
	public:
		virtual void Operation();
	};

	class Decorator : public Component
	{
	public:
		Decorator( Component * pComponent ) : m_pComponent( pComponent ){};
		virtual ~Decorator(){};
	public:
		virtual void Operation();
	protected:
		Component * m_pComponent;
	};

	class ConcreteDecoratorOne : public Decorator
	{
	public:
		ConcreteDecoratorOne( Component * pComponent ) : Decorator( pComponent ){};
		virtual ~ConcreteDecoratorOne(){};
	public:
		virtual void Operation();
	protected:
		void ExtraOperationOne(); 
	};

	class ConcreteDecoratorTwo : public Decorator
	{
	public:
		ConcreteDecoratorTwo( Component * pComponent ) : Decorator( pComponent ){};
		virtual ~ConcreteDecoratorTwo(){};
	public:
		virtual void Operation();
	protected:
		void ExtraOperationTwo();
	};
}