#include "Composite.h"
#include <iostream>
#include <vector>

namespace DesignPattern
{
	void Leaf::Operation()
	{
		std::cout<<"Leaf::Operation()"<<std::endl;
	}

	void Composite::Operation()
	{
		std::cout<<"Composite::Operation()"<<std::endl;
		for (	std::vector<Component *>::iterator vecIter = m_ComponentVector.begin();
				vecIter != m_ComponentVector.end(); 
				vecIter++ )
		{
			(*vecIter)->Operation();
		}
	}

	void Composite::Add( Component * pComp )
	{
		m_ComponentVector.push_back( pComp );
	}

	void Composite::Remove( Component * pComp )
	{
		for (	std::vector<Component *>::iterator vecIter = m_ComponentVector.begin();
				vecIter != m_ComponentVector.end(); 
				)
		{
			if ( (*vecIter) == pComp )
			{
				vecIter = m_ComponentVector.erase( vecIter );
			}
			else
				vecIter++ ;
		}
	}

	Component * Composite::GetChild( int index )
	{
		if ( index >= m_ComponentVector.size() )
			return NULL;
		return m_ComponentVector[index];
	}
}