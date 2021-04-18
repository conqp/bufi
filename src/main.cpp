#include <iostream>
#include <string>
#include <vector>

#include "fproject.h"

using std::cout;
using std::endl;
using std::vector;

/*
	Capital values and rates.
*/
void task1() {
	vector p1rates = {-35.0, 38.5, 127.05};
	vector p2rates = {-100.0, 165.0, 242.0};
	vector p3rates = {-50.0, 110.0, 60.5};
	double interestRate = 0.1;

	FinancingProject p1(p1rates, interestRate);
	FinancingProject p2(p2rates, interestRate);
	FinancingProject p3(p3rates, interestRate);

	vector projects = {p1, p2, p3};
	cout << "######### Projects ##########" << endl;

	for (FinancingProject project : projects)
		cout << project << endl;

	cout << "####### Investments #########" << endl;

	double budget = 50;
	vector investments = investOptimal(budget, projects);

	for (long unsigned int i = 0; i < investments.size(); i++)
		cout << projects[i] << "Investment: " << investments[i] << endl << endl;
}

int main() {
	task1();
	return 0;
}
