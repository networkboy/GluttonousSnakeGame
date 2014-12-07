// sssDoc.cpp : implementation of the CSssDoc class
//

#include "stdafx.h"
#include "sss.h"

#include "sssDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSssDoc

IMPLEMENT_DYNCREATE(CSssDoc, CDocument)

BEGIN_MESSAGE_MAP(CSssDoc, CDocument)
	//{{AFX_MSG_MAP(CSssDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSssDoc construction/destruction

CSssDoc::CSssDoc()
{
	// TODO: add one-time construction code here

}

CSssDoc::~CSssDoc()
{
}

BOOL CSssDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSssDoc serialization

void CSssDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSssDoc diagnostics

#ifdef _DEBUG
void CSssDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSssDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSssDoc commands
