#include <iostream>
/*
Sort and Search Demo Program, version 1.0
March 20th, 2017, Brendan Jackson
*/

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
	public:
		void Read();
		void Print();
		void BubbleSort();
		void InsertionSort();
		void SelectionSort();
		void LinearSearch(element target, bool & found, int & position);
		void BinarySearch(element target, bool & found, int & position);
	};

int main(){
	AList A;

	cout << "Current list: " ; //(empty) (KNOWN to be ordered)
	
	cout << "Actions: \n" 
		 << "1. Reset the current list from the keyboard \n"
		 << "2. Reset the current list using randomly generated elements\n"
		 << "3. Perform Bubble Sort on the current list\n"
		 << "4. Perform Insertion Sort on the current list\n"
		 << "5. Perform Selection Sort on the current list\n"
		 << "6. Perform Linear Search on the current list\n"
		 << "7. Perform Binary Search on the current list\n"
		 << "8. Quit the program\n"
		<< "Choose an action: \n" ;

	switch(menu_selection){
		//reset current list from keyboard
		case 1: 
			break;
		//reset currnet list from randomly generated elements
		case 2: 
			break;
		//Perform Bubble Sort
		case 3: 
			break;
		//Perform Insertion Sort
		case 4: 
			break;
		//Perform Selection Sort
		case 5: 
			break;
		//Perform Linear Search
		case 6: 
			break;
		//Perform BinarySearch
		case 7: 
			break;
		//Quit
		case 8: 
			break;
	}


	cout << "Read:";
	A.Read();
	cout << "\nPrint:";
	A.Print();
	cout << "\nBubblesort:";
	A.BubbleSort();
	cout << "\nPrint:";
	A.Print();

	// generate random number for rand()
	srand(int(time(0)));
	cout << "Here is one random number: " << rand() << endl;
	
	}

	void AList::Read(){
		//PRE: none
		//POST: The Native Object (N.O.) Alist is now valid, holding telements provided by the user
		element userval;

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
	void AList::Print(){
		//PRE: The N.O. AUist is valid
		//POST: The N.O. AList is unchanged, and its elements have been displaed to the user
		for (int i = 0; i < size; i++)
			cout << items[i] << endl;
		}	

	void AList::BubbleSort(){
		// PRE: The N.O. AList is valid
		// POST: The N.O. AList is unchanged, except that its elements are now in ascending order
		for(int i = 0; i < size - 1; i++)
			for (int j = 0; j < size - 1 -i; j++)
				if(items[j] > items[j + 1])
					Swap(j,j+1);
				else
					;
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
		
		element read_element() {
        // PRE:  the user must enter a series of zero or more non-valid element values, followed by a valid element value
               
        
        // POST: all entered non-valid element values will be successfully discarded, and the first valid element
        //       value entered will be returned

        element userval;        // used to collect the user's input
                                // value

        // attempt to get an input value whose data type is an element
        
        // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke sequences of
        // "true" and "false" instead of "1" and "0"
        cin >> boolalpha >> userval;

        // repeat the following as long as this attempt failed, presumably because the data type of the user's input was not an element
        while (! cin.good()) {

                // re-enable the just-disabled cin object
                cin.clear();

                // from the input buffer, discard up to 80 keystrokes or until the enter key is seen, whichever comes first
                cin.ignore(80, '\n');

                // tell the user what happened, and to try again
                cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";

                // attempt to get an input value whose data type is an element
                //
                // the boolalpha manipulator is used in case elements are bools, to allow for inputs using the keystroke
                // sequences of "true" and "false" instead of "1" and "0"
                cin >> boolalpha >> userval;
                }

        // return the valid element value given by the user
        return userval;
        }

  void AList::InsertionSort(){
    	//PRE: The N.O. AList is valid
    	//POST: The N.O. Alist is unchanged, except that its elements are now in ascending order
    	int j;
    	bool done;
    	for(int i = 1; i < size; i++){
    		j = i;
    		done = false;
    		while((j >= 1) && (! done)){
    			if(items[j] < items[j - 1]){
    				Swap(j, j - 1);
    				j -= 1;
    				}
    			else
    				done = true;
    			}
    		}
       	}
