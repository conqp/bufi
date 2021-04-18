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
	vector<double> p1rates = {-35, 38.5, 127.05};
	vector<double> p2rates = {-100, 165, 242};
	vector<double> p3rates = {-50, 110, 60.5};
	double interestRate = 0.1;

	FinancingProject p1(p1rates, interestRate);
	FinancingProject p2(p2rates, interestRate);
	FinancingProject p3(p3rates, interestRate);

	vector<FinancingProject> projects = {p1, p2, p3};
	cout << "######### Projects ##########" << endl;

	for (FinancingProject project : projects)
		cout << project << endl;

	cout << "####### Investments #########" << endl;

	double budget = 50;
	vector<double> investments = investOptimal(budget, projects);

	for (long unsigned int i = 0; i < investments.size(); i++)
		cout << projects[i] << "Investment: " << investments[i] << endl << endl;
}

int main() {
	task1();
	return 0;
}
