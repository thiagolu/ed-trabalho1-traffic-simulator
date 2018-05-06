#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <road/street.hpp>
#include <structures/array_list.hpp>
#include <vehicles/car.hpp>

class TrafficLight {
private:
  Road::Queue *input;
  structures::ArrayList<Road::Street> *output;

public:
  TrafficLight (Road::Queue* input, structures::ArrayList<Road::Street>* output) : input(input), output(output) {}

  virtual ~TrafficLight () {
  }

  void change_state() {
    if (input->has_element()) {
      vehicles::Car car = input->remove_vehicle();
      Road::Street destination = output->at(0);
      destination.insert_vehicle(car);
    }
  }
};
#endif
