#ifndef VARIATION_H
#define VARIATION_H

#include <memory>
#include <string>

namespace dgs {

class Variation {
public:
	virtual ~Variation() = default;

	virtual void reset() = 0;
	virtual bool next() = 0;
	virtual void saveState(const std::string &id) = 0;
	virtual void loadState(const std::string &id) = 0;
};
typedef std::shared_ptr<Variation> VariationPtr;

}

#endif // VARIATION_H
