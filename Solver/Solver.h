#ifndef SOLVER_H
#define SOLVER_H

#include <Core/Problem.h>

namespace dgs {

class Solver
{
public:
	virtual ~Solver() = default;
    virtual double solve(Problem &problem) = 0;
};

}

#endif // SOLVER_H
