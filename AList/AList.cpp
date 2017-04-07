/*
* Brendan Jackson
* "CS215-J1E1" 
* Spring 2017
* "Programming Assignment #1"
* This program Creates a list using two seperate methods,
* sorts by a number of methods,
* and searches by a couple of methods as well
*/
//Basic Library, primarily used for the cin and cout statemnts
#include <iostream>
//Gives us the epoch calendar used for the rand()
#include <ctime>
//used fo random number generation
#include <cstdlib>
//prvents calling std on every operation
using namespace std;
//to be used to limit the size of our list to 50
const int MLS = 50;
//indirect datatype for future use
typedef int element;
//Sentinel used to end input on Read method
const element SENTINEL = -1;
//constant string
const string ELEMENT_NAME = "whole number";
//reads any data type you choose to set it as
element read_element();

//Class used for creating and sorting a list of 50 integers or less
class AList{
  //defines members that cannot be edited outsid of the class
	private:
    //declaers and defines a list with a maximum size of MLS
		element items[MLS];
    //declares and defines the variable size
		int size;
    //declaeres and defines the swap function (changes list order)
		void Swap(int pos1, int pos2);
    //declares and defines the variable found, used when searching a list
		bool found;
    //declares and defines a variable to be used with random number generation
    int randomLimitLow;
    //declares and defines a variable to be used with as an indicator for the list being ordered
    string current_order;
	
  //defines members that can be edited outside of the class
  public:
    //Used to start and setup the program
    void Bootstrap();
    //method used to get get list values
		void Read();
    //method used to print the list
		void Print();
    //method used to print the list
    void Menu();
    //method used to get the users menu selction
    int ReadMenu();
    //method used to generate a random number on menu selection 2
    void GenerateRandom();
    //method used to get the size of the random list 
    int ReadRandomSize();
    //method used to get the lower range of the random list
    int ReadRandomLimitLow();
    //method used to get the upper range of the random list
    int ReadRandomLimitHigh();
    //method used to calculate the random numbers generated
    void ReadRandom(int randomRange, int randomLimitLow, int randomLimitHigh);
    //1 of 3 methods used to sort the list 
		void BubbleSort();
    //2 of 3 methods used to sort the list 
		void InsertionSort();
    //3 of 3 methods used to sort the list 
		void SelectionSort();
    //method used to setup a linear search on list
    void CallLinearSearch();
    //method used to perform the linear search on the list
		void LinearSearch(element target, bool & found, int & position);
    //method used to setup a Binary search on list
    void CallBinarySearch();
    //method used to perform the Binary search on the list
		void BinarySearch(element target, bool & found, int & position);
    //Method used to prevent unecessary sorting of the list
    void OrderCheck();
	};

//Main function used to declare object and use all methods
int main(){
  //Instantiates AList class to "A"
	AList A;
  //calls bootstrap method
  A.Bootstrap();
	}

//Starts program
void AList::Bootstrap(){
  //PRE: none
  //POST: The Native Object (N.O.) Alist will now recieve data
  //Startup notification for the user
  cout << "\n Sort and Search Demo Program, version 1.0 (c) 2017, Brendan Jackson\n" ;
  //Sets a marker of -2 if the list is not used, to prevent unecessary calls later
  items[0] = -2;
  //Sets a marker of "NOT KNOWN" to prevent unecessary calls later
  current_order = "NOT KNOWN";
  //Sets up the random seed based on epoch calendar
  srand(int(time(0)));
  //Calls the menu
  Menu();
  }
  
