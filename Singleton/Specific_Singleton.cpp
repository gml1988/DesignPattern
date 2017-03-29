#include "Singleton.h"
#include <iostream>

namespace DesignPattern
{
	//前面加上"Singleton * "
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

	//如果没有显示的调用Delete的话，那么在main函数结束的时候，由OS进行垃圾回收
	//Q：何时进行该singleton的内存回收工作？
	Singleton::~Singleton()
	{
		std::cout<<"The deconstructor of Singleton."<<std::endl;
	}

	void Singleton::Operation()
	{
		std::cout<<"Singleton::Operation "<<m_iData<<std::endl;
	}
}