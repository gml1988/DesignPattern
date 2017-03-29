//ÿ��Handler�ж���һ�����κ�̣������handler���Դ������������������ܴ����򽫸����󽻸����κ�̴���
//��Handler�Ļ�����Ĭ���ǽ������ν�����̵�
//���ĳ��������Դ�����������ظ�Handler���д���������ܴ�����������û����еĺ������д���
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
		//��������ĵĺ���ߵ�ָ�룬�ȹ���ú���ߣ����ܹ�����ǰ�����
		//���߼����趨��������API�����趨�����ΪNULL
		HelpHandler( HelpHandler * pSuccessor = NULL ) : m_pSuccessor( pSuccessor ){};
		virtual ~HelpHandler(){};
	public:
		//ÿһ����ͬ������������ظ÷�����������ͬ��������Դ���ͬ��Request����
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

	//ApplicationΪ������࣬�����к����
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
