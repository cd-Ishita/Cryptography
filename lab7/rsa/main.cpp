#include<iostream>
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

void encrypt(int message, int e, int n){
	int cipher = fast_exponent(message, e, n);
	cout<<"Process: "<<message<<" "<<e<<" "<<n<<endl;
	cout<<"Ciphertext: "<<cipher<<endl;
}

void decrypt(int cipher, int d, int n){
	int message = fast_exponent(cipher, d, n);
	
	cout<<"Message: "<<message<<endl;
}

int main(){

	int p, q;
	
	cout<<"Enter the prime number p: ";
	cin>>p;
	
	cout<<"Enter the prime number q: ";
	cin>>q;
	
	int n = p*q;
	int eulers_t = (p-1)*(q-1);
	
	// bob chooses e such that it is coprime with eulers_t
	int e;
	for(int i=2;i<eulers_t;i++){
		if(eulers_t%i != 0){
			e = i;
			break;
		}
	}
	
	
	// bob solves d*e = 1 mod eulers_1
	int d, i=1;
	while(true){
		if((i*e)%eulers_t == 1){
			d = i;
			break;
		}
		i++;
	}
	
	
	// bob makes (e, n) public and (p, q, d) secret
	cout<<"Public Key (e, n): ("<<e<<", "<<n<<")"<<endl;
	cout<<"Secret Key (p, q, d): ("<<p<<", "<<q<<", "<<d<<")"<<endl;
	
	
	cout<<endl<<endl;
	int choice;
	cout<<"Enter 0 for encryption and 1 for decryption: ";
	cin>>choice;
	
	if(choice == 0){
		int message;
		cout<<"Enter the message to be encrypted: ";
		cin>>message;
		
		encrypt(message, e, n);
	}
	else{
		int cipher;
		cout<<"Enter the ciphertext to be decrypted: ";
		cin>>cipher;
		
		decrypt(cipher, d, n);
	}
}
