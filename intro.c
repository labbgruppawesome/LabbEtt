#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

void writeInput();

typedef struct {
	char userInputStr[100];
}something;


HANDLE hRead;
HANDLE hWrite;
CRITICAL_SECTION critical;
LPTSTR SlotName = TEXT("\\\\.\\mailslot\\MailSlot");

int main()
{
	hRead = mailslotCreate(SlotName);
	hWrite = mailslotConnect(SlotName);
	char endmsg[5] = "END\n";
	something *input = malloc(100);
	if (!InitializeCriticalSectionAndSpinCount(&critical, INFINITE))
		return -1;

	threadCreate(writeInput, NULL);

	while (TRUE)
	{
		mailslotRead(hRead, input->userInputStr, 100);
		printf("Following message was recieved: %s",input->userInputStr);

		if ((strcmp(endmsg, input->userInputStr)) == 0)
		{
			break;
		}
			
	}
	printf(".. Process ending");
	system("pause > nul");

	mailslotClose(hRead);
	mailslotClose(hWrite);
	DeleteCriticalSection(&critical);
	return 0;
}

void writeInput()
{
	char endmsg[5] = "END\n";
	something *userInput = malloc(100);
	
	while (TRUE)
	{
		EnterCriticalSection(&critical);
		fgets(userInput->userInputStr, 100, stdin);
		mailslotWrite(hWrite, userInput->userInputStr, 100);
		LeaveCriticalSection(&critical);
		
		if ((strcmp(endmsg, userInput->userInputStr)) == 0)
		{
			break;
		}
	}
	
}


