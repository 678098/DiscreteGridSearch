#include "../Core/Problem.h"
#include "../Variation/DiscreteVariation.h"
#include "../Solver/GlobalOptimizationSolver.h"
#include "../Core/Function.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

enum ITEM_STATE {
    IS_NOT_TAKEN,
    IS_TAKEN
};

class NPTimeBackpack : public dgs::Function {
public:
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
    
    std::vector<ITEM_STATE> states;
    std::vector<int> volumes;
    std::vector<int> costs;
    int capacity = 0;
};

int main(int argc, char **argv) {
    srand(time(NULL) + clock());
    
    NPTimeBackpack *f = new NPTimeBackpack;
    
    int itemsNum = rand() % 5 + 10;
    for (int i = 0; i < itemsNum; i++) {
        f->states.push_back(IS_NOT_TAKEN);
        f->volumes.push_back(rand() % 200 + 50);
        f->costs.push_back(rand() % 1000 + 100);
        f->capacity += rand() % 100 + 10;
    }
    
    dgs::Problem problem;
    for (int i = 0; i < itemsNum; i++) {
        problem.addVariation(dgs::DiscreteVariation<ITEM_STATE>::build(&f->states[i], {IS_NOT_TAKEN, IS_TAKEN}));
    }
    problem.setFunction(dgs::FunctionPtr(f));
    
    dgs::GlobalOptimizationSolver solver;
    
    std::cout << solver.solve(problem) << std::endl;
    
    return 0;
}
