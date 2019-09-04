#include<iostream>
#include<cstring>
using namespace std;
int main(){ 
	string dataWord, codeWord="0000000",recWord;
	int posBits[3];
	cout<<"\nEnter 4 bit data word: ";
	cin>>dataWord;
	codeWord[4] = dataWord[3];
	codeWord[2] = dataWord[2];
	codeWord[1] = dataWord[1];
	codeWord[0] = dataWord[0];
	// r1 = r1 ^ dataPos(1,3,5,7)[3 bit table] --> r1 = r1^(p3==dataWord[0])^(p5==dataWord[1])^(p7==dataWord[3])
	codeWord[6] = dataWord[3]^dataWord[2]^dataWord[0];
	codeWord[5] = dataWord[3]^dataWord[1]^dataWord[0];
	codeWord[3] = dataWord[2]^dataWord[1]^dataWord[0];
	cout<<"\nRedundant bits are: "<<codeWord[3]<<" "<<codeWord[5]<<" "<<codeWord[6];
	cout<<"\nEnter recieved data(7 bits): ";
	cin>>recWord;
	posBits[0] = recWord[6]^recWord[4]^recWord[2]^recWord[0];
	posBits[1] = recWord[5]^recWord[4]^recWord[1]^recWord[0];
	posBits[2] = recWord[3]^recWord[2]^recWord[1]^recWord[0];
	if(posBits[0]==posBits[1]==posBits[2]==0) 
		cout<<"\nNo error during transmission.\n";
	else{
		int errPos = (1*posBits[0])+(2*posBits[1])+(4*posBits[2]);
		cout<<"\nError in transmission at bit: "<<errPos;
		cout<<"\nReal codeword: "<<codeWord;
		cout<<"\nRecieved codeword: "<<recWord<<endl;
	}
	return 0;
}
