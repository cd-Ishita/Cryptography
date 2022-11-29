#include<iostream>
#include<map>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	cout<<"Enter the cipher key: ";
	string key;
	cin>>key;

	cout<<"Enter the plaintext: ";
	string plainText;
	cin>>plainText;

	int mat[plainText.size()][plainText.size()];
	int vec[plainText.size()];	
	int k=0;
	for(int i=0;i<plainText.size();i++){
		vec[i] = (int)plainText[i] - 97;
		for(int j=0;j<plainText.size();j++){
			mat[i][j] = (int)key[k] - 97;
			k++;
		}
	}

	int product[plainText.size()];
	for(int i=0;i<plainText.size();i++){
		product[i] = 0;		
		for(int j=0;j<plainText.size();j++){
			product[i] = product[i] + vec[j] * mat[i][j];
		}
	}

	for(int i=0;i<plainText.size();i++){
		char temp = (char)(product[i]%26 + 97);
		cout<<temp<<" ";
	}
	
	cout<<endl;

}
