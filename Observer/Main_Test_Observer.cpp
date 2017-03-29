#include "Observer.h"
#include <iostream>

using DesignPattern::IObserver;
using DesignPattern::IObservable;
using DesignPattern::ConcreteObserver;
using DesignPattern::ConcreteObservable;

int main()
{
	IObservable * pObservable = new ConcreteObservable();

	for ( int index = 0; index < 10; index++ )
	{
		IObserver * pObserver = new ConcreteObserver( index );
		pObservable->AttachObserver( pObserver );
		if ( index == 5 )
		{
			pObservable->NotifyObserver();
			pObservable->DetachObserver( pObserver );
		}
	}
	pObservable->NotifyObserver();

	std::cin.get();
	return 0;
}