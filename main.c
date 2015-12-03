#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"

int main(int argc, char **argv)
{
	char *inputline;
	List *list;
	list = CreateList();

	inputline = (char *)malloc(CHAR_ARRAY_SIZE);
	do{
		fgets(inputline, CHAR_ARRAY_SIZE, stdin);
		StringToLower(inputline);
		inputline = strtok(inputline, "\n");
		CallSubFunctions(list,inputline);
		//printf("%s", inputline);
	} while (strcmp(inputline, "exit"));
	
	return 0;
}