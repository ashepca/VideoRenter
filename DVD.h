//: DVD.h

/* 
 Title: DVD.h
 Description: Header file for a DVD Class
 Date: 29-Sep-2019
 Author: Andrew Shepherd
 Version: 1.0
 Copyright: 2019 Andrew Shepherd

 Purpose: Interface file for the data and operations of the DVD class.
*/

// include and define statements
#ifndef DVD_H
#define DVD_H
#include <string>
using namespace std; 

class DVD {
   int starRating; // e.g. 1 to 5
   bool checkedIn;
public:
   string title;
   float rentalCost;
   DVD(); // Constructor 
   DVD(string title, float rentalCost); // Constructor with direct input
   ~DVD(); // Destructor
   void checkIn();
   void checkOut();
   void rate(int starRating);
   void print();
};
#endif // DVD_H ///:~
