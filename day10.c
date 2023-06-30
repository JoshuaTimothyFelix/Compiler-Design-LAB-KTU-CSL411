#include <stdio.h>
#include <string.h>

char exprsn[20];
char temp_var = 'Z';

void main(){
	printf("Enter the expression: ");
	scanf("%s", exprsn);
	printf("Intermediate code:\n");
	while (strlen(exprsn) > 3){
		printf("%s\n", exprsn);
		int flag = 0;
		if (flag != 1)
		for (int i = 0; i < strlen(exprsn); i++)
			if (exprsn[i] == '/' || exprsn[i] == '*'){
				printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);
				exprsn[i - 1] = temp_var;
				temp_var--;
				for (int j = i; exprsn[j] != '\0'; j++)
					exprsn[j] = exprsn[j + 2];
				flag = 1;
				break;
				}
		if (flag != 1)
			for (int i = 0; i < strlen(exprsn); i++)
				if (exprsn[i] == '+' || exprsn[i] == '-'){
					printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);
					exprsn[i - 1] = temp_var;
					temp_var--;
					for (int j = i; exprsn[j] != '\0'; j++)
						exprsn[j] = exprsn[j + 2];
					flag = 1;
					break;
					}
		}
	printf("%s\n", exprsn);
	}
