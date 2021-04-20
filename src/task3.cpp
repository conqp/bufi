#include <iostream>
#include <vector>

#include "fproject.h"
#include "task3.h"

using std::cout;
using std::endl;
using std::vector;
using bufi::FinancingProject;
using bufi::getExecutableProjects;

void bufi::task3()
{
	cout << "######### Task 3 ##########" << endl;
	vector p1rates = {-90.0, 30.0, 30.0, 60.0};
	vector p2rates = {-80.0, 20.0, 40.0, 30.0};
	vector p3rates = {-110.0, 20.0, 100.0, 20.0};
	vector p4rates = {-60.0, 10.0, 40.0, 30.0};
	double interestRate = 0.1;

	FinancingProject p1(p1rates, interestRate);
	FinancingProject p2(p2rates, interestRate);
	FinancingProject p3(p3rates, interestRate);
	FinancingProject p4(p4rates, interestRate);

	vector projects = {p1, p2, p3, p4};
	vector executableProjects = getExecutableProjects(projects);

	cout << "### Executable projects ####" << endl;

	for (FinancingProject project : executableProjects)
		cout << project << endl;

	cout << endl;
}
