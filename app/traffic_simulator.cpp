#include<iostream>
#include<hello.hpp>

int main(int argc, char const *argv[]) {
  uint32_t age;
  std::cout << "Digite um numero" << '\n';
  std::cin >> age;
  Hello::say(age);
  return 0;
}
