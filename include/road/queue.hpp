
#include <cstdint>  // std::size_t
#include <structures/queue.hpp>
#ifndef TRACK_QUEUE_H
#define TRACK_QUEUE_H

namespace Road {
  class Queue {
  private:
    structures::ArrayQueue<std::size_t> *queue;

  public:
    Queue () {
      queue = new structures::ArrayQueue<std::size_t>();
    }

    virtual ~Queue () {

    }

    void enqueue(std::size_t number) {
      queue->enqueue(number);
    }

    bool has_element() {
      // printf("%s", queue->empty() ?"true":"false");
      return queue->empty();
    }
  };
} /* Road */

#endif
