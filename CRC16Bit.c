#include<iostream>
#include<cstring>
using namespace std;
void crc(string gP, string dataW, int k) {
	string rem, quo, holder, newREM;
	string zC = "00000000000000000";
	char zer[20] = "01";
	string zero = "0", one = "1";
	int nZ = 15;
	for(int i = 0; i<gP.length()-1; i++) {
			holder = ((gP[i+1]==dataW[i+1])?zero:one);
			rem.append(holder);
	}
	for(int j = 0; j<k; j++){
		char c = rem[0];
		newREM = rem;
		if(c == zer[0]){
			rem = "";
			for(int i = 0; i<gP.length()-1; i++) {
				holder = ((gP[i+1]==newREM[i+1])?zero:one);
				rem.append(holder);
		}}
		else{
			rem = "";
			for(int i = 0; i<gP.length()-1; i++) {
				holder = ((zC[i+1]==newREM[i+1])?zero:one);
				rem.append(holder);
		}}
	}
	cout<<"\nREM = "<<rem;
}		
int main() {
	string genPoly = "10001000000100001";
	string zero="0", one="1";
	int n, k, numZeros, i, len3;
	cout<<"Enter data word: ";
	string dataWord;
	cin>>dataWord;	
	k=dataWord.length();
	string codeWord;
	n=15+k;		
	numZeros=n-k;	
	cout<<"\nGenerating polynomial = "<<genPoly;
	cout<<"\nAdding zeroes..";
	string newDataWord = dataWord;
	for(i=k;i<=n;i++){	
		newDataWord.append(zero);
	}
	cout<<"\nNew Data Word="<<newDataWord;
	string dataW = dataWord;
	crc(genPoly, newDataWord, k);	
	return 0;
}
