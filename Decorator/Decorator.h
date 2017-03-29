//Decorator和ConcreteComponent共同继承一个Component的虚基类，这样两者就有相同的对外公开的接口
//Decorator中 *** 还有一个指向Component的指针 ***，该指针的值可以被实例化为不同的ConcreteComponent
//这样的话，一个固定类型的ConcreteDecorator可以对不同的子类的ConcreteComponent进行相同操作的修饰
//比如对桌面的边框，或者对任务栏都可以进行相同的透明化
//在ConcreteComponent中可以有不同的对Component中Operation的实现，但是不同的Decorator可以对不同的
//Component的Operation上面加上一些修饰，就是额外的操作

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