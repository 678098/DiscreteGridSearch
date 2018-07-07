#ifndef GLOBALOPTIMIZATIONSOLVER_H
#define GLOBALOPTIMIZATIONSOLVER_H

#include "Solver.h"

namespace dgs {
    
class GlobalOptimizationSolver : public Solver
{
public:
    double solve(Problem &problem) override;
    
private:
    void resetAll(std::vector<VariationPtr> &vars);
    bool next(std::vector<VariationPtr> &vars);
};

}

#endif // GLOBALOPTIMIZATIONSOLVER_H
