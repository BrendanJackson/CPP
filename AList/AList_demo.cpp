#include <iostream>

using namespace std;
const int MLS = 10;

class AList{
	private:
		
		void Swap(int pos1, int pos2);
	public:
		int test_list[MLS];
		int size;
		int items[MLS];
		void BubbleSort();
	};

int main(){
	AList A;
	
	A.BubbleSort();
}

void AList::BubbleSort(){
	// items[MLS] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	size = 10;
	test_list[MLS] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	for(int i = 0; i < size -1; i++){
		for(int j = 0; j < size - 1 - i; j++)
			if(test_list[j] > test_list[j + 1])
				Swap(j, j + 1);
					 cout << test_list[0] << test_list[1] << test_list[2] << test_list[3] << test_list[4] << test_list[5] << test_list[6] << test_list[7] << test_list[8] << test_list[9] << endl;
		}
				 cout << test_list[0] << test_list[1] << test_list[2] << test_list[3] << test_list[4] << test_list[5] << test_list[6] << test_list[7] << test_list[8] << test_list[9] << endl;
	}
void AList::Swap(int pos1, int pos2){
	int temp = test_list[pos1];
	test_list[pos1] = test_list[pos2];
	test_list[pos2] = temp;
	}
