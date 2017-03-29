#include "Prototype.h"

namespace DesignPattern
{
	Prototype * ConcretePrototypeA::Clone()
	{
		return new ConcretePrototypeA( *this );
	}

	Prototype * ConcretePrototypeB::Clone()
	{
		return new ConcretePrototypeB( *this );
	}

	Prototype * ConcretePrototypeC::Clone()
	{
		return new ConcretePrototypeC( *this );
	}
}