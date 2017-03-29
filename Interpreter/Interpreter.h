//��Context�д洢����ÿһ��String��������Ӧ��Boolֵ��ӳ���
//����ͬһ��BoolExp���ڲ�ͬ��Context�£������в�ͬ��ֵ
//����NonTerminalExpression���ڲ������ɸ�IBoolExp�ĳ�Ա��EvaluateΪ������ԱEvaluate������߼�����������ά��һ���ķ��Ĺ���
//�ݹ�������Ա�Ľ��Ͳ���
//��������Compositeģʽ
//ֻ�ж�Variable�Ż���String����������TerminalExpression���ڴ˲����ٽ��еݹ飬���Եõ��������Context�в�ѯ��
//�ڲ�ͬ�ı��ʽ��ֻ�洢�˱���������ͨ����ͬ������ʵ�ֲ�ͬ���߼�
//����ȡֵ��Σ�ֻ��ͨ��������Context���õ�

#pragma once
#include <map>
#include <string>

namespace DesignPattern
{
	using std::map;
	using std::string;
	class Context
	{
	public:
		Context(){};
		virtual ~Context(){};
	public:
		void Assign( std::string strName, bool bValue );
		bool LookUp( std::string strName );
	private:
		std::map<std::string,bool> m_NameValueMap;
	};

	class IBooleanExp
	{
	public:
		IBooleanExp(){};
		virtual ~IBooleanExp(){};
	public:
		virtual bool Interpret( Context * pContext ) = 0;
	};

	class VariableExp : public IBooleanExp
	{
	public:
		VariableExp( std::string strName ) : m_strName( strName ){};
		virtual ~VariableExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		std::string m_strName;
	};

	class AndExp : public IBooleanExp
	{
	public:
		AndExp( IBooleanExp * pLeft, IBooleanExp * pRight ) : m_pBoolExpLeft( pLeft ), m_pBoolExpRight( pRight ){};
		virtual ~AndExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExpLeft;
		IBooleanExp * m_pBoolExpRight;
	};

	class OrExp : public IBooleanExp
	{
	public:
		OrExp( IBooleanExp * pLeft, IBooleanExp * pRight ) : m_pBoolExpLeft( pLeft ), m_pBoolExpRight( pRight ){};
		virtual ~OrExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExpLeft;
		IBooleanExp * m_pBoolExpRight;
	};

	class NotExp : public IBooleanExp
	{
	public:
		NotExp( IBooleanExp * pExp ) : m_pBoolExp( pExp ){};
		virtual ~NotExp(){};
	public:
		virtual bool Interpret( Context * pContext );
	private:
		IBooleanExp * m_pBoolExp;
	};
}