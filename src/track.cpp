
#include <stdint.h>
#include<street.hpp>
#include <track_queue.hpp>

#ifndef TRACK_CPP
#define TRACK_CPP


class Track {
private:
  Road::Street *street1;

public:

  virtual ~Track () {

  }

  Track() {
    street1 = new Road::Street();
  }

  void track_number(uint64_t number) {
    street1->enqueue_test(number);
  }
};

uint64_t Road::Street::doit(uint64_t number) {
  Track *tra = new Track();
  tra->track_number(number);
  return track_number;
}
#endif
