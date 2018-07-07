#ifndef DISCRETEVARIATION_H
#define DISCRETEVARIATION_H

#include "Variation.h"
#include "../Core/VariableWrapper.h"
#include <vector>

namespace dgs {

template<typename _Tp> class DiscreteVariation : public Variation
{
public:
    static VariationPtr build(_Tp *dataPtr, const std::vector<_Tp> &values) {
        return VariationPtr(new DiscreteVariation<_Tp>(dataPtr, values));
    }
    
    void reset() override {
        currentIndex = 0;
        wrap.set(values.at(0));
    }
    
    bool next() override {
        currentIndex++;
        if (currentIndex >= values.size()) {
            return false;
        }
        wrap.set(values.at(currentIndex));
        return true;
    }
    
private:
    DiscreteVariation(_Tp *dataPtr, const std::vector<_Tp> &values) : wrap(dataPtr), values(values) {
    }
    
    VariableWrapper<_Tp> wrap;
    std::vector<_Tp> values;
    int currentIndex = 0;
};

}

#endif // DISCRETEVARIATION_H
