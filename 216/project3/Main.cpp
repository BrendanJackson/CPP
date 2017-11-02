/*
  |--------------------------------------------------------------------------
  | Project #2 Main Function
  |--------------------------------------------------------------------------
  |
  | Brendan Jackson
  | 10/05/2017
  | CS216
  |
  | Driver
  | The main() function will instantiate three arrays of the GenericRecord class using each of the
  | three struct names as template parameter respectively.
  | Write loops that input data from the keyboard and calls the mutator functions of the array objects
  | to insert the data in the array objects.
  | Write loops that iterate through the arrays to call the accessor and get the data then display it in
  | table form (three tables one for furniture, one for computers, and one for buildings). The table
  | should be formatted using iomanip functions and flags (see projects 1 and 2).
  |
*/

// pulls in header file
#include "Declarations.h"

/* Main
************************/
int main()
{
  cout << endl; //Command line style

GenericRecord<Furniture> inventory[1000];
GenericRecord<Computer> machines[1000];
GenericRecord<Building> physicalStructures[1000];



inventory[0].setIdentifier(1);
cout << inventory[0].getRecord().Identifier << endl;

inventory[0].setDescription("wapples");
cout << inventory[0].getRecord().Description << endl;

inventory[0].setValue(1.22);
cout << inventory[0].getRecord().Value << endl;



physicalStructures[0].setIdentifier("bacon");
cout << physicalStructures[0].getRecord().Identifier << endl;

physicalStructures[0].setDescription("yum!");
cout << physicalStructures[0].getRecord().Description << endl;

physicalStructures[0].setValue(1.22);
cout << physicalStructures[0].getRecord().Value << endl;

/*
Write loops that input data from the keyboard and
calls the mutator functions of the array objects to insert the data
in the array objects.
*/

// write a loop that inputs data into the each array
int answer;
while (answer != 4){
  // Display Menu
  cout << "Welcome to the program\n"
       << "Choose a ";
  // End Menu
}



/*
Write loops that iterate through the arrays to call the accessor and get
the data then display it in table form (three tables one for furniture,
one for computers, and one for buildings). The table should be formatted
using iomanip functions and flags (see projects 1 and 2).
*/

// write a loop that iterates through the array and displays it in a table
//
// ie.
//                        Furniture
// Index     Identifier   Description   Value
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8




  cout << endl; //Command line style
}
