#include<iostream>
#include<cstring>
#include<istream>
#include<istream>
#include<cstdio>

const int max_size = 10;
using namespace std;


void fillArray( int a[], int size, int &numberUsed);
int dosomething(int a[], int size, int numberUsed, int sum);

int main(){

  int someArray[max_size] , numbers, sumPar = 0;


  fillArray(someArray, max_size, numbers);
  dosomething(someArray, max_size, numbers, sumPar);
  return 0;
}

void fillArray( int a[], int size, int &numberUsed){
  cout << "Enter values for the array" << endl;
  int next, index =0;

  cin >> next;
  while((next>=0) &&(index < size)){
        a[index] = next;
        index++;
        cin >> next;
  }
  numberUsed = index;
}

int dosomething(int a[], int size, int numberUsed, int sum){
  cout << "The value for the array is: " << endl;
  for(int i=0; i<numberUsed; i++){

    cout << a[i] << endl;
  }
  cout << "The average value is" << endl;
  for(int i=0; i<numberUsed; i++){
    sum += a[i];

  }
    cout << sum << endl;
    cout << sum / size << endl;
}
