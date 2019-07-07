#ifndef VARIABLEWRAPPER_H
#define VARIABLEWRAPPER_H

#include <functional>

namespace dgs {

template<typename _Tp>
using SetterType = typename std::function<void(const _Tp &)>;

template<typename _Tp> class VariableWrapper {
public:
	static VariableWrapper by_ref(_Tp &data) {
		return VariableWrapper([&](const _Tp &value) {data = value;});
	}

	static VariableWrapper by_setter(SetterType<_Tp> setter) {
		return VariableWrapper(setter);
	}

	void set(const _Tp &value) {
		setter(value);
	}
private:
	VariableWrapper(SetterType<_Tp> setter) :
			setter(setter) {
	}

	SetterType<_Tp> setter;
};

}

#endif // VARIABLEWRAPPER_H
