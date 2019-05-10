// WindowsProject2.cpp : Defines the entry point for the application.
// Change

#include "stdafx.h"
#include "Windowsx.h" // for GET_X_LPARAM


// wingdi.h (include Windows.h)  GetCharWidth32
#include "WindowsProject2.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



// SafeRelease inline function .		
template <class T> inline void SafeRelease(T **ppT)
{
    if (*ppT) {  (*ppT)->Release();  *ppT = NULL; }
}

Math::Eq_Edit editor;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
 //   wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.hbrBackground 	= (HBRUSH)GetStockObject(BLACK_BRUSH);

    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   editor.init_DirectWrite(hWnd);


   ShowWindow(hWnd, nCmdShow);
   ShowCaret(hWnd);
   UpdateWindow(hWnd);

   return TRUE;
}

void Math::Eq_Edit::loadGlyphs(){

			
// u'\u0420\u043e\u0441\u0441\u0438\u044f'
	//glyph = L'\u222b';
//	glyph = 8747;
// greek letters   0391 03c9  913   969
//	glyph = (TCHAR) wParam;

//	glyphs[0][0] = L'\u222b';
// 		TCHAR glyphs[10][25]{};

// Top row = row 0: Greek Caps 
	for( int col = 0; col < 25; col++){
		  glyphs[0][col] = 913 + col;
	}

// Row 1: Greek Lower Case 
	for( int col = 0; col < 25; col++){
		  glyphs[1][col] = 945 + col;
	}

// fill out the top row == 0 25 - 49
	glyphs[2][0] =  8722; // 2212 minus sign
	glyphs[2][1] =  0177; // 00b1 plus minus sign
	glyphs[2][2] =  8723; // 2213 minus plus sign
	glyphs[2][3] =  8721; // 2211 summation
	glyphs[2][4] =  8730; // 221a square root
	glyphs[2][5] =  8731; // 221b cube root

	glyphs[2][6] =  8733; // 221d prortional
	glyphs[2][7] =  8734; // 221e infinity
	glyphs[2][8] =  8747; // 222b integral
	glyphs[2][9] =  8748; // 222c double integral
	glyphs[2][10] =  8749; // 222d triple integral
	glyphs[2][11] =  8750; // 222e contour integral

	glyphs[2][12] =  8751; // 222f surface integral
	glyphs[2][13] =  8752; // 2230 volume integral
	glyphs[2][14] =  8771; // 2243 approx
	glyphs[2][15] =  8800; // 2260 not equal
	glyphs[2][16] =  8801; // 2261 indentity
	glyphs[2][17] =  8804; // 2264 L.E.

	glyphs[2][18] =  8805; // 2265 G.E.
	glyphs[2][19] =  8901; // 22c5 dot operator
	glyphs[2][20] =  8706; // 2202 partial diff
	glyphs[2][21] =  8711; // 2207 nabla
	glyphs[2][22] =  8719; // 220f n-Nary product
	glyphs[2][23] =  8721; // 2211 summation.
	glyphs[2][24] =  8804; // 2264 L.E.



	glyphs[3][0] =  2981; // 304 comb macron.
	glyphs[3][1] =  27E8; // 305 comb overline
	glyphs[3][2] =  27E9; // 2202 partial diff
	glyphs[3][3] =  2207; // 2207 nabla
	glyphs[3][4] =  0305; // 220f n-Nary product
	glyphs[3][5] =  0303; // 2211 summation.
	glyphs[3][6] =  0302; // 2264 L.E.
	
}
void Math::Eq_Edit::init_DirectWrite(HWND hWnd){

	handle = hWnd;

	hdc = GetDC(hWnd); 
	GetTextMetrics(hdc, &tm); 
	ReleaseDC(hWnd, hdc);

	charCount = 0;

	fontSize = 28.0f;
	level[7] = fontSize/2.0f;
	level[6] = 0.0f; 
	level[5] = -fontSize/2.0f; 
	lineEnd = pageMargin;
	insertionPoint = pageMargin;
	indexLeft = -1;

	CreateCaret(hWnd, NULL, 0, fontSize);

	loadGlyphs();

	HRESULT hr = D2D1CreateFactory( D2D1_FACTORY_TYPE_SINGLE_THREADED, &pD2DFactory_ );
	
	UINT DpI(0);
	float dpiScaleX_;
	float dpiScaleY_;

	if (SUCCEEDED(hr)){
		pD2DFactory_->GetDesktopDpi(&dpiScaleX_, &dpiScaleY_);	
		DpI = GetDpiForWindow(hWnd);
		dpiScaleX_ = 96/dpiScaleX_;
		dpiScaleY_ = 96/dpiScaleY_;
	}

	if (SUCCEEDED(hr)){
		hr = DWriteCreateFactory( DWRITE_FACTORY_TYPE_SHARED,
				__uuidof(IDWriteFactory),
				reinterpret_cast<IUnknown**>(&pDWriteFactory_) );
	}



	if (SUCCEEDED(hr)){ 
		hr = pDWriteFactory_->CreateTextFormat( 
			// L"Arial",
			//L"Cambria Math",
			L"Cambria Math",
			NULL, 
			DWRITE_FONT_WEIGHT_SEMI_LIGHT,
		//	DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			fontSize,// font size
			L"en-us",
			&pMathFormat_);

		pMathFormat_->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_JUSTIFIED);
		pMathFormat_->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
		pMathFormat_->SetIncrementalTabStop(50.0f);
	}

}
//struct DWRITE_TEXT_METRICS

    /// Left-most point of formatted text relative to layout box
    /// (excluding any glyph overhang).
