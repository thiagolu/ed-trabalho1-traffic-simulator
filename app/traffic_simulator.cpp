#include <iostream>
#include "Simulator.h"

int main() {
    int vehicles;
    std::cout << "Enter the number of cars to be inserted into the system" << '\n';
    std::cin >> vehicles;
    Simulator obj = Simulator();
    obj.run(vehicles);
    return 0;

}
