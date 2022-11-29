#include<stdio.h>

int main(){
	printf("Enter the number: ");
	int a;
	scanf("%d", &a);
	
	printf("The multiplicative inverse are: \n");
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			/*if(i*j < a) {
				 if((i*j + a)%a == 1){
					printf("%d and %d\n", i, j);
					break;
				}
			}*/
			if((i*j)%a == 1) {
				printf("%d and %d\n", i, j); 
				break;
			}
		}
	}

}
