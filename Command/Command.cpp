#include "Command.h"

namespace DesignPattern
{
	void ConcreteCommandAlpha::Execute()
	{
		m_pReceiver->ActionAlpha();
	}

	void ConcreteCommandBeta::Execute()
	{
		m_pReceiver->ActionBeta();
	}

	MacroCommand::~MacroCommand()
	{
		while ( !m_CommandList.empty() )
		{
			Command * pCommand = m_CommandList.front();
			m_CommandList.pop_front();
			delete pCommand;
		}
	}

	//加入了MacroCommand后，该元素Command的内存释放交给MacroCommand来做
	void MacroCommand::AddCommand(Command *pCommand)
	{
		m_CommandList.push_back( pCommand );
	}

	void MacroCommand::RemoveCommand(Command * pCommand)
	{
		for ( std::list<Command*>::iterator listIter = m_CommandList.begin(); listIter != m_CommandList.end(); )
		{
			if( *listIter == pCommand )
			{
				Command * pCmdDelete = *listIter;
				listIter = m_CommandList.erase( listIter );
				delete pCmdDelete;
			}
			else
				listIter++;
		}
	}

	void MacroCommand::Execute()
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