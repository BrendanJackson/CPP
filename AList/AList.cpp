#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
const int MLS = 50;
typedef int element;
const element SENTINEL = -1;
const string ELEMENT_NAME = "whole number";
element read_element();
class AList{
	private:
		element items[MLS];
		int size;
		void Swap(int pos1, int pos2);
		bool found;
	public:
    int randomLimitLow;
    // int randomLimitHigh;
    string current_order;
    void Bootstrap();
		void Read();
		void Print();
    void Menu();
    int ReadMenu();
    void GenerateRandom();
    int ReadRandomAmount();
    int ReadRandomLimitLow();
    void ReadRandomLimitHigh(int randomLimitLow, int & randomLimitHigh);
    void ReadRandom(int randomAmount, int randomLimitLow, int randomLimitHigh);
		void BubbleSort();
		void ReverseBubbleSort();
		void InsertionSort();
		void SelectionSort();
    void CallLinearSearch();
		void LinearSearch(element target, bool & found, int & position);
    void CallBinarySearch();
		void BinarySearch(element target, bool & found, int & position);
	};

int main(){
	AList A;
  
  A.Bootstrap();
	// bool found = false;
	// int position = 7;
	// //target is 7 adjust to whatever or go at it indirectly
	// A.LinearSearch(7, found, position);
	// cout << "\nlinear search ran!\n" << "found: " << found << "\nposition: " << position <<endl ;

	
	// A.BinarySearch(5, found, position);
	// cout << "\nBinary search ran!\n" << "found: " << found << "\nposition: " << position <<endl ;
	}

  void AList::Bootstrap(){
      cout << "\n Sort and Search Demo Program, version 1.0 (c) 2017, Brendan Jackson\n" ;
      items[0] = -2;
      current_order = "NOT KNOWN";
      Menu();
    }

	void AList::Read(){
		//PRE: none
		//POST: The Native Object (N.O.) Alist is now valid, holding telements provided by the user
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

    void AList::ReadRandom(int randomAmount, int randomLimitLow, int randomLimitHigh){
    //PRE: none
    //POST: The Native Object (N.O.) Alist is now valid, holding telements provided by the user
    //create a list of numbers that is randomAmount long, each number must be between randomlimitlow and randomlimitihigh
    
    for(int i = 0; i < randomAmount; i++)
      while(items[i] > randomLimitLow || items[i] < randomLimitHigh)
        rand();
    }

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

  void AList::Menu(){
    int menu_choice;
    if(items[0] == -2)
      cout << "\nCurrent list: " << "(empty)" << " (" << current_order << " to be ordered)\n"  ; 
    else {
      cout << "\nCurrent list: ";
       for (int i = 0; i < size; i++)
        cout << items[i] << " " ;
       cout << " (" << current_order << " to be ordered)\n\n"  ;
    }
         
    
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

    menu_choice = ReadMenu();   
    

    switch (menu_choice){
      //
      case 1: 
        Read();
        Menu();
        break;
      
      //
      case 2:
        AList::GenerateRandom();
        Menu();
        break; 
      
      //
      case 3: 
        BubbleSort();
        Menu();
        break;

      //
      case 4:
        InsertionSort();
        Menu();
        break;
      
      //
      case 5:
        SelectionSort();
        Menu();
        break;
      
      //
      case 6:
        CallLinearSearch();
        Menu();
        break;
      
      //
      case 7:
        CallBinarySearch();
        Menu();
        break;

      //
      case 8:
        cout << "\nQuitting Sort and Search Demo Program, version 1.0\n";
        break;
      }
      
        
      }

  void AList::GenerateRandom(){
    int randomAmount;
    int randomLimitHigh;
    current_order = "NOT KNOWN";
     // randomLimitHigh;
    // generate random number for rand()
    srand(int(time(0)));
  // cout << "Here is one random number: " << rand() << endl;
    cout << "\nResetting the current list using randomly generated elements.\n\n";
    
    randomAmount = ReadRandomAmount();
    randomLimitLow = ReadRandomLimitLow();
    ReadRandomLimitHigh(randomLimitLow,  randomLimitHigh);

    cout << "still passes, randomLimitHigh ===" << randomLimitHigh;
    ReadRandom(randomAmount, randomLimitLow, randomLimitHigh);
    // cout << "\n\nFinished resetting, " << randomAmount << " elements between " <<  randomLimitLow << " and " << randomLimitHigh << " randomly generated.\n\n";
  }

  int AList::ReadRandomAmount(){
      // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned

        int randomAmount;        // used to collect the user's input value
        cout << "Enter the desired number of elements (0 to 50): " ;

        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> randomAmount;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || randomAmount < 0 || randomAmount > 50) {

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
                cin >> boolalpha >> randomAmount;
                }

        // return the valid element value given by the user
        return randomAmount;
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
    
  void AList::ReadRandomLimitHigh(int randomLimitLow, int & randomLimitHigh){
      // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
      // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //  value entered will be returned
        // int randomLimitHigh;        // used to collect the user's input
                                // value
        cout << "Enter the upper limit of the range (" << randomLimitLow << " to 2147483646): " ;
        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> randomLimitHigh;
        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good() || randomLimitHigh < randomLimitLow || randomLimitHigh > 2147483646) {

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
                  cout << "Invalid range type, should be within " << randomLimitLow << " and 2147483646, try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                  cout << "2nd cin statement";
                cin >> randomLimitHigh;
                }
        cout << "2nd cin pass";
        // return the valid element value given by the user
        // return randomLimitHigh;
    }

	void AList::BubbleSort(){
		// PRE: The N.O. AList is valid
		// POST: The N.O. AList is unchanged, except that its elements are now in ascending order
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
      cout << "\nPerforming Bubble Sort on the current list.\n";
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
      cout << "\nPerforming Bubble Sort on the current list.\n";
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
            actualComparisons++;
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