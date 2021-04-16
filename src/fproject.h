#ifndef FPROJECT_H
#define FPROJECT_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Finanzierungsprojekt
 */
class FinanceProject {
private:
	std::vector<double> depositSurplusses;
	double interestRate;
public:
	FinanceProject(std::vector<double>& depositSurplusses, double interestRate);
	virtual ~FinanceProject() = default;

	std::vector<double> getDepositSurplusses() const;
	double getInvestment() const;
	double getCapitalValue() const;
	double getCapitalValueRate() const;
	virtual void print(std::ostream& target = std::cout) const;
	friend std::ostream& operator<<(std::ostream& target, FinanceProject const& person);
};

bool sortByCapitalValueRate(FinanceProject alice, FinanceProject bob);
std::vector<double> investOptimal(double budget, std::vector<FinanceProject> projects);

#endif
