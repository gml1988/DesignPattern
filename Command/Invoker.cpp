#include "Invoker.h"
#include "Command.h"
#include <list>

namespace DesignPattern
{
	Invoker::Invoker()
	{

	}

	Invoker::~Invoker()
	{
		while ( !m_CommandList.empty() )
		{
			Command * pCommand = m_CommandList.front();
			m_CommandList.pop_front();
			delete pCommand;
		}
	}

	void Invoker::AddCommand( Command * pCommand )
	{
		m_CommandList.push_back( pCommand );
	}

	void Invoker::Invoke()
	{
		while ( !m_CommandList.empty() )
		{
			Command * pCommand = m_CommandList.front();
			m_CommandList.pop_front();
			pCommand->Execute();
			delete pCommand;
		}
	}
}