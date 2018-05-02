#include<road/street.hpp>

#ifndef TRACK_H
#define TRACK_H

// Track object
// List of streets
// It has all the streets displayed as queues
// Contains a list from all the output streets

class Track {
private:
  Road::Street *street1;

public:

  virtual ~Track () {
  }

  Track() {
    street1 = new Road::Street();
  }

  void add_car(std::size_t number) {
    street1->insert_vehicles(number);
  }

  bool empty_check() {
    return street1->empty();
  }
};
#endif
