
#include <cstdint>  // std::size_t
#include <queue.hpp>
#ifndef TRACK_QUEUE_H
#define TRACK_QUEUE_H

class TrackQueue {
private:
  structures::ArrayQueue<uint64_t> *queue;

public:
  TrackQueue () {
    queue = new structures::ArrayQueue<uint64_t>();
  }

  virtual ~TrackQueue () {

  }

  void enqueue(uint64_t number) {
    printf("%lu\n", number);
  }
};

#endif
