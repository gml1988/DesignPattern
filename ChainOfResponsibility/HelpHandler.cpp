#include "HelpHandler.h"
#include <iostream>

namespace DesignPattern
{
	void HelpHandler::HandleRequest( Request * pRequest )
	{
		if ( m_pSuccessor != NULL )
			m_pSuccessor->HandleRequest( pRequest );
		else
			std::cout<<"Discard the request : "<<pRequest->GetType()<<std::endl;
	}

	bool ButtonHelpHandler::HasHelp( Request * pRequest )
	{
		if ( pRequest->GetType() == RequestType::REQUEST_BUTTON )
			return true;
		return false;
	}

	void ButtonHelpHandler::HandleRequest(Request * pRequest )
	{
		if ( HasHelp( pRequest ) )
			std::cout<<"ButtonHelpHandler::HandleRequest()"<<std::endl;
		else
			HelpHandler::HandleRequest( pRequest );
	}

	bool DialogHelpHandler::HasHelp( Request * pRequest )
	{
		if ( pRequest->GetType() == RequestType::REQUEST_DIALOG )
			return true;
		return false;
	}

	void DialogHelpHandler::HandleRequest(Request * pRequest )
	{
		if ( HasHelp( pRequest ) )
			std::cout<<"DialogHelpHandler::HandleRequest()"<<std::endl;
		else		//交给基类去做，基类的工作是转发给下一个后继者
			HelpHandler::HandleRequest( pRequest );
	}
	
	bool ApplicationHelpHandler::HasHelp( Request * pRequest )
	{
		if ( pRequest->GetType() == RequestType::REQUEST_APPLICATION )
			return true;
		return false;
	}

	void ApplicationHelpHandler::HandleRequest(Request * pRequest )
	{
		if ( HasHelp( pRequest ) )
			std::cout<<"ApplicationHelpHandler::HandleRequest()"<<std::endl;
		else
			HelpHandler::HandleRequest( pRequest );
	}
}