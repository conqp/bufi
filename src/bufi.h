/* SPDX-License-Identifier: GPL-3.0 */
/*
 * Business finance library.
 */
#ifndef BUFI_H
#define BUFI_H

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
	bool sortByCapitalValueRate(FinancingProject const & alice, FinancingProject const & bob);
	std::vector<FinancingProject> getExecutableProjects(std::vector<FinancingProject>& projects);
	std::vector<double> investOptimal(double budget, std::vector<FinancingProject>& projects);
	double presentValue(double interestRate, int runtime);
	double frm_in_advance(double cashflow, double interestRate, double runtime);
	double frm_in_rears(double cashflow, double interestRate, double runtime);
}

#endif
