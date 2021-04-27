#include <iostream>
#include <vector>

#include "bufi.h"
#include "topic1.h"

using std::cout;
using std::endl;
using std::vector;
using bufi::FinancingProject;
using bufi::getExecutableProjects;
using bufi::investOptimal;

/*
	Capital values and rates.
*/
void topic1::task1() {
	cout << "###   Task #1   ###" << endl;
	vector p1rates = {-35.0, 38.5, 127.05};
	vector p2rates = {-100.0, 165.0, 242.0};
	vector p3rates = {-50.0, 110.0, 60.5};
	double interestRate = 0.1;

	FinancingProject p1(p1rates, interestRate);
	FinancingProject p2(p2rates, interestRate);
	FinancingProject p3(p3rates, interestRate);

	vector projects = {p1, p2, p3};
	cout << "* Projects:" << endl;

	for (FinancingProject project : projects)
		cout << project << endl;

	cout << "* Investments:" << endl;

	double budget = 50;
	vector investments = investOptimal(budget, projects);

	for (long unsigned int i = 0; i < investments.size(); i++)
		cout << projects[i] << "Investment: " << investments[i] << endl << endl;
}

void topic1::task2()
{
	cout << "###   Task #2   ###" << endl;
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
	cout << "* Projects:" << endl;

	for (FinancingProject project : projects)
		cout << project << endl;

	cout << "* Investments:" << endl;

	double budget = 400;
	vector investments = investOptimal(budget, projects);

	for (long unsigned int i = 0; i < investments.size(); i++)
		cout << projects[i] << "Investment: " << investments[i] << endl << endl;
}

void topic1::task3()
{
	cout << "###   Task #3   ###" << endl;
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

	cout << "* Executable projects:" << endl;

	for (FinancingProject project : executableProjects)
		cout << project << endl;
}

void topic1::run_tasks()
{
	cout << ":::   Topic 1   :::" << endl;
	task1();
	task2();
	task3();
	cout << endl;
}
