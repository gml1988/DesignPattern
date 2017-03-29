#include "Memento.h"

namespace DesignPattern
{
	Memento * Originator::CreateMemento()
	{
		Memento * pMemento = new Memento( m_iState );
		return pMemento;
	}

	void Originator::SetMemento( const Memento * pMemento )
	{
		m_iState = pMemento->GetState();
	}
}