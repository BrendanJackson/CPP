#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   string month1;
   string month2;
   string month3;

   double month1_rainfall;
   double month2_rainfall;
   double month3_rainfall;

   double rainfall

   cout << "Enter three consecutive months: " << endl;
   cin >> month1 >> month2 >> month3;

   cout << "How many inches of rain fell in " << month1 << "?" << endl;
   cin >>  month1_rainfall;

   cout << "How much inches of rain fell in " << month2 << "?" << endl;
   cin >> month2_rainfall;

   cout << "How much inches of rain fell in " << month3 << "?" << endl;
   cin >> month3_rainfall;

   avg_rainfall = (month1_rainfall + month2_rainfall + month3_rainfall)/2;
    

   cout << "The average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is " <<  avg_rainfall << " inches.";

   return 0;
}