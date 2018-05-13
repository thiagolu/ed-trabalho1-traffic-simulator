//
// Created by tlu on 5/13/18.
//

#include "Simulator.h"
#include "../include/Track.h"
#include "../include/track/street.h"
#include "../include/TrafficLight.h"

int Simulator::run(int number) {
    track::Street *input_street;
    track::Street *out_north;
    track::Street *out_south;
    auto *car1 = new vehicles::Car(22);
    auto *car2 = new vehicles::Car(333);
    TrafficLight *traffic_light;

    input_street = new track::Street('A');
    out_north = new track::Street('B');
    out_south = new track::Street('C');
    auto *track = new Track();

    input_street->add_street_as_output(*out_north);
    input_street->add_street_as_output(*out_south);

    track->add_street_to_list(*input_street);
    track->add_street_to_list(*out_south);
    track->add_street_to_list(*out_north);
    traffic_light = new TrafficLight(input_street->input_queue, input_street->output_list);

    for (int i = 0; i <= number; ++i) {
        auto *temp_car1 = new vehicles::Car(i);
        input_street->insert_vehicle(*temp_car1);
        traffic_light->change_state();
    }


    input_street->insert_vehicle(*car1);
    traffic_light->change_state();
    input_street->insert_vehicle(*car2);
    traffic_light->change_state();

    return number;
}
