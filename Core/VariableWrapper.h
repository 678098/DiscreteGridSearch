#ifndef VARIABLEWRAPPER_H
#define VARIABLEWRAPPER_H

namespace dgs {

template<typename _Tp> class VariableWrapper
{
public:
    VariableWrapper(_Tp *data) : data(data) {
    }
    
    void set(const _Tp &value) {
        *data = value;
    }
private:
    _Tp *data = nullptr;
};

}

#endif // VARIABLEWRAPPER_H
