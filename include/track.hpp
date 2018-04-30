#include<street.hpp>
#include <track_queue.hpp>

#ifndef TRACK_H
#define TRACK_H
class Track {
private:
  Road::Street *street1;

public:

  virtual ~Track () {

  }

  Track() {
    street1 = new Road::Street();
  }

  void add_car(uint64_t number) {
    street1->insert_vehicles(number);
  }
};
#endif
