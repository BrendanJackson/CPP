#include <iostream>
using namespace std;

int main (){	
	
	const double pi = 3.14159;

	int menu;

	double radius;
	double circle_area;

	double rectangle_length;
	double rectangle_width;
	double rectangle_area;

	double triangle_base;
	double triangle_height;
	double triangle_area;


	cout << "Geometry Calculator\n\n";

	cout << "1. Calculate the area of a Circle\n";

	cout << "2. Calculate the area of a Rectangle\n";

	cout << "3. Calculate the area of a Triangle\n";

	cout << "4. Quit\n";

	cout << "Enter your choice (1-4): ";

	cin >> menu;
	
	switch (menu){
		case 1:
			while (radius <= 0){
				cout << " What is the radius of your circle: \n";
				cin >> radius;
				
				if (radius <= 0){
					cout << "The radius can not be less than  zero.";
				}
			}

			circle_area = pi * (radius*radius);

			cout << "The circle's area is: " << circle_area;
			break;

		case 2: 
			while (rectangle_length <= 0){
				cout << " What is the length of your rectangle: \n";
				cin >> rectangle_length;
				
				if (rectangle_length <= 0){
					cout << "Only enter positive values  for base  and height.";
				}
			}
			
			while (rectangle_width <= 0){
				cout << " What is the width of your rectangle: \n";
				cin >> rectangle_width;
				
				if (rectangle_width <= 0){
					cout << "Only enter positive values  for base  and height.";
				}
			}

			rectangle_area = rectangle_length * rectangle_width;

			cout << "area of the rectangle: " << rectangle_area ;

			break;

		case 3:
			while (triangle_base <= 0){
				cout << " What is the length of your triangle’s base: \n";
				cin >> triangle_base;
				
				if (triangle_base <= 0){
					cout << "Only enter positive values  for base  and height.";
				}
			}
			
			while (triangle_height <= 0){
				cout << " What is the height of your triangle: \n";
				cin >> triangle_height;
				
				if (triangle_height <= 0){
					cout << "Only enter positive values  for base  and height.";
				}
			}

			triangle_area = (triangle_base * triangle_height) / 2 ;

			cout << "area of the triangle: " << triangle_area ;

			break;

		case 4:
			cout << "Program ending.";
			break;
		
		default:
			cout << "The valid choices are 1 through 4. Run the program again and select one of those.";

	}

	return 0 ;
}


			
	


4.21: Geometry Calculator

Write a program  that displays the following menu:



Geometry Calculator

1. Calculate the area of a Circle

2. Calculate the area of a Rectangle

3. Calculate the area of a Triangle

4. Quit

Enter your choice (1-4):





If the user enters 4, the program  should end.


Input Validation: Display an error message  if the user enters a
number outside the range of 1 through 4 when selecting an item
from the menu. Do not accept negative values  for the circle’s
radius, the rectangle’s length or width, or the triangle’s base 
or height.


NOTE:
If the user enters an improper menu choice (1-4), the program  prints
"The valid choices are 1 through 4. Run the program  again and select one of those."


If the user enters a negative radius, the program  prints "The radius can not be less than  zero."


If the user enters a negative value  for height or base , the program  prints "Only enter positive values  for base  and height."










