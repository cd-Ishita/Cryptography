#include<iostream>
#include<time.h>
using namespace std;

int fast_exponent(int a, int b, int n){
	string binary = "";
	int i = 0;
	while(b > 0){
		if(b%2 == 0) binary = "0" + binary;
		else binary = "1" + binary;
		
		b = b / 2;
		i++;
	}
	
	int c = 0, f = 1;
	for(int i=binary.size() - 1;i>=0;i--){
		f = (f*f)%n;
		c = 2*c;
		
		if(binary[i] == '1'){
			c = c + 1;
			f = (f*a)%n;
		}
	}
	return f;
	
}

int multiplicative_inverse(int a, int n){
	for(int i=1;i<=n;i++){
		if((i*a)%n == 1) return i;
	}
	return 0;
}

int main(){

	srand(time(0));
	int q, alpha;
	cout<<"Enter the prime number: ";
	cin>>q;
	
	cout<<"Enter the primitive root: ";
	cin>>alpha;
	
	// key generation - alice
	int Xa = rand()%(q-1);
	int Ya = fast_exponent(alpha, Xa, q);
	
	cout<<"Public key generated: (q, alpha, Ya): ("<<q<<", "<<alpha<<", "<<Ya<<")"<<endl;
	cout<<"Private key generated: (Xa): "<<Xa<<endl;
	
	// encryption - bob
	cout<<"Enter the message: "<<endl;
	int M;
	cin>>M;
	
	int k = rand()%q;
	
	int K = fast_exponent(Ya, k, q);
	
	int C1 = fast_exponent(alpha, k, q);
	int C2 = (K*M)%q;
	
	cout<<"Ciphertext generated (C1, C2): ("<<C1<<", "<<C2<<")"<<endl;
	
	cout<<"Starting decryption"<<endl;
	int k_a = fast_exponent(C1, Xa, q);
	int m = (multiplicative_inverse(k_a, q) * C2 )% q;
	
	cout<<"Message: "<<m<<endl;
}
