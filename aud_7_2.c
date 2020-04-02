#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h> 
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	DWORD level = 2;
	LPCWSTR servername = NULL;
	LPCWSTR username;
	NET_API_STATUS nStatus;
	LPUSER_INFO_2 pBuf = NULL;

	//username = gets();
	
	nStatus = NetUserGetInfo(servername, (wchar_t*)L"Алексей", level, (LPBYTE*)&pBuf);

	if (nStatus == NERR_Success)
	{
		wprintf(L"User account name: %s\n", pBuf->usri2_name);
		wprintf(L"Password: %s\n", pBuf->usri2_password);
		wprintf(L"Password age (seconds): %d\n",
			pBuf->usri2_password_age);
		if (pBuf->usri2_priv == USER_PRIV_ADMIN)
			printf("Privilege level: Administrator\n");
		else if(pBuf->usri2_priv == USER_PRIV_USER)
			printf("Privilege level: User\n");
		else if (pBuf->usri2_priv == USER_PRIV_GUEST)
			printf("Privilege level: Guest\n");
		wprintf(L"Home directory: %s\n", pBuf->usri2_home_dir);
		wprintf(L"User comment: %s\n", pBuf->usri2_comment);
		wprintf(L"Flags (in hex): %x\n", pBuf->usri2_flags);
		wprintf(L"Script path: %s\n", pBuf->usri2_script_path);
	}
	else if (nStatus == NERR_UserNotFound)
		printf("User can't be found\n");

	system("pause");
	return 0;
}