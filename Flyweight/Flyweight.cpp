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
		//������ÿ��ConcreteFlyweight�Ĺ��촫��Ĳ�������Hard Coding
		//�����������ļ��н����������Ψһ��������Flyweightʵ������Ĺ���Ĳ�����ʲô
		//��Ϊ������ֻ��һ��ʵ���������ĵĻ�ֻ��Ҫ�趨һ������Ĳ����Ϳ�����
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