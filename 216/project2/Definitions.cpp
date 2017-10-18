/*
  |--------------------------------------------------------------------------
  | Project #2 Definitions
  |--------------------------------------------------------------------------
  |
  | Brendan Jackson
  | 10/05/2017
  | CS216
  |
  | This option controls the default authentication "guard" and password
  | reset options for your application. You may change these defaults
  | as required, but they're a perfect start for most applications.
  |
  */

#include "Declarations.h"

/* SalesSlip
************************/
SalesSlip::SalesSlip()
{
  const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));
    date = s;
}
void SalesSlip::getDate()
{
  cout << date;
}
void SalesSlip::displayMenu()
{

  cout << "\nWelcome to the sales site, would you like to fill out a sales slip?\n"
       << "\nChoose one of the 4 members, view the sales summary, or exit the program";
  if (counterSarah < 5)
    cout << "\n1 for Sarah";
  if (counterJesse < 5)
    cout << "\n2 for Jesse";
  if (counterBreanna < 5)
    cout << "\n3 for Breeanna";
 if (counterBrittany < 5)
    cout << "\n4 for Brittany";

    cout << "\n5 to view the summary and quit the program\n";
}
void SalesSlip::setMenuSelection()
{
  int sarahOff = 0;
  int jesseOff = 0;
  int breannaOff = 0;
  int brittanyOff = 0;

  cin >> menuSelection;
  if (counterSarah >= 5)
    sarahOff = 1;
  if (counterJesse >= 5)
    jesseOff = 2;
  if (counterBreanna >= 5)
    breannaOff = 3;
  if (counterBrittany >= 5)
    brittanyOff = 4;

  while (! cin.good() || menuSelection < 1 || menuSelection > 6 || menuSelection == sarahOff
  || menuSelection == jesseOff || menuSelection == breannaOff || menuSelection == brittanyOff){
    cin.clear();
    cin.ignore(80, '\n');
    if(!cin.good()){
      cout << "\nInvalid data type, should be an integer, try again:";

    } else
    cout << "\nInvalid selection, please choose from these menu items: ";

    if (counterSarah < 5)
      cout << "\n1 for Sarah";
    if (counterJesse < 5)
      cout << "\n2 for Jesse";
    if (counterBreanna < 5)
      cout << "\n3 for Breeanna";
   if (counterBrittany < 5)
      cout << "\n4 for Brittany";

      cout << "\n5 to view the summary and quit the program\n";

    cin >> boolalpha >> menuSelection;
  }//end while
}
int SalesSlip::getMenuSelection()
{
  return menuSelection;
}
void SalesSlip::userCounter(int answer)
{
  if (getSalesPersonID() == 1 && answer == 0)
    counterSarah = 5;
  else if (getSalesPersonID() == 1)
    counterSarah++;
  else if (getSalesPersonID() == 2 && answer == 0)
    counterJesse = 5;
  else if (getSalesPersonID() == 2)
    counterJesse++;
  else if (getSalesPersonID() == 3 && answer == 0)
    counterBreanna = 5;
  else if (getSalesPersonID() == 3)
    counterBreanna++;
  else if (getSalesPersonID() == 4 && answer == 0)
    counterBrittany = 5;
  else if (getSalesPersonID() == 4)
    counterBrittany++;

}
void SalesSlip::setSalesPersonID(int choice)
{
  salesPersonID = choice;
}
double SalesSlip::getSalesPersonID()
{
  return salesPersonID;
}
void SalesSlip::setProductID()
{
  cin >> boolalpha >> productID;

  // repeat the following as long as this attempt failed,
  //presumably because the data type of the user's input was not an element
  while (! cin.good() || productID < 1 || productID > 5) {

    // re-enable the just-disabled cin object
    cin.clear();

    // from the input buffer,
    //discard up to 80 keystrokes or
    // until the enter key is seen, whichever comes first
    cin.ignore(80, '\n');

    // tell the user what happened, and to try again
    if(!cin.good())
      cout << "Invalid data type, should be an element, try again: ";
    else
      cout << "Invalid range type, should be within 1 and 5, try again: ";

    // attempt to get an input value whose data type is an element
    //
    // the boolalpha manipulator is used
    //  in case elements are bools, to allow
    //for inputs using the keystroke
    // sequences of "true" and "false" instead of "1" and "0"
    cin >> boolalpha >> productID;
    }

}
double SalesSlip::getProductID()
{
  return productID;
}
void SalesSlip::setProductPrice()
{
  cin >> boolalpha >> productPrice;

  // repeat the following as long as this attempt failed,
  //presumably because the data type of the user's input was not an element
  while (! cin.good() || productPrice < 0.00 || productPrice > 100000000) {

    // re-enable the just-disabled cin object
    cin.clear();

    // from the input buffer,
    //discard up to 80 keystrokes or
    // until the enter key is seen, whichever comes first
    cin.ignore(80, '\n');

    // tell the user what happened, and to try again
    if(!cin.good()){
      cout << "Invalid data type, should be a double, try again: ";
      } else
      cout << "Invalid range type, should be within 0.00 and 100000000, try again: ";

    // attempt to get an input value whose data type is an element
    //
    // the boolalpha manipulator is used
    //  in case elements are bools, to allow
    //for inputs using the keystroke
    // sequences of "true" and "false" instead of "1" and "0"
    cin >> boolalpha >> productPrice;
    }

}
double SalesSlip::getProductPrice()
{
  return productPrice;
}



