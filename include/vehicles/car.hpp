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
  Car () : info(44) {}
  virtual ~Car () {

  }

  int name(/* arguments */) {
    return 2;
  }
};
} /* vehicles */
#endif
