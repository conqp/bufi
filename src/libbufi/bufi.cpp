#include <cmath>
#include <ostream>
#include <string>
#include <vector>

#include "bufi.h"
#include "functions.h"

using std::endl;
using std::ostream;
using std::string;
using std::vector;
using bufi::FinancingProject;

FinancingProject::FinancingProject(vector<double>& depositSurplusses, double interestRate)
: depositSurplusses(depositSurplusses), interestRate(interestRate)
{
}

vector<double> FinancingProject::getDepositSurplusses() const
{
	return depositSurplusses;
}

double FinancingProject::getInvestment() const
{
	return abs(depositSurplusses[0]);
}

double FinancingProject::getCapitalValue() const
{
	double result = 0;

	for (long unsigned int i = 0; i < depositSurplusses.size(); i++)
		result += depositSurplusses[i] / pow(1 + interestRate, i);

	return result;
}

double FinancingProject::getCapitalValueRate() const
{
	return getCapitalValue() / abs(depositSurplusses[0]);
}

void FinancingProject::print(ostream& target) const
{
	target << "Deposit surplusses: " << join<double>(depositSurplusses, ", ") << endl;
	target << "Capital value: " << getCapitalValue() << endl;
	target << "Capital value rate: " << getCapitalValueRate() << endl;
}

ostream& bufi::operator<<(ostream& target, FinancingProject const& project)
{
	project.print(target);
	return target;
}

bool bufi::sortByCapitalValueRate(FinancingProject const & alice, FinancingProject const & bob)
{
	return alice.getCapitalValueRate() > bob.getCapitalValue();
}

vector<FinancingProject> bufi::getExecutableProjects(vector<FinancingProject>& projects)
{
	vector<FinancingProject> result = {};
	sort(projects.begin(), projects.end(), sortByCapitalValueRate);

	for (FinancingProject project : projects) {
		if (project.getCapitalValueRate() < 0)
			break;

		result.emplace_back(project);
	}

	return result;
}

vector<double> bufi::investOptimal(double budget, vector<FinancingProject>& projects)
{
	double investment;
	vector<double> result = {};
	sort(projects.begin(), projects.end(), sortByCapitalValueRate);

	for (FinancingProject project : getExecutableProjects(projects)) {
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

/*
	Present value of an annuity for n payment periods
	DE: Rentenbarwertfaktor (RBF)
*/
double bufi::presentValue(double interestRate, int runtime)
{
	return (1 / interestRate) * (1 - (1 / (pow(1 + interestRate, runtime))));
}

/*
	Fixed-rate mortgage in rears
	DE: nachsch??ssige Annuit??t
*/
double bufi::FRMInRears(double cashflow, double interestRate, double runtime)
{
	return cashflow * presentValue(interestRate, runtime);
}

/*
	Fixed-rate mortgage in advance
	DE: vorsch??ssige Annuit??t
*/
double bufi::FRMInAdvance(double cashflow, double interestRate, double runtime)
{
	return (1 + interestRate) * FRMInRears(cashflow, interestRate, runtime);
}

double bufi::equivalentFRM(double capitalValue, double presentValue)
{
	return capitalValue / presentValue;
}
