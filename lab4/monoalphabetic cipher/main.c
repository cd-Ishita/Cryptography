#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void plainToCipher(char str[], char key[]){
	char res[1000];
	int i=0;
	while(str[i] != '\0'){
		res[i] = key[(int)str[i]-97];
		i++;
	}

	printf("The Plain Text given was : %s\n", str);
	printf("The Cipher Text generated is : %s\n", res);
}

void cipherToPlain(char str[], char key[]){
	char res[1000];
	int i=0;
	while(str[i] != '\0'){
		for(int j=0;j<26;j++){
			if(key[j] == str[i]){
				res[i] = (char)(j+97);
				break;
			}
		}
		i++;
	}

	printf("The Cipher Text given was : %s \n", str);
	printf("The Plain Text generated is : %s \n", res);
}

int main(){
	// generating the key
	char alphabet[26];
	char key[26];
	srand(time(0));

	bool visited[26];
	int temp;

	for(int i=0;i<26;i++) visited[i] = false;
	for(int i=0;i<26;i++){
		alphabet[i] = (char)(i+97);
		temp = rand()%26;
		while(visited[temp]){
			temp = rand()%26;
		}	
		visited[temp] = true;
		key[i] = (char)(temp+97);
	}

	printf("The key generated is: \n");
	for(int i=0;i<26;i++){
		printf("%c -> %c\n", alphabet[i], key[i]);
	}

	printf("Enter 0 for plaintext -> ciphertext \nEnter 1 for ciphertext -> plaintext\n");
	int ans;
	scanf("%d", &ans);
	
	if(ans == 1){
		char str[1000];
		printf("Enter the ciphertext: ");
		scanf("%s", str);
		
		cipherToPlain(str, key);
	}
	else{
		
		char str[1000];
		printf("Enter the plaintext: ");
		scanf("%s", str);
		
		plainToCipher(str, key);
	}
} 
