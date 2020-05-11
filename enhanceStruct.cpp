/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

const int MAX_EXERCISE = 5;
const int MAX_STUDENT = 25;
const int MAX_COURSES = 5;



struct Exercise{
  int score = 0;    // if you don't initialize the member variable, it might contain undefined value
  int point = 0;

};  // must end with semicolon

struct Student{
  string name;
  // a student can have an collection of exercises and each exercise has score and point
  Exercise exerciseList[MAX_EXERCISE];
  int numberOfExerciseTaken = 0;



};

struct ClassRoom{
   Student studentList[MAX_STUDENT];
	int roomNumber;
   string courseName;


};

Exercise printTotalExercise(Student pStudent, int bonusScore);

Exercise printTotalExercise(Student pStudent);

void initStudentExercises(Student& pStudent);

// demonstrate the call by reference
void getExerciseData(Exercise& pExercise, int i);

// getExercise will return the variable/memory address contains the score and point
Exercise addBonusToExercise(Exercise pExercise, int bonusScore);

/*
user input: number of exercise
each exercise should contain score and point
*/
int main()
{
   ;
   ClassRoom sClassRoom;
   Student sStudent;
   int numberOfStudents;




   cout << "Enter course name " << flush;
   cin >> sClassRoom.courseName;


   cout << "Enter room number of " << flush;
   cin >> sClassRoom.roomNumber;

   cout << "How many students are in the class" << endl;
   cin >> numberOfStudents;


   for(int i =0; i<  numberOfStudents; i++){
      initStudentExercises(sClassRoom.studentList[i]);
      cout << "Enter name of student " << flush;
      cin >> sClassRoom.studentList[i].name;

   }


    // Exercise sExercise; // we declare variable, sExercise as type of Exercise (struct)

    for(int i = 0; i < numberOfStudents; i++){
         cout << "How many exercises did " << sClassRoom.studentList[i].name << " complete";
         cin >> sClassRoom.studentList[i].numberOfExerciseTaken;

         for(int j = 0; j < sClassRoom.studentList[i].numberOfExerciseTaken; j++){
            getExerciseData(sClassRoom.studentList[i].exerciseList[j], j + 1);
         }

        }

   for(int i=0; i < numberOfStudents; i++)
      printTotalExercise(sClassRoom.studentList[i]);


   cout << "After bonus: \n";
   for(int i=0; i < numberOfStudents; i++)
      printTotalExercise(sClassRoom.studentList[i], 5);


   return 0;
}

Exercise printTotalExercise(Student pStudent, int bonusScore){
    pStudent.exerciseList[0].score += bonusScore;
    return printTotalExercise(pStudent);
}

Exercise printTotalExercise(Student pStudent){

    Exercise totalExercise; // We declare variable, totalExercise as type of Exercise (struct)

    for(int i=0; i<pStudent.numberOfExerciseTaken; i++){
        totalExercise.score += pStudent.exerciseList[i].score;
        totalExercise.point += pStudent.exerciseList[i].point;
    }

    cout << pStudent.name << " scored " << totalExercise.score << " out of " << totalExercise.point << ", percentage: " << ((double)totalExercise.score/totalExercise.point)*100 << endl;

    return totalExercise;
}

void initStudentExercises(Student& pStudent){
    pStudent.name = "No Body";
    for(int i=0; i< MAX_EXERCISE; i++)
    {
        pStudent.exerciseList[i].score = 0;
        pStudent.exerciseList[i].point = 10;
    }
}

void getExerciseData(Exercise& pExercise, int i){
    cout << "Score for exercise " << i << "? ";
    cin >> pExercise.score;

    cout << "Point for exercise " << i << "? ";
    cin >> pExercise.point;
}

// pExercise is pass by value where we declare a return with Exercise type
Exercise addBonusToExercise(Exercise pExercise, int bonusScore){
    Exercise retExercise = pExercise;
    retExercise.score += bonusScore;

    return retExercise;
}
