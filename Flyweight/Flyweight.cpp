#include "Flyweight.h"
#include <stdio.h>
#include <map>
#include <string>

namespace DesignPattern
{
	Flyweight * FlyweightFactory::GetFlyWeight(const std::string strFlyweightKey)
	{
		if ( IsExisted( strFlyweightKey ) )
			return m_FlyweightMap[strFlyweightKey];
		Flyweight * pFlyweight = NULL;
		//在这里每个ConcreteFlyweight的构造传入的参数都是Hard Coding
		//可以在配置文件中进行设置这个唯一的轻量级Flyweight实例传入的构造的参数是什么
		//因为本来就只有一个实例，这样的的话只需要设定一个构造的参数就可以了
		if ( strFlyweightKey == "ConcreteFlyweightA" )
			pFlyweight = new ConcreteFlyweightA( 10 );
		else if ( strFlyweightKey == "ConcreteFlyweightB" )
			pFlyweight = new ConcreteFlyweightB( "New Flyweight" );
		else if ( strFlyweightKey == "ConcreteFlyweightC" )
			pFlyweight = new ConcreteFlyweightC( 5.000 );
		else
			std::cout<<"unrecognizable  Flyweight Type Name"<<std::endl;
		if ( pFlyweight != NULL )
			m_FlyweightMap[strFlyweightKey] = pFlyweight ;
		return pFlyweight;
	}

	bool FlyweightFactory::IsExisted( std::string strFlyweightKey )
	{
		return ( m_FlyweightMap.count( strFlyweightKey ) > 0 );
	}

	FlyweightFactory::~FlyweightFactory()
	{
		for ( std::map<std::string,Flyweight*>::iterator mapIter = m_FlyweightMap.begin();
				mapIter != m_FlyweightMap.end(); )
		{
			Flyweight * pFlyweight = mapIter->second;
			mapIter = m_FlyweightMap.erase( mapIter );
			delete pFlyweight;
		}
	}

	void ConcreteFlyweightA::Operation()
	{
		std::cout<<m_iData<<std::endl;
	}

	void ConcreteFlyweightB::Operation()
	{
		std::cout<<m_strData<<std::endl;
	}

	void ConcreteFlyweightC::Operation()
	{
		std::cout<<m_dData<<std::endl;
	}
}