#include "Mediator.h"
#include <iostream>

namespace DesignPattern
{
	void ConcreteMediator::CreateColleague()
	{
		m_pColleagueA_1 = new ConcreteColleagueA( this );
		m_pColleagueA_2 = new ConcreteColleagueA( this );
		m_pColleagueB = new ConcreteColleagueB( this );
	}

	void ConcreteMediator::NotifiedByColleague( Colleague * pColleague )
	{
		if ( pColleague == m_pColleagueA_1 )
		{
			std::cout<<"Notified by m_pColleagueA_1"<<std::endl;
		}
		else if ( pColleague == m_pColleagueA_2 )
		{
			std::cout<<"Notified by m_pColleagueA_2"<<std::endl;
		}
		else if( pColleague == m_pColleagueB )
		{
			std::cout<<"Notified by m_pColleagueB"<<std::endl;
		}
	}

	void Colleague::NotifyMediator()
	{
		m_pMediator->NotifiedByColleague( this );
	}
}