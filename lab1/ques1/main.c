#include<stdio.h>
int main(){
	int characters[26];
	char str[100];
	printf("Enter the input string:");
	scanf("%[^\n]%*c", str);

	for(int i=0;i<26;i++){
		characters[i] = 0;
	}

	int size = sizeof(str)/sizeof(char);
	printf("Size: %d", size);
	int i=0;	
	while(i<100 && str[i] != '\0'){
		characters[(int)str[i] - 97]++;
		i++;
	}


	printf("Result for string %s\n", str);
	for(int i=0;i<26;i++){
		printf("Character: %c ------ Frequency: %d\n", (char)(i+97), characters[i]);
	}
}
