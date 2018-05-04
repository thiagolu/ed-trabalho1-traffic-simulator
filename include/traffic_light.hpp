#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <road/street.hpp>
#include <structures/array_list.hpp>

class TrafficLight {
private:
  Road::Queue *input;
  structures::ArrayList<Road::Street> *output;

public:
  TrafficLight (Road::Queue* input, structures::ArrayList<Road::Street>* output) : input(input), output(output) {}
  virtual ~TrafficLight ();
};
#endif
