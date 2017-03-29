#include "Singleton.h"
#include <iostream>

using DesignPattern::SingletonExample;

int main()
{
	SingletonExample * pSingletonExample = SingletonExample::Instance();
	std::cout<<pSingletonExample->GetData()<<std::endl;
	std::cin.get();
	return 0;
}