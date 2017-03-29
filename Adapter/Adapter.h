//通过聚合的方式
//内部有一个Adaptee的成员变量指针，该指针可以由用户进行创建，在Adapter进行构造的时候
//作为构造函数进行传入，在调用继承与Target的对外功用的接口Operation的时候，实际是委托给了Adaptee的
//Adaptee::SpecialOperation的实现
//对于聚合内部的Adaptee的成员指针，其内存托管给了Adapter进行释放，这样可以和继承方式的进行相呼应
//////////////////////////////////////////////////////////////////////////
//通过继承的方式
//Adapter对Target进行public继承，对Adaptee进行private继承
//在调用继承与Target的接口Operation的时候，实现其实使用的是Adaptee的实现
//使用Adaptee::SpecialOperation进行转发给该特定的子类的具体实现

#pragma once	

namespace DesignPattern
{
	class Target
	{
	public:
		Target(){};
		virtual ~Target(){};
	public:
		virtual void Request() = 0;
	};

	class Adaptee
	{
	public:
		Adaptee(){};
		virtual ~Adaptee(){};
	public:
		virtual void SpecificRequest();
	};

	class InheritAdapter : public Target, private Adaptee
	{
	public:
		InheritAdapter(){};
		virtual ~InheritAdapter(){};
	public:
		virtual void Request();
	};

	class AggregateAdapter : public Target
	{
	public:
		AggregateAdapter( Adaptee * pAdaptee ) : m_pAdaptee( pAdaptee ){};
		virtual ~AggregateAdapter(){};
	public:
		virtual void Request();
	protected:
		Adaptee * m_pAdaptee;
	};
}