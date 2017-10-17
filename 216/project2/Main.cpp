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
      sales.setSalesSlipSummary( SalesSlip::salesRepresentativesInfo );
      sales.getSalesSlipSummary();
      exit(0);
    }
    slip1.setSalesPersonID( slip1.getMenuSelection() );
    cout << "\nI made it out of the setsales get menu selection dealio";
// !TODO <CODE>is caught somewhere in while, searching for solution</CODE>
    int slipCount = 0;
    do {
      SalesSlip::salesRepresentativesInfo[i][0] = slip1.getSalesPersonID();

      cout << "\nWhat is your product ID (1-5)? ";
      slip1.setProductID();
      SalesSlip::salesRepresentativesInfo[i][1] = slip1.getProductID();

      cout << "\nHow much total sales did you earn from the product? ";
      slip1.setProductPrice();
      SalesSlip::salesRepresentativesInfo[i][2] = slip1.getProductPrice();

      // !TODO if user selects no, personCounter = 5;


      slipCount++;
      if(slipCount < 5){
        cout << "\nWould you like to fill out another slip for this user?"
           << "\nType \"y\" for yes and \"n\" for no ";
        cin >> answer;
      }
      slip1.userCounter(answer);
    } while (slipCount < 5 && answer == 'y');
  }




  cout << endl;
}
