#include<stdio.h>

void plainToCipher(char str[], int shift){
	char res[1000];
	int i=0;
	while(str[i] != '\0'){
		if(str[i] == ' '){
			i++;
			continue;
		}
		res[i] = (char)(((int)str[i] - 97 + shift)%26 + 97);
		i++;
	}
	
	printf("The Plain Text given was : %s\n", str);
	printf("The Cipher Text generated is : %s\n", res);
}

void cipherToPlain(char str[], int shift){
	char res[1000];
	int i=0;
	while(str[i] != '\0'){
		if(str[i] == ' '){
			i++;
			continue;
		}		
		int temp = (int)str[i] - 97 - shift;
		if(temp < 26) temp = temp + 26;
		res[i] = (char)(temp%26 + 97);
		i++;
	}
	
	printf("The Cipher Text given was : %s\n", str);
	printf("The Plain Text generated is : %s\n", res);
}

int main(){

	printf("Enter the shift: ");
	int shift;
	scanf("%d", &shift);
	
	printf("Enter 1 for plaintext -> ciphertext \nEnter 0 for ciphertext -> plaintext\n");
	int ans;
	scanf("%d", &ans);
	
	if(ans == 0){
		char str[1000];
		printf("Enter the ciphertext: ");
		scanf("%s", str);
		
		cipherToPlain(str, shift);
	}
	else{
		
		char str[1000];
		printf("Enter the plaintext: ");
		scanf("%s", str);
		
		plainToCipher(str, shift);
	}
}
