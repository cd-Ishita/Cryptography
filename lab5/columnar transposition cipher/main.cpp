#include<iostream>
#include<map>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	cout<<"Enter the cipher keyword: ";
	string cipherKey;
	cin>>cipherKey;

	cout<<"Enter the plaintext: ";
	string plainText;
	cin>>plainText;

	int size = cipherKey.length();
	int size1 = plainText.length();
	char temp[size1/size + 1][size];
	

	int j = 0, i=0, k=0;
	cout<<"Transposition matrix: "<<endl;
	while(plainText[k] != '\0'){
		temp[i][j] = plainText[k];
		cout<<temp[i][j]<<" ";
		j++;
		k++;
		if(j == size){
			cout<<endl;
			j = 0;
			i++;
		}
	}
	
	while(i != size1/size +1 || j != size){
		temp[i][j] = '\0';
		j++;
		if(j == size && i == size1/size) break;
		else if(j == size) {
			j = 0;
			i++;
		}
	}
			
	
	map<char, int> m;
	for(int i=0;i<size;i++){
		m.insert({cipherKey[i], i});
	}

	cout<<endl<<endl<<"The ciphertext is: ";
	map<char, int>::iterator it = m.begin();
	while(it != m.end()){
		int i=0;
		while(isalpha(temp[i][it->second]) || i < size1/size+1){
			
			cout<<temp[i][it->second];
			i++;
		}
		it++;
	}
	cout<<endl;
}
