#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void plainToCipher(char str[], char key[5][5], int visited[]){
	printf("The Plain Text given was : %s\n", str);
	char res[1000];

	int i=0;
	while(str[i] != '\0' && str[i+1] != '\0'){
		if(str[i] == str[i+1]) str[i+1] = 'z';		
		if(visited[(int)str[i]-97] / 5 == visited[(int)str[i+1]-97] / 5){
			res[i] = key[visited[(int)str[i]-97]/5][(visited[(int)str[i]-97]%5 + 1)%5];
			res[i+1] = key[visited[(int)str[i+1]-97]/5][(visited[(int)str[i+1]-97]%5 + 1)%5];

		}
		else if(visited[(int)str[i]-97]%5 == visited[(int)str[i+1]-97]%5){
			res[i] = key[(visited[(int)str[i]-97]/5 + 1)%5][visited[(int)str[i]-97]%5];
			res[i+1] = key[(visited[(int)str[i+1]-97]/5 + 1)%5][visited[(int)str[i+1]-97]%5];
		}
		else{
			res[i] = key[visited[(int)str[i]-97]/5][visited[(int)str[i+1]-97]%5];
			res[i+1] = key[visited[(int)str[i+1]-97]/5][visited[(int)str[i]-97]%5];
		}
		i = i + 2;
	}
	
	if(str[i] != '\0'){
		str[i+1] = 'z';
		if(visited[(int)str[i]-97] / 5 == visited[(int)str[i+1]-97] / 5){
			res[i] = key[visited[(int)str[i]-97]/5][(visited[(int)str[i]-97]%5 + 1)%5];
			res[i+1] = key[visited[(int)str[i+1]-97]/5][(visited[(int)str[i+1]-97]%5 + 1)%5];

		}
		else if(visited[(int)str[i]-97]%5 == visited[(int)str[i+1]-97]%5){
			res[i] = key[(visited[(int)str[i]-97]/5 + 1)%5][visited[(int)str[i]-97]%5];
			res[i+1] = key[(visited[(int)str[i+1]-97]/5 + 1)%5][visited[(int)str[i+1]-97]%5];
		}
		else{
			res[i] = key[visited[(int)str[i]-97]/5][visited[(int)str[i+1]-97]%5];
			res[i+1] = key[visited[(int)str[i+1]-97]/5][visited[(int)str[i]-97]%5];
		}
	}

	printf("The Cipher Text generated is : %s\n", res);
		
		
}

int main(){

	// generating the key square

	char key[5][5];
	printf("Enter the Playfair cipher key : ");
	char cipherKey[1000];
	scanf("%[^\n]%*c", cipherKey);
	
	int visited[26];

	for(int i=0;i<26;i++) visited[i] = 0;
	int i=0;
	int row = 0, col = 0;
	while(cipherKey[i] != '\0'){
		if(cipherKey[i] != ' ' && cipherKey[i] != 'j' && visited[(int)cipherKey[i] - 97] == 0){
			key[row][col] = cipherKey[i];
			if(col == 4){
				row++;
				col = 0;
			}
			else col++;
		
			visited[(int)cipherKey[i] - 97] = 1;
		}
		i++;
	}

	for(int i=0;i<26;i++){
		if(i != 9 && visited[i] == 0){
			key[row][col] = (char)(i+97);
			if(col == 4){
				row++;
				col = 0;
			}
			else col++;
		}
	}

	printf("The playfair matrix generated is : \n");
	for(int i=0;i<5;i++){
		printf("| ");
		for(int j=0;j<5;j++){
			printf("%c | ", key[i][j]);
			visited[(int)key[i][j]-97] = 5*i+j;
		}
		printf("\n");
	}


	printf("Enter 0 for plaintext -> ciphertext \nEnter 1 for ciphertext -> plaintext\n");
	int ans;
	scanf("%d", &ans);
	
	if(ans == 1){
		char str[1000];
		printf("Enter the ciphertext: ");
		scanf("%s", str);
		
		//cipherToPlain(str, key, visited);
	}
	else{
		
		char str[1000];
		printf("Enter the plaintext: ");
		scanf("%s", str);
		
		plainToCipher(str, key, visited);
	}
}
