#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

char production[10][10];
int count;
char input[10];
char stack[10];
int stack_top=0;
char start_symbol[2];

int can_reduce(){
	if (strlen(stack)==0)
		return -1;
	for(int i=stack_top;i>=0;i--)
		for(int j=0;j<count;j++)
			if(!strcmp(stack+i,production[j]+2))
				return j;
	return -1;
	}

int main(){
	printf("Enter no. of productions: ");
	scanf("%d", &count);
	for (int i = 0; i < count; i++){
		printf("Enter production %d: ", i);
		scanf("%s", production[i]);
		}
	start_symbol[0]=production[0][0];
	start_symbol[1]='\0';
	printf("Enter input string :");
	scanf("%s",input);
	int itr=0;
	printf("Start symbol is : %s", start_symbol);
	for(int i=0;i<=strlen(input);itr++){
		printf("Iteration : %d \n",itr);
		printf("Stack : %s \n",stack);
		printf("Input : %s \n",input+i);
		int reduce_prod=0;
		if((!strcmp(stack,start_symbol))&& i==strlen(input)){
			printf("\nString is accepted.");
			exit(0);
			}
		reduce_prod=can_reduce();
		if(reduce_prod>=0){
			printf("Operation : Reduce\n");
			stack_top-=strlen(production[reduce_prod]+2);
			stack[stack_top++]=production[reduce_prod][0];
			stack[stack_top]='\0';
			}
		else{
			printf("Operation : Shift\n");
			stack[stack_top++]=input[i];
			stack[stack_top]='\0';
			i++;
			}
		}
		printf("\nString rejected\n");
	}
