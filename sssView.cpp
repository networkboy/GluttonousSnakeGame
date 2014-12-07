#include "stdafx.h"
#include "sss.h"

#include "sssDoc.h"
#include "sssView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
struct Snake

{
	
	int x,y;
	
	int len;
	
	int direct;
	
}Snake[50];

struct Food

{
	
	int x;
	
	int y;
	
	int isfood;
	
}Food;


/////////////////////////////////////////////////////////////////////////////
// CSssView

IMPLEMENT_DYNCREATE(CSssView, CView)

BEGIN_MESSAGE_MAP(CSssView, CView)
	//{{AFX_MSG_MAP(CSssView)
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_start, Onstart)
	ON_COMMAND(ID_push, Onpush)
	ON_COMMAND(ID_exit, Onexit)
	ON_COMMAND(ID_contint, Oncontint)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSssView construction/destruction

CSssView::CSssView()
{
	// TODO: add construction code here

}

CSssView::~CSssView()
{
}

BOOL CSssView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSssView drawing

void CSssView::OnDraw(CDC* pDC)
{
	CSssDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	//CBrush DrawBrush=(RGB(255,255,255));
    //pDC->Rectangle(20,20,1000,400);
	

}

/////////////////////////////////////////////////////////////////////////////
// CSssView printing

BOOL CSssView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSssView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSssView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSssView diagnostics

#ifdef _DEBUG
void CSssView::AssertValid() const
{
	CView::AssertValid();
}

void CSssView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSssDoc* CSssView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSssDoc)));
	return (CSssDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSssView message handlers

void CSssView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=11;
	Snake[2].x=12;
	Snake[2].y=12;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;
	// TODO: Add your specialized code here and/or call the base class
	

	
}

void CSssView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	switch(nChar)
	{
	case VK_UP:if(Snake[0].direct!=2)Snake[0].direct=1;break; 
	case VK_DOWN:if(Snake[0].direct!=1)Snake[0].direct=2;break;
	case VK_LEFT:if(Snake[0].direct!=4)Snake[0].direct=3;break;  
	case VK_RIGHT:if(Snake[0].direct!=3)Snake[0].direct=4;break;  
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	

}

void CSssView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CString str;
	str.Format("%d,%d",point.x,point.y);
	AfxMessageBox(str);
	CView::OnRButtonDown(nFlags, point);


}

void CSssView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC=GetDC();
	CString soure;
	SetTimer(1,200,NULL);
	soure.Format("得分:%d!",(Snake[0].len-3)*10); 
	if(Snake[0].x*20<=0||Snake[0].y*20<=0||Snake[0].x*20>=1000||Snake[0].y*20>=700)
	{
		KillTimer(1);
		AfxMessageBox(soure);
		
	}
    
	    if(Snake[0].len>3)
		for(int sn=Snake[0].len-1;sn>0;sn--)
		{
			if(Snake[0].x*20==Snake[sn].x*20&&Snake[0].y*20==Snake[sn].y*20)
			{
				KillTimer(1);
				AfxMessageBox(soure);
	
			}
		}
	    pDC->SelectStockObject(WHITE_PEN);
		pDC->Rectangle(Snake[Snake[0].len-1].x*20,Snake[Snake[0].len-1].y*20,(Snake[Snake[0].len-1].x+1)*20,(Snake[Snake[0].len-1].y+1)*20);
	    for(int i=Snake[0].len-1;i>0;i--)
		{   
			Snake[i].x=Snake[i-1].x;
			Snake[i].y=Snake[i-1].y;
		}
		

		if(Snake[0].direct==1)Snake[0].y--;
		if(Snake[0].direct==2)Snake[0].y++;
		if(Snake[0].direct==3)Snake[0].x--;
		if(Snake[0].direct==4)Snake[0].x++;
		CBrush DrawBrush=(RGB(12,12,12));
		CBrush *Drawbrush=pDC->SelectObject(&DrawBrush);
	    pDC->Rectangle(Snake[0].x*20,Snake[0].y*20,(Snake[0].x+1)*20,(Snake[0].y+1)*20);
		if(Snake[0].x*20==Food.x*20&&Snake[0].y*20==Food.y*20)
		{
			Snake[0].len++;
			Food.isfood=1;
			
		}
	
		if(Food.isfood==1)
		{
		    srand((unsigned)time(NULL));
			do
			{    
				        Food.x=rand();
					    Food.y=rand();
				    for(int isfo=Snake[0].len-1;isfo>=0;isfo--)	    
					if(Food.x*20==Snake[isfo].x*20&&Food.y*20==Snake[isfo].y*20)
					{
						Food.x=rand();
					    Food.y=rand();
					}
			}
			while(Food.x*20<0||Food.y*20<0||Food.x*20>1000||Food.y*20>700);
			
			pDC->Rectangle(Food.x*20,Food.y*20,(Food.x+1)*20,(Food.y+1)*20);
		     Food.isfood=0;
		} 
        
		CView::OnTimer(nIDEvent);
		

}

void CSssView::Onstart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,300,NULL);
	//AfxMessageBox("3秒后开始游戏!");
	CView::OnInitialUpdate();
	Snake[0].x=10;
	Snake[0].y=10;
	Snake[1].x=11;
	Snake[1].y=10;
	Snake[2].x=12;
	Snake[2].y=10;
	Snake[0].direct=3;
	Snake[0].len=3;
	Food.isfood=1;

	
}

void CSssView::Onpush() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	AfxMessageBox("暂停游戏...");

	
}

void CSssView::Onexit() 
{
	AfxMessageBox("退出游戏...");
	exit (0);

}

void CSssView::Oncontint() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);

	
}
