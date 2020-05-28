#include <bits/stdc++.h>
#include<time.h>
#include<unistd.h>
#include<chrono>

using namespace std;
const int MAX_SIZE =25;


bool areDistinct(vector<int> arr);
int biggestArray(vector<int> arr);


int main()
{
	int n;
   clock_t start, stop;
	bool somebool = true;
	cout <<"enter size of array: " << flush;
	cin >> n;
   cout << "Initializing array with unique random values...\n";
	do{
		 std::vector<int> arr;
		 for(int i=0; i < n; i++){
			sleep(1);
			srand(time(0));
	 	 	arr.push_back((rand()% 500) +1);
			//cout << arr[i];
		 }
		 if (areDistinct(arr)) {
         for(int i=0; i< arr.size(); i++)
            cout << arr[i] << " ";

         auto start = std::chrono::high_resolution_clock::now();
         biggestArray(arr);
         auto stop = std::chrono::high_resolution_clock::now();
         cout << "Largest element is " <<  biggestArray(arr) << endl;
         double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
         cout << "LArgest element calculation took: " << duration << " microseconds" << endl;
         break;

		 }
		 else {
			//cout << "Not all Elements are Distinct\n";
			continue;
		 }

	}while(somebool = true);



	return 0;
}


bool areDistinct(vector<int> arr){
    int n = arr.size();

    // Put all array elements into a "Container" increasing the size of the container by the number of elements inserted.
    // an unordered_set, the value of an element is at the same time its key, that identifies it uniquely.
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    // If all elements are distinct, size of
    // set should be same array. We are therefore comparing the size of the set s,
    return (s.size() == arr.size());
}

int biggestArray(vector<int> arr ){
   int max=arr[0];
   for(int i=1; i< arr.size(); i++ )
      if(arr[i] > max)
      max = arr[i];

   return max;
}
