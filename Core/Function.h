#ifndef FUNCTION_H
#define FUNCTION_H

#include <memory>

namespace dgs {
    
class Function
{
public:
    virtual double calculate() = 0;
};
typedef std::shared_ptr<Function> FunctionPtr;

}

#endif // FUNCTION_H
