#include<stdio.h>
int main(){

	char str[100];
	printf("Enter the input: ");
	scanf("%[^\n]%*c",str);

	int size = 0;
	while(str[size] != '\0'){
		size++;
	}

	int i=0, j=size-1;
	while(i<j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++; j--;
	}

	printf("The reversed string is: %s\n", str); 
}
