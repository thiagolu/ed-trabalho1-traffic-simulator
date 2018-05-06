#include <stdint.h>
#include <cstdint>  // std::size_t
#include <road/queue.hpp>
#include <road/street.hpp>
#include <vehicles/car.hpp>
#include <track.hpp>
#include <simulator.hpp>

#ifndef TRACK_CPP
#define TRACK_CPP

// Run the simulation with params
std::size_t Simulator::run(std::size_t number) {
  Road::Street *input_street, *out_north, *out_south;
  vehicles::Car *car1 = new vehicles::Car(22);
  vehicles::Car *car2 = new vehicles::Car(333);
  input_street = new Road::Street('A');
  out_north = new Road::Street('B');
  out_south = new Road::Street('C');
  Track *track = new Track();

  input_street->add_street_as_output(*out_north);
  input_street->add_street_as_output(*out_south);

  input_street->insert_vehicle(*car1);
  printf("%p\n", car1);
  input_street->insert_vehicle(*car2);
  printf("%p\n", car2);

  track->add_street_to_list(*input_street);
  track->add_street_to_list(*out_south);
  track->add_street_to_list(*out_north);

  TrafficLight *traffic_light = new TrafficLight(input_street->input_queue, input_street->output_list);
  traffic_light->change_state();

  printf("%i\n", input_street->output_list->size());

  track->show_output();

  return number;
}
#endif
