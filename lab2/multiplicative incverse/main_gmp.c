#include<stdio.h>
#include<gmp.h>

int main(){
	printf("Enter the number: ");
	mpz_t n;
	mpz_init(n);
	gmp_scanf("%Zd", n);

	printf("The multiplicative inverse are: \n");
	mpz_t it;
	mpz_init(it);

	mpz_t res;
	mpz_init(res);

	mpz_set_d(it, 1);
	while(mpz_cmp(it, n) != 0){
		mpz_t it1;
		mpz_init(it1);
		mpz_add_ui(it1, it, 1);
		while(mpz_cmp(it1, n) != 0){
			mpz_mul(res, it, it1);
			mpz_mod(res, res, n);
			if(mpz_cmp_d(res, 1) == 0){
				gmp_printf("%Zd and %Zd\n", it, it1);
				break;
			}
			mpz_add_ui(it1, it1, 1);
		}
		mpz_add_ui(it, it, 1);
		
	} 
}
