namespace DesignPattern
{
	class Singleton
	{
	public:
		~Singleton();
	public:
		static Singleton * Instance();
		void Operation();
	protected:
		Singleton();
	private:
		static Singleton * m_pInstance;
		int m_iData;
	};
}