//    FLOAT left;
    /// Top-most point of formatted text relative to layout box
    /// (excluding any glyph overhang).
 //   FLOAT top;
    /// The width of the formatted text ignoring trailing whitespace
    /// at the end of each line.
//    FLOAT width;
    /// The width of the formatted text taking into account the
    /// trailing whitespace at the end of each line.
//    FLOAT widthIncludingTrailingWhitespace;
    /// The height of the formatted text. The height of an empty string
    /// is determined by the size of the default font's line height.
//    FLOAT height;
    /// Initial width given to the layout. Depending on whether the text
    /// was wrapped or not, it can be either larger or smaller than the
    /// text content width.
 //   FLOAT layoutWidth;
    /// Initial height given to the layout. Depending on the length of the
    /// text, it may be larger or smaller than the text content height.
 //   FLOAT layoutHeight;
    /// The maximum reordering count of any line of text, used
    /// to calculate the most number of hit-testing boxes needed.
    /// If the layout has no bidirectional text or no text at all,
    /// the minimum level is 1.
//    UINT32 maxBidiReorderingDepth;
    /// Total number of lines.
//    UINT32 lineCount;

// Partition the glyphRect which is
//
// 0.5f*clientWidth  - pageMargin - middleMargin 
// x 0.5f*clientHeight - page margin -middle margin
// Into 10 rows and 25 columns to display upto 250 glyphs
//

void Math::Eq_Edit::displayGlyphs(){

	D2D1_POINT_2F glyphOrigin {0.0f};

	for( int row = 0; row < 10; row++ ){
		for( int col = 0; col < 25; col++){
			glyphOrigin.x = pageMargin + cellWidth*static_cast<float>(col);
			glyphOrigin.y = pageMargin + cellHeight*static_cast<float>(row);

			pDWriteFactory_->CreateTextLayout(
				&glyphs[row][col],
				1,			
				pMathFormat_,
				static_cast<float>(glyphRect.right), // width of layout box
				static_cast<float>(glyphRect.bottom), // width of layout box
				&pMathLayout_ );
			pRT_->DrawTextLayout( glyphOrigin, pMathLayout_, pMathBrush_ );
		}
	}

}


void Math::Eq_Edit::getGlyphMerics(){
 
   SafeRelease(&pMathLayout_);
   pDWriteFactory_->CreateTextLayout(
      &glyph,
      1,			
      pMathFormat_,
      10.0f, // width of layout box
      10.0f,  // height of layout box
      &pMathLayout_ );

   DWRITE_TEXT_METRICS metrics;
   pMathLayout_->GetMetrics( &metrics);
   glyphWidth = metrics.width;
}

