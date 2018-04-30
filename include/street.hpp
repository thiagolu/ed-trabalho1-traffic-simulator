#include<stdint.h>
#include<iostream>
#include<track_queue.hpp>

#ifndef STREET_H
#define STREET_H
  namespace Road {

    class Street {
    private:
      uint64_t track_number;
      TrackQueue *input_queue;

    public:
      Street() {
        track_number = 5;
        input_queue = new TrackQueue();
      }

      void enqueue_test(uint64_t number) {
        input_queue->enqueue(number);
      }

      uint64_t doit(uint64_t);
    };
  }

#endif
