#include "Composite.h"
#include <iostream>

using DesignPattern::Leaf;
using DesignPattern::Composite;
using DesignPattern::Component;

int main()
{
	Component * pTopComp = new Composite();
	
	Component * pLeaf1_Level1 = new Leaf();
	pTopComp->Add( pLeaf1_Level1 );
	Component * pLeaf2_Level1 = new Leaf();
	pTopComp->Add( pLeaf2_Level1 );

	Component * pComposite1_Level1 = new Composite();
	pTopComp->Add( pComposite1_Level1 );
	Component * pLeaf3_Level2 = new Leaf();
	pComposite1_Level1->Add( pLeaf3_Level2 );
	Component * pLeaf4_Level2 = new Leaf();
	pComposite1_Level1->Add( pLeaf4_Level2 );
	
	Component * pComposite2_Level2 = new Composite();
	pComposite1_Level1->Add( pComposite2_Level2 );
	Component * pLeaf5_Level3 = new Leaf();
	pComposite2_Level2->Add( pLeaf5_Level3 );
	Component * pLeaf6_Level3 = new Leaf();
	pComposite2_Level2->Add( pLeaf6_Level3 );

	pTopComp->Operation();

	std::cin.get();
	return 0;
}