void Math::Eq_Edit::draw_Eq(){

	D2D1_POINT_2F origin {0.0f};
	D2D1_RECT_F paperRect{};
	D2D1_SIZE_F rtSize{};

	if (SUCCEEDED(CreateDeviceResources()))
	{
		HRESULT hr = S_OK;
		pRT_->BeginDraw(); 

		rtSize = pRT_->GetSize();
		paperRect.right = rtSize.width; paperRect.bottom = rtSize.height;

		pRT_->FillRectangle(&paperRect, pPaperBrush_);
		SafeRelease(&pMathLayout_);

		displayGlyphs();

		HideCaret(handle); 
		SafeRelease(&pMathLayout_);

		origin.x = pageMargin;
		for( int i = 0; i < charCount; i++ ){		
			origin.y = static_cast<float>( currentLevel.top);
			origin.x = S[i].x - S[i].w;
			pDWriteFactory_->CreateTextLayout(
				&S[i].s,
				1,			
				pMathFormat_,
				450.0f, // width of layout box
				100.0f,  // height of layout box
				&pMathLayout_ );
			// Handle the space bar
			pRT_->DrawTextLayout( origin , pMathLayout_, pMathBrush_ );

		}
		SetCaretPos(insertionPoint, currentLevel.top ); 
		ShowCaret(handle);


// Diagnostics paperRect.bottom
DWRITE_TEXT_METRICS metrics;
float glyphWidth;
		SafeRelease(&pMathLayout_);
		std::wstring diagnostic{};
		std::wstring f_number{};
		f_number.clear();
		f_number = L"equationRect.bottom =  ";
		f_number.append( std::to_wstring( equationRect.bottom ));
		f_number.append( L"   groundLevel = ");
		f_number.append( std::to_wstring( groundLevel ));
		float f_debug{};

			origin.x = 0.0f;
			origin.y = static_cast<float>(equationRect.bottom) - 35.0f;
			diagnostic = L"Hello";
			pDWriteFactory_->CreateTextLayout(
				(PWSTR)f_number.c_str(),
				(UINT32)lstrlen((PWSTR)f_number.c_str()),			
				pMathFormat_,
				paperRect.right, // width of layout box
				100.0f,  // height of layout box
				&pMathLayout_ );



			pRT_->DrawTextLayout( origin , pMathLayout_, pMathBrush_ );


		if (D2DERR_RECREATE_TARGET == pRT_->EndDraw()) DiscardDeviceResources();
	} //End if (SUCCEEDED( CreateDeviceResources())
	return;
}

HRESULT Math::Eq_Edit::CreateDeviceResources(){
    HRESULT hr = S_OK;
	if(!pRT_){

		RECT rc;
		GetClientRect(handle, &rc);
		D2D1_SIZE_U Usize = D2D1::SizeU((rc.right - rc.left ),
										(rc.bottom - rc.top ));
		hr = pD2DFactory_->CreateHwndRenderTarget( 
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties( handle, Usize ), &pRT_ );

		pRT_->CreateSolidColorBrush(D2D1::ColorF(0xF4B480),  &pMathBrush_ );
//		pRT_->CreateSolidColorBrush(D2D1::ColorF(0x2F4F4F),  &pPaperBrush_ );
		pRT_->CreateSolidColorBrush(D2D1::ColorF(0x000000),  &pPaperBrush_ );

		

	}

	if( FAILED( hr )) return hr;

    return S_OK;
}


void Math::Eq_Edit::DiscardDeviceResources(){
	
	SafeRelease(&pPaperBrush_);
    SafeRelease(&pMathBrush_);
  	SafeRelease(&pMathLayout_);
    SafeRelease(&pRT_);

}

