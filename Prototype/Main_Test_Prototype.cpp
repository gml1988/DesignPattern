#include "Prototype.h"
#include <iostream>

using DesignPattern::Prototype;
using DesignPattern::ConcretePrototypeA;
using DesignPattern::ConcretePrototypeB;
using DesignPattern::ConcretePrototypeC;

int main()
{
	Prototype * pProtypeA = new ConcretePrototypeA( 10 );
	Prototype * pProtypeB = new ConcretePrototypeB( "Design Pattern" );
	Prototype * pProtypeC = new ConcretePrototypeC( 15, 'A' );

	Prototype * A_1 = pProtypeA->Clone();
	Prototype * B_1 = pProtypeB->Clone();
	Prototype * C_1 = pProtypeC->Clone();
	std::cin.get();
	return 0;
}