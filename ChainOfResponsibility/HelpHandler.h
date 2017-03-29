//每个Handler中都有一个责任后继，如果本handler可以处理该请求，则处理，如果不能处理，则将该请求交给责任后继处理
//在Handler的基类中默认是将该责任交给后继的
//如果某个子类可以处理，则进行重载该Handler进行处理，如果不能处理则继续调用基类中的函数进行处理
#include <stdio.h>

namespace DesignPattern
{
	enum RequestType
	{
		REQEUST_NONE = 0,
		REQUEST_BUTTON = 1,
		REQUEST_DIALOG = 2,
		REQUEST_APPLICATION = 3
	};

	class Request
	{
	public:
		Request( RequestType requestType ) : m_RequestType( requestType ){};
		virtual ~Request(){};
	public:
		RequestType GetType(){ return m_RequestType; }
	private:
		RequestType m_RequestType;
	};

	class HelpHandler
	{
	public:
		//参数传入的的后继者的指针，先构造好后继者，才能构造其前面的类
		//或者加入设定后继者这个API，先设定后继者为NULL
		HelpHandler( HelpHandler * pSuccessor = NULL ) : m_pSuccessor( pSuccessor ){};
		virtual ~HelpHandler(){};
	public:
		//每一个不同的子类可以重载该方法，这样不同的子类可以处理不同的Request集合
		virtual bool HasHelp( Request * pRequest ) = 0;
		virtual void HandleRequest( Request * pRequest );
	private:
		HelpHandler * m_pSuccessor;
	};

	class ButtonHelpHandler
		: public HelpHandler
	{
	public:
		ButtonHelpHandler( HelpHandler * pSuccessor ) : HelpHandler( pSuccessor ){};
		virtual ~ButtonHelpHandler(){};
	public:
		virtual bool HasHelp( Request * pRequest );
		virtual void HandleRequest( Request * pRequest );
	};

	class DialogHelpHandler
		: public HelpHandler
	{
	public:
		DialogHelpHandler( HelpHandler * pSuccessor ) : HelpHandler( pSuccessor ){};
		virtual ~DialogHelpHandler(){};
	public:
		virtual bool HasHelp( Request * pRequest );
		virtual void HandleRequest( Request * pRequest ); 
	};

	//Application为顶层的类，不会有后继者
	class ApplicationHelpHandler
		: public HelpHandler
	{
	public:
		ApplicationHelpHandler( ) : HelpHandler(){};
		virtual ~ApplicationHelpHandler(){};
	public:
		virtual bool HasHelp( Request * pRequest );
		virtual void HandleRequest( Request * pRequest ); 
	};
}
