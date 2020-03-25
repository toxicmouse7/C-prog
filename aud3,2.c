#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <assert.h>
#include <windows.h> 
#include <lm.h>
#include <LMaccess.h>
#include <locale.h>

int main()
{
    LPUSER_INFO_1 pBuf = NULL;
    LPUSER_INFO_1 pTmpBuf;
    DWORD dwLevel = 1;
    DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
    DWORD dwEntriesRead = 0;
    DWORD dwTotalEntries = 0;
    DWORD dwResumeHandle = 0;
    DWORD i;
    DWORD dwTotalCount = 0;
    NET_API_STATUS nStatus;
    LPTSTR pszServerName = NULL;

    setlocale(0, "Russian");
	
    printf("Local users: \n");
    do
    {
        nStatus = NetUserEnum((LPCWSTR)pszServerName,
            dwLevel,
            FILTER_NORMAL_ACCOUNT,
            (LPBYTE*)&pBuf,
            dwPrefMaxLen,
            &dwEntriesRead,
            &dwTotalEntries,
            &dwResumeHandle);
        //
        // Если вызов выполнен успешно
        //
        if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA))
        {
            if ((pTmpBuf = pBuf) != NULL)
            {
                //
                // Цикл по записям.
                //
                for (i = 0; (i < dwEntriesRead); i++)
                {
                    assert(pTmpBuf != NULL);

                    if (pTmpBuf == NULL)
                    {
                        fprintf(stderr, "An access violation has occurred\n");
                        break;
                    }
                    //
                    //  Вывод имени пользователя, если администратор.
                    //
                    if (pTmpBuf->usri1_priv == USER_PRIV_USER)                    
                        wprintf(L"\t-- %s\n", pTmpBuf->usri1_name);

                    pTmpBuf++;
                    dwTotalCount++;
                }
            }
        }
        //
        // Иначе, вывод системной ошибки.
        //
        else
            fprintf(stderr, "A system error has occurred: %d\n", nStatus);
        //
        // Очищение буффера.
        //
        if (pBuf != NULL)
        {
            NetApiBufferFree(pBuf);
            pBuf = NULL;
        }
    } while (nStatus == ERROR_MORE_DATA);

    printf("\nTotal count of entries: %d\n", dwTotalCount);

    if (pBuf != NULL)
        NetApiBufferFree(pBuf);
}