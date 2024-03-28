#include <windows.h> 
#include <tchar.h> 
#include <cmath>
#include <xstring>
#include "resource.h"
#define _USE_MATH_DEFINES
typedef std::basic_string<TCHAR, std::char_traits<TCHAR>,
	std::allocator<TCHAR> > String;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
int APIENTRY _tWinMain(HINSTANCE This, // Дескриптор текущего приложения 
	HINSTANCE Prev,         // В современных системах всегда 0 
	LPTSTR cmd,           // Командная строка 
	int mode)           // Режим отображения окна 
{
	HWND hWnd;    // Дескриптор главного окна программы 
	MSG msg;    // Структура для хранения сообщения 
	WNDCLASS wc;  // Класс окна 
				  // Определение класса окна   
	wc.hInstance = This;
	wc.lpszClassName = WinName;      // Имя класса окна 
	wc.lpfnWndProc = WndProc;        // Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW;    // Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // Стандартный курсор 
	wc.lpszMenuName = NULL;  // Нет меню 
	wc.cbClsExtra = 0;    // Нет дополнительных данных класса 
	wc.cbWndExtra = 0;    // Нет дополнительных данных окна 
						  // Заполнение окна белым цветом 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClass(&wc)) return 0;  // Регистрация класса окна  
										// Создание окна 
	hWnd = CreateWindow(WinName,  // Имя класса окна 
		_T("Лабораторная № 2 WinAPI"),  // Заголовок окна 
		WS_OVERLAPPEDWINDOW,    // Стиль окна 
		CW_USEDEFAULT,  // x 
		CW_USEDEFAULT,  // y  Размеры окна 
		CW_USEDEFAULT,  // Width
		CW_USEDEFAULT,  // Height 
		HWND_DESKTOP, // Дескриптор родительского окна 
		NULL,    // Нет меню 
		This,    // Дескриптор приложения 
		NULL);   // Дополнительной информации нет 
	ShowWindow(hWnd, mode); //Показать окно 
							// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); // Посылает сообщение функции WndProc() 
	}
	return 0;
}


void DrawLineOutline(HWND hwnd, POINT ptBeg, POINT ptEnd)
{
	HDC hdc; 
	hdc = GetDC(hwnd); 
	SetROP2(hdc, R2_NOT); 
	SelectObject(hdc, GetStockObject(NULL_BRUSH)); 
	MoveToEx(hdc, ptBeg.x, ptBeg.y, NULL);
	LineTo(hdc, ptEnd.x, ptEnd.y); 
	ReleaseDC(hwnd, hdc); 
}

