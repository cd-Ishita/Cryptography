#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
bool millerTest(int n, int d){
	int random = (rand()%(n-2-2+1)) + 2;
	double x = pow(random, d);
	x = x%(double)n;
	if(x == 1 || x == n-1) return true;

	while(d != n-1){
		x = (x*x)%n;
		d = d*2;
		if(x == 1) return false;
		if(x == n-1) return true;
	}

	return false;
}
bool isPrime(int n, int k){
	if(n <= 3){
		return true;
	}

	if(n%2 == 0) return false;
	
	int temp;
	int exp = 2;
	while(true){
		temp = (n-1)/exp;
		if((n-1)%(exp) != 0){
			exp = exp*2;
		}
		else{
			if(temp%2 == 0){
				exp = exp*2;
			}
			else{
				break;
			}
		}
	}

	for(int i=0;i<k;i++){
		if(millerTest(n, temp) == false)
			return false;
	}
	return true; 
}
int main(){
	srand(time(0));
	printf("Enter the number to be checked: ");
	int n;
	scanf("%d", &n);
	isPrime(n, 4);
}
