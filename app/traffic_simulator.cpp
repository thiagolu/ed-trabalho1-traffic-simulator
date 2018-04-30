#include <cstdint>  // std::size_t
#include<iostream>
#include<street.hpp>

int main(int argc, char const *argv[]) {
  uint32_t age;
  std::cout << "Digite um numero" << '\n';
  std::cin >> age;
  Road::Street *obj = new Road::Street();
  obj->doit(age);
  return 0;
}
