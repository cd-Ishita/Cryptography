#include<stdio.h>
int main(){
	char str[100];
	char res[100];

	printf("Enter the input string: ");
	scanf("%[^\n]%*c", str);
	
	int i = 0, index = 0;
	while(str[i] != '\0'){
		if(((int)str[i] >= 97 && (int)str[i] <= 122) || ((int)str[i] >= 65 && (int)str[i] <= 90)){
			res[index] = str[i];
			index++;			
		}
		i++;
	}
	
	printf("Result: %s\n", res);
  
}
