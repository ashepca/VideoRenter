//: VideoRenter.cpp

/* 
 Title: VideoRenter.cpp
 Description: Program that manages DVD rental in a video store
 Date: 29-Sep-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose: The program is intended to represent a DVD rental in a video store,
          and will test the DVD's data and operations.

 Compile (with GNU C++):  g++ DVDRenter.cpp DVD.cpp

 Classes: DVD

 Variables: 
        fileName - string - used to store input file name entered by user
        currentTitle - string - used to hold the current title as the file is
           looped through reading all DVD titles
        currentCost - float - - used to hold the current rentalCost as the file
           is looped through reading all DVD titles
        movieNum - int - used to keep count of the DVD number in the file
          file is entered and opened.
*/

// include and define statements
#include "DVD.h"
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

#define SIZE 10

// ------------------------------------------------------------------------
// Function: main()
// Purpose:  Main execution of the program
// Inputs:  none
// ------------------------------------------------------------------------

int main(void) {
   // variables
   string fileName;
   string currentTitle;
   float currentCost;
   int movieNum = 0;

   // request and obtain input file name
   cout << "\nEnter a file of DVDs to add, e.g. DVDList.txt: ";
   cin >> fileName;
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   // declare and open file
   ifstream inputFile(fileName);

   while(!inputFile) {
      cout << "File not found, please enter another file: ";
      cin >> fileName;
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      inputFile.open(fileName);
   }

   //create a DVD array and populate with data from fileName
   DVD movieList[SIZE];

   while(getline(inputFile, currentTitle) && movieNum < SIZE) {
      movieList[movieNum].title = currentTitle;
      inputFile >> currentCost;
      inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      movieList[movieNum].rentalCost = currentCost;
      movieNum++;
   }

   //display list of movies and data fields as entered from file
   cout << "\nList of Movies (as entered):\n" << endl;
   for(int i = 0; i < SIZE; i++) {
      movieList[i].print();
   }

   // test DVD class functions and change some data fields
   movieList[0].checkOut();
   movieList[1].rate(3);
   movieList[2].rentalCost = 3.33;
   movieList[3].title = "Four";
   movieList[3].rentalCost = 4.44;
   movieList[3].rate(4);
   movieList[4].checkOut();
   movieList[4].checkIn();

   //display list of movies and data fields after changes
   cout << "\nList of Movies (after changes):\n" << endl;
   for(int i = 0; i < SIZE; i++) {
      movieList[i].print();
   }
   cout << "\n" << endl;
} ///:~
