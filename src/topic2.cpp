#include <iostream>
#include <string>

#include "bufi.h"
#include "topic2.h"

using std::cout;
using std::endl;
using bufi::presentValue;
using bufi::FRMInAdvance;
using bufi::FRMInRears;

/*
	Lecture example calculation.
*/
void topic2::example1()
{
	double cashflow = 10000.0;		// ten thousand euros
	double interestRate = 4.0 / 100;	// four percent
	int runtime = 3; 			// three years

	double pva = presentValue(interestRate, runtime);
	double frmRears = FRMInRears(cashflow, interestRate, runtime);
	double frmAdvance = FRMInAdvance(cashflow, interestRate, runtime);

	cout << "* Example PVA:" << endl;
	cout << "Interest rate: " << interestRate << endl;
	cout << "Runtime: " << runtime << endl;
	cout << "=> PVA: " << pva << endl;
	cout << "=> FRM in rears: " << frmRears << endl;
	cout << "=> FRM in advance: " << frmAdvance << endl;
}

void topic2::run_tasks()
{
	cout << ":::   Topic 2   :::" << endl;
	example1();
}
