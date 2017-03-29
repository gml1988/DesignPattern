#include "HelpHandler.h"
#include <iostream>

using DesignPattern::ApplicationHelpHandler;
using DesignPattern::ButtonHelpHandler;
using DesignPattern::DialogHelpHandler;
using DesignPattern::HelpHandler;
using DesignPattern::Request;
using DesignPattern::RequestType;

int main()
{
	ApplicationHelpHandler * pApplication = new ApplicationHelpHandler();
	DialogHelpHandler * pDialog = new DialogHelpHandler( pApplication );
	ButtonHelpHandler * pButton = new ButtonHelpHandler( pDialog );

	Request * pRequest = new Request( RequestType::REQUEST_BUTTON );
	//Request * pRequest = new Request( RequestType::REQUEST_DIALOG );
	//Request * pRequest = new Request( RequestType::REQUEST_APPLICATION );
	//Request * pRequest = new Request( RequestType::REQEUST_NONE );
	pButton->HandleRequest( pRequest );

	std::cin.get();
	return 0;
};