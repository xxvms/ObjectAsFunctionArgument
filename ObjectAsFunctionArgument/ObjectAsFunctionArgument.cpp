// ObjectAsFunctionArgument.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Distance // English distance class
{
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0) // this is constructor with no arguments 
	{}
	Distance(int feet_, double inches_) : feet(feet_), inches(inches_) // constractor with 2 arguments
	{}
	void getDistance() // get lenght from user
	{
		std::cout << "Enter Feet: ";
		std::cin >> feet;
		std::cout << "Enter Inches: ";
		std::cin >> inches;
	}
	void showDistance() // display distance
	{
		std::cout << feet << "\' - " << inches << "\"";
	}
	void addDistance(Distance, Distance); // declaration
};
void Distance::addDistance(Distance Distance2_, Distance Distance3_) // add lenght Distance2 and Distance3
{
	inches = Distance2_.inches + Distance3_.inches; // add inches
	feet = 0; // for possible carry
	if (inches >= 12.0) //if total is greater then 12
	{
		inches -= 12.0; // decrease inches by -12  and
		feet++; // increase feet by 1
	}
	feet += Distance2_.feet + Distance3_.feet; // add feet
}

int main()
{
	Distance Dist1, Dist3; // define 2 lenghts
	Distance Dist2(11, 6.25); // definining and initializing dist2

	Dist1.getDistance(); // get dist1 from user
	Dist3.addDistance(Dist1, Dist2); // add Dist 1 and Dist 2

	std::cout << "\nDist1 = "; Dist1.showDistance();
	std::cout << "\nDist2 = "; Dist2.showDistance();
	std::cout << "\nDist3 = "; Dist3.showDistance();
	std::cout << std::endl;

	system("pause");
    return 0;
}

