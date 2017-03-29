//实体Entity将工作委托给State去做，并且需要暴露一个ChangeState的接口，供State类进行调用
//State做完工作后，在State类中调用实体类的ChangeState接口，自动进行状态的转换
//这样状态转换的逻辑就交给State集合，Entity对State族之间的状态转换逻辑可以一无所知


namespace DesignPattern
{
	class TCPState;

	class TCPConnection
	{
	public:
		TCPConnection();
		virtual ~TCPConnection();
	public:
		virtual void ActiveOpen();
		virtual void PassiveOpen();
		virtual void Close();
		virtual void Send();
		virtual void Synchronize();
	private:
		//需要将ChangeState设定为私有的，这样外界不能更改State状态
		//并且需要将TCPState设定为友元类，只有TCPState能够更改TCPConnection的状态
		friend class TCPState;
		void ChangeState( TCPState * pState );
	private:
		TCPState * m_pState;
	};

	class TCPState
	{
	public:
		//首先State的基类需要有所有的TCPConnection需要的接口，并且需要有默认的实现
		//而不同的TCPState的子类则需要重载该State对应的操作
		virtual void Transmit( TCPConnection * pConnection ){};
		virtual void ActiveOpen( TCPConnection * pConnection ){};
		virtual void PassiveOpen( TCPConnection * pConnection ){};
		virtual void Close( TCPConnection * pConnection ){};
		virtual void Synchronize( TCPConnection * pConnection ){};
		virtual void Acknowledge( TCPConnection * pConnection ){};
		virtual void Send( TCPConnection * pConnection ){};
	protected:
		//对于TCPState内部的改变TCPConnection状态的API也不能随意给外部调用
		//状态的转换只能够通过调用TCPState的API的过程中进行自动的转化
		//并且需要设定为protected类型，这样TCPState的子类可以通过调用ChangeState来进行改变TCPConnection的状态
		void ChangeState(  TCPConnection * pConnection, TCPState * pState );
	};

	//不同的State的子类可以写成Singleton的形式
	class TCPEstablished : public TCPState
	{
	public:
		virtual void Close( TCPConnection * pConnection );
		virtual void Transmit( TCPConnection * pConnection );

		static TCPState * Instance();
	private:
		static TCPState * m_pInstance;
	};

	class TCPListen : public TCPState
	{
	public:
		virtual void Send( TCPConnection * pConnection );

		static TCPState * Instance();
	private:
		static TCPState * m_pInstance;
	};

	class TCPClosed : public TCPState
	{
	public:
		virtual void ActiveOpen( TCPConnection * pConnection );
		virtual void PassiveOpen(TCPConnection * pConnection );

		static TCPState * Instance();
	private:
		static TCPState * m_pInstance;
	};
}