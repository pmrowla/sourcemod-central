#include "InstallerMain.h"
#include "Welcome.h"
#include "ChooseMethod.h"

INT_PTR CALLBACK WelcomeHandler(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		{
			return (INT_PTR)TRUE;
		}
	case WM_COMMAND:
		{
			if (LOWORD(wParam) == ID_WELCOME_EXIT
				|| LOWORD(wParam) == ID_CLOSE)
			{
				EndDialog(hDlg, NULL);
				return (INT_PTR)TRUE;
			}
			else if (LOWORD(wParam) == ID_WELCOME_NEXT)
			{
				EndDialog(hDlg, (INT_PTR)DisplayChooseMethod);
				return (INT_PTR)TRUE;
			}
			break;
		}
	}

	return (INT_PTR)FALSE;
}

void *DisplayWelcome(HWND hWnd)
{
	INT_PTR val;
	
	if ((val = DialogBox(
		g_hInstance, 
		MAKEINTRESOURCE(IDD_WELCOME),
		hWnd,
		WelcomeHandler)) == -1)
	{
		return NULL;
	}

	return (void *)val;
}
