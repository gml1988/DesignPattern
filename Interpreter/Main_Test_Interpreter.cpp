#include "Interpreter.h"
#include <iostream>
#include <string>

using DesignPattern::Context;
using DesignPattern::IBooleanExp;
using DesignPattern::VariableExp;
using DesignPattern::AndExp;
using DesignPattern::OrExp;
using DesignPattern::NotExp;

int main()
{
	Context * pContext = new Context();

	IBooleanExp * pVariableA = new VariableExp( "a" );
	IBooleanExp * pVariableB = new VariableExp( "b" );
	IBooleanExp * pVariableC = new VariableExp( "c" );

	IBooleanExp * pAAndB = new AndExp( pVariableA, pVariableB );
	IBooleanExp * pNotC = new NotExp( pVariableC );
	IBooleanExp * pAndBOrNotC = new OrExp( pAAndB, pNotC );

	pContext->Assign( "a", true );
	pContext->Assign( "b", false );
	pContext->Assign( "c", true );

	std::cout<<pAAndB->Interpret( pContext )<<std::endl;
	std::cout<<pNotC->Interpret( pContext )<<std::endl;
	std::cout<<pAndBOrNotC->Interpret( pContext )<<std::endl;

	delete pAndBOrNotC;
	delete pNotC;
	delete pAAndB;
	delete pVariableC;
	delete pVariableB;
	delete pVariableA;
	delete pContext;

	std::cin.get();
	return 0;
}