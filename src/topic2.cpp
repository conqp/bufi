#include <iostream>
#include <string>

#include "bufi.h"
#include "topic2.h"

using std::cout;
using std::endl;
using bufi::presentValue;

/*
	Lecture example calculation.
*/
void topic2::example1()
{
	cout << "* Example PVA:" << endl;
	double interestRate = 4.0 / 100;	// four percent
	int runtime = 3; 			// three years
	cout << "Interest rate: " << interestRate << endl;
	cout << "Runtime: " << runtime << endl;
	double pva = presentValue(interestRate, runtime);
	cout << "=> PVA: " << pva << endl;
}

void topic2::run_tasks()
{
	cout << ":::   Topic 2   :::" << endl;
	example1();
}