void Math::Eq_Edit::keyDown( WPARAM wParam){

    switch (wParam) 
    { 
        case VK_LEFT:   // LEFT ARROW 

			if( indexLeft  <= 0 ){
				insertionPoint = pageMargin;
				indexLeft = -1;
				MessageBeep((UINT) -1);
				}


			else insertionPoint = S[--indexLeft].x;

			HideCaret(handle);
			SetCaretPos( insertionPoint, currentLevel.top);
			ShowCaret(handle);
 
            // The caret can move only to the beginning of 
            // the current line. 
 
            //if (nCaretPosX > 0) 
            //{ 
            //    HideCaret(hwndMain); 
 
            //    // Retrieve the character to the left of 
            //    // the caret, calculate the character's 
            //    // width, then subtract the width from the 
            //    // current horizontal position of the caret 
            //    // to obtain the new position. 
 
            //    ch = pchInputBuf[--nCurChar]; 
            //    hdc = GetDC(hwndMain); 
            //    GetCharWidth32(hdc, ch, ch, &nCharWidth); 
            //    ReleaseDC(hwndMain, hdc); 
            //    nCaretPosX = max(nCaretPosX - nCharWidth, 
            //        0); 
            //    ShowCaret(hwndMain); 
            //} 
            break; 
 
        case VK_RIGHT:  // RIGHT ARROW 

			if( indexLeft == charCount -1 ){
				MessageBeep((UINT) -1 );
				break;}


			insertionPoint = S[++indexLeft].x;
			HideCaret(handle);
			SetCaretPos( insertionPoint, currentLevel.top);
			ShowCaret(handle);

 
            // Caret moves to the right or, when a carriage 
            // return is encountered, to the beginning of 
            // the next line. 
 
            //if (nCurChar < cch) 
            //{ 
            //    HideCaret(hwndMain); 
 
            //    // Retrieve the character to the right of 
            //    // the caret. If it's a carriage return, 
            //    // position the caret at the beginning of 
            //    // the next line. 
 
            //    ch = pchInputBuf[nCurChar]; 
            //    if (ch == 0x0D) 
            //    { 
            //        nCaretPosX = 0; 
            //        nCaretPosY++; 
            //    } 
 
            //    // If the character isn't a carriage 
            //    // return, check to see whether the SHIFT 
            //    // key is down. If it is, invert the text 
            //    // colors and output the character. 
 
            //    else 
            //    { 
            //        hdc = GetDC(hwndMain); 
            //        nVirtKey = GetKeyState(VK_SHIFT); 
            //        if (nVirtKey & SHIFTED) 
            //        { 
            //            crPrevText = SetTextColor(hdc, 
            //                RGB(255, 255, 255)); 
            //            crPrevBk = SetBkColor(hdc, 
            //                RGB(0,0,0)); 
            //            TextOut(hdc, nCaretPosX, 
            //                nCaretPosY * dwCharY, 
            //                &ch, 1); 
            //            SetTextColor(hdc, crPrevText); 
            //            SetBkColor(hdc, crPrevBk); 
            //        } 
 
            //        // Get the width of the character and 
            //        // calculate the new horizontal 
            //        // position of the caret. 
 
            //        GetCharWidth32(hdc, ch, ch, &nCharWidth); 
            //        ReleaseDC(hwndMain, hdc); 
            //        nCaretPosX = nCaretPosX + nCharWidth; 
            //    } 
            //    nCurChar++; 
            //    ShowCaret(hwndMain); 
//                break; 
 //           } 
            break; 
 
        case VK_UP:     // UP ARROW 
			break;
        case VK_DOWN:   // DOWN ARROW 
            //MessageBeep((UINT) -1); 
            //return 0; 
			break;
        case VK_HOME:   // HOME 


			indexLeft = -1;
			insertionPoint = pageMargin;
			HideCaret(handle);
			SetCaretPos( insertionPoint, currentLevel.top);
			ShowCaret(handle);
 
            // Set the caret's position to the upper left 
            // corner of the client area. 
 
            //nCaretPosX = nCaretPosY = 0; 
            //nCurChar = 0; 
            break; 
 
        case VK_END:    // END 

			if( indexLeft ==  -1 ){
				MessageBeep((UINT) -1 );
				break;}

			indexLeft = charCount-1;
			insertionPoint = S[indexLeft].x;
			HideCaret(handle);
			SetCaretPos( insertionPoint, currentLevel.top);
			ShowCaret(handle);
			break;
 
            // Move the caret to the end of the text. 
 
            //for (i=0; i < cch; i++) 
            //{ 
            //    // Count the carriage returns and save the 
            //    // index of the last one. 
 
            //    if (pchInputBuf[i] == 0x0D) 
            //    { 
            //        cCR++; 
            //        nCRIndex = i + 1; 
            //    } 
            //} 
            //nCaretPosY = cCR; 
 
            //// Copy all text between the last carriage 
            //// return and the end of the keyboard input 
            //// buffer to a temporary buffer. 
 
            //for (i = nCRIndex, j = 0; i < cch; i++, j++) 
            //    szBuf[j] = pchInputBuf[i]; 
            //szBuf[j] = TEXT('\0'); 
 
            //// Retrieve the text extent and use it 
            //// to set the horizontal position of the 
            //// caret. 
 
            //hdc = GetDC(hwndMain);
            //hResult = StringCchLength(szBuf, 128, pcch);
            //if (FAILED(hResult))
            //{
            //// TODO: write error handler
            //} 
            //GetTextExtentPoint32(hdc, szBuf, *pcch, 
            //    &sz); 
            //nCaretPosX = sz.cx; 
            //ReleaseDC(hwndMain, hdc); 
            //nCurChar = cch; 
             
 
		default: 
            break; 
    } 
            //SetCaretPos(nCaretPosX, nCaretPosY * dwCharY); 
}