void DrawBox(HWND hwnd, POINT ptBeg, POINT ptEnd,bool fBlocking, bool fValidBox)
{
	HDC hdc;
	hdc = GetDC(hwnd);
	HPEN pen = CreatePen(rand() % 5, rand() % 9 + 1, RGB(rand() % 255, rand() % 255, rand() % 255));
	SelectObject(hdc, pen);
	HBRUSH brush = CreateHatchBrush(rand() % 6, RGB(rand() % 255, rand() % 255, rand() % 255));
	SelectObject(hdc, brush);
	if (fValidBox)
	{
		Rectangle(hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y);
	}

	if (fBlocking)
	{
		Rectangle(hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y);
	}
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	srand(11);
	static HMENU hMenu;
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	HWND Dia;
	static HWND hbutton1, hbutton2, hbutton3, hwndedit1, hwndedit2, hwndedit3, hbutton4;
	static BOOL  fBlocking, fValidBox;
	static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd, pt[6],oldb,olde,ptm,oldptm;
	static bool  f1 = false, f2 = false, f3 = false, f4 = false, fBlock = false,fp=false;
	static int A = 100, B = 140, l, R = 40;
	wchar_t  *str;
	switch (iMsg)
	{

	case WM_CREATE:
		hMenu = CreateMenu();
		AppendMenu(hMenu, MF_STRING | MF_POPUP, 1000, _T("Файл"));
		AppendMenu(hMenu, MF_STRING, 1001, _T("Операции"));
		SetMenu(hwnd, hMenu);

		hbutton2 = CreateWindow(_T("button"), _T("Рисование прямоугольника"), WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, (HMENU)2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hbutton1 = CreateWindow(_T("button"), _T("Выввод текста"), WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hbutton3 = CreateWindow(_T("button"), _T("Рисование фигуры"), WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, (HMENU)5, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hbutton4 = CreateWindow(_T("button"), _T("Немодальное окно"), WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, (HMENU)7, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hwndedit1 = CreateWindow(_T("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)3, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hwndedit2 = CreateWindow(_T("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)4, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hwndedit3 = CreateWindow(_T("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 0, 0, 0, 0, hwnd, (HMENU)6, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		return 0;

	case WM_SIZE:

		MoveWindow(hbutton1, LOWORD(lParam) - 180, 75, 160, 22, TRUE);
		MoveWindow(hbutton2, LOWORD(lParam) - 200, 185, 200, 22, TRUE);
		MoveWindow(hbutton3, LOWORD(lParam) - 190, 210, 180, 22, TRUE);
		MoveWindow(hbutton4, LOWORD(lParam) - 190, 235, 180, 22, TRUE);
		MoveWindow(hwndedit1, LOWORD(lParam) - 115, 120, 30, 22, TRUE);
		MoveWindow(hwndedit2, LOWORD(lParam) - 115, 140, 30, 22, TRUE);
		MoveWindow(hwndedit3, LOWORD(lParam) - 115, 160, 30, 22, TRUE);
		return 0;

	case WM_COMMAND:
		if (LOWORD(wParam) == 1000 || LOWORD(wParam) == 1001)
		{
			MessageBox(hwnd, _T("Выбран пункт меню"), _T(""), NULL);
		}
		if (LOWORD(wParam) == 1)
		{
			f1 = true;
			f3 = false;
			f2 = false;
			InvalidateRect(hwnd, NULL, TRUE); 
		}
		if (LOWORD(wParam) == 2)
		{
			f3 = true;
			f1 = false;
			f2 = false;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (LOWORD(wParam) == 5)
		{
			f2 = true;
			f3 = false;
			f1 = false;
			l = GetWindowTextLength(hwndedit1);
			str = new wchar_t[l + 1];
			GetWindowText(hwndedit1, str, l + 1);
			A = _wtoi(str);
			l = GetWindowTextLength(hwndedit2);
			str = new wchar_t[l + 1];
			GetWindowText(hwndedit2, str, l + 1);
			B = _wtoi(str);
			l = GetWindowTextLength(hwndedit3);
			str = new wchar_t[l + 1];
			GetWindowText(hwndedit3, str, l + 1);
			R = _wtoi(str);
			if (A == 0)
				A = 100;
			if (B == 0)
				B = 140;
			if (R == 0)
				R = 40;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		if (LOWORD(wParam) == 7)
		{
			Dia = CreateDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(DLG_1), hwnd, DlgProc);
			ShowWindow(Dia, SW_SHOW);
		}
		return 0;
	case WM_LBUTTONDOWN:
		if (f3)
		{
			oldb.x = ptBoxBeg.x;
			oldb.y = ptBoxBeg.y;
			olde.x = ptBoxEnd.x;
			olde.y = ptBoxEnd.y;
			ptBeg.x = ptEnd.x = LOWORD(lParam);
			ptBeg.y = ptEnd.y = HIWORD(lParam);
			if (fp)
			{
				if (oldb.x > olde.x)
				{
					if (oldb.y < olde.y)
					{ 
						if ((ptBeg.x <= oldb.x) && (ptBeg.x >= olde.x) && (ptBeg.y >= oldb.y) && (ptBeg.y <= olde.y))
						{
							SetCursor(LoadCursor(NULL, IDC_SIZEALL));
							fBlock = TRUE;
							return 0;
						}
					}
					else
					{ 
						if ((ptBeg.x <= oldb.x) && (ptBeg.x >= olde.x) && (ptBeg.y <= oldb.y) && (ptBeg.y >= olde.y))
						{
							SetCursor(LoadCursor(NULL, IDC_SIZEALL));
							fBlock = TRUE;
							return 0;
						}
					}
				}
				else
				{
					if (oldb.y < olde.y)
					{
						if ((ptBeg.x >= oldb.x) && (ptBeg.x <= olde.x) && (ptBeg.y >= oldb.y) && (ptBeg.y <= olde.y))
						{
							SetCursor(LoadCursor(NULL, IDC_SIZEALL));
							fBlock = TRUE;
							return 0;
						}
					}
					else
					{
						if ((ptBeg.x >= oldb.x) && (ptBeg.x <= olde.x) && (ptBeg.y <= oldb.y) && (ptBeg.y >= olde.y))
						{
							SetCursor(LoadCursor(NULL, IDC_SIZEALL));
							fBlock = TRUE;
							return 0;
						}
					}
				}
			}
			DrawLineOutline(hwnd, ptBeg, ptEnd); 
			SetCapture(hwnd); 
			SetCursor(LoadCursor(NULL, IDC_CROSS));
			fBlocking = TRUE; 
		}
		else
		{
				MessageBox(NULL, _T("Выберите действие"), _T(""), MB_ICONERROR | MB_OK);
		}
		return 0;
	case WM_RBUTTONDOWN:
	{
		hdc = GetDC(hwnd);
		HFONT font = CreateFont(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("Arial"));
		SelectObject(hdc, font);
		SetTextColor(hdc, RGB(0, 47, 31));
		TextOut(hdc, 20, 180, _T("Была нажата правая кнопка мыши"), 32);
		ReleaseCapture();
		DeleteObject(font);
	}
	case WM_MOUSEMOVE:
		if (f3)
		{
			if (fBlock)
			{
				hdc = GetDC(hwnd);
				DrawBox(hwnd, ptBoxBeg, ptBoxEnd, fBlocking, fValidBox);
				SetCursor(LoadCursor(NULL, IDC_SIZEALL));
				GetClientRect(hwnd, &rect);
				ptm.x = LOWORD(lParam); 
				ptm.y = HIWORD(lParam);
				ptBoxBeg.x += ptm.x - ptBeg.x;
				ptBoxEnd.x += ptm.x - ptBeg.x;
				ptBoxBeg.y += ptm.y - ptBeg.y;
				ptBoxEnd.y += ptm.y - ptBeg.y;
				ptBeg.x = ptm.x;
				ptBeg.y = ptm.y;
				Rectangle(hdc, rect.left, rect.top, rect.right - 200, rect.bottom);
				SetCursor(LoadCursor(NULL, IDC_ARROW));
				ReleaseCapture();
				DrawBox(hwnd, ptBoxBeg, ptBoxEnd, fBlocking, fValidBox);
				return 0;
			}
			if (fBlocking)
			{
				SetCursor(LoadCursor(NULL, IDC_CROSS));
				DrawLineOutline(hwnd, ptBeg, ptEnd); 
				ptEnd.x = LOWORD(lParam); 
				ptEnd.y = HIWORD(lParam); 
				DrawLineOutline(hwnd, ptBeg, ptEnd); 
			}
		}
		return 0;

	case WM_LBUTTONUP:
		if (f3)
		{
			if (fBlock)
			{
				DrawBox(hwnd, ptBoxBeg, ptBoxEnd, fBlocking, fValidBox);
				fBlock = FALSE;
				SetCursor(LoadCursor(NULL, IDC_ARROW));
				return 0;
			}
			if (fBlocking)
			{
				hdc = GetDC(hwnd);
				DrawLineOutline(hwnd, ptBeg, ptEnd);
				ptBoxBeg = ptBeg;
				ptBoxEnd.x = LOWORD(lParam); 
				ptBoxEnd.y = HIWORD(lParam); 
				ReleaseCapture();
				SetCursor(LoadCursor(NULL, IDC_ARROW));
				fBlocking = FALSE;
				fValidBox = TRUE; 
				InvalidateRect(hwnd, NULL, TRUE);
				f4 = true;
			}
		}
		return 0;

	case WM_CHAR:
		if (f3)
		{
			if (fBlocking & wParam == '\x1B')
			{
				DrawLineOutline(hwnd, ptBeg, ptEnd);
				ReleaseCapture();
				SetCursor(LoadCursor(NULL, IDC_ARROW));
				fBlocking = FALSE;
			}
		}
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		SetTextColor(hdc, RGB(34, 134, 184));
		TextOut(hdc, rect.right - 170, 100, _T("Параметры фигуры"), 18);
		TextOut(hdc, rect.right - 130, 120, _T("A:"), 4);
		TextOut(hdc, rect.right - 130, 140, _T("B:"), 4);
		TextOut(hdc, rect.right - 130, 160, _T("R:"), 4);
		Rectangle(hdc, rect.left, rect.top, rect.right - 200, rect.bottom);
		if (f1)
		{
			HFONT font = CreateFont(28, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, _T("Arial"));
			SelectObject(hdc, font);
			SetTextColor(hdc, RGB(0, 47, 31));
			TextOut(hdc, 20, 180, _T("Крючков Василий Игоревич"), 26);
			DeleteObject(font);
		}
		if (f2)
		{
			HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
			SelectObject(hdc, pen);
			HBRUSH brush = CreateHatchBrush(HS_VERTICAL, RGB(0, 0, 255));
			SelectObject(hdc, brush);
			Ellipse(hdc, 380 - R, 220 + R, 380 + R, 220 - R);
			brush = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 0, 255));
			SelectObject(hdc, brush);
			pt[0].x = 380 +R;
			pt[0].y = 220 +A/2;
			pt[1].x = 380 + R;
			pt[1].y = 220 - A / 2;
			pt[2].x = 380 + R + B/2;
			pt[2].y = 220 - A;
			pt[3].x = 380 + R + B;
			pt[3].y = 220 - A / 2;
			pt[4].x = 380 + R + B;
			pt[4].y = 220 + A / 2;
			pt[5].x = 380 + R;
			pt[5].y = 220 + A / 2;
			Polygon(hdc, pt, 6);
		}
		if (f4)
		{ 
			DrawBox(hwnd, ptBoxBeg, ptBoxEnd,fBlocking,fValidBox);
			fp = true;
			f4 = false;
		}
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY: PostQuitMessage(0); break;
	default: return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
	return 0;
}
INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC, hCompatibleDC;
	PAINTSTRUCT PaintStruct;
	static HANDLE hBitmap, hOldBitmap;
	RECT Rect;
	static BITMAP Bitmap;
	switch (uMsg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &PaintStruct);
		hBitmap = LoadImage(NULL, _T("picture.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
		hCompatibleDC = CreateCompatibleDC(hDC);
		hOldBitmap = SelectObject(hCompatibleDC, hBitmap);
		GetClientRect(hwnd, &Rect);
		StretchBlt(hDC, 0, 0, Rect.right, Rect.bottom, hCompatibleDC, 0, 0, Bitmap.bmWidth,
			Bitmap.bmHeight, SRCCOPY);
		SelectObject(hCompatibleDC, hOldBitmap);
		DeleteObject(hBitmap);
		DeleteDC(hCompatibleDC);
		EndPaint(hwnd, &PaintStruct);
		return TRUE;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case CLOSS:
			DestroyWindow(hwnd);
			return TRUE;
		}
	case WM_DESTROY: 
		UpdateWindow(hwnd);
		return TRUE;
	}
	return FALSE;
}