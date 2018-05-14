//
// Created by tlu on 5/13/18.
//

#include <cstdint>  // std::size_t
#include "../vehicles/Car.h"
#include "../structures/array_queue.h"

#ifndef TRACK_SIMULATOR_QUEUE_H
#define TRACK_SIMULATOR_QUEUE_H



namespace track {
    class Queue {
    private:
        structures::ArrayQueue<vehicles::Car> *queue;

    public:
        Queue () {
            queue = new structures::ArrayQueue<vehicles::Car>();
        }
        Queue (int size) {
            queue = new structures::ArrayQueue<vehicles::Car>(size);
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
}


#endif //TRACK_SIMULATOR_QUEUE_H
