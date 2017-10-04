#pragma once
#include "NouseSettings.h"
#include "SettingsTabDlg.h"

// CBasicSettingsDlg dialog

class CBasicSettingsDlg : public CSettingsTabDlg
{
	//DECLARE_DYNAMIC(CBasicSettingsDlg)

public:
	CBasicSettingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBasicSettingsDlg();

// Dialog Data
	enum { IDD = IDD_BASIC_SETTINGS_DLG };

	virtual void GetData(CSettingsHandler* p_SettingsHandler);
	virtual void SetData(CSettingsHandler* p_SettingsHandler);
protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	
	HWND CreateToolTip(HWND hwndTool, HWND hDlg, PTSTR pszText)
	{
		if (!hwndTool || !hDlg || !pszText)
		{
			return FALSE;
		}
			
		// Create the tooltip. g_hInst is the global instance handle.
		HWND hwndTip = CreateWindowEx(NULL, TOOLTIPS_CLASS, NULL,
			WS_POPUP | TTS_ALWAYSTIP | TTS_BALLOON,
			CW_USEDEFAULT, CW_USEDEFAULT,
			CW_USEDEFAULT, CW_USEDEFAULT,
			hDlg, NULL,
			AfxGetInstanceHandle(), NULL);

		if (!hwndTool || !hwndTip)
		{
			return (HWND)NULL;
		}

		// Associate the tooltip with the tool.
		TOOLINFO toolInfo = { 0 };
		toolInfo.cbSize = sizeof(toolInfo);
		toolInfo.hwnd = hDlg;
		toolInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
		toolInfo.uId = (UINT_PTR)hwndTool;
		toolInfo.lpszText = pszText;
		::SendMessage(hwndTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);

		return hwndTip;
	};
	int m_nCursorSize;
	int m_nCursorSpeed;
	int m_nCountdownCalibration;
	int m_nCountdownDwell;
	int m_nEnableYellowState;
	int m_nNavigationType;
	int m_nMotionRangeHorizontal;
	int m_nMotionRangeVertical;
	int m_nResolutionPixels;
	int m_nResolutionSeconds;
	int m_nUserFaceDetection;
	int m_nLightNormalization;
	int m_nEnableAutoRecalibration;
	int m_nEnableSounds;

	DECLARE_MESSAGE_MAP()
public:
private:
	CSliderCtrl m_sldr_CursorSize;
	CSliderCtrl m_sldr_CursorSpeed;
	CSliderCtrl m_sldr_CountdownCaliberTime;
	CSliderCtrl m_sldr_CountdownDwellTime;
	CSliderCtrl m_sldr_VerticalMotionRange;
	CSliderCtrl m_sldr_HorizontalMotionRange;
	CSliderCtrl m_sldr_ResolitionPixels;
	CSliderCtrl m_sldr_ResolitionSeconds;

public:
	afx_msg void OnBnClickedUserFaceDetecCheck();
};