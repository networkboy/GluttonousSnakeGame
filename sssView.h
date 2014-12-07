// sssView.h : interface of the CSssView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SSSVIEW_H__D932EB2B_68FD_4D0A_8507_1AB073FCAA6C__INCLUDED_)
#define AFX_SSSVIEW_H__D932EB2B_68FD_4D0A_8507_1AB073FCAA6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSssView : public CView
{
protected: // create from serialization only
	CSssView();
	DECLARE_DYNCREATE(CSssView)

// Attributes
public:
	CSssDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSssView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSssView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSssView)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onstart();
	afx_msg void Onpush();
	afx_msg void Onexit();
	afx_msg void Oncontint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in sssView.cpp
inline CSssDoc* CSssView::GetDocument()
   { return (CSssDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSSVIEW_H__D932EB2B_68FD_4D0A_8507_1AB073FCAA6C__INCLUDED_)
