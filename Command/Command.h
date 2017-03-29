#pragma once
#include <iostream>
#include <list>
//��Command�з�װ�˵����ߣ��Լ����õĺ���

namespace DesignPattern
{
	//Ҳ����д������࣬ͬһ����Ա�����ĵ���ʵ�岻ͬ
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

	//������Խ�����ָ�봫����Ϊ���캯���Ĳ���������ÿһ��Command������Ϊһ��ģ�壬
	//�������Ե��ò�ͬ�ĳ�Ա����
	//����ÿһ��ConcreteCommandֻ���Ӧһ���ض��ĳ�Ա��������
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