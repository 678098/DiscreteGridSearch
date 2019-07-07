#include "GlobalOptimizationSolver.h"

namespace dgs {

void GlobalOptimizationSolver::resetAll(std::vector<VariationPtr> &vars) {
	for (size_t i = 0; i < vars.size(); i++) {
		vars[i]->reset();
	}
}

bool GlobalOptimizationSolver::next(std::vector<VariationPtr> &vars) {
	for (int i = 0; i < vars.size(); i++) {
		if (vars[i]->next()) {
			return true;
		}
		vars[i]->reset();
	}
	return false;
}

double GlobalOptimizationSolver::maximize(Problem &problem) {
	return solve(problem,
			[&](double rival, double currentBest) {return rival > currentBest;},
			"max");
}

double GlobalOptimizationSolver::minimize(Problem &problem) {
	return solve(problem,
			[&](double rival, double currentBest) {return rival < currentBest;},
			"min");
}

double GlobalOptimizationSolver::solve(Problem &problem,
		std::function<bool(double, double)> isBetter,
		const std::string &category) {
	std::vector<VariationPtr> vars = problem.getVariations();
	FunctionPtr func = problem.getFunction();

	resetAll(vars);
	problem.saveState("initial");

	double bestValue = func->calculate();

	while (next(vars)) {
		double value = func->calculate();
		if (isBetter(value, bestValue)) {
			bestValue = value;
			problem.saveState(category);
		}
	}

	return bestValue;
}

}
