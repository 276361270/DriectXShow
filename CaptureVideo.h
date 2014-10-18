// CCaptureVideo��Ƶ��׽��ͷ�ļ�
/////////////////////////////////////////////////////////////////////
#if !defined(AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_)
#define AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_
/////////////////////////////////////////////////////////////////////
// CaptureVideo.h : header file
/////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <atlbase.h>
#include <windows.h>
#include <qedit.h>
#include <dshow.h>
#ifndef SAFE_RELEASE
#define SAFE_RELEASE( x )if ( NULL != x ){x->Release();x = NULL;}//�����SAFE_RELEASE��������Դ���ͷźͻ���
#endif
class CSampleGrabberCB;//��CSampleGrabberCB���ǰ��������������Ҫ��֮���壬ʵ�ʶ���λ����Դ�ļ���
class CCaptureVideo : public CWnd 
{
	friend class CSampleGrabberCB;//��CSampleGrabberCB����ΪCCaptureVideo�����Ԫ�࣬
								//������CSampleGrabberCB���е����к���������CCaptureVideo����Ԫ���������Է��ʱ����˽�г�Ա
public:
	void GrabOneFrame(BOOL bGrab);//��õ�֡ͼ��
	void ConfigCameraPin(HWND hParent);//��������ͷ����Ƶ��ʽ
	void ConfigCameraFilter(HWND hParent);//��������ͷ��֡ͼ���ͼ�����
	HRESULT Init(int iDeviceID,HWND hWnd);//���һϵ�г�ʼ���������罨���˲�ͼ�����������Լ��˲��������ӣ���Ƶ���ڵ���ʾ���豸��ö��
	HRESULT ReInit(int iDeviceID, HWND hWnd);
	int EnumVideoDevices(HWND hVideoList);//ö����Ƶϵͳ�豸����һ����Ͽ���
	int EnumAudioDevices(HWND hAudioList);//ö����Ƶ�豸��һ����Ͽ���
	CCaptureVideo();
	virtual ~CCaptureVideo();
	HRESULT	CaptureImagesToAVI(CString inFileName);//���񱣴���Ƶ
private:
	IBaseFilter *pMux;//������ƵΪAVI�ļ�

	HWND m_hWnd;
	IGraphBuilder *m_pGB;
	ICaptureGraphBuilder2* m_pCapture;
	IBaseFilter* m_pBF;
	//IBaseFilter *m_pABF;
	IMediaControl* m_pMC;
	IVideoWindow* m_pVW;
	ISampleGrabber* m_pGrabber;
protected:
	void FreeMediaType(AM_MEDIA_TYPE& mt);
	bool BindFilter(int deviceId, IBaseFilter **pFilter);//��ѡ����ָ�����豸�󶨵�һ���˲�����
	void ResizeVideoWindow();
	HRESULT SetupVideoWindow();
	HRESULT InitCaptureGraphBuilder();//��ʼ��������˲�ͼ��͹�����
};
#endif // !defined(AFX_CAPTUREVIDEO_H__F5345AA4_A39F_4B07_B843_3D87C4287AA0__INCLUDED_)