void Math::Eq_Edit::wmChar(WPARAM wParam){
	switch (wParam) 
    { 
		case 0x08:  // backspace
			if( charCount == 0 || indexLeft == -1 ) MessageBeep((UINT) -1);
			else{
				deleteGlyph();
			    InvalidateRect(handle, NULL, FALSE);
			}
			break;

		case 0x0A:  // linefeed 
			break;
		case 0x1B:  // escape 
			MessageBeep((UINT) -1); 
			//return; 
		case 0x09:  // tab 
			// Convert tabs to four consecutive spaces. 
			//for (i = 0; i < 4; i++) 
			//	SendMessage(hwndMain, WM_CHAR, 0x20, 0); 
			//return 0; 
			break;
		case 0x0D:  // carriage return 
 
            // Record the carriage return and position the 
            // caret at the beginning of the new line.

            //pchInputBuf[cch++] = 0x0D; 
            //nCaretPosX = 0; 
            //nCaretPosY += 1; 
            break;

// displayable character 
        default:   
			
			setEqStringMetrics( (WCHAR)wParam );
			InvalidateRect(handle, NULL, FALSE);
			break; 
    } 
}

void  Math::Eq_Edit::lButtonUp( WPARAM wParam, LPARAM lParam ){
	int mouse_up_X = GET_X_LPARAM(lParam); 
	int mouse_up_Y = GET_Y_LPARAM(lParam);
// Is Mouse in equation level?
	if(( mouse_up_X > pageMargin  &&    mouse_up_X  <  equationRect.right ) &&
			( mouse_up_Y > currentLevel.top && mouse_up_Y < currentLevel.top + fontSize )){

		float X = static_cast<float>(mouse_up_X);
	//	insertionPoint = lineEnd;

	//  Handle the first glyph AS A SPECIAL CASE
		if( X < S[0].x ){
			if( X > pageMargin + S[0].w/2.0f){
				insertionPoint = S[0].x;
				indexLeft = 0;}
			else{
				insertionPoint = pageMargin;
				indexLeft = -1;}
		}


		else if( X > S[charCount - 1].x ){
			insertionPoint = S[charCount - 1].x;
			indexLeft = charCount - 1;
		}
		

		else{
			for( int i = 1; i < charCount; i++ ){
				float space = (S[ i ].x - S[i-1].x)/2.0f;
				if( X >= S[i-1].x  &&  X <= S[i-1].x  + space ){
					insertionPoint = S[i-1].x;
					indexLeft = i-1;
					break;
				}
				else if( X >= S[i-1].x + space && X <= S[i].x ){
					insertionPoint = S[i].x;
					indexLeft = i;
					break;
				}
			}
		}

//	insertionPoint = static_cast<float>( mouseX );
	HideCaret(handle);
	SetCaretPos( insertionPoint, currentLevel.top);
	ShowCaret(handle);
	return;
	}

	InvalidateRect(handle, NULL, FALSE);	

}

