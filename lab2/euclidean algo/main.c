#include<stdio.h>

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	printf("Enter the two numbers: ");
	int a, b;
	scanf("%d %d", &a, &b);
	
	int res = gcd(a, b);
	printf("The gcd of the two numbers: %d\n", res);
}
