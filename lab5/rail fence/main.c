#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

	printf("Enter the plaintext: ");
	char plainText[1000];
	scanf("%[^\n]%*c", plainText);

	printf("Enter the number of rails: ");
	int rails = 3;
	//scanf("%d", &rails);

	char res[1000];
	int count = 0;
	int k = 0;
	for(int i=0;i<rails;i++){
		int jumps = (rails - i - 1)*2;
		for(int j=count;j<strlen(plainText);j = j + jumps){
			res[k] = plainText[j];
			k++;
		}
		count++;
	}

	printf("The cipher text is: %s", res);
//(number of rails - i - 1)*2 -1
//(4-0-1)*2 - 1 = 5
//(4-1-1)*2 - 1 = 3


//g     o     s
// e   f r   k
//  e s   g e
//   k     e
	
}
