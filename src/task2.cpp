#include <iostream>
#include <vector>

#include "fproject.h"
#include "task2.h"

using std::cout;
using std::endl;
using std::vector;
using bufi::FinancingProject;
using bufi::investOptimal;

void task2()
{
	vector p1rates = {-60.0, 120.0};
	vector p2rates = {-90.0, 120.0};
	vector p3rates = {-150.0, 150.0};
	vector p4rates = {-100.0, 75.0};
	double interestRate = 0.1;

	FinancingProject p1(p1rates, interestRate);
	FinancingProject p2(p2rates, interestRate);
	FinancingProject p3(p3rates, interestRate);
	FinancingProject p4(p4rates, interestRate);

	vector projects = {p1, p2, p3, p4};
	cout << "######### Projects ##########" << endl;

	for (FinancingProject project : projects)
		cout << project << endl;

	cout << "####### Investments #########" << endl;

	double budget = 400;
	vector investments = investOptimal(budget, projects);

	for (long unsigned int i = 0; i < investments.size(); i++)
		cout << projects[i] << "Investment: " << investments[i] << endl << endl;
}
