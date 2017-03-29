#include <iostream>
#include "Proxy.h"
using DesignPattern::SubjectProxy;
using DesignPattern::Subject;

int main()
{
	Subject * pSubjectProxy = new SubjectProxy();
	pSubjectProxy->Request();

	std::cin.get();
	return 0;
}