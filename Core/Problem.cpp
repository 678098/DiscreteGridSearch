#include "Problem.h"

namespace dgs {
    
void Problem::addVariation(VariationPtr variableVariation) {
    vars.push_back(variableVariation);
}

void Problem::setFunction(FunctionPtr _function){
    function = _function;
}

std::vector<VariationPtr> &Problem::getVariations() {
    return vars;
}
    
FunctionPtr &Problem::getFunction() {
    return function;
}

}
