#pragma once
#ifndef __CLIENT_ENGINE_H__
#define __CLIENT_ENGINE_H__
#include "NetworkMgr.h"

struct IMessageHandler
{
	virtual BOOL OnCommandHandle(UINT16 wCommandID, UINT64 u64ConnID, CBufferHelper *pBufferHelper) = 0;
};

class ClientEngine : public ICommandHandler
{
public:
	ClientEngine();

	~ClientEngine();

	BOOL InitEngine();

	BOOL CloseEngine();

	BOOL SetClientID(UINT64 u64ClientID);  //һ���ǽ�ɫID

	BOOL SetLoginSvrInfo(char *szIpAddr, UINT16 sPort);

	BOOL SendData(char *pData, UINT32 dwLen);

	BOOL Login(char *pszAccountName, char *pszPassword);

	BOOL RegisterNetHandler(IMessageHandler *pMsgHandler);

	BOOL Render();

	//�������ڲ�����Ϣ����
	BOOL OnCommandHandle(UINT16 wCommandID, UINT64 u64ConnID, CBufferHelper *pBufferHelper);
	BOOL OnUpdate(UINT32 dwTick){return TRUE;};

	UINT32 OnCmdConnectNotify(UINT16 wCommandID, UINT64 u64ConnID, CBufferHelper *pBufferHelper);
protected:

	UINT64				m_u64ClientID;

	std::string			m_strAccountName;
	std::string			m_strPassword;

	std::string			m_strLoginSvrIp;
	UINT16				m_sLoginSvrPort;

	CNetworkMgr			m_NetworkMgr;
	
	std::vector<IMessageHandler*> m_vtMsgHandler;

};

#endif