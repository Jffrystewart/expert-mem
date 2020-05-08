#include<iostream>
#include<cstring>


using namespace std;

void timeconversion24(char (&time)[20]);
// converts 12 hour with proper formatting, into 24 hour time.
void timeconversion12(char (&time)[20]);
// converts 24 hour with proper formatting into 12 hour time.


int main(){
	char initTime[20];
	int select;
	bool someBool = true;
	do{
		cout << "Enter current time in either 24 hour or 12 hour format\n";
		cout << "If 12 hour format, then last entry must be AM or PM: " << flush;
		cin >> initTime;
		string selection;

		if(initTime[strlen(initTime) -2] == 'P' || initTime[strlen(initTime) -2] == 'A' )
			select = 2;
		else
			select = 1;

		switch(select){

			case 1:
				timeconversion24(initTime);
				cout << "\n";
				break;
			case 2:
				timeconversion12(initTime);
				cout << "\n";
				break;
		}
		cout << "Would you like to continue?" << flush;
		cin >> selection;
		if(selection == "y" || selection == "Y")
			continue;
		else
			cout << "Exiting.." << endl;
			break;
	}while(someBool = true);
	return 0;
}







void timeconversion24(char (&time)[20]){
	int time1 = (int)time[0] - '0';
	int time2 = (int)time[1] - '0';
	int timeT = (time1 * 10 + time2);

	if(timeT >12){
		timeT -=12;
		cout << timeT;
		for(int i=2; i<=7; i++)
			cout << time[i];
			cout << "PM";
			cout << " Converted from 24 hour to 12 hour format.";
	}

	else{
		for(int i=0; i<=7; i++)
			cout << time[i];
			cout << " AM";
			cout << " Converted from 24 hour to 12 hour format";
	}
}

void timeconversion12(char (&time)[20]){
	int time1 = (int)time[1] - '0' ;
	int time2 = (int)time[0] - '0';
	int timeT = (time2 * 10 + time1 % 10);

	if(time[8] == 'A'){
		for(int i=0; i<=7; i++)
				cout << time[i];
				cout << "Converted from 12 hour to 24 hour format";
	}

	else{
		if(12 == timeT){
			cout << "12";
			cout << timeT;
			for(int i=2; i<=7; i++)
				cout << time[i];
		}
		else{
		 	timeT += 12;
			cout << timeT;
			for(int i=2; i<=7; i++)
				cout << time[i];
		}
	}

}
