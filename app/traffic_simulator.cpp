#include <cstdint>  // std::size_t
#include<iostream>
#include <simulator.hpp>
#include<street.hpp>

int main(int argc, char const *argv[]) {
  uint32_t vehicles;
  std::cout << "Enter the number of cars to be inserted into the system" << '\n';
  std::cin >> vehicles;
  Simulator obj = Simulator();
  obj.run(vehicles);

  return 0;
}
