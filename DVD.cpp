//: DVD.cpp

/* 
 Title: DVD.cpp
 Description: Implementation file for a DVD Class
 Date: 29-Sep-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose: Implementation file for the operations of the DVD class.
*/

// include and define statements
#include "DVD.h"
#include <iostream>
#include <string> 
using namespace std;

DVD::DVD() {
   starRating = 5;  // default rating, I only rent the best movies
   checkedIn = true;  // defaults as checked in
}

DVD::DVD(string name, float cost) {
   title = name;
   rentalCost = cost;
   starRating = 5;  // default rating, I only rent the best movies
   checkedIn = true;  // defaults as checked in
} 

DVD::~DVD() {  
}

void DVD::checkIn() {
   checkedIn = true;
}

void DVD::checkOut() {
   checkedIn = false;
}

void DVD::rate(int rating) {
   starRating = rating;
}

void DVD::print() {
   if(rentalCost != 0) { // only prints if a movie has been entered
      cout << "Movie" << endl;
      cout << "   Title: " << title << endl;
      cout << "   Rental Cost: " << rentalCost << endl;
      cout << "   Star Rating: " << starRating << endl;
      cout << "   Checked in: " << (checkedIn ? "yes" : "no") << endl;
   }
} ///:~
