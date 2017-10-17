/*
  |--------------------------------------------------------------------------
  | Project #2 Details
  |--------------------------------------------------------------------------
  |
  | Brendan Jackson
  | 10/05/2017
  | CS216
  |
  |  DATA STRUCTURES
  |  First, provide a struct of the sales slip.
  | Second, provide the class whose data members are as follows:
  | • A one-dimensional array of slip structures to be used to store sales information for all the
  | sales people for a month.
  | • A two dimensional array that will contain a summary of the data from the one dimensional
  | array where the rows shall represent salesperson and the columns shall represent product.
  | • A one-dimensional array of names of the four salespersons.
  | • A one dimensional array of product names.
  |
  */

/* Libraries
************************/
// contains definitions of cin, cout, endl, and input/output operators
#include <iostream>
// contains rand( ) and srand( ) for random number generation
#include <cstdlib>
// contains definition of type string
#include <string>
#include <sstream>
// set precision
#include <iomanip>
// dynamic arrays
#include <vector>


//standard namespace
using namespace std;

/* Global Variables
************************/
extern int counterSarah;
extern int counterJesse;
extern int counterBreanna;
extern int counterBrittany;


/* Struct prototype
************************/
struct SalesSlip
{
  private:
    double salesPersonID = 0;
    double productID = 0;
    double productPrice = 0.00;
    string dateOfSale = "10/05/2017";
    double dailyTotal = 1.00;
    int menuSelection = 0;
  public:
    static double salesRepresentativesInfo[20][3];
    void displayMenu();
    void setMenuSelection();
    int getMenuSelection();
    void userCounter(char answer);
    void salesSlipBootstrap(int choice);
    void setSalesRepresentativesInfo( double salesPersonID, double productID, double productPrice );
    double getSalesRepresentativesInfo();
    void setSalesPersonID(int choice);
    double getSalesPersonID();
    void setProductID();
    double getProductID();
    void setProductPrice();
    double getProductPrice();
    void setDateOfSale();
    string getDateOfSale();
};


/* Class prototype
************************/
class Sales
{
  private:
    SalesSlip salesSlipContainer[1];
    string salesSlipSummary[20][3];
    string salesPersons[4] = { "Sarah", "Jesse", "Breeanna", "Brittany"};
    string salesTotals[4];
    string productNames[5] = { "Magic Mouse", "Switch", "Camera", "Paralettes", "Time"};
    char initialResponse;
  public:
    void setSalesSlipContainer(SalesSlip);
    SalesSlip getSalesSlipContainer();
    void setSalesSlipSummary( double salesRepresentativesInfo[20][3] );
    void getSalesSlipSummary();
    string setSalesPersons();
    string getSalesPersons();
    string setProductNames();
    string getProductNames();
};
