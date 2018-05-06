#ifndef CAR_HPP
#define CAR_HPP

#include <cstdint>
#include <stdexcept>

namespace vehicles {
class Car {
private:
  /* data */

public:
  int info;
  Car (int information) : info(information) {}
  Car () {}
  virtual ~Car () {

  }

  int name(/* arguments */) {
    return 2;
  }
};
} /* vehicles */
#endif
