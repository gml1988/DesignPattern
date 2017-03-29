#include "Observer.h"
#include <vector>
#include <iostream>
#include <string>

namespace DesignPattern
{
	void ConcreteObserver::Update( IObservable* pObservable )
	{
		std::cout<<"ConcreteObserver "<<m_iData<<" Update()"<<std::endl;
	}

	std::string ConcreteObservable::GetStringValue()
	{
		return m_stringData;
	}

	void ConcreteObservable::AttachObserver( IObserver * pObserver )
	{
		m_ObserverVector.push_back( pObserver );
	}

	void ConcreteObservable::DetachObserver( IObserver * pObserver )
	{
		for(	std::vector<IObserver*>::iterator vecIter = m_ObserverVector.begin();
				vecIter != m_ObserverVector.end();)
		{
			if( (*vecIter) == pObserver )
				vecIter = m_ObserverVector.erase( vecIter );
			else
				vecIter++;
		}
	}

	void ConcreteObservable::NotifyObserver()
	{
		for(	std::vector<IObserver*>::iterator vecIter = m_ObserverVector.begin();
				vecIter != m_ObserverVector.end();
				vecIter++ )
		{
			(*vecIter)->Update( this );
		}
	}
}