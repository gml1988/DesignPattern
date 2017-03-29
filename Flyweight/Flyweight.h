//FlyweightFactory中每一相当于维护一个轻量级实例的集合，
//如果已经在列表（可以用Map的形式）中，则直接从列表中取
//Map的键值可以是Flyweight轻量级子类的名称，用字符串作为Key
//如果不在列表中则生成一个新的实例，并且加入到列表中
//对于Flyweight的内存释放交给FlyweightFactory来做
//一般Flyweight的子类都可以写成单件类的形式，这样相当于存储了一个Flyweight的仓库
#pragma once

#include<map>
#include <string>
#include <iostream>

namespace DesignPattern
{
	class Flyweight;

	class FlyweightFactory
	{
	public:
		FlyweightFactory(){};
		virtual ~FlyweightFactory();
	public:
		Flyweight * GetFlyWeight( const std::string strFlyweightKey );
	protected:
		bool IsExisted( std::string strFlyweightKey );
	private:
		std::map<std::string, Flyweight*> m_FlyweightMap;
	};

	class Flyweight
	{
	public:
		virtual ~Flyweight(){};
	protected:
		Flyweight(){};
	public:
		virtual void Operation() = 0;
	};

	class ConcreteFlyweightA : public Flyweight
	{
		//将FlyweightFactory声明为Flyweight的友元类，这样的话，就只能够Factory来进行Flyweight
		//的构造，外界不能够再次构造Flyweight的其他的实体
		//这样也保证了只有一个ConcreteFlyweight的实例
		//并且ConcreteFlyweight可以使用Singleton的形式
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightA(){ std::cout<<"Destructor of ConcreteFlyweightA"<<std::endl; }
	protected:
		ConcreteFlyweightA( int iData ) : m_iData( iData ){ std::cout<<"Constructor of ConcreteFlyweightA"<<std::endl; };
	public:
		virtual void Operation();
	private:
		int m_iData;
	};

	class ConcreteFlyweightB : public Flyweight
	{
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightB(){ std::cout<<"Destructor of ConcreteFlyweightB"<<std::endl; }
	protected:
		ConcreteFlyweightB( std::string strData ) : m_strData( strData ){ std::cout<<"Constructor of ConcreteFlyweightB"<<std::endl; };
	public:
		virtual void Operation();
	private:
		std::string m_strData;
	};

	class ConcreteFlyweightC : public Flyweight
	{
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightC(){ std::cout<<"Destructor of ConcreteFlyweightC"<<std::endl; }
	protected:
		ConcreteFlyweightC( double dData ) : m_dData( dData ){ std::cout<<"Constructor of ConcreteFlyweightC"<<std::endl; };
	public:
		virtual void Operation();
	private:
		double m_dData;
	};
}