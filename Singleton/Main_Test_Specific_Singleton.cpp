#include "Singleton.h"
#include <iostream>

int main()
{
	using DesignPattern::Singleton;
	Singleton * pInstance_1 = Singleton::Instance();
	pInstance_1->Operation();

	Singleton * pInstance_2 = Singleton::Instance();
	pInstance_2->Operation();

	//delete pInstance_1;

	std::cin.get();
	return 0;
}