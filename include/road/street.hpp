#include<stdint.h>
#include<iostream>
#include<road/queue.hpp>

#ifndef STREET_H
#define STREET_H
namespace Road {
  class Street {
  private:
    std::size_t track_number;
    Queue *input_queue;

  public:
    Street() {
      track_number = 5;
      input_queue = new Queue();
    }

    void insert_vehicles(std::size_t number) {
      input_queue->enqueue(number);
    }

    bool empty() {
      return input_queue->has_element();
    }

    uint64_t doit(uint64_t);
  };
}

#endif
