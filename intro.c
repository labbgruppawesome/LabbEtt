
/* Laboration 1
* DVA315 - Mälardalens Högskola
* Erika Weilander EWR15002
* Linus Sens Ingels LIS16001
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

void printHelloWorld();
void printHelloMoon();

int main()
{

	printHelloWorld();
	printHelloMoon();

	system("pause");

}



void printHelloWorld()
{
	int i;
	for (i = 0; i<10; i++) {
		printf("Hello World\n");
		Sleep(600);
	}
}

void printHelloMoon()
{
	for (int i = 0; i < 10000000; i++) {
		printf("Hello Moon\n");
		Sleep(120);
	}
}