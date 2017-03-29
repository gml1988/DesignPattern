#pragma once
#include <iostream>

namespace DesignPattern
{
	class Implementor;

	class Abstraction
	{
	public:
		Abstraction( Implementor * pImp );
		//我们把Implementor的内存释放工作交给Abstraction类来做
		virtual ~Abstraction();
	public:
		void Operation();
		static Implementor * CreateConcreteImplementorA();
		static Implementor * CreateConcreteImplementorB();
	private:
		Implementor * m_pImplementor;
	};

	class Implementor
	{
		friend class Abstraction;
	public:
		virtual ~Implementor(){};
	protected:
		Implementor(){};
		virtual void OperationImp() = 0;
	};

	class ConcreteImplementorA : public Implementor
	{
		friend class Abstraction;
	public:
		virtual ~ConcreteImplementorA(){ std::cout<<"Destructor of ConcreteImplementorA"<<std::endl; }
	protected:
		ConcreteImplementorA(){ std::cout<<"Constructor of ConcreteImplementorA"<<std::endl; }
		virtual void OperationImp();
	};

	class ConcreteImplementorB : public Implementor
	{
		friend class Abstraction;
	public:
		virtual ~ConcreteImplementorB() { std::cout<<"Destructor of ConcreteImplementorB"<<std::endl; }
	protected:
		ConcreteImplementorB() { std::cout<<"Constructor of ConcreteImplementorB"<<std::endl; }
		virtual void OperationImp();
	};
}