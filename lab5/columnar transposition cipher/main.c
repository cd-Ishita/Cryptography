#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	printf("Enter the cipher keyword: ");
	char cipherKey[1000];
	scanf("%[^\n]%*c", cipherKey);
	
	printf("Enter the plaintext: ");
	char plainText[1000];
	scanf("%[^\n]%*c", plainText);

	int size = strlen(cipherKey);
	int size1 = strlen(plainText);
	char temp[size1+1][size];
	
	printf("%d and %d", size, size1);

	int j = 0, i=0, k=0;
	while(plainText[k] != '\0'){
		temp[i][j] = plainText[k];
		j++;
		k++;
		if(j == size){
			j = 0;
			i++;
		}
	}
	
	char res[100]
	int positions[size];
	for(int i=0;i<size;i++){
		int count = (int)cipherKey[i];
		for(int j=0;j<i;j++){
						
}
