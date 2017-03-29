#include "Decorator.h"
#include <iostream>

using DesignPattern::Component;
using DesignPattern::ConcreteComponentA;
using DesignPattern::ConcreteComponentB;
using DesignPattern::Decorator;
using DesignPattern::ConcreteDecoratorOne;
using DesignPattern::ConcreteDecoratorTwo;

int main()
{
	Component * pCompA = new ConcreteComponentA();
	Component * pCompB = new ConcreteComponentB();

	Decorator * pDecoratorOneCompA = new ConcreteDecoratorOne( pCompA );
	Decorator * pDecoratorOneCompB = new ConcreteDecoratorOne( pCompB );
	Decorator * pDecoratorTwoCompA = new ConcreteDecoratorTwo( pCompA );
	Decorator * pDecoratorTwoCompB = new ConcreteDecoratorTwo( pCompB );

	pDecoratorOneCompA->Operation();
	pDecoratorOneCompB->Operation();
	pDecoratorTwoCompA->Operation();
	pDecoratorTwoCompB->Operation();

	delete pDecoratorTwoCompB;
	delete pDecoratorTwoCompA;
	delete pDecoratorOneCompB;
	delete pDecoratorOneCompA;

	delete pCompB;
	delete pCompA;

	std::cin.get();
	return 0;
}