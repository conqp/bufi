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

double FinanceProject::getInvestment() const
{
	return abs(depositSurplusses[0]);
}

double FinanceProject::getCapitalValue() const
{
	double result = 0;

	for (long unsigned int i = 0; i < depositSurplusses.size(); i++)
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

bool sortByCapitalValueRate(FinanceProject alice, FinanceProject bob)
{
	return alice.getCapitalValueRate() > bob.getCapitalValue();
}

vector<double> investOptimal(double budget, std::vector<FinanceProject> projects)
{
	double investment;
	vector<double> result = {};
	sort(projects.begin(), projects.end(), sortByCapitalValueRate);

	for (FinanceProject project : projects) {
		if (budget == 0)
			break;

		investment = project.getInvestment();

		if (budget < investment) {
			result.emplace_back(budget);
			return result;
		}

		result.emplace_back(investment);
		budget -= investment;
	}

	return result;
}

#endif
