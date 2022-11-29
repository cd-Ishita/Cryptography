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

int main(){
	
	cout<<"Enter value of prime number q: ";
	int q, alpha;
	cin>>q;
	
	cout<<"Enter value of alpha: ";
	cin>>alpha;
	
	if(alpha > q){
		cout<<"Alpha cannot be greater than q."<<endl<<"Exit";
		return 0;
	}
	
	// alice generates a private key Xa such that Xa < q
	srand(time(0));
	
	int Xa = rand()%q;
	cout<<"Alice's private key Xa: "<<Xa<<endl;
		
	// bob generates a private key Xb such that Xb < q
	int Xb = rand()%q;
	cout<<"Bob's private key Xb: "<<Xb<<endl;
	
	// alice calculates a public key Ya
	int Ya = fast_exponent(alpha, Xa, q);
	cout<<"Alice's public key Ya: "<<Ya<<endl;
	
	// bob calculates a public key Yb 
	int Yb = fast_exponent(alpha, Xb, q);
	cout<<"Bob's public key Yb: "<<Yb<<endl;
	
	// alice calculates shared secret key 
	int Ka = fast_exponent(Yb, Xa, q);
	cout<<"Alice's shared secret key Ka: "<<Ka<<endl;
	
	// bob calculates shared secret key
	int Kb = fast_exponent(Ya, Xb, q);
	cout<<"Bob's shared secret key Kb: "<<Kb<<endl;
		
}
