//Memento�Ĺ��캯��Ϊ˽�еģ���������޷����죬�������Ա������Set��GetҲ��Private��
//ֻ��Originator�ࣨ��Ԫ�ࣩ���ܽ���Memento�Ĺ���

namespace DesignPattern
{
	class Memento;

	class Originator
	{
	public:
		Originator( int iState ) : m_iState( iState ){};
		virtual ~Originator(){};
	public:
		Memento * CreateMemento();
		void SetMemento( const Memento * pMemento );
		inline void SetState( int iState ){ m_iState = iState; }
		inline int GetState() const{ return m_iState; }
	private:
		int m_iState;
	};

	class Memento
	{
		//��Ҫ��Originator����Ϊ��Ԫ�࣬�������Է����乹�캯���Լ�
		//Get,Set����
		friend class Originator;
	public:
		virtual ~Memento(){};
	private:
		//Memento�Ĺ��캯�����Լ���Ա������Get��Set��ֻ�ܹ�������Ԫ��Originator���з���
		//����Client�������⹹���Լ��ı�״̬
		Memento( int iState ) : m_iState( iState ){};
		inline int GetState() const{ return m_iState; }
		inline void SetState( int iState ){ m_iState = iState; }
	private:
		int m_iState;
	};
}
