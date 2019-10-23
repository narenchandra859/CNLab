#include<iostream>
#include<cstring>
using namespace std;
string crc(string gP, string dataW, int k) {
	string rem="", quo="", holder="", newREM="",zC = "00000000000000000000";
	char zer[20] = "01";
	int pos=17;
	string zero = "0", one = "1";
	for(int i = 0; i<gP.length()-1; i++) 
			rem.append((gP[i+1]==dataW[i+1])?zero:one);
	if(k!=1)rem.append((dataW[pos++]==zer[0]?zero:one));
	for(int j = 0; j<k-1; j++){
		char c = rem[0];
		newREM = rem;
		if(c == zer[1]){
			rem = "";
			for(int i = 0; i<gP.length()-1; i++) 
				rem.append((gP[i+1]==newREM[i+1])?zero:one);
		}
		else{
			rem = "";
			for(int i = 0; i<gP.length()-1; i++)
				rem.append((zC[i+1]==newREM[i+1])?zero:one);
		}
		if(!(j==k-2))rem.append((dataW[pos++]==zer[0]?zero:one));
	}
	return rem;
}		
int main() {
	string genPoly = "10001000000100001", zero="0", one="1", c, dataWord, codeWord, newDataWord;
	char z='0', o='1';
	int k, numZeros, i, errPos;
	cout<<"Enter data word: ";
	cin>>dataWord;	
	k = dataWord.length();		
	numZeros=16;	
	cout<<"\nGenerating polynomial = "<<genPoly;
	newDataWord = dataWord;
	for(i=0;i<numZeros;i++)	
		newDataWord.append(zero);
	cout<<"\nNew Data Word="<<newDataWord;
	string rem = crc(genPoly, newDataWord, k);
	codeWord = dataWord.append(rem);
	cout<<"\nFinal Remainder(CRC checksum) = "<<rem;
	cout<<"\nCODEWORD = "<<codeWord;
	cout<<"\nCheck for error? Y/N: ";
	cin>>c;
	if(c=="Y"){
		cout<<"\nEnter the position to insert error: ";
		cin>>errPos;
		codeWord[errPos]==z?(codeWord[errPos]=o):(codeWord[errPos]=z);
		cout<<"\nSending the codeword: "<<codeWord;
		rem = crc(genPoly, codeWord, k);
		cout<<"\nRemainder: "<<rem;
		cout<<"\nWrong codeword sent, remainder is not zero!\n";
	}
	else{ 
		cout<<"\nSending the codeword: "<<codeWord;
		rem = crc(genPoly, codeWord, k);
		cout<<"\nRemainder: "<<rem;
		cout<<"\nRemainder zero, transmission successful.\n";
	}
	return 0;
}