//Displays the menu a long with information on the current list
void AList::Menu(){
  //A variable used to store the users menu selection
  int menu_choice;
  //Conditional set to check if the list is empty or not
  if(items[0] == -2)
    //output of empty list conditional
    cout << "\nCurrent list: " << "(empty)" << " (" << current_order << " to be ordered)\n"  ; 
  else {
    //output of non-empty list
    cout << "\nCurrent list: ";
    if(size < 10){
      for (int i = 0; i < size; i++)
        cout << items[i] << " " ;
      } else {
    //lists larger than 10 will be organized, breaking the line every 10th list item.    
      cout << "\n";
      for (int i = 0; i < size; i++){
        cout << items[i] << " " ;
        if(i == 9 || i == 19 || i == 29 || i == 39)
          cout << "\n";
        }
        cout << "\n";
      }

      
      cout << " (" << current_order << " to be ordered)\n\n"  ;
  }
       
  //Displays a list of options and their uses for the user
  cout << "Actions:\n"
       << "1. Reset the current list from the keyboard\n"
       << "2. Reset the current list using randomly generated elements\n"
       << "3. Perform Bubble Sort on the current list\n"
       << "4. Perform Insertion Sort on the current list\n"
       << "5. Perform Selection Sort on the current list\n"
       << "6. Perform Linear Search on the current list\n"
       << "7. Perform Binary Search on the current list\n"
       << "8. Quit the program\n"
       << "Choose an action:\n";
  //Gets the user input and saves it, used to later call on the operations the user selected
  menu_choice = ReadMenu();   
  
  // reads user input listed above and calls the corresponding methods the user requested
  switch (menu_choice){
    //Calls the Read Method, when it is finished running, the user is sent back to the menu
    case 1: 
      Read();
      Menu();
      break;
    
    //Calls the GenerateRandom Method, when it is finished running, the user is sent back to the menu
    case 2:
      GenerateRandom();
      Menu();
      break; 
    
    //Calls the BubbleSort Method, when it is finished running, the user is sent back to the menu
    case 3: 
      BubbleSort();
      Menu();
      break;

    //Calls the InsertionSort Method, when it is finished running, the user is sent back to the menu
    case 4:
      InsertionSort();
      Menu();
      break;
    
    //Calls the SelctionSort Method, when it is finished running, the user is sent back to the menu
    case 5:
      SelectionSort();
      Menu();
      break;
    
    //Calls the CallLinearSearch Method, when it is finished running, the user is sent back to the menu
    case 6:
      CallLinearSearch();
      Menu();
      break;
    
    //Calls the CallBinaryrSearch Method, when it is finished running, the user is sent back to the menu
    case 7:
      CallBinarySearch();
      Menu();
      break;

    //Gives the user a final message and ends the program
    case 8:
      cout << "\nQuitting Sort and Search Demo Program, version 1.0\n";
      break;
    }
    
      
  }

//This method takes in the users input for the menu,
//types and range checks it, then returns the result, selecting the next method to be called
int AList::ReadMenu(){
      int menu_choice;
      cin >> boolalpha >> menu_choice;

          // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
          while (! cin.good() || menu_choice < 1 || menu_choice > 8) {

                  // re-enable the just-disabled cin object
                  cin.clear();

                  // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                  cin.ignore(80, '\n');

                  // tell the user what happened, and to try again
                  if(!cin.good()){
                    cout << "Invalid data type, should be an element ("
                          << ELEMENT_NAME
                          << "), try again: ";
                    } else
                    cout << "Invalid range type, should be within 1 and 8, try again: ";
                    
                  // attempt to get an input value whose data type is an element
                  //
                  // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                  // sequences of "true" and "false" instead of "1" and "0"
                  cin >> boolalpha >> menu_choice;
                  }

          // return the valid element value given by the user
          return menu_choice;
    }




  void AList::Print(){
    //PRE: The N.O. AUist is valid
    //POST: The N.O. AList is unchanged, and its elements have been displaed to the user
    for (int i = 0; i < size; i++)
      cout << items[i] << endl;
    } 

