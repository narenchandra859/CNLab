#include<iostream>
#include<cstring>
using namespace std;
string crc(string gP, string dataWord, int k) {
  int pos = 17;
  char z[3] = "01";
  string zero = "0", one = "1", rem, newrem;
  for(int i = 0; i<gP.length()-1; i++) 
    rem.append((gP[i+1]==dataWord[i+1])?zero:one);
  rem.append((dataWord[pos++]==z[1])?one:zero);
  for(int j = 0; j<k-1; j++) {
    newrem = rem;
    if(rem[0] == z[1]) {
      rem = "";
      for(int i = 0; i<gP.length()-1; i++)
        rem.append((gP[i+1]==newrem[i+1])?zero:one);
    }
    else
      rem = newrem.substr(1,16);
    if(j!=k-2)rem.append((dataWord[pos++]==z[1])?one:zero);
  }
  return rem;
}
int main() {
  string gP = "10001000000100001", codeWord, dataWord, zero = "0", one = "1";
  cout<<"\nEnter the dataword : ";
  char z[3]="01";
  cin>>dataWord;
  int k = dataWord.length();
  codeWord = dataWord;
  for(int i = 0; i<16; i++) 
    dataWord.append("0");
  cout<<"\nNew dataword = "<<dataWord;
  string rem = crc(gP, dataWord, k);
  cout<<"\nCRC rem = "<<rem;
  codeWord.append(rem);
  cout<<"\nNew codeword = "<<codeWord;
  cout<<"\nCheck error? Y/N: ";
  cin>>z[2];
  if(z[2]=='Y') {
    cout<<"\nEnter position of error: ";
    int p;
    cin>>p;
    codeWord[p] = (codeWord[p]==z[0])?z[1]:z[0];
    cout<<"\nSending codeword "<<codeWord;
    rem = crc(gP, codeWord, k);
    cout<<"\nRemainder = "<<r;
    cout<<"\nRemainder not zero! Error!";
  }
  else {
    rem = crc(gP, codeWord, k);
    cout<<"\nSending codeword "<<codeWord;
    cout<<"\nRemainder = "<<r;
    cout<<"\nRemainder zero, no error!";
  }
}
