#include "Interpreter.h"
#include <map>
#include <string>

namespace DesignPattern
{
	void Context::Assign( std::string strName, bool bValue )
	{
		m_NameValueMap[strName] = bValue;
	}

	bool Context::LookUp( std::string strName )
	{
		std::map<string,bool>::iterator mapIter = m_NameValueMap.find( strName );
		if ( mapIter == m_NameValueMap.end() )
		{
			m_NameValueMap[strName] = false;
			return false;
		}
		else
			return mapIter->second;
	}

	bool VariableExp::Interpret( Context * pContext )
	{
		return pContext->LookUp( m_strName );
	}

	bool AndExp::Interpret( Context * pContext )
	{
		bool bResult = m_pBoolExpLeft->Interpret( pContext ) && m_pBoolExpRight->Interpret( pContext );
		return bResult;
	}

	bool OrExp::Interpret( Context * pContext )
	{
		bool bResult = m_pBoolExpLeft->Interpret( pContext ) || m_pBoolExpRight->Interpret( pContext );
		return bResult;
	}

	bool NotExp::Interpret( Context * pContext )
	{
		bool bResult = !m_pBoolExp->Interpret( pContext );
		return bResult;
	}
}