void AList::Read(){
  //PRE: none
  //POST: The Native Object (N.O.) Alist is now valid, holding elements provided by the user
  element userval;
  current_order = "NOT KNOWN";
  size = 0;
  cout << "Enter elements, " << SENTINEL << " to stop: ";
  userval = read_element();
  while ((userval != SENTINEL) && (size < MLS)){
    items[size] = userval;
    size++;
    if (size < MLS )
      userval = read_element();
    else
      cout << "List is now full, ending input" << endl;
    }
  //if the list is only a single number, it should be considered ordered because there is nothing to sort
  if(size == 1)
    current_order = "KNOWN";
  }

   element read_element() {
        // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned
        element userval;        // used to collect the user's input value
                                
        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> userval;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || userval < -1 || userval > 2147483647) {

                // re-enable the just-disabled cin object
                cin.clear();

                // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                cin.ignore(80, '\n');

                // tell the user what happened, and to try again
               if(!cin.good()){
                  cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";
                  } else
                  cout << "Invalid range type, should be within -1 and 2147483647, try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                cin >> boolalpha >> userval;
                }

        // return the valid element value given by the user
        return userval;
    }


  void AList::GenerateRandom(){
    int randomLimitHigh;
    current_order = "NOT KNOWN";
     // randomLimitHigh;
    // generate random number for rand()
    
  // cout << "Here is one random number: " << rand() << endl;
    cout << "\nResetting the current list using randomly generated elements.\n\n";
    
    size = ReadRandomSize();

    randomLimitLow = ReadRandomLimitLow();

    randomLimitHigh = ReadRandomLimitHigh();

    ReadRandom(size, randomLimitLow, randomLimitHigh);

    if(size == 1)
      current_order = "KNOWN";
  }

  int AList::ReadRandomSize(){
      // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned

        int randomRange;        // used to collect the user's input value
        cout << "Enter the desired number of elements (0 to 50): " ;

        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> randomRange;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || randomRange < 0 || randomRange > 50) {

                // re-enable the just-disabled cin object
                cin.clear();

                // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                cin.ignore(80, '\n');

                // tell the user what happened, and to try again
               if(!cin.good()){
                  cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";
                  } else
                  cout << "Invalid range type, should be within 0 and 50, try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                cin >> boolalpha >> randomRange;
                }

        // return the valid element value given by the user
        return randomRange;
    }
  
  int AList::ReadRandomLimitLow(){
      // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned
        int randomLimitLow;        // used to collect the user's input
                                // value
        cout << "Enter the lower limit of the range (0 to 2147483646): " ;
        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> randomLimitLow;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || randomLimitLow < 0 || randomLimitLow > 2147483646) {

                // re-enable the just-disabled cin object
                cin.clear();

                // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                cin.ignore(80, '\n');

                // tell the user what happened, and to try again
               if(!cin.good()){
                  cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";
                  } else
                  cout << "Invalid range type, should be within 0 and 2147483646, try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                cin >> boolalpha >> randomLimitLow;
                }

        // return the valid element value given by the user
        return randomLimitLow;
    }

  int AList::ReadRandomLimitHigh(){
       // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned
        int randomLimitHigh;        // used to collect the user's input
                                // value
        cout << "Enter the upper limit of the range (0 to 2147483647): " ;
        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> randomLimitHigh;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || randomLimitHigh < 0 || randomLimitHigh > 2147483647) {

                // re-enable the just-disabled cin object
                cin.clear();

                // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                cin.ignore(80, '\n');

                // tell the user what happened, and to try again
               if(!cin.good()){
                  cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";
                  } else
                  cout << "Invalid range type, should be within 0 and 2147483646, try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                cin >> boolalpha >> randomLimitHigh;
                }

        // return the valid element value given by the user
        return randomLimitHigh;
    }

  
    //Takes in range limits for the GenerateRandom method and creates a list with the given parameters 
    void AList::ReadRandom(int size, int randomLimitLow, int randomLimitHigh){
    //PRE: none
    //POST: The Native Object (N.O.) Alist is now valid, holding telements provided by the user
    //create a list of numbers that is randomRange long, each number must be between randomlimitlow and randomlimitihigh
    int random;
    for(int i = 0; i < size; i++){
      random = (rand() % (randomLimitHigh - randomLimitLow + 1)) + randomLimitLow;
      items[i] = random;  
      }
     
    }

	void AList::BubbleSort(){
		// PRE: The N.O. AList is valid
		// POST: The N.O. AList is unchanged, except that its elements are now in ascending order
    OrderCheck();
    cout << "\nPerforming Bubble Sort on the current list.\n";
    int theoreticalComparisons;
    int theoreticalMoves;
    int actualComparisons;
    int actualMoves;

    theoreticalComparisons = 2 * (size * size) ;
    theoreticalMoves = ((3 * (size * size) - size) / 2);
    actualComparisons = 0;
    actualMoves = 0;
    
		for(int i = 0; i < size - 1; i++){
      actualComparisons++;
      for (int j = 0; j < size - 1 -i; j++){
        actualComparisons++;
        if(items[j] > items[j + 1]){
          actualComparisons++;
          Swap(j,j+1);
          actualMoves += 3;
          }else{};
        }
        
      }
			
					

    cout << "\nTheoretical sort statistics: " << theoreticalComparisons << " element comparisons, " << theoreticalMoves << " element movements\n";
    cout << "Actual sort statistics: " << actualComparisons << " element comparisons, " << actualMoves << " element movements\n"; 

    current_order = "KNOWN";
		}

	void AList::Swap(int pos1, int pos2){
		//PRE: The N.O. AUist is valid
		//	0 <= pos1 < size
		//	0 <= pos2 < size
		//POST: The N.O. AList is unchanged, except that the two elements previously in positions pos1 and pos2 havn been swapped
		element temp;

		temp = items[pos1];
		items[pos1] = items[pos2];
		items[pos2] = temp;
		}
	

    void AList::InsertionSort(){
    	//PRE: The N.O. AList is valid
    	//POST: The N.O. Alist is unchanged, except that its elements are now in ascending order
      OrderCheck();
      cout << "\nPerforming Insertion Sort on the current list.\n";
    	int j;
    	bool done;

      int theoreticalComparisons;
      int theoreticalMoves;
      int actualComparisons;
      int actualMoves;

      theoreticalComparisons = 2 * (size * size) ;
      theoreticalMoves = ((3 * (size * size) - size) / 2);
      actualComparisons = 0;
      actualMoves = 0;

    	for(int i = 1; i < size; i++){
    		j = i;
    		done = false;
        actualComparisons++;
    		while((j >= 1) && (! done)){
          actualComparisons++;
    			if(items[j] < items[j - 1]){
    				Swap(j, j - 1);
            actualMoves++;
            actualComparisons++;
    				j -= 1;
    				}
    			else
    				done = true;
    			}
    		}
       	
      cout << "\nTheoretical sort statistics: " << theoreticalComparisons << " element comparisons, " << theoreticalMoves << " element movements\n";
      cout << "Actual sort statistics: " << actualComparisons << " element comparisons, " << actualMoves << " element movements\n"; 
      current_order = "KNOWN";
     	}

    void AList::SelectionSort(){
    	//PRE: the N.O. AList is valid
    	//Post: the N.O. Alist is unchanged, except that its elements are now in ascending order
      OrderCheck();
      cout << "\nPerforming Selection Sort on the current list.\n";
    	int maxpos;

      int theoreticalComparisons;
      int theoreticalMoves;
      int actualComparisons;
      int actualMoves;

      theoreticalComparisons = 2 * (size * size) ;
      theoreticalMoves = ((3 * (size * size) - size) / 2);
      actualComparisons = 0;
      actualMoves = 0;

    	for(int i = size - 1; i > 0; i--){
    		maxpos = 0;
        actualComparisons++;
    		for(int j = 1; j <= i; j++){
          actualComparisons++;
          if (items[j] > items[maxpos]){
            actualComparisons++;
            maxpos = j;
          } else
            actualMoves++;
          Swap(maxpos, i);
        }
    			
    	}

    cout << "\nTheoretical sort statistics: " << theoreticalComparisons << " element comparisons, " << theoreticalMoves << " element movements\n";
    cout << "Actual sort statistics: " << actualComparisons << " element comparisons, " << actualMoves << " element movements\n"; 
    current_order = "KNOWN";
    }

    void AList::CallLinearSearch(){
      element target;
      bool found;
      int position;

        if(items[0] == -2){
          cout << "\nPlease create a list and retry.\n";
          Menu();
          } else {
            cout << "\nPerforming Linear Search on the current list.\n\n" 
                 << "Enter a target element to search for: ";
            target = read_element();
            LinearSearch(target, found, position);
          }
      }

  	void AList::LinearSearch(element target, bool & found, int & position){
     			// PRE: The N.O. AList is valid
       		//POST: the N.O. AList is unchanged, and if target exists on the N.O. AlistY found will be true, 
       		//and position will be a location of the target on the N.O. AList otherwise found will be false, and position will be undefined
          int theoreticalComparisons;
          int actualComparisons;


       		found = false;
       		position = 0; 
       		while((! found) && (position < size))
       			if (target == items[position])
       				found = true;
       			else
       				position++;

            theoreticalComparisons = size;
            actualComparisons = position + 1;

           if(!found){
              cout << "The target was not in the list, please try again\n";
            } else { 
           		 cout << "\nThe target was FOUND on the current list in position " << position << ".\n"
                    << "Theoretical search statistics: " << theoreticalComparisons << " element comparisons\n"
                    << "Actual search statistics: " << actualComparisons << " element comparisons\n\n"
                    << "Finishing Linear Search.\n";
            }
       	}

  void AList::CallBinarySearch(){
    element target;
    bool found;
    int position;

      if(items[0] == -2){
        cout << "\nPlease create a list and retry.\n";
        Menu();
        } else if(current_order == "NOT KNOWN") {
          cout << "\nPlease place the list in order and retry.\n";
          Menu();
        } else  {
          cout << "\nPerforming Binary Search on the current list.\n\n" 
               << "Enter a target element to search for: ";
          target = read_element();
          BinarySearch(target, found, position);
        }
    }

     	void AList::BinarySearch(element target, bool & found, int & position){
       		// PRE: N.O. AList is valid, and its elements are in ascending order

       		// POST:the N.O. AList is unchanged, and: if the target exists on the E.O. AList: found will be true, andpositionie will be a location of the target on the N.O. AList otherwise found will be ffalse, and position will be undefined
          int theoreticalComparisons;
          int actualComparisons;

       		int low;
       		int high;
       		int mid;

          actualComparisons = 0;

       		low = 0;
       		high = size - 1;
       		found = false;
       		while ((! found) && (low <= high)){
       			mid = (low + high) / 2;
            actualComparisons++;
       			if (target == items[mid]){
       				found = true;
       				position = mid;
       			} else if (target < items[mid]){
       				high = mid - 1;
       			} else
       				low = mid + 1;
       		}

          theoreticalComparisons = 2 * (size /  size);
          
            if(!found){
              cout << "The target was not in the list, please try again\n";
             } else { 
              cout << "\nThe target was FOUND on the current list in position " << position << ".\n"
                   << "Theoretical search statistics: " << theoreticalComparisons << " element comparisons\n"
                   << "Actual search statistics: " << actualComparisons << " element comparisons\n"
                   << "Finishing Linear Search.\n";
              }
       	}
void AList::OrderCheck(){
  if(current_order == "KNOWN" && size == 1){
    cout << "\nSorry, but your list contains only one number, create another list if you would like to use a sort method";
    Menu();
    } else if(current_order == "KNOWN"){
    cout << "\nSorry, but your list is already in order, create another list if you would like to use a sort method";  
    Menu(); 
    } else
    ;
    
   
    
   
   
  }