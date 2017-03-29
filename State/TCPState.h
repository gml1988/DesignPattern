//ʵ��Entity������ί�и�Stateȥ����������Ҫ��¶һ��ChangeState�Ľӿڣ���State����е���
//State���깤������State���е���ʵ�����ChangeState�ӿڣ��Զ�����״̬��ת��
//����״̬ת�����߼��ͽ���State���ϣ�Entity��State��֮���״̬ת���߼�����һ����֪


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
		//��Ҫ��ChangeState�趨Ϊ˽�еģ�������粻�ܸ���State״̬
		//������Ҫ��TCPState�趨Ϊ��Ԫ�ֻ࣬��TCPState�ܹ�����TCPConnection��״̬
		friend class TCPState;
		void ChangeState( TCPState * pState );
	private:
		TCPState * m_pState;
	};

	class TCPState
	{
	public:
		//����State�Ļ�����Ҫ�����е�TCPConnection��Ҫ�Ľӿڣ�������Ҫ��Ĭ�ϵ�ʵ��
		//����ͬ��TCPState����������Ҫ���ظ�State��Ӧ�Ĳ���
		virtual void Transmit( TCPConnection * pConnection ){};
		virtual void ActiveOpen( TCPConnection * pConnection ){};
		virtual void PassiveOpen( TCPConnection * pConnection ){};
		virtual void Close( TCPConnection * pConnection ){};
		virtual void Synchronize( TCPConnection * pConnection ){};
		virtual void Acknowledge( TCPConnection * pConnection ){};
		virtual void Send( TCPConnection * pConnection ){};
	protected:
		//����TCPState�ڲ��ĸı�TCPConnection״̬��APIҲ����������ⲿ����
		//״̬��ת��ֻ�ܹ�ͨ������TCPState��API�Ĺ����н����Զ���ת��
		//������Ҫ�趨Ϊprotected���ͣ�����TCPState���������ͨ������ChangeState�����иı�TCPConnection��״̬
		void ChangeState(  TCPConnection * pConnection, TCPState * pState );
	};

	//��ͬ��State���������д��Singleton����ʽ
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