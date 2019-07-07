#ifndef PROBLEM_H
#define PROBLEM_H

#include <Variation/Variation.h>
#include "Function.h"
#include <vector>

namespace dgs {

class Problem
{
public:
    void addVariation(VariationPtr variableVariation);
    void setFunction(FunctionPtr function);

    std::vector<VariationPtr> &getVariations();
    FunctionPtr &getFunction();

    void saveState(const std::string &id);
    void loadState(const std::string &id);
private:
    std::vector<VariationPtr> vars;
    FunctionPtr function;
};

}

#endif // PROBLEM_H
