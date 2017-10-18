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
double SalesSlip::salesRepresentativesInfo[20][3];

void SalesSlip::displayMenu(){

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
  cin >> menuSelection;
}
int SalesSlip::getMenuSelection()
{
  return menuSelection;
}
void SalesSlip::userCounter(char answer)
{
  if (getSalesPersonID() == 1)
    counterSarah++;
  else if (getSalesPersonID() == 1 && answer == 'n')
    counterSarah = 5;
  else if (getSalesPersonID() == 2)
    counterJesse++;
  else if (getSalesPersonID() == 2 && answer == 'n')
    counterJesse = 5;
  else if (getSalesPersonID() == 3)
    counterBreanna++;
  else if (getSalesPersonID() == 3 && answer == 'n')
    counterBreanna = 5;
  else if (getSalesPersonID() == 4)
    counterBrittany++;
  else if (getSalesPersonID() == 4 && answer == 'n')
    counterBrittany = 5;
}
void SalesSlip::setSalesRepresentativesInfo(double salesPersonID, double productID, double productPrice )
{
  static int i = 0;

  SalesSlip::salesRepresentativesInfo[i][0] = salesPersonID;
  SalesSlip::salesRepresentativesInfo[i][1] = productID;
  SalesSlip::salesRepresentativesInfo[i][2] = productPrice;
  i++;
}
double SalesSlip::getSalesRepresentativesInfo()
{

  // !TODO why does array bounds popup on the 2nd array but not the 1st?
  return salesRepresentativesInfo[20][2];
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
  cin >> productID;
}
double SalesSlip::getProductID()
{
  return productID;
}
void SalesSlip::setProductPrice()
{
  cin >> productPrice;
}
double SalesSlip::getProductPrice()
{
  return productPrice;
}
// void SalesSlip::setDateOfSale()
// {
//   get timestamp mm/dd/yyyy
// }
string SalesSlip::getDateOfSale()
{
  return dateOfSale;
}



/* Sales
************************/
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

  salesSlipSummary[i][1] = to_string(slip.getProductID());
  salesSlipSummary[i][2] = to_string(slip.getProductPrice());
  i++;
}
void Sales::getTotals()
{
  // how do I remove this from a loop?
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  for(int i=0;i <= 20;i++){
    if (salesSlipSummary[i][0] == "Sarah"){
      // cout << "\n<string>salesSlipSummary[i][2]: " << salesSlipSummary[i][2]
      //      << "\n<double>salesSlipSummary[i][2]: " << stod(salesSlipSummary[i][2]);
      // double price = stod(salesSlipSummary[i][2]);
      sarahRow = i;
      sarahTotal[j] = stod(salesSlipSummary[i][2]);;
      j++;
    }
    else if (salesSlipSummary[i][0] == "Jesse"){
      jesseTotal[k] = stod(salesSlipSummary[i][2]);
      jesseRow = i;
      k++;
    }
    else if (salesSlipSummary[i][0] == "Breanna"){
      breannaTotal[l] = stod(salesSlipSummary[i][2]);
      breannaRow = i;
      l++;
    }
    else if (salesSlipSummary[i][0] == "Brittany"){
      brittanyTotal[m] = stod(salesSlipSummary[i][2]);
      brittanyRow = i;
      m++;
    }
  }

}
void Sales::getSalesSlipSummary()
{

  cout << "\nDOODAD THIRD QUARTER 2016 SALES REPORT" << endl
       << setw(18) << left << "SALES PERSON" << setw(14) << "PRODUCT"
       << setw(11) << right << "AMOUNT" << setw(11) << "TOTAL" << endl;

  cout << setw(18) << left << "-----------------"
       << setw(14) << "-------------"
       << setw(11) << right << "----------"
       << setw(11) << "----------";

  for (int i = 0;i <= 20;i++){
    cout << endl;
    double sarahGrandTotal = sarahTotal[0]+sarahTotal[1]+sarahTotal[2]+sarahTotal[3]+sarahTotal[4];
    double jesseGrandTotal = jesseTotal[0]+jesseTotal[1]+jesseTotal[2]+jesseTotal[3]+jesseTotal[4];
    double breannaGrandTotal = breannaTotal[0]+breannaTotal[1]+breannaTotal[2]+breannaTotal[3]+breannaTotal[4];
    double brittanyGrandTotal = brittanyTotal[0]+brittanyTotal[1]+brittanyTotal[2]+brittanyTotal[3]+brittanyTotal[4];

    // cout << "\nrow is " << sarahRow << " i is " << i << " sarahTotal is: " << sarahGrandTotal;

    cout << setw(18) << left << salesSlipSummary[i][0]
         << setw(14) << salesSlipSummary[i][1]
         << setw(11) << right << setprecision(2) << salesSlipSummary[i][2];

    if (i != sarahRow && jesseRow && i != breannaRow && i != brittanyRow)
      cout << setw(11) << "";
    else if (i == sarahRow){
      getTotals();
      cout << setw(11) << setprecision(2) << sarahGrandTotal << "\n";
    }
    else if (i == jesseRow){
      getTotals();
      cout << setw(11) << setprecision(2) << jesseGrandTotal << "\n";
    }
    else if (i == breannaRow){
      getTotals();
      cout << setw(11) << setprecision(2) << breannaGrandTotal << "\n";
    }
    else if (i == brittanyRow){
      getTotals();
      cout << setw(11) << setprecision(2) << brittanyGrandTotal << "\n";
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
