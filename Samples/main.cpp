#include <Core/Problem.h>
#include <Variation/DiscreteVariation.h>
#include <Solver/GlobalOptimizationSolver.h>
#include <Core/Function.h>
#include <iostream>
#include <time.h>
#include <cstdlib>

enum ITEM_STATE {
	IS_NOT_TAKEN, IS_TAKEN
};

class NPTimeBackpack: public dgs::Function {
public:
	NPTimeBackpack() {
		itemsNum = rand() % 5 + 10;
		for (int i = 0; i < itemsNum; i++) {
			states.push_back(IS_NOT_TAKEN);
			volumes.push_back(rand() % 200 + 50);
			costs.push_back(rand() % 1000 + 100);
			capacity += rand() % 100 + 10;
		}
	}

	double calculate() override {
		int usedVolume = 0;
		double totalCost = 0;

		for (size_t i = 0; i < costs.size(); i++) {
			if (states.at(i) == IS_TAKEN) {
				usedVolume += volumes.at(i);
				totalCost += costs.at(i);
			}
		}

		return (usedVolume > capacity) ? -1000 : totalCost;
	}

	void printState() {
		std::cout << "Backpack" << std::endl;
		std::cout << "capacity: " << capacity << std::endl;
		std::cout << "taken cost: " << calculate() << std::endl;
		std::cout << "items: " << itemsNum << std::endl;
		for (int i = 0; i < itemsNum; i++) {
			std::cout << i;
			if (states.at(i) == IS_TAKEN) {
				std::cout << " taken, ";
			} else {
				std::cout << " not taken, ";
			}
			std::cout << "volume = " << volumes.at(i) << ", ";
			std::cout << "cost = " << costs.at(i) << std::endl;
		}
	}

	std::vector<ITEM_STATE> states;
	std::vector<int> volumes;
	std::vector<int> costs;
	int itemsNum = 0;
	int capacity = 0;
};

int main(int argc, char **argv) {
	srand(time(NULL) + clock());

	std::shared_ptr<NPTimeBackpack> backpack(new NPTimeBackpack);

	backpack->printState();

	dgs::Problem problem;
	for (int i = 0; i < backpack->itemsNum; i++) {
		problem.addVariation(
				dgs::DiscreteVariation<ITEM_STATE>::build(backpack->states[i], {
						IS_NOT_TAKEN, IS_TAKEN }));
	}
	problem.setFunction(backpack);

	dgs::GlobalOptimizationSolver solver;

	std::cout << solver.solve(problem) << std::endl;

	problem.loadState("max");
	backpack->printState();


	return 0;
}
