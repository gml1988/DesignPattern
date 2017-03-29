#pragma once
#include <iostream>
#include <list>
//在Command中封装了调用者，以及调用的函数

namespace DesignPattern
{
	//也可以写成虚基类，同一个成员函数的调用实体不同
	class Receiver
	{
	public:
		Receiver(){};
		virtual ~Receiver(){};
	public:
		virtual void ActionAlpha(){ std::cout<<"Receiver::ActionAlpha()"<<std::endl; }
		virtual void ActionBeta(){ std::cout<<"Receiver::ActionBeta()"<<std::endl; }
	};

	class Command
	{
	public:
		Command(){};
		virtual ~Command(){};
	public:
		virtual void Execute() = 0;
	};

	//后面可以将函数指针传入作为构造函数的参数，这样每一种Command可以作为一个模板，
	//这样可以调用不同的成员函数
	//现在每一种ConcreteCommand只会对应一种特定的成员函数操作
	class ConcreteCommandAlpha
		: public Command
	{
	public:
		ConcreteCommandAlpha( Receiver * receiver ) : m_pReceiver( receiver ){};
		virtual ~ConcreteCommandAlpha(){ std::cout<<"ConcreteCommandAlpha::~ConcreteCommandAlpha()"<<std::endl; };
	public:
		virtual void Execute();
	private:
		Receiver * m_pReceiver;
	};

	class ConcreteCommandBeta
		: public Command
	{
	public:
		ConcreteCommandBeta( Receiver * receiver ) : m_pReceiver( receiver ){};
		virtual ~ConcreteCommandBeta(){ std::cout<<"ConcreteCommandBeta::~ConcreteCommandBeta()"<<std::endl; };
	public:
		virtual void Execute();
	private:
		Receiver * m_pReceiver;
	};

	class MacroCommand
		: public Command
	{
	public:
		MacroCommand(){};
		virtual ~MacroCommand();
	public:
		void Execute();
		void AddCommand( Command * pCommand );
		void RemoveCommand( Command * pCommand );
	private:
		std::list<Command*> m_CommandList;
	};
}