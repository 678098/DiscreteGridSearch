#ifndef VARIATION_H
#define VARIATION_H

#include <memory>

namespace dgs {

class Variation
{
public:
    virtual void reset() = 0;
    virtual bool next() = 0; 
};
typedef std::shared_ptr<Variation> VariationPtr;

}

#endif // VARIATION_H
