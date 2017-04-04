#include <iostream>
using namespace std;

typedef int element;
const int MLS = 50; //MAx list size
const element SENTINEL = -1;
const string ELEMENT_NAME = "Whole Number";
element read_element();

//Class declaration
class AList{
	private:
		element items[MLS];
		int size;
		void Swap(int pos1, int pos2);
	public:
		void Read();
		void Print();
		void BubbleSort();
		void ReverseBubbleSort();


		void LinearSearch();
};

int main(){
AList A;

//Reads numbers form the user into the list
cout << "get user input with read method";
A.Read();

cout << "\nPrint the list now\n";
A.Print();
cout << "\nSort the list in ascending order and print\n";
A.BubbleSort();
A.Print();

cout << "\nSort the list in descending order and print\n";
A.ReverseBubbleSort();
A.Print();

cout << "\n choose a number to search for\n";
A.LinearSearch();
A.Print();

}

element read_element() {
        element userval;        // used to collect the user's input
     
        cin >> boolalpha >> userval;

        while (! cin.good()) {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invalid data type, should be an element ("
                        << ELEMENT_NAME
                        << "), try again: ";

                cin >> boolalpha >> userval;
                }
        return userval;
        }

void AList::Read(){
	element userval;

	size = 0;
	cout << "Enter numbers, " << SENTINEL << " will end this sequence: ";
	userval = read_element();

	while ((userval != SENTINEL) && (size < MLS)){
			items[size] = userval;

			size++;
			if (size < MLS )
				//runs read_element(), userval = result
				userval = read_element();
			else
				cout << "List is now full, ending input" << endl;
	}

}

void AList::Print(){
	for(int i = 0; i < size; i++)
		cout << items[i] << endl;
}

void AList::Swap(int pos1, int pos2){
	element temp;
	temp = items[pos1];
	items[pos1] = items[pos2];
	items[pos2] = temp;
}


/*************************
*********SORTS************
*************************/
void AList::BubbleSort(){
	//size is the size of the current list
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size - 1 - i; j++)
			if(items[j] > items[j + 1])
				Swap(j, j + 1);
}

void AList::ReverseBubbleSort(){
	for(int i = 0; i < size - 1; i++)
		for(int j = 0; j < size - 1 - i;j++)
			if(items[j] < items[j + 1])
				Swap(j, j + 1);
}

/****************************
*********SEARCHES************
*****************************/
void AList::LinearSearch(){
	int target;


	target = read_element();
	for(int i = 0; i < size -1; i++)
		if(items[i] == target)
			cout << "\ntarget: " << target << " found at position " << items[i];


}

