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
public:
	FinanceProject(std::vector<double>& depositSurplusses);
	virtual ~FinanceProject() = default;

	std::vector<double> getDepositSurplusses() const;
	double getCapitalValue(double interestRate) const;
	double getCapitalValueRate(double interestRate) const;
	virtual void print(std::ostream& target = std::cout) const;
	friend std::ostream& operator<<(std::ostream& target, FinanceProject const& person);
};

#endif
