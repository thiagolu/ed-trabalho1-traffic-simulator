//
// Created by tlu on 5/13/18.
//

#ifndef TRACK_SIMULATOR_TRAFFICLIGHT_H
#define TRACK_SIMULATOR_TRAFFICLIGHT_H

#include "vehicles/Car.h"
#include "track/street.h"
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

class TrafficLight {
private:
    track::Queue *input;


    structures::ArrayList<track::Street> *output;
public:

    TrafficLight (track::Queue* input, structures::ArrayList<track::Street>* output) : input(input), output(output) {}

    virtual ~TrafficLight () {
    }

    void change_state() {
        printf("%s\n", "#### Traffic Light changed ####");
        if (input->has_element()) {
            vehicles::Car car = input->remove_vehicle();
            track::Street destination = output->at(generate_random());
            printf("%s", "Moving car: ");
            printf("%i\n", car.info);
            printf("%s", "To destination => ");
            printf("%c\n", destination.get_id());
            destination.insert_vehicle(car);
        }
        printf("%s\n", "");
    }
    int generate_random() {
        int magic_number;
        rand ();
        magic_number  = rand() % output->size();
        printf("%s", "printing magic");
        printf("%i\n", magic_number);
        return magic_number;
    }
};


#endif //TRACK_SIMULATOR_TRAFFICLIGHT_H
