#include<stdint.h>
#include<iostream>
#include<road/queue.hpp>
#include <structures/array_list.hpp>
#include <vehicles/car.hpp>

#ifndef STREET_H
#define STREET_H
namespace Road {
  class Street {
  private:
    std::size_t track_number;
    char id;

  public:
    Queue *input_queue;
    structures::ArrayList<Street> *output_list;
    Street() {
    }

    Street(char id) {
      track_number = 5;
      input_queue = new Queue();
      output_list = new structures::ArrayList<Street>();
      this->id = id;
    }

    void insert_vehicle(vehicles::Car& car) {
      printf("%s", "sdaddsad  -- ");
      printf("%i\n", car.info);
      input_queue->insert_vehicle(car);
    }

    vehicles::Car remove_vehicle() {
      vehicles::Car car = input_queue->remove_vehicle();
      printf("%s", "remove  -- ");
      printf("%i\n", car.info);

      return input_queue->remove_vehicle();
    }

    void add_street_as_output(const Street& street) {
      output_list->push_back(street);
    }

    bool empty() {
      return input_queue->has_element();
    }

    std::size_t get_id() {
      return id;
    }

    uint64_t doit(uint64_t);
  };
}

#endif
