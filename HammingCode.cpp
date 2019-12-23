#include "iostream"
#include "cstring"
using namespace std;
int main() {
	string dW, cW="0000000", rW;
	int pB[3];
	cout<<"\nEnter the dataword (4 bits): ";
	cin>>dW;
	cW[4]=dW[3];
	cW[2]=dW[2];
	cW[1]=dW[1];
	cW[0]=dW[0];
	cW[6] = dW[3]^dW[2]^dW[0];
	cW[5] = dW[3]^dW[1]^dW[0];
	cW[3] = dW[2]^dW[1]^dW[0];
	cout<<"\nRedundant bits = "<<cW[3]<<" "<<cW[5]<<" "<<cW[6];
	cout<<"\nEnter recieved data: ";
	cin>>rW;
	pB[0] = rW[6]^rW[4]^rW[2]^rW[0];
	pB[1] = rW[5]^rW[4]^rW[1]^rW[0];
	pB[2] = rW[3]^rW[2]^rW[1]^rW[0];
	if((pB[0]==0)&&(pB[1]==0)&&(pB[2]==0))
		cout<<"\nNo error in transmission.\n";
	else {
		cout<<"\nError during transmission.";
		int err = (1*pB[0])+(2*pB[1])+(4*pB[2]);
		cout<<"\nError at position "<<7-err;
		cout<<"\nExpected codeword:\t"<<cW;
		cout<<"\nRecieved codeword:\t"<<rW<<endl;
	}
	return 0;
}
