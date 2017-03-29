#include "Memento.h"
#include <iostream>

using DesignPattern::Originator;
using DesignPattern::Memento;

int main()
{
	Originator * pOriginator = new Originator(10);
	std::cout<<pOriginator->GetState()<<std::endl;
	Memento * pMementor = pOriginator->CreateMemento();
	pOriginator->SetState( 15 );
	std::cout<<pOriginator->GetState()<<std::endl;
	pOriginator->SetMemento( pMementor );
	std::cout<<pOriginator->GetState()<<std::endl;

	std::cin.get();
	return 0;
}