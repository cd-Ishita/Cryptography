#include<stdio.h>
int main(){
	int size;
	printf("Size of array: ");
	scanf("%d", &size);
	
	char message[size+1];
	printf("Enter the message: ");
	scanf("%s", message);
	

	int even_bits = 0;	
	for(int i=size-1;i>=0;i--){
		if(message[i] == '1'){
			even_bits++;
		}
		message[i+1] = message[i];
	}

	if(even_bits%2 == 0){
		message[0] = '0';
	}
	else{
		message[0] = '1';
	}

	printf("Coded message: %s\n", message);
}
