//FlyweightFactory��ÿһ�൱��ά��һ��������ʵ���ļ��ϣ�
//����Ѿ����б�������Map����ʽ���У���ֱ�Ӵ��б���ȡ
//Map�ļ�ֵ������Flyweight��������������ƣ����ַ�����ΪKey
//��������б���������һ���µ�ʵ�������Ҽ��뵽�б���
//����Flyweight���ڴ��ͷŽ���FlyweightFactory����
//һ��Flyweight�����඼����д�ɵ��������ʽ�������൱�ڴ洢��һ��Flyweight�Ĳֿ�
#pragma once

#include<map>
#include <string>
#include <iostream>

namespace DesignPattern
{
	class Flyweight;

	class FlyweightFactory
	{
	public:
		FlyweightFactory(){};
		virtual ~FlyweightFactory();
	public:
		Flyweight * GetFlyWeight( const std::string strFlyweightKey );
	protected:
		bool IsExisted( std::string strFlyweightKey );
	private:
		std::map<std::string, Flyweight*> m_FlyweightMap;
	};

	class Flyweight
	{
	public:
		virtual ~Flyweight(){};
	protected:
		Flyweight(){};
	public:
		virtual void Operation() = 0;
	};

	class ConcreteFlyweightA : public Flyweight
	{
		//��FlyweightFactory����ΪFlyweight����Ԫ�࣬�����Ļ�����ֻ�ܹ�Factory������Flyweight
		//�Ĺ��죬��粻�ܹ��ٴι���Flyweight��������ʵ��
		//����Ҳ��֤��ֻ��һ��ConcreteFlyweight��ʵ��
		//����ConcreteFlyweight����ʹ��Singleton����ʽ
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightA(){ std::cout<<"Destructor of ConcreteFlyweightA"<<std::endl; }
	protected:
		ConcreteFlyweightA( int iData ) : m_iData( iData ){ std::cout<<"Constructor of ConcreteFlyweightA"<<std::endl; };
	public:
		virtual void Operation();
	private:
		int m_iData;
	};

	class ConcreteFlyweightB : public Flyweight
	{
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightB(){ std::cout<<"Destructor of ConcreteFlyweightB"<<std::endl; }
	protected:
		ConcreteFlyweightB( std::string strData ) : m_strData( strData ){ std::cout<<"Constructor of ConcreteFlyweightB"<<std::endl; };
	public:
		virtual void Operation();
	private:
		std::string m_strData;
	};

	class ConcreteFlyweightC : public Flyweight
	{
		friend class FlyweightFactory;
	public:
		virtual ~ConcreteFlyweightC(){ std::cout<<"Destructor of ConcreteFlyweightC"<<std::endl; }
	protected:
		ConcreteFlyweightC( double dData ) : m_dData( dData ){ std::cout<<"Constructor of ConcreteFlyweightC"<<std::endl; };
	public:
		virtual void Operation();
	private:
		double m_dData;
	};
}