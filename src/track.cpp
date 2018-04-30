
#include <stdint.h>
#include <track.hpp>
#include <simulator.hpp>

#ifndef TRACK_CPP
#define TRACK_CPP

uint64_t Simulator::run(uint64_t number) {
  Track *tra = new Track();
  tra->add_car(number);
  return number;
}
#endif
