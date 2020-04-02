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

int main(int argc, char* argv[])
{
	_wsetlocale(LC_ALL, L"Russian");
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DWORD level = 2;
	LPCWSTR servername = NULL;
	wchar_t username[21];
	NET_API_STATUS nStatus;
	LPUSER_INFO_2 pBuf = NULL;

	_getws_s(username, 20);

	nStatus = NetUserGetInfo(servername, (wchar_t*)username, level, (LPBYTE*)&pBuf);

	if (nStatus == NERR_Success)
	{
		wprintf(L"User account name: %s\n", pBuf->usri2_name);
		wprintf(L"Password: %s\n", pBuf->usri2_password);
		wprintf(L"Password age (seconds): %d\n", pBuf->usri2_password_age);
		if (pBuf->usri2_priv == USER_PRIV_ADMIN)
			printf("Privilege level: Administrator\n");
		else if (pBuf->usri2_priv == USER_PRIV_USER)
			printf("Privilege level: User\n");
		else if (pBuf->usri2_priv == USER_PRIV_GUEST)
			printf("Privilege level: Guest\n");
		wprintf(L"Last logon (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_last_logon);
		wprintf(L"Last logoff (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_last_logoff);
		if (pBuf->usri2_acct_expires == TIMEQ_FOREVER)
			printf("Account expires(seconds since January 1, 1970 GMT): Never\n");
		else wprintf(L"Account expires (seconds since January 1, 1970 GMT): %d\n", pBuf->usri2_acct_expires);
		wprintf(L"Max storage: %d\n", pBuf->usri2_max_storage);
		wprintf(L"Bad password count: %d\n", pBuf->usri2_bad_pw_count);
		wprintf(L"Number of logons: %d\n", pBuf->usri2_num_logons);
		wprintf(L"Logon server: %s\n", pBuf->usri2_logon_server);
		wprintf(L"Country code: %d\n", pBuf->usri2_country_code);
		wprintf(L"Code page: %d\n", pBuf->usri2_code_page);
	}
	else if (nStatus == NERR_UserNotFound)
		printf("User can't be found\n");
	else if (nStatus == ERROR_ACCESS_DENIED)
		printf("The user does not have access to the requested information.");
	else if (nStatus == ERROR_INVALID_LEVEL)
		printf("The value specified for the level parameter is invalid.");
	else if (nStatus == NERR_InvalidComputer)
		printf("The computer name is invalid.");

	system("pause");
	return 0;
}