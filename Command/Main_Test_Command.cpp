#include "Invoker.h"
#include "Command.h"
#include <iostream>

using DesignPattern::Command;
using DesignPattern::ConcreteCommandAlpha;
using DesignPattern::ConcreteCommandBeta;
using DesignPattern::MacroCommand;
using DesignPattern::Invoker;
using DesignPattern::Receiver;

int main()
{
	Receiver * pReceiver = new Receiver();
	Invoker * pInvoker = new Invoker();
	Command * pCommand_1 = new DesignPattern::ConcreteCommandAlpha( pReceiver );
	pInvoker->AddCommand( pCommand_1 );
	Command * pCommand_2 = new ConcreteCommandBeta( pReceiver );
	pInvoker->AddCommand( pCommand_2 );
	
	MacroCommand * pMacroCommand = new MacroCommand();
	Command * pCommand_3 = new ConcreteCommandBeta( pReceiver );
	Command * pCommand_4 = new ConcreteCommandAlpha( pReceiver );
	Command * pCommand_5 = new ConcreteCommandAlpha( pReceiver );
	pMacroCommand->AddCommand( pCommand_3 );
	pMacroCommand->AddCommand( pCommand_4 );
	pMacroCommand->AddCommand( pCommand_5 );
	pMacroCommand->RemoveCommand( pCommand_5 );
	//Ĭ�ϴ���Ҳ���к�����ת��
	pInvoker->AddCommand( (Command*)(pMacroCommand) );

	pInvoker->Invoke();

	//��Client������Invoker�Լ�Receiver���ͷ�
	delete pInvoker;
	delete pReceiver;

	std::cin.get();
	return 0;
}