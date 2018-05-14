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
    structures::ArrayList<track::Street> *input_streets;
    structures::ArrayList<track::Street> *input_horizontal_streets;
    structures::ArrayList<track::Street> *input_vertical_streets;
    enum Direction { Horizontal,Vertical};
    Direction current_direction = Horizontal;

public:

    TrafficLight (structures::ArrayList<track::Street>* input_streets) : input_streets(input_streets) {}

    TrafficLight (structures::ArrayList<track::Street>* input_horizontal_streets, structures::ArrayList<track::Street>* input_vertical_streets) : input_horizontal_streets(input_horizontal_streets), input_vertical_streets(input_vertical_streets) {
    }

    virtual ~TrafficLight () {
    }


    void change_state(track::Street source) {
        track::Queue *input = source.input_queue;
        structures::ArrayList<track::Street> *destination_list = source.output_list;
        if (input->has_element()) {
            std::cout << "[INFO] Source: { name: " <<  source.get_name() << " ";
            vehicles::Car car = input->remove_vehicle();
            track::Street destination = destination_list->at(static_cast<size_t>(generate_random(destination_list)));
            printf("%s", "action: :change_car, car_id:  ");
            printf("%i", car.info);
            printf("%s", ", destination: ");
            std::cout << destination.get_name() << "}\n";
            destination.insert_vehicle(car);
        }
    }

    void change_multiple_states() {

        printf("%s\n", "\n[EVENT] #### Traffic Light changed ####");
        structures::ArrayList<track::Street> *streets = get_active();
        if (!streets->empty()) {
            int size = streets->size() - 1;
            for (int i = 0; i <= size; ++i) {
                track::Street source = streets->at(i);
                change_state(source);
            }
        }
        toggle();
    }

    int generate_random(structures::ArrayList<track::Street> *limit) {
        int magic_number;
        rand ();
        magic_number  = static_cast<int>(rand() % limit->size());
        return magic_number;
    }

    void toggle() {
        if (current_direction == Horizontal) {
            current_direction = Vertical;
        } else {
            current_direction = Horizontal;
        }
    }
    structures::ArrayList<track::Street>* get_active() {
        if (current_direction == Horizontal) {
            return input_horizontal_streets;
        }
        if (current_direction == Vertical) {
            return input_vertical_streets;
        }
        return input_horizontal_streets;

    }

};


#endif //TRACK_SIMULATOR_TRAFFICLIGHT_H
