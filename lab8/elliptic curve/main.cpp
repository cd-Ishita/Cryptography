#include<iostream>
#include<time.h>
using namespace std;

void point_doubling(int &x1, int &y1, int n, int count, int x3. int y3, int a){
	if(count == n){
		x1 = x3;
		y1 = y3;
		return;
	}
	else{
		point_addition(x3, y3, a);
		count = count * 2;
		point_doubling(x1, y1, n, count, x3, y3);
	}
}

void point_addition(int &x1, int &y1, int a){
	
	if(y1 != 0){
		int m = (3*x1*x1 + a) / ( 2 * y1);
		int x3 = m*m - 2 * x1;
		int y3 = m*(x1 - x3) - y1;
		x1 = x3;
		y1 = y3;
	}

}

void point_mul(int &x1, int &y1, int n, a){
	if(n%2 == 0) point_doubling(x1, y1, n, 1, x1, y1, a);
	else{
		point_doubling(x1, y1, n-1, 1, x1, y1, a);
		point_addition(x1, y1, a);
	}
}

int main(){
	srand(time(0));

	// key generation
	int a, b, x1, y1, n;
	
	cout<<"Enter the ellipse parameters a and b: "<<endl;
	cin>>a>>b;
	
	cout<<"Enter the point G (x1, y1): "<<endl;
	cin>>x1>>y1;
	
	cout<<"Enter value of n: "<<endl;
	cin>>n;
	
	// user a 
	int na = rand()%n;
	
	int pax1 = x1, pay1 = y1;
	
	int Pa = point_mul(px1, py1, na, a);
	
	// user b 
	int nb = rand()%n;
	
	int pbx1 = x1, pby1 = y1;
	int Pb = point_mul(pbx1, pby1, nb, a);
	
	point_mul(pbx1, pby1, na, a);
	point_mul(pax1, pay1, nb, a);
	
	cout<<"Key generation: "<<endl<<"ka: "<<pkx1<<" "<<pby1<<"| kb: "<<pkb<<endl;
	
	// A chooses random positive integer k
	int k = rand()%n;
	int cipherx1 = x1, ciphery1 = y1, cipherx2 = pbx1, ciphery2 = pby1;
	point_mul(cipherx1, ciphery1, k, a);
	point_mul(cipherx2, ciphery2, k, a);
	
	// point addition
	if(mx1 != cipherx2 && my1 != ciphery2){
		int m = (ciphery2 - my1) / (cipherx2 - mx1);
		int x3 = m*m - mx1 - cipherx2;
		int y3 = m *(mx1 - x3) - my1;
		cout<<"Encrypted points: "<<endl;
		cout<<"Point 1: "<<cipherx1<<" and "<<ciphery1<<endl;
		cout<<"Point 2: "<<x3<<" and "<<y3<<endl;
	}
	else if(mx1 == cipherx2 && my1 != ciphery2){
		cout<<"Vertical line"<<endl;
	}
	else if(mx1 == cipherx2 && my1 == ciphery2 && my1 != 0){
		int m = (3 * mx1 * mx1 + a) / ( 2 * my1);
		int x3 = m*m - 2 * mx1;
		int y3 = m *( mx1 - x3) - my1;
		
		cout<<"Encrypted points: "<<endl;
		cout<<"Point 1: "<<cipherx1<<" and "<<ciphery1<<endl;
		cout<<"Point 2: "<<x3<<" and "<<y3<<endl;
	}
}
