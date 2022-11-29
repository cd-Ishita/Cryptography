#include<stdio.h>
int main(){
	char str[100];
	
	printf("Enter the input string: ");
	scanf("%[^\n]%*c", str);

	int characters[26];
	for(int i=0;i<26;i++){
		characters[i] = 0;
	}

	int i=0;
	while(str[i] != '\0'){
		characters[(int)str[i]-97]++;
		i++;
	}


	char res[100];
	i = 0;
	int index = 0;
	for(int i=0;i<26;i++){
		for(int j=0;j<characters[i];j++){
			res[index] = (char)(i+97);
			index++;
		}
	}

	printf("Lexicographically sorted string: %s\n", res);
}
