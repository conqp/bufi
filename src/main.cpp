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

	FinanceProject p1(p1rates, interestRate);
	FinanceProject p2(p2rates, interestRate);
	FinanceProject p3(p3rates, interestRate);

	vector<FinanceProject> projects = {p1, p2, p3};

	for (FinanceProject project : projects)
		cout << project << endl;
}

int main() {
	task1();
	return 0;
}
