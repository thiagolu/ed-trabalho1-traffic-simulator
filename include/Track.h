//
// Created by tlu on 5/13/18.
//

#ifndef TRACK_SIMULATOR_TRACK_H
#define TRACK_SIMULATOR_TRACK_H


#include "track/street.h"

class Track {
private:
    structures::ArrayList<track::Street> *list;

public:

    virtual ~Track () {
    }

    Track() {
        list = new structures::ArrayList<track::Street>();
    }

    void add_street_to_list(track::Street& street) {
        list->push_front(street);
    }

    void change_street(track::Street& source, track::Street& destination) {
        vehicles::Car car = source.remove_vehicle();
        printf("%p\n", car);
        destination.insert_vehicle(car);
    }

    void show_output() {
        track::Street street1 = list->pop_front();
        track::Street result3 = list->pop_back();
        change_street(result3, street1);
        printf("%i\n",street1.remove_vehicle().info );
    }
};


#endif //TRACK_SIMULATOR_TRACK_H
