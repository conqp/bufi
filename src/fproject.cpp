#ifndef __FPROJECT__
#define __FPROJECT__

#include <cmath>
#include <ostream>
#include <string>
#include <vector>

#include "functions.h"
#include "fproject.h"

using std::ostream;
using std::string;
using std::vector;

FinanceProject::FinanceProject(vector<double>& depositSurplusses)
: depositSurplusses(depositSurplusses)
{
}

vector<double> FinanceProject::getDepositSurplusses() const
{
	return depositSurplusses;
}

double FinanceProject::getCapitalValue(double interestRate) const
{
	double result = depositSurplusses[0];

	for (long unsigned int i = 1; i < depositSurplusses.size(); i++)
		result += depositSurplusses[i] / pow(1 + interestRate, i);

	return result;
}

double FinanceProject::getCapitalValueRate(double interestRate) const
{
	return getCapitalValue(interestRate) / abs(depositSurplusses[0]);
}

void FinanceProject::print(ostream& target) const
{
	target << "Deposit surplusses: " << join<double>(depositSurplusses, ", ");
}

ostream& operator<<(ostream& target, FinanceProject const& project)
{
	project.print(target);
	return target;
}

#endif