/* Sales
************************/
Sales::Sales()
{
  for(int i=0;i<20;i++)
    for(int j=0;j<20;j++)
      salesSlipSummary[20][3] = "";
}
void Sales::setSalesSlipContainer(SalesSlip slip)
{
  static int i = 0;
  salesSlipContainer[i] = slip;

  if (slip.getSalesPersonID() == 1)
    salesSlipSummary[i][0] = "Sarah";
  else if (slip.getSalesPersonID() == 2)
    salesSlipSummary[i][0] = "Jesse";
  else if (slip.getSalesPersonID() == 3)
    salesSlipSummary[i][0] = "Breanna";
  else if (slip.getSalesPersonID() == 4)
    salesSlipSummary[i][0] = "Brittany";

  if (slip.getProductID() == 1)
    salesSlipSummary[i][1] = productNames[0];
  else if (slip.getProductID() == 2)
    salesSlipSummary[i][1] = productNames[1];
  else if (slip.getProductID() == 3)
    salesSlipSummary[i][1] = productNames[2];
  else if (slip.getProductID() == 4)
    salesSlipSummary[i][1] = productNames[3];
  else if (slip.getProductID() == 5)
    salesSlipSummary[i][1] = productNames[4];

  stringstream productPrice;
  productPrice << fixed << setprecision(2) << slip.getProductPrice();
  salesSlipSummary[i][2] = productPrice.str();
  i++;
}
void Sales::getTotals()
{
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;
  for(int i=0;i <= 20;i++){
    if (salesSlipSummary[i][0] == "Sarah"){
      sarahRow = i;
      sarahTotal[j] = stod(salesSlipSummary[i][2]);;
      j++;
    }
    else if (salesSlipSummary[i][0] == "Jesse"){
      jesseRow = i;
      jesseTotal[k] = stod(salesSlipSummary[i][2]);
      k++;
    }
    else if (salesSlipSummary[i][0] == "Breanna"){
      breannaRow = i;
      breannaTotal[l] = stod(salesSlipSummary[i][2]);
      l++;
    }
    else if (salesSlipSummary[i][0] == "Brittany"){
      brittanyRow = i;
      brittanyTotal[m] = stod(salesSlipSummary[i][2]);
      m++;
    }
  }

}
void Sales::getSalesSlipSummary()
{
  double sarahGrandTotal;
  double jesseGrandTotal;
  double breannaGrandTotal;
  double brittanyGrandTotal;

  cout << "\nDOODAD THIRD QUARTER 2016 SALES REPORT" << endl
       << setw(18) << left << "SALES PERSON" << setw(14) << "PRODUCT"
       << setw(11) << right << "AMOUNT" << setw(11) << "TOTAL" << endl;

  cout << setw(18) << left << "-----------------"
       << setw(14) << "-------------"
       << setw(11) << right << "----------"
       << setw(11) << "----------";

  for (int i = 0;i <= 20;i++){
    cout << endl;
    sarahGrandTotal = sarahTotal[0]+sarahTotal[1]+sarahTotal[2]+sarahTotal[3]+sarahTotal[4];
    jesseGrandTotal = jesseTotal[0]+jesseTotal[1]+jesseTotal[2]+jesseTotal[3]+jesseTotal[4];
    breannaGrandTotal = breannaTotal[0]+breannaTotal[1]+breannaTotal[2]+breannaTotal[3]+breannaTotal[4];
    brittanyGrandTotal = brittanyTotal[0]+brittanyTotal[1]+brittanyTotal[2]+brittanyTotal[3]+brittanyTotal[4];

    cout << setw(18) << left << salesSlipSummary[i][0]
         << setw(14) << salesSlipSummary[i][1]
         << setw(11) << right << salesSlipSummary[i][2];


    if (i != sarahRow && i != jesseRow && i != breannaRow && i != brittanyRow)
      cout << setw(11) << "";
    else if (i == sarahRow){
      getTotals();
      cout << setw(11) << setprecision(2) << fixed << sarahGrandTotal;
    }
    else if (i == jesseRow){
      getTotals();
      cout << setw(11) << setprecision(2) << fixed << jesseGrandTotal;
    }
    else if (i == breannaRow){
      getTotals();
      cout << setw(11) << setprecision(2) << fixed << breannaGrandTotal;
    }
    else if (i == brittanyRow){
      getTotals();
      cout << setw(11) << setprecision(2) << fixed << brittanyGrandTotal;
    }

  }


}
// string Sales::getSalesPersons()
// {
//   // return salesPersons;
// }
// string Sales::setSalesPersons()
// {
// }
// string Sales::setProductNames()
// {
// }
// string Sales::getProductNames()
// {
//   return productNames[0];
// }
