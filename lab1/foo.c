#include<stdio.h>
#include<gmp.h>
#include<stdarg.h>

void func(mpz_t a, mpz_t b){
	mpz_t result;
	mpz_init(result);
	mpz_add(result, a, b);
	
	
	gmp_printf("result: %d", result);
	mpz_clear(result);
}

int main(){
	mpz_t a;
	mpz_t b;
	mpz_init(a);
	mpz_init(b);
	
	gmp_printf("Give input");
	gmp_scanf("%Zd\n", a);
	gmp_scanf("%Zd\n", b);
	mpz_set(a, 10);
	mpz_set(b, 20);
	
	func(a, b);
	mpz_clear(a);
	mpz_clear(b);
	return 0;
}
