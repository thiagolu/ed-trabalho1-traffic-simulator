
#include <cstdint>  // std::size_t
#include <structures/queue.hpp>
#include <vehicles/car.hpp>
#ifndef TRACK_QUEUE_H
#define TRACK_QUEUE_H

namespace Road {
  class Queue {
  private:
    structures::ArrayQueue<vehicles::Car> *queue;

  public:
    Queue () {
      queue = new structures::ArrayQueue<vehicles::Car>();
    }

    virtual ~Queue () {

    }

    void insert_vehicle(vehicles::Car& car) {
      queue->enqueue(car);
    }

    vehicles::Car remove_vehicle() {
      vehicles::Car car = queue->dequeue();
      return car;
    }

    bool has_element() {
      return !queue->empty();
    }
  };
} /* Road */

#endif
