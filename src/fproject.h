#ifndef FPROJECT_H
#define FPROJECT_H

#include <iostream>
#include <string>
#include <vector>

/**
 * Finanzierungsprojekt
 */
namespace bufi {
	class FinancingProject {
	private:
		std::vector<double> depositSurplusses;
		double interestRate;
	public:
		FinancingProject(std::vector<double>& depositSurplusses, double interestRate);
		virtual ~FinancingProject() = default;

		std::vector<double> getDepositSurplusses() const;
		double getInvestment() const;
		double getCapitalValue() const;
		double getCapitalValueRate() const;
		virtual void print(std::ostream& target = std::cout) const;
		friend std::ostream& operator<<(std::ostream& target, FinancingProject const& person);
	};

	std::ostream& operator<<(std::ostream& target, FinancingProject const& person);
	bool sortByCapitalValueRate(FinancingProject alice, FinancingProject bob);
	std::vector<double> investOptimal(double budget, std::vector<FinancingProject> projects);
}

#endif
