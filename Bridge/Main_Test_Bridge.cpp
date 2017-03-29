#include "Bridge.h"
#include <iostream>

using DesignPattern::Abstraction;
using DesignPattern::Implementor;
using DesignPattern::ConcreteImplementorA;
using DesignPattern::ConcreteImplementorB;

int main()
{
	Abstraction * pAbstraction1 = new Abstraction( Abstraction::CreateConcreteImplementorA() );
	Abstraction * pAbstraction2 = new Abstraction( Abstraction::CreateConcreteImplementorB() );
	pAbstraction1->Operation();
	pAbstraction2->Operation();
	delete pAbstraction1;
	delete pAbstraction2;

	std::cin.get();
	return 0;
}