#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> key_schedule(string key, int rounds){

}

string hex_to_bin(string hex_p){
	unordered_map<char, string> map;
	map['0'] = "0000";
	map['1'] = "0001";
	map['2'] = "0010";
	map['3'] = "0011";
	map['4'] = "0100";
	map['5'] = "0101";
	map['6'] = "0110";
	map['7'] = "0111";
	map['8'] = "1000";
	map['9'] = "1001";
	map['A'] = "1010";
	map['B'] = "1011";
	map['C'] = "1100";
	map['D'] = "1101";
	map['E'] = "1110";
	map['F'] = "1111";
	
	string res = "";
	for(int i=0;i<hex_p.size();i++){
		res = res + map[hex_p[i]];
	}
	return res;
}

vector<vector<string>> to_blocks(string plaintext){
	vector<vector<string>> grid(4, vector<string>);
	int count = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			grid[j].append(plaintext.substr(count, 32));
			count = count + 32;
		}
	}
	
	// check grid once
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<grid[i][j]<<" ";
		}
	}
	return grid;
}	

vector<vector<string>> subBytes(vector<vector<string>> grid){
	vector<vector<string>> sub = grid;
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			sub[i][j] = grid[s_box[i][j] % 4][s_box[i][j]/4]
		}
	}
	
	return sub;
}

vector<vector<string>> shiftRows(vector<vector<string>> grid){
	for(int i=1;i<grid.size();i++){
		for(int j=0;j<i;j++){
			grid[i].push_back(grid[i][0]);
			grid[i].erase(grid[i].begin());
		}
	}
	
	return grid;
}

vector<vector<string>> mixColumns(vector<vector<string>> grid){
	int matrix[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	};
	
	
}

int main(){
	int size;
	int rounds;
	cout<<"Enter key size in bits: ";
	cin>>size;
	
	if(size == 128) rounds = 10;
	else if(size == 192) rounds = 12;
	else if(size == 256) rounds = 14;
	
	string key;
	cout<<"Enter the key: ";
	cin>>key;
	
	// creation of round keys
	vector<string> round_keys = key_schedule(key, rounds);
	
	// assuming plaintext in form of hexadecimal
	
	string hex_p;
	cout<<"Enter the message to be encrypted: ";
	cin>>hex_p;
	
	string plaintext = hex_to_bin(hex_p);
	vector<vector<string>> grid = to_blocks(plaintext);
	
	// encryption
	// 16 byte grid, column major
	// b0 b4 b8 b12
	// b1 b5 b9 b13
	// b2 b6 b10 b14
	// b3 b7 b11 b15
	
	
}
