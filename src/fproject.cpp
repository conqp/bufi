#ifndef __FPROJECT__
#define __FPROJECT__

#include <cmath>
#include <ostream>
#include <string>
#include <vector>

#include "functions.h"
#include "fproject.h"

using std::endl;
using std::ostream;
using std::string;
using std::vector;

FinanceProject::FinanceProject(vector<double>& depositSurplusses, double interestRate)
: depositSurplusses(depositSurplusses), interestRate(interestRate)
{
}

vector<double> FinanceProject::getDepositSurplusses() const
{
	return depositSurplusses;
}

double FinanceProject::getCapitalValue() const
{
	double result = depositSurplusses[0];

	for (long unsigned int i = 1; i < depositSurplusses.size(); i++)
		result += depositSurplusses[i] / pow(1 + interestRate, i);

	return result;
}

double FinanceProject::getCapitalValueRate() const
{
	return getCapitalValue() / abs(depositSurplusses[0]);
}

void FinanceProject::print(ostream& target) const
{
	target << "Deposit surplusses: " << join<double>(depositSurplusses, ", ") << endl;
	target << "Capital value: " << getCapitalValue() << endl;
	target << "Capital value rate: " << getCapitalValueRate() << endl;
}

ostream& operator<<(ostream& target, FinanceProject const& project)
{
	project.print(target);
	return target;
}

#endif
