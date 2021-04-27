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
	cout << "* Example PVA:" << endl;
	double cashflow = 10000.0;		// ten thousand euros
	double interestRate = 4.0 / 100;	// four percent
	int runtime = 3; 			// three years
	cout << "Interest rate: " << interestRate << endl;
	cout << "Runtime: " << runtime << endl;
	double pva = presentValue(interestRate, runtime);
	cout << "=> PVA: " << pva << endl;
	double frmRears = FRMInRears(cashflow, interestRate, runtime);
	cout << "=> FRM in rears: " << frmRears << endl;
	double frmAdvance = FRMInAdvance(cashflow, interestRate, runtime);
	cout << "=> FRM in advance: " << frmAdvance << endl;
}

void topic2::run_tasks()
{
	cout << ":::   Topic 2   :::" << endl;
	example1();
}
