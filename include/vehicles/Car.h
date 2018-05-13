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
        /* data */

    public:
        int info{};

        explicit Car (int information) : info(information) {}
        Car () = default;

        virtual ~Car () = default;

        int name(/* arguments */) {
            return 2;
        }
    };
} /* vehicles */


#endif //TRACK_SIMULATOR_CAR_H
