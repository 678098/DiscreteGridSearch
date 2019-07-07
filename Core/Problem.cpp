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

void Problem::saveState(const std::string &id) {
	for (VariationPtr &var : vars) {
		var->saveState(id);
	}
}

void Problem::loadState(const std::string &id) {
	for (VariationPtr &var : vars) {
		var->loadState(id);
	}
}

}
