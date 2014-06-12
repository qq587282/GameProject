#pragma once
#include "afxcmn.h"
#include "PacketDef\ClientPacket.h"
#include "Resource.h"


// CDlgSelect 对话框

class CDlgSelect : public CDialog
{
	DECLARE_DYNAMIC(CDlgSelect)

public:
	CDlgSelect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSelect();

// 对话框数据
	enum { IDD = IDD_DLG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnNewChar();

	DECLARE_MESSAGE_MAP()

public:
	BOOL AddCharPickInfo(StCharPickInfo &PickInfo);

	BOOL RefreshListCtrl();

public:

	UINT32			m_nCount;
	StCharPickInfo  m_CharInfoList[4];
	UINT32			m_dwAccountID;

	CListCtrl m_CharList;
	
};
