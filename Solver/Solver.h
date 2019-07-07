#ifndef SOLVER_H
#define SOLVER_H

#include <Core/Problem.h>

namespace dgs {

class Solver
{
public:
	virtual ~Solver() = default;
    virtual double minimize(Problem &problem) = 0;
    virtual double maximize(Problem &problem) = 0;
};

}

#endif // SOLVER_H
