#include<stdio.h>
#include<gmp.h>
#include<stdbool.h>
void calculate(mpz_t number[], mpz_t rem[], mpz_t ans, mpz_t k){
	mpz_t x;
	mpz_init(x);
	mpz_set_d(x, 1);
	
	mpz_t modAns;
	mpz_init(modAns);

	while(1){
		mpz_t j;
		mpz_init(j);
		mpz_set_d(j, 0);
		while(mpz_cmp(j,k) != 0){
			mpz_mod(modAns, x, number[j]);
			if(mpz_cmp(modAns, rem[j]) != 0){
				break;
			}

		}
		
		if(mpz_cmp(j, k) == 0){
			mpz_set(ans, x);
			return;
		}
		mpz_add_d(x, x, 1);
	}	
}

int main(){
	printf("Enter the number of elements: ");
	mpz_t size, it;
	mpz_init(size);
	mpz_init(it);	
	gmp_scanf("%Zd", size);

	mpz_t number[size];
	mpz_t rem[size];
	mpz_set_d(it, 0);
	while(mpz_cmp(it, size) != 0){
		mpz_init(number[it]);
		printf("Enter the number: ");
		gmp_scanf("%Zd", number[it]);

		mpz_init(rem[it]);
		printf("Enter the remainder: ");
		gmp_scanf("%Zd", rem[it]);
		mpz_add_d(it, it, 1);
	}	


	mpz_t res;
	mpz_init(res);
	calculate(number, rem, res, size);
	gmp_printf("The gcd of the two numbers: %Zd\n", res);
}
