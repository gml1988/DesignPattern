#include "Singleton.h"
#include <iostream>

namespace DesignPattern
{
	//ǰ�����"Singleton * "
	Singleton * Singleton::m_pInstance = NULL;

	Singleton * Singleton::Instance()
	{
		if ( m_pInstance == NULL )
			m_pInstance = new Singleton();
		return m_pInstance;
	}

	Singleton::Singleton()
	{
		std::cout<<"The constructor of Singleton."<<std::endl;
		m_iData = 100;
	}

	//���û����ʾ�ĵ���Delete�Ļ�����ô��main����������ʱ����OS������������
	//Q����ʱ���и�singleton���ڴ���չ�����
	Singleton::~Singleton()
	{
		std::cout<<"The deconstructor of Singleton."<<std::endl;
	}

	void Singleton::Operation()
	{
		std::cout<<"Singleton::Operation "<<m_iData<<std::endl;
	}
}