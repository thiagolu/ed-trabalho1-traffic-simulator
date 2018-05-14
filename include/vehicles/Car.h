//
// Created by tlu on 5/13/18.
//

#ifndef TRACK_SIMULATOR_CAR_H
#define TRACK_SIMULATOR_CAR_H


#include <cstdint>
#include <stdexcept>

namespace vehicles {
    class Car {
    private:
        int speed;
        int size;

    public:
        int info{};

        explicit Car (int information) : info(information), speed(10), size(1) {}
        Car () = default;

        virtual ~Car () = default;

    };
} /* vehicles */


#endif //TRACK_SIMULATOR_CAR_H
