#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

void writeInput();

HANDLE hRead;
HANDLE hWrite;
LPTSTR SlotName = TEXT("\\\\.\\mailslot\\MailSlot");

int main()
{
	hRead = mailslotCreate(SlotName);
	hWrite = mailslotConnect(SlotName);
	char endmsg[3] = "END";
	char *userInputStr = malloc(100);
	
	threadCreate(writeInput, NULL);
	
	while (TRUE)
	{
		mailslotRead(hRead, userInputStr, 100);
		printf(userInputStr);
	}
	printf("Hej Minkan");
	
	system("pause > nul");
	return 0;
}

void writeInput()
{
	char *userInput = malloc(100);
	while (TRUE)
	{
		fgets(userInput, 100, stdin);
		mailslotWrite(hWrite, userInput, 100);
	}
}


