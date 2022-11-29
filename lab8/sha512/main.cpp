#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

string dec_to_bin(int message){
	string res = "";
	
	while(message > 0){
		if(message%2 == 0) res = "0" + res;
		else res = "1" + res;
		
		message = message / 2;
	}
	
	return res;
}

string padding(string m){
	string res = "1";
	while((res.size() + m.size() + 128)%1024 != 0){
		res = res + "0";
	}
	res = res + m;
	return res;
}

string append_len(string m, int size){
	string bin = dec_to_bin(size);
	
	while(bin.size() != 128){
		bin = "0" + bin;
	}
	return bin;
}

vector<string> hash_buffer(){
	string A = "0110101000001001111001100110011111110011101111001100100100001000";
	string B = "1011101101100111101011101000010110000100110010101010011100111011";
	string C = "0011110001101110111100110111001011111110100101001111100000101011";
	string D = "1010010101001111111101010011101001011111000111010011011011110001";
	string E = "0101000100001110010100100111111110101101111001101000001011010001";
	string F = "1001101100000101011010001000110000101011001111100110110000011111";
	string G = "0001111110000011110110011010101111111011010000011011110101101011";
	string H = "0101101111100000110011010001100100010011011111100010000101111001";
	
	vector<string> vec;
	vec.push_back(A);
	vec.push_back(B);
	vec.push_back(C);
	vec.push_back(D);
	vec.push_back(E);
	vec.push_back(F);
	vec.push_back(G);
	vec.push_back(H);
	
	return vec;
}

string rotr(int count, string m){
	for(int i=0;i<count;i++){
		string temp = m.substr(0, m.size()-1);
		temp = m[m.size()-1] + temp;
		m = temp;
	}
	
	return m;
}

string shr(int count, string m){
	string temp = m.substr(0, count);
	
	for(int i=0;i<count;i++){
		temp = "0" + temp;
	}
	return temp;
}

string and_func(string a, string b){
	string res = "";
	for(int i=0;i<a.size();i++){
		if(a[i] == '1' && b[i] == '1') res = res + "1";
		else res = res + "0";
	}
	return res;
}

string not_func(string a){
	string res = "";
	for(int i=0;i<a.size();i++){
		if(a[i] == '1') res = res + "0";
		else res = res + "1";
	}
	return res;
}

string xor_func(string a, string b){
	string res = "";
	for(int i=0;i<a.size();i++){
		if(a[i] == b[i]){
			res = res + "0";
		}
		else{
			res = res + "1";
		}
	}
	return res;
}

string add_func(string a, string b){
	string addRes = "";
	int carry = 0;
	for(int i=a.size()-1;i>=0;i--){
      		int re = carry;
      		if(a[i] == '1'){
         		re = re+1;
 		}
      		else{
         		re = re+0;
 		}
      
      		if(b[i] == '1'){
         		re = re+1;
 		}
      
      		if(re%2==1) addRes = '1' + addRes;
		else addRes = '0' + addRes;
      
      		if(re<2) carry = 0;
      		else carry = 1;
   	}
   	return addRes;
}

string sigma_func(string m, int x, int y, int z){
	string a = rotr(x, m);
	string b = rotr(y, m);
	string c = shr(z, m);
	
	// xor a and b
	string res = xor_func(a, b);
	
	// xor res and c
	res = xor_func(res, c);
	
	return res;
}
 

vector<string> message_schedule(string m){
	vector<string> vec;
	for(int i=0;i<80;i++){
		if(i < 16){
			vec.push_back(m.substr(i, 1024/16));
		}
		else{
			string temp = sigma_func(vec[i-2], 1, 8, 7);
			temp = add_func(temp, vec[i-7]);
			
			string temp1 = sigma_func(vec[i-15], 19, 61, 6);
			temp1 = add_func(temp1, vec[i-16]);
			vec.push_back(add_func(temp, temp1));
		}
	}
	
	return vec;
}

vector<string> round(vector<string> buf, string message, string constant){
	
	vector<string> buf1 = buf;
	buf1[1] = buf[0];
	buf1[2] = buf[1];
	buf1[3] = buf[2];
	buf1[5] = buf[4];
	buf1[6] = buf[5];
	buf1[7] = buf[6];
	
	// for a
	
	string sigma1 = xor_func(xor_func(rotr(28, buf[0]), rotr(34, buf[0])), rotr(39, buf[0]));
	
	
	// maj calc
	string maj = xor_func(xor_func(and_func(buf[0], buf[1]), and_func(buf[0], buf[2])), and_func(buf[1], buf[2]));
	
	string res = xor_func(sigma1, maj);
	
	// calculations from h
	string ch = xor_func(and_func(buf[4], buf[5]), and_func(not_func(buf[4]), buf[6]));
	
	string temp = xor_func(ch, buf[7]);
	
	string sigma2 = xor_func(xor_func(rotr(14, buf[4]), rotr(18, buf[4])), rotr(41, buf[4]));
	
	temp = xor_func(sigma2, temp);
	temp = xor_func(temp, message);
	temp = xor_func(temp, constant);
	
	buf1[0] = xor_func(res, temp);
	buf1[4] = xor_func(buf[3], temp);
	
	return buf1;
}

int main(){

	srand(time(0));
	int message = 78787;
	string m = dec_to_bin(message);
	int size = m.size();
	m = padding(m);
	m = append_len(m, size);
	vector<string> buf = hash_buffer();
	vector<string> message_sche = message_schedule(m);
	for(int i=0;i<80;i++){
		int k = rand();
		vector<string> temp = round(buf, message_sche[i], dec_to_bin(k));
		buf = temp;
	}
	
	cout<<"Encrypted message: "<<endl;
	cout<<buf[0]<<endl;
	cout<<buf[1]<<endl;
	cout<<buf[2]<<endl;
	cout<<buf[3]<<endl;
	cout<<buf[4]<<endl;
	cout<<buf[5]<<endl;
	cout<<buf[6]<<endl;
	cout<<buf[7]<<endl;
}
