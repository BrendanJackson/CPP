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
#include <stdlib.h>     /* atof, string to double */
#include <ctime>
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
    string date;
    double salesPersonID = 0;
    int productID = 0;
    double productPrice = 0.00;
    int menuSelection = 0;
  public:
    SalesSlip();
    void getDate();
    static double salesRepresentativesInfo[20][3];
    void displayMenu();
    void setMenuSelection();
    int getMenuSelection();
    void userCounter(int answer);
    void salesSlipBootstrap(int choice);
    void setSalesPersonID(int choice);
    double getSalesPersonID();
    void setProductID();
    double getProductID();
    void setProductPrice();
    double getProductPrice();
};


/* Class prototype
************************/
class Sales
{
  private:
    string salesPersons[4] = { "Sarah", "Jesse", "Breeanna", "Brittany"};
    string salesTotals[4];
    string productNames[5] = { "Magic Mouse", "Switch", "Camera", "Paralettes", "Time"};
    SalesSlip salesSlipContainer[20];
    string salesSlipSummary[20][3];
    double sarahTotal[5] = {0.00,0.00,0.00,0.00,0.00};
    double jesseTotal[5] = {0.00,0.00,0.00,0.00,0.00};
    double breannaTotal[5] = {0.00,0.00,0.00,0.00,0.00};
    double brittanyTotal[5] = {0.00,0.00,0.00,0.00,0.00};
    int sarahRow;
    int jesseRow;
    int breannaRow;
    int brittanyRow;
  public:
    void setSalesSlipContainer(SalesSlip);
    void getSalesSlipContainer();
    void setSalesSlipSummary(SalesSlip salesSlipContainer[19]);
    void getSalesSlipSummary();
    void getTotals();
    // string setSalesPersons();
    // string getSalesPersons();
    // string setProductNames();
    // string getProductNames();
};
