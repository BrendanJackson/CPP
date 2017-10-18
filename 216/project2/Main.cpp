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
  int answer = -1;
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
    int slipCount = 0;
    do {
      cout << "\nWhat is your product ID (1-5)? ";
      slip1.setProductID();

      cout << "\nHow much total sales did you earn from the product? ";
      slip1.setProductPrice();

      sales.setSalesSlipContainer(slip1);

      slipCount++;
      if(slipCount < 5){
        cout << "\nWould you like to fill out another slip for this user?"
             << "\nType \"1\" for yes and \"0\" for no "
             << "\n(Choosing no will prevent you from accessing this user again).\n";
        cin >> boolalpha >> answer;

        // repeat the following as long as this attempt failed,
        //presumably because the data type of the user's input was not an element
        while (! cin.good() || answer < 0 || answer > 1) {
          // re-enable the just-disabled cin object
          cin.clear();

          // from the input buffer,
          //discard up to 80 keystrokes or
          // until the enter key is seen, whichever comes first
          cin.ignore(80, '\n');

          cout << "\ninvalid try again, "
               << "\nType \"1\" for yes and \"0\" for no "
               << "\n(Choosing no will prevent you from accessing this user again).\n";
          cin >> boolalpha >> answer;
        }
      }
      // prevents any one salesperson from having more than 5 slips.
      slip1.userCounter(answer);
    } while (slipCount < 5 && answer == 1);
  }


  // !TODO what does a more dirct route look like?

  cout << endl;
}
