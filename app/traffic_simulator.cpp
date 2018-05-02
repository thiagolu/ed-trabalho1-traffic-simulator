#include <cstdint>  // std::size_t
#include<iostream>
#include <simulator.hpp>


int main(int argc, char const *argv[]) {
  std::size_t vehicles;
  std::cout << "Enter the number of cars to be inserted into the system" << '\n';
  std::cin >> vehicles;
  Simulator obj = Simulator();
  obj.run(vehicles);

  return 0;
}
