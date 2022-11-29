#include<stdio.h>
#include<gmp.h>
#include<stdbool.h>
#include<stdlib.h>
void calculate(mpz_t number[], mpz_t rem[], mpz_t ans, int k){
	mpz_t x;
	mpz_init(x);
	mpz_set_d(x, 1);
	
	mpz_t modAns;
	mpz_init(modAns);

	while(true){
		int j;
		for(j=0;j<k;j++){		
			mpz_mod(modAns, x, number[j]);
			if(mpz_cmp(modAns, rem[j]) != 0){
				break;
			}

		}
		
		if(j == k){
			mpz_set(ans, x);
			return;
		}
		mpz_add_ui(x, x, 1);
	}	
}

int main(){
	printf("Enter the number of elements: ");
	int size;	
	scanf("%d", &size);

	mpz_t number[size], rem[size];
	//mpz_t *number, *rem;
	//number = (mpz_t*)malloc(size+1);	
	//rem = (mpz_t*)malloc(size+1);
	
	for(int i = 0;i < size; i++){
		mpz_init(number[i]);
		printf("Enter the number: ");
		gmp_scanf("%Zd", number[i]);

		mpz_init(rem[i]);
		printf("Enter the remainder: ");
		gmp_scanf("%Zd", rem[i]);
	}	


	mpz_t res;
	mpz_init(res);
	calculate(number, rem, res, size);
	gmp_printf("The number is : %Zd\n", res);
}
