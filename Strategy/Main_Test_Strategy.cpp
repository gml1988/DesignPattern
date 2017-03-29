#include "Strategy.h"
#include <iostream>

using DesignPattern::StrategyContext;
using DesignPattern::IStrategy;
using DesignPattern::ConcreteStrategyA;
using DesignPattern::ConcreteStrategyB;

int main()
{
	IStrategy * pConcreteStrategyA = new ConcreteStrategyA();
	IStrategy * pConcreteStrategyB = new ConcreteStrategyB();
	StrategyContext * pContextA = new StrategyContext( pConcreteStrategyA );
	StrategyContext * pContextB = new StrategyContext( pConcreteStrategyB );

	pContextA->ContextInterface();
	pContextB->ContextInterface();

	delete pContextB;
	delete pContextA;
	delete pConcreteStrategyB;
	delete pConcreteStrategyA;

	std::cin.get();
	return 0;
}