void  Math::Eq_Edit::lButtonDown( WPARAM wParam, LPARAM lParam ){
	int mouseX = GET_X_LPARAM(lParam); 
	int mouseY = GET_Y_LPARAM(lParam);

// Mouse in glyphBox

 	if(( mouseX > pageMargin && mouseY > pageMargin ) &&
	  (  mouseX < glyphBox.right && mouseY < glyphBox.bottom )){
		int row{}; int col{};
		row = ( mouseY - pageMargin )/cellHeight;
		col = ( mouseX - pageMargin )/cellWidth;
		if(glyphs[row][col]){
			glyph = glyphs[row][col];
			setEqStringMetrics( glyph );
		}
	}

// Mouse in modelBox	
	else if (( mouseX > modelRect.left &&  mouseY > pageMargin ) &&
	       (   mouseX < modelRect.right && mouseY < modelRect.bottom )){
		int modelX = mouseX;
	}

// Is Mouse in equation level?
	else if(( mouseX > pageMargin  &&     mouseX  <  equationRect.right ) &&
			( mouseY > currentLevel.top && mouseY < currentLevel.top + fontSize )){

		HideCaret(handle);
		float X = static_cast<float>(mouseX);
	//	insertionPoint = lineEnd;

	//  Handle the first glyph AS A SPECIAL CASE
		if( X < S[0].x ){
			if( X > pageMargin + S[0].w/2.0f){
				insertionPoint = S[0].x;
		//		nCurChar = 1;
				indexLeft = 0;}
			else{
				insertionPoint = pageMargin;
		//		nCurChar = 0;
				indexLeft = -1;}
		}


		else if( X > S[charCount - 1].x ){
			insertionPoint = S[charCount - 1].x;
			indexLeft = charCount - 1;
		}
		

		else{
			for( int i = 1; i < charCount; i++ ){
				float space = (S[ i ].x - S[i-1].x)/2.0f;
				if( X >= S[i-1].x  &&  X <= S[i-1].x  + space ){
					insertionPoint = S[i-1].x;
			//		nCurChar = i;
					indexLeft = i-1;
					break;
				}
				else if( X >= S[i-1].x + space && X <= S[i].x ){
					insertionPoint = S[i].x;
			//		nCurChar = i+1;
					indexLeft = i;
					break;
				}
			}
		}

//	insertionPoint = static_cast<float>( mouseX );
	// HideCaret(handle);
	SetCaretPos( insertionPoint, currentLevel.top);
	ShowCaret(handle);
	return;
	}

	InvalidateRect(handle, NULL, FALSE);	
}

void Math::Eq_Edit::wmSize( int w, int h){

	HideCaret(handle);

	if (pRT_){		
		if(FAILED( pRT_->Resize(D2D1::SizeU(w, h)))){
			DiscardDeviceResources();
		//	log(L"FAILED( pRT_->Resize");
			return; 
		}
	}

    ::GetClientRect( handle, &clientRect );
	 
	// these are all ints or long ints
    clientWidth = clientRect.right - clientRect.left;
	clientHeight = clientRect.bottom - clientRect.top;

	glyphRect.left = 0;	glyphRect.right = 0.5f*clientWidth;
	glyphRect.top  = 0;	glyphRect.bottom = 0.5f*clientHeight;

	glyphBox.left = glyphBox.top = pageMargin; 
	glyphBox.right = 0.5f*clientWidth -  middleMargin;
	glyphBox.bottom  = glyphRect.bottom;

	cellWidth = (glyphBox.right- glyphBox.left )/25.0f;
	cellHeight = 1.5f*cellWidth;

	modelRect.left = glyphRect.right;	modelRect.right = clientWidth;
	modelRect.top  = glyphRect.bottom;	modelRect.bottom = glyphRect.bottom;

	equationRect.left = 0;	equationRect.right = clientWidth;
	equationRect.top  = modelRect.bottom;	equationRect.bottom = clientHeight;

	groundLevel = 0.55*clientHeight;

	currentLevel.top = groundLevel;
	insertionPoint = lineEnd;
	SetCaretPos( insertionPoint, currentLevel.top); 
	ShowCaret(handle); 
}
void Math::Eq_Edit::wmSetFocus(){
	CreateCaret(handle, NULL, 0, fontSize); 
	SetCaretPos(insertionPoint, currentLevel.top); 
	ShowCaret(handle); 
}

