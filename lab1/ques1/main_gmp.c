#include<stdio.h>
#include<gmp.h>
int main(){
	mpz_t val1, val2;
	mpz_inits(val1, val2, NULL);
	mpz_set_ui(val1, 10949494900837);
	mpz_set_ui(val2,8456830978392);

	mpz_t res, res1;
	mpz_inits(res, res1, NULL);
	mpz_add(res, val1, val2);
	mpz_mul(res1, val1, val2);
	gmp_printf("Addition : %Zd\n", res);
	gmp_printf("Multiplication : %Zd\n", res1);


	gmp_randstate_t state;
	gmp_randinit_mt(state);

	printf("Unsigned long %lu \n", gmp_urandomb_ui(state, 10));
}
