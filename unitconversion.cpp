#include<iostream>
#include<cstring>

using namespace std;


float inputFunction(float &unitPar, float &meter);
void conversionI2M(float &unitPar, float &meter);
void conversionM2I(float &unitPar, float &meter);
int main(){

	float unitMain, mMain;

	float unitSwitch;




	int  Mselect;

	//float unitSwitch;
	bool somebool = true;
	do{
		cout << "Enter a unit to convert.\n";
		cin >> unitSwitch;
		string cont;
		//cin >> unitMain;
		cout << " We can convert feet, meters or inches";
		cout << "What would you like to convert your unit into? " << flush;
		cout << "1. convert from inches to meters\n";
		cout << "2. convert from meters to inches\n";
		cout << "3. co"
		cin >> Mselect;

		switch(Mselect){

			case 1:
				cout << "convert from inches to meters" << endl;
				conversionI2M(unitSwitch, unitMain);
				break;
			case 2:
				cout << "convert from meters to inches";
				conversionM2I(unitSwitch, unitMain );
				break;
			case 3:
				conversionM2I(unitSwitch, unitMain );
		}
		cout << "Would you like to continue?" << endl;
		cin >> cont;
		if(cont == "Y" || cont == "y")
			continue;
		else
			cout << "Exiting...";
			break;
	}while(somebool  = true);


	//inputFunction(unitMain,  mMain);
	return 0;
}


/*float inputFunction(float &unitPar){

	int  Mselect;
	float unitSwitch;
	bool somebool = true;
	do{

		cin >> Mselect;

		switch(Mselect){

			case 1:
				cout << "convert from inches to meters" << endl;
				conversionI2M(unitSwitch, Mselect);
				break;
			case 2:
				cout << "convert from meters to inches";
				conversionM2I(unitSwitch, Mselect);
				break;
			}
			int cont;
			cout << "Would you like to continue?" << endl;
			cin >> cont;

			if(cont == 'Y' || 'y')
				continue;
			else
				break;
	}while(somebool  = true);
*/

void conversionI2M(float &unitPar, float &meter){
	meter = unitPar / 39.37;
	cout << meter << endl;
}

void conversionM2I(float &meter, float &unitPar ){
	unitPar = meter * 39.37;
	cout << unitPar << endl;
}
