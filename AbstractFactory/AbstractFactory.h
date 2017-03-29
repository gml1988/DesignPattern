//对于每一种ConcreteProduct，AbstractFactory都会有队应该Product的Interface
//然后不同的ConcreteFactory就可以对于每一种ConcreteProduct有不同的创建
//类似于不同的厂商生产同一个产品，做法肯定不一样，这样在同一个

#pragma once

namespace DesignPattern
{
	//AbstractProductA和AbstractProductB是不同类型的产品族的基类
	//类似于“可乐”和“鸡翅”
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

	//Factory可以生产不同产品族的产品，但是不同的ConcreteFactory可以对于某一特定的产品族
	//生产出同一类型产品的不同实现
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