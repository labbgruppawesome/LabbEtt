#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "wrapper.h"

void print_hello();
void hello_moon();
int main()
{
	print_hello();

	return 0;
}

void print_hello()
{
	for (int i = 0; i < 10; i++)
	{
		printf("Hello world \n");
		Sleep(600);
	}
}

void hello_moon()
{
	printf("Hello Moon \n");
	Sleep(120);

}