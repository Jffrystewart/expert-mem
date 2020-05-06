#include<iostream>
#include<cstring>

// shift each byte from a binary string, N number of bytes to either the left or the right.

using namespace std;

void shiftStringR(char strMsg[]);
//called by functiong shiftString 4. Sets tmp equal to byte indexed at length of strMsg, then loops through each byte starti
//begining at index i= length of strMsg -1 and setting it equal to index i-1 effectively moving each byte to the right, ignoring NULL terminator.

void shiftString4(char strMsg[], int &num);
//while loop. so that we can shift each byte N number of times depending on user input.

void shiftString6(char strMsg[], int &num);
//while loop does the same as shiftString 4 except calls function shiftString6 intead. This is used for moving byte to the left.

void shiftStringL(char strMsg[]);
//called by function shiftString6. Sets tmp equal to byte at index 0 of strMsg, then loops through each byte starting at index i and setting
//them equal to the next value at index i+1 effectively moving each byte to the left, ignoring NULL terminator.

int main(){
  char str[] = "1010010";
  int numberOfBits;
  int direction;


  cout << "How many bytes do you want to shift" << endl;
  cin >> numberOfBits;
  cout << "Shift to the right or left" << endl;
  cout << "1. Right\n";
  cout << "2. Left\n";

  cin >> direction;   // switch case for left or right direction.
  switch(direction){
    case 1:
    cout << str << endl;
    shiftString4(str, numberOfBits);

    case 2:
    cout << str << endl;
    shiftString6(str, numberOfBits);
  }
  return 0;
}

void shiftStringR(char strMsg[]){
  char tmp = strMsg[strlen(strMsg)-1];
  for(int i=strlen(strMsg)-1; i>0; i--){
    strMsg[i] = strMsg[i-1];
  }
  strMsg[0] = tmp;
}


void shiftString4(char strMsg[], int &num){
  while(num > 0){
    shiftStringR(strMsg);
    cout << strMsg << endl;
    num--;
  }

}
void shiftStringL(char strMsg[]){
  char tmp = strMsg[0];

  for(int i=0; i<strlen(strMsg)-1; i++){
    strMsg[i] = strMsg[i+1];
  }
  strMsg[strlen(strMsg)-1] = tmp;
}
void shiftString6(char strMsg[], int &num){
  while(num >0){
    shiftStringL(strMsg);
    cout << strMsg << endl;
    num--;
  }

}
