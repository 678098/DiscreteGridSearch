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
    
double GlobalOptimizationSolver::solve(Problem &problem) {
    std::vector<VariationPtr> vars = problem.getVariations();
    FunctionPtr func = problem.getFunction();
    
    resetAll(vars);
    double bestValue = func->calculate();
    
    while (next(vars)) {
        double value = func->calculate();
        if (value > bestValue) bestValue = value;
    }
    
    return bestValue;
}

}
