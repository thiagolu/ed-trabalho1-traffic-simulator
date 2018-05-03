#include <stdint.h>
#include <cstdint>  // std::size_t
#include <road/queue.hpp>
#include <road/street.hpp>
#include <track.hpp>
#include <simulator.hpp>

#ifndef TRACK_CPP
#define TRACK_CPP

// Run the simulation with params passed
std::size_t Simulator::run(std::size_t number) {
  Track *tra = new Track();
  tra->show_output();
  return number;
}
#endif
