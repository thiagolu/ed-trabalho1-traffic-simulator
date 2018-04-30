#include<stdint.h>
#include<iostream>
#include<track_queue.hpp>
#include<track.hpp>

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator {
public:
  uint64_t run(uint64_t);
};
#endif
