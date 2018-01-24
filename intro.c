#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

HANDLE hSlot;
LPTSTR SlotName = TEXT("\\\\.\\mailslot\\MailSlot");

int main()
{
	char userInputStr[100];
	char msgRecieved[] = "Received";
	char systemEnd[] = "END";

	printf("Type your message here: \n");
	fgets(&userInputStr, 100, stdin);

	hSlot = mailslotCreate(SlotName);
	printf("Hej Linkan");
	mailslotWrite(hSlot, userInputStr, 100);
	printf("Hej Skinkan");
	mailslotRead(hSlot, userInputStr, 100);
	printf("Hej Minkan");



	system("pause > nul");
	return 0;
}
