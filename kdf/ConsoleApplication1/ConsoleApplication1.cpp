#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>


int main(void)
{
	// записываемая строка
	char message[] = "Hello METANIT.COM!";
	// находим длину записываемой строки
	int n = sizeof(message) / sizeof(message[0]);
	FILE* fp = fopen("data.txt", "w");
	if (fp)
	{
		// посимвольно записываем в файл
		for (int i = 0; i < n; i++)
		{
			putc(message[i], fp);
		}

		fclose(fp);
		printf("File has been written\n");
	}
}
