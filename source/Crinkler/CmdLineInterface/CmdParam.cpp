#include "CmdParam.h"

using namespace std;

CmdParam::CmdParam(const char* parameterName, const char* description, const char* argumentDescription, int flags) {
	m_parameterName = parameterName;
	m_description = description;
	if(argumentDescription)
		m_argumentDesc = argumentDescription;
	m_flags = flags;
	m_numMatches = 0;
}

string CmdParam::ToString() const {
	char buff[1024];
	char param[1024];
	if(m_flags & PARAM_TAKES_ARGUMENT) {
		if(m_flags & PARAM_ALLOW_NO_ARGUMENT_DEFAULT)
			sprintf_s(param, sizeof(param), "%s[:%s]", m_parameterName.c_str(), m_argumentDesc.c_str());
		else
			sprintf_s(param, sizeof(param), "%s:%s", m_parameterName.c_str(), m_argumentDesc.c_str());
	} else {
		sprintf_s(param, sizeof(param), "%s", m_parameterName.c_str());
	}
	sprintf_s(buff, sizeof(buff), "/%-24s%s", param, "");
	return string(buff);
}

