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
  return salesRepresentativesInfo[20][3];
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
  salesSlipContainer[0] = slip;
}
SalesSlip Sales::getSalesSlipContainer()
{
  return salesSlipContainer[0];
}

void Sales::setSalesSlipSummary( double salesRepresentativesInfo[20][3] )
{
  int i = 0;
  while(i <= 20){
    if(salesRepresentativesInfo[i][0] == 1)
      salesSlipSummary[i][0] = "Sarah";
    else if(salesRepresentativesInfo[i][0] == 2)
      salesSlipSummary[i][0] = "Jesse";
    else if(salesRepresentativesInfo[i][0] == 3)
      salesSlipSummary[i][0] = "Breanna";
    else if(salesRepresentativesInfo[i][0] == 4)
      salesSlipSummary[i][0] = "Brittany";

    salesSlipSummary[i][1] = to_string(salesRepresentativesInfo[i][1]);
    salesSlipSummary[i][2] = to_string(salesRepresentativesInfo[i][2]);
    i++;
  }
}
void Sales::getSalesSlipSummary()
{
  for (int i = 0;i <= 20;i++){
    for (int j = 0;j <= 3;j++){
      cout << "\nsalesSlipSummary" << "[" << i << "]" << "[" << j << "]" << salesSlipSummary[i][j];
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
string Sales::getProductNames()
{
  return productNames[0];
}
