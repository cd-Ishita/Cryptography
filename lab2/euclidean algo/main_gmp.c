#include<stdio.h>
#include<gmp.h>

void gcd(mpz_t a, mpz_t b, mpz_t res){
	
	if(mpz_cmp_d(b, 0) == 0){
		mpz_set(res, a);
		return;
	}
	
	mpz_t rem;
	mpz_init(rem);
	mpz_mod(rem, a, b);

	gcd(b, rem, res);
}

int main(){
	printf("Enter the two numbers: ");
	mpz_t a, b;
	mpz_init(a);
	mpz_init(b);

	gmp_scanf("%Zd %Zd", a, b);
	//gmp_printf("Number is : %Zd and %Zd\n", a, b);
	
	mpz_t res;
	mpz_init(res);
	gcd(a, b, res);
	gmp_printf("The gcd of the two numbers: %Zd\n", res);
}
