#ifndef DISCRETEVARIATION_H
#define DISCRETEVARIATION_H

#include "Variation.h"
#include <Core/VariableWrapper.h>
#include <vector>
#include <map>

namespace dgs {

template<typename _Tp> class DiscreteVariation: public Variation {
public:
	static VariationPtr build(_Tp &data, const std::vector<_Tp> &values) {
		return VariationPtr(new DiscreteVariation<_Tp>(&data, values));
	}

	void reset() override {
		if (!values.empty()) {
			currentIndex = 0;
			wrap.set(values.at(0));
		}
	}

	bool next() override {
		currentIndex++;
		if (currentIndex >= values.size()) {
			return false;
		}
		wrap.set(values.at(currentIndex));
		return true;
	}

	void saveState(const std::string &id) override {
		states[id] = currentIndex;
	}

	void loadState(const std::string &id) override {
		if (states.find(id) == states.end()) {
			throw std::runtime_error("Can't load state with id = " + id);
		}
		currentIndex = states[id];
		wrap.set(values.at(currentIndex));
	}

private:
	DiscreteVariation(_Tp *dataPtr, const std::vector<_Tp> &values) :
			wrap(dataPtr), values(values) {
		reset();
	}

	VariableWrapper<_Tp> wrap;
	std::vector<_Tp> values;
	std::map<std::string, int> states;
	int currentIndex = 0;
};

}

#endif // DISCRETEVARIATION_H
