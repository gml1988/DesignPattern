//Proxy比较重要的是，Proxy和RealSubject都会继承与Subject
//这样Proxy和RealSubject都会有相同的接口，用户不能区分调用的是Proxy还是RealSubject
//并且这样Proxy通过Delegate，将操作交给RealSubject
//这样只有在调用RealSubject的API的时候才将其进行实例化
//每一个子类有一个相应的代理，因为RealSubject的实例化是交给Proxy来做的
#pragma once
namespace DesignPattern
{
	class Subject
	{
	public:
		Subject(){};
		virtual ~Subject(){};
	public:
		virtual void Request() = 0;
	};

	class SubjectProxy
		: public Subject
	{
	public:
		SubjectProxy();
		//析构函数中，由Proxy负责RealSubject的析构内存释放
		virtual ~SubjectProxy();
	public:
		virtual void Request();
	private:
		//指向的应该是虚基类
		Subject * m_pRealSubject;
	};

	class RealSubject
		: public Subject
	{
		virtual void Request();
	};
}