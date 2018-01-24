#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

void print_hello();
void hello_moon();

int main()
{
	threadCreate(print_hello, NULL);

	system("pause > nul");
	return 0;
}

void print_hello()
{
	for (int i = 0; i < 10; i++)
	{
		printf("Hello world \n");
		Sleep(120);
		
	}
	threadCreate(hello_moon, NULL);

}

void hello_moon()
{
	for (int i = 0; i < 10; i++)
	{
		printf("Hello Moon \n");
		Sleep(120);

	}

	threadCreate(print_hello, NULL);

}