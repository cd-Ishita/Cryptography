#include<stdio.h>
#include<gmp.h>
#include<stdbool.h>
bool millerTest(mpz_t n, mpz_t d, gmp_randstate_t state){
	mpz_t rand;
	mpz_init(rand);	

	mpz_t m;
	mpz_init(m);
	mpz_sub_ui(m, n, 2);

	mpz_urandomm(rand, state, m);
	mpz_t x;
	mpz_init(x);
	mpz_powm(x, rand, d, n);
	

	mpz_add_ui(m, m, 1);
	//mpz_mod(x, x, n);
	if(mpz_cmp_ui(x, 1) == 0 || mpz_cmp(x, m) == 0) return true;
	
	while(mpz_cmp(d, m) != 0){
		mpz_mul(x, x, x);
		mpz_mod(x, x, n);
		mpz_mul_ui(d, d, 2);
		if(mpz_cmp(x, m) == 0) return true;
		if(mpz_cmp_d(x, 1) == 0) return false;
	}
	return false;
		
}

bool isPrime(mpz_t n, mpz_t k, gmp_randstate_t state){
	if(mpz_cmp_d(n,1) == 0 || mpz_cmp_d(n,1) == 0 || mpz_cmp_d(n,1) == 0){
		return true;
	}
	
	if(mpz_divisible_ui_p(n,2) == 0) return false;

	mpz_t temp;
	mpz_t exp;
	mpz_t m;	
	mpz_inits(temp, exp, m, NULL);
	mpz_set_d(exp, 2);
	mpz_sub_ui(m, n, 1);
	
	while(true){
		if(mpz_divisible_p(m, exp) == 0) mpz_mul_ui(exp, exp, 2);
		else{
			mpz_cdiv_q(temp, m, exp);
			if(mpz_divisible_ui_p(temp, 2) == 0) mpz_mul_ui(exp, exp, 2);
			else break;
		}
	}

	mpz_t it;
	mpz_init(it);
	mpz_set_d(it, 0);
	while(mpz_cmp(it, k) != 0){
		if(millerTest(m, temp, state) == false) return false;
	}

	return true;
}

int main(){
	
	gmp_randstate_t state;
	gmp_randinit_default(state);
	mpz_t seed;
	mpz_init(seed);
	mpz_set_d(seed, 16);
	gmp_randseed(state, seed);

	printf("Enter the number to be checked: ");
	mpz_t n;
	gmp_scanf("%Zd", n);

	printf("Enter the number of iterations: ");
	mpz_t k;
	gmp_scanf("%Zd", k);
	if(isPrime(n, k, state) == true){
		printf("The number is prime");
	}
	else{
		printf("The number is not prime");
	}
}

