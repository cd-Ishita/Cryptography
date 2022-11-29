#include<stdio.h>

int extended_gcd(int a, int b, int* x, int* y){
	if(a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1;
	int gcd = extended_gcd(b%a, a, &x1, &y1);

	*x = y1 - (b/a) * x1;
	*y = x1;

	return gcd;
}

int main(){
	printf("Enter the two numbers: ");
	int a, b;
	scanf("%d %d", &a, &b);
	
	int x, y;
	int res = extended_gcd(a, b, &x, &y);
	printf("The gcd of the two numbers: %d\n", res);
}
