#include <stdio.h>
#include <windows.h>
#include <string.h>

#include "wrapper.h"

int main()
{

	helloWorld();
	system("pause");

	return 0;
}

void helloWorld()
{
	printf("Hello World\n");
}