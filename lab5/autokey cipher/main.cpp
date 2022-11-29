#include<iostream>
#include<map>
#include<cstring>
#include<cctype>
using namespace std;

void plainToCipher(string cipherText, string cipherKey){
	string res;
	for(int i=0;i<cipherText.size();i++){
		res = res + (char)(((int)cipherText[i] - 97 + (int)cipherKey[i] - 97)%26 + 97);
	}
	
	cout<<"The cipher text is : "<<res<<endl<<endl;
}

int main(){
	cout<<"Enter the cipher key: ";
	string key;
	cin>>key;

	cout<<"Enter the plaintext: ";
	string plainText;
	cin>>plainText;

	string cipherKey;
	cipherKey = cipherKey + key;
	cipherKey = cipherKey + plainText.substr(1, plainText.size());

	plainToCipher(plainText, cipherKey);

}
