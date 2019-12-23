#include "iostream"
#include "cstring"
using namespace std;
string crc(string gP, string d, int k) {
	int pos = 17;
	string rem=d, newrem;
	for(int i = 0; i<k; i++) {
		newrem = rem;
		rem="";
		if(newrem[0]=='1') {
			for(int j = 1; j<17; j++) 
				rem.append(newrem[j]==gP[j]?"0":"1");
		}
		else 
			rem = newrem.substr(1,16);
		if(i!=k-1)
			rem.append(d[pos++]=='0'?"0":"1");
	}
	return rem;
}
int main() {
	string gP="10001000000100001", codeWord, dataWord;
	cout<<"\nEnter the data word: ";
	cin>>dataWord;
	int k = dataWord.length();
	codeWord = dataWord;
	for(int i = 0; i<16; i++)
		dataWord.append("0");
	cout<<"\nNew data word = "<<dataWord;
	string rem = crc(gP, dataWord, k);
	cout<<"\nCRC remainder = "<<rem;
	codeWord.append(rem);
	cout<<"\nNew codeword = "<<codeWord<<endl;
	cout<<"1.Check Error\n2.Exit:";
	int p, c;
	cin>>c;
	if(c==1) {
		cout<<"\nEnter position of error: ";
		cin>>p;
		codeWord[p]=(codeWord[p]=='0'?'1':'0');
		cout<<"\nSending codeword: "<<codeWord;
		rem = crc(gP, codeWord, k);
		cout<<"\nRemainder: "<<rem;
		cout<<"\nNot zero, error!";
	}
	else {
		cout<<"\nSending codeword: "<<codeWord;
		rem = crc(gP, codeWord, k);
		cout<<"\nRemainder: "<<rem;
		cout<<"\nZero, no error.";
	}
	return 0;
}