void  Math::Eq_Edit::deleteGlyph(){

	glyph = S[indexLeft].s;

 	if( glyph == 32 ) glyphWidth = 0.5f*fontSize;
	    
	else getGlyphMerics();

	//   A|   Handle this case
	if( charCount == 1 ){
		charCount = 0;
		indexLeft = -1;
		insertionPoint = pageMargin;
		S.resize(0);
		return;
	}

	--charCount;

	for( int i = indexLeft; i < charCount;  i++){
		S[i].s = S[i+1].s;
		S[i].w = S[i+1].w;
		S[i].x = S[i+1].x - glyphWidth;
    }

	--indexLeft; 
    S.resize(charCount);

	if( indexLeft == -1 ) insertionPoint = pageMargin;
	else insertionPoint -= glyphWidth;
}

void Math::Eq_Edit::setEqStringMetrics(WCHAR newGlyph){

	glyph = newGlyph;

 	if( glyph == 32 ){
		glyphWidth = 0.5f*fontSize;
	}
    
	else getGlyphMerics();
	
	//if( S[i].s == 32 ){
	//	S[i].width = 0.5f*fontSize;
	//}
 //


// ? IP at the end line 
   if( indexLeft == charCount - 1 ){ 
 //  if( indexLeft == charCount - 1 || charCount == 0 ){ 
       ++charCount;                        
       S.resize(charCount);       
       S[charCount-1].s = glyph;            
       S[charCount-1].w = glyphWidth;       
       insertionPoint += glyphWidth;                    
       S[charCount-1].x = insertionPoint;		    
       ++indexLeft;                                
       return; 
   } 

// Ip is "in" the line
   // dont increment gCount until out of loop

   S.resize(charCount + 1); 
   for( int i = charCount; i > indexLeft + 1 ; i--){
       S[i].s = S[i-1].s;
       S[i].w = S[i-1].w;
       S[i].x = S[i-1].x + glyphWidth;
   }

  ++indexLeft;; ++charCount; 

  // Put that new glyph in the run
   S[indexLeft].s = glyph;          
   S[indexLeft].w = glyphWidth;
   if( indexLeft == 0 ){
	   S[indexLeft].x = pageMargin + glyphWidth;
//	   insertionPoint = pageMargin;
	   insertionPoint = S[indexLeft].x;

   }

   else{
		insertionPoint += glyphWidth;	   
		S[indexLeft].x = S[indexLeft-1].x + glyphWidth;
   }  
}    


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_SIZE:
	//	Win::log("in winProc rcvd WM_SIZE");
	//  Windows will send this when we resize, max or min the window.
	//	ViewDW will send this when changing the graphics mode or the OGL routine.
	//  The graphics mode will be in wParam GL_MODE = 40007, DW_MODE = 40012
    //  returnValue = ctrl->size(LOWORD(lParam), HIWORD(lParam), GL_WIN);
								// x			y                mode
		editor.wmSize(LOWORD(lParam), HIWORD(lParam));   
        break;

	case WM_KEYDOWN:
	{
		editor.keyDown( wParam);
		break;
	}
	case WM_CHAR:
	{


		editor.wmChar( wParam);
		break;
	}
	case WM_SETFOCUS: 
	{
		// Create, position, and display the caret when the 
        // window receives the keyboard focus. 

		editor.wmSetFocus();
			//CreateCaret(hWnd, (HBITMAP) 1, 0, 20); 
			//SetCaretPos(lineEnd, 0); 
			//ShowCaret(hWnd); 
        break; 
	}
	case WM_KILLFOCUS: 
	{ 
		// Hide and destroy the caret when the window loses the 
        // keyboard focus. 
 
        HideCaret(hWnd); 
        DestroyCaret(); 
        break; 
	}
	case WM_LBUTTONDOWN:

		editor.lButtonDown( wParam, lParam);
    break;

	case WM_LBUTTONUP:

		editor.lButtonUp( wParam, lParam);
    break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			editor.draw_Eq();
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
		HideCaret(hWnd); 
        DestroyCaret(); 

        PostQuitMessage(0);
		editor.DiscardDeviceResources();
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
