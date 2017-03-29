#include "Builder.h"
#include <iostream>

using DesignPattern::Product;
using DesignPattern::Director;
using DesignPattern::Builder;
using DesignPattern::ConcreteBuilderA;
using DesignPattern::ConcreteBuilderB;

int main()
{
	ConcreteBuilderA * pBuilderA = new ConcreteBuilderA();
	ConcreteBuilderB * pBuilderB = new ConcreteBuilderB();
	Director * pDirector = new Director();
	pDirector->ConstructProductOne( pBuilderA );
	Product * pProductOneA = pBuilderA->GetResult();

	pDirector->ConstructProductOne( pBuilderB );
	Product * pProductOneB = pBuilderB->GetResult();

	pDirector->ConstructProductTwo( pBuilderA );
	Product * pProductTwoA = pBuilderA->GetResult();

	pDirector->ConstructProductTwo( pBuilderB );
	Product * pProductTwoB = pBuilderB->GetResult();

	delete pProductTwoB;
	delete pProductTwoA;
	delete pProductOneB;
	delete pProductOneA;
	delete pDirector;
	delete pBuilderB;
	delete pBuilderA;
	std::cin.get();
	return 0;
}