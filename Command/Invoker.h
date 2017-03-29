#pragma once
#include <list>

namespace DesignPattern
{
	class Command;

	class Invoker
	{
	public:
		Invoker();
		virtual ~Invoker();
	public:
		void AddCommand( Command * pCommand );
		void Invoke();
	private:
		std::list<Command*> m_CommandList;
	};
}