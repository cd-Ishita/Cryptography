#include<stdio.h>
#include<gmp.h>
void extended_gcd(mpz_t a, mpz_t b, mpz_t x, mpz_t y, mpz_t res){
	if(mpz_cmp_d(a,0) == 0) {
		mpz_set_d(x, 0);
		mpz_set_d(y, 1);
		mpz_set(res, b);
		return;
	}

	mpz_t x1, y1, gcd;
	mpz_init(x1);
	mpz_init(y1);
	mpz_init(gcd);
	
	mpz_t rem;
	mpz_init(rem);
	mpz_mod(rem, b, a);

	extended_gcd(rem, a, x1, y1, gcd);

	mpz_cdiv_q(x, b, a);
	mpz_mul(x, x, x1);
	mpz_sub(x, y1, x); 
	//*x = y1 - (b/a) * x1;
	mpz_set(y, x1);	
	//*y = x1;
	
	mpz_set(res, gcd);
	return;
}

int main(){
	printf("Enter the two numbers: ");
	mpz_t a, b;
	mpz_init(a);
	mpz_init(b);	
	gmp_scanf("%Zd %Zd", a, b);
	
	mpz_t x, y, res;
	mpz_init(x);
	mpz_init(y);
	mpz_init(res);
	extended_gcd(a, b, x, y, res);
	gmp_printf("The gcd of the two numbers: %Zd\n", res);
}
