/*
  |--------------------------------------------------------------------------
  | Project #2 Main Function
  |--------------------------------------------------------------------------
  |
  | Brendan Jackson
  | 10/05/2017
  | CS216
  |
  | The main() function will instantiate an object of the Sales class and call the member functions as
  | follows
  | (a) input sales to fill the one-d array
  | (b) compute totals to fill the two-d array
  | (c) output table
  |
  */

#include "Declarations.h"
int counterSarah = 0;
int counterJesse = 0;
int counterBreanna = 0;
int counterBrittany = 0;

/* Main
************************/
int main()
{
  char answer;
  int i = 0; //array counter
  //!TODO why doesn't method chaining work here?
  Sales sales;
  SalesSlip slip1;

  while (slip1.getMenuSelection() < 5 || slip1.getMenuSelection() > 0){
    slip1.displayMenu();
    slip1.setMenuSelection();
    if (slip1.getMenuSelection() == 5){
      sales.getSalesSlipSummary();
      exit(0);
    }
    slip1.setSalesPersonID( slip1.getMenuSelection() );
    cout << "\nI made it out of the setsales get menu selection dealio";
// !TODO <CODE>is caught somewhere in while, searching for solution</CODE>
    int slipCount = 0;
    do {
      cout << "\nWhat is your product ID (1-5)? ";
      slip1.setProductID();

      cout << "\nHow much total sales did you earn from the product? ";
      slip1.setProductPrice();

      sales.setSalesSlipContainer(slip1);

      sales.getSalesSlipSummary();

      slipCount++;
      if(slipCount < 5){
        cout << "\nWould you like to fill out another slip for this user?"
           << "\nType \"y\" for yes and \"n\" for no ";
        cin >> answer;
      }
      slip1.userCounter(answer);
    } while (slipCount < 5 && answer == 'y');
  }


  // !TODO what does a more dirct route look like?

  cout << endl;
}
