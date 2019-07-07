#ifndef GLOBALOPTIMIZATIONSOLVER_H
#define GLOBALOPTIMIZATIONSOLVER_H

#include "Solver.h"
#include <functional>

namespace dgs {

class GlobalOptimizationSolver: public Solver {
public:
	double minimize(Problem &problem) override;
	double maximize(Problem &problem) override;

private:
	double solve(Problem &problem, std::function<bool(double, double)> isBetter, const std::string &category);

	void resetAll(std::vector<VariationPtr> &vars);
	bool next(std::vector<VariationPtr> &vars);
};

}

#endif // GLOBALOPTIMIZATIONSOLVER_H
