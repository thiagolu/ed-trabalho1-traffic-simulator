#include <iostream>
#include "Simulator.h"
#include <track/street.h>
#include <string>

int main() {
    int vehicles;
    Simulator obj = Simulator();
    auto *input_vertical = new structures::ArrayList<track::Street>();
    auto *input_horizontal = new structures::ArrayList<track::Street>();

//
    track::Street *input_west_1;
    track::Street *out_west_1;

    track::Street *input_north_1;
    track::Street *out_north_1;

    track::Street *input_north_2;
    track::Street *out_north_2;

    track::Street *input_south_1;
    track::Street *out_south_1;

    track::Street *input_mid_1;
    track::Street *out_mid_1;

    track::Street *input_south_2;
    track::Street *out_south_2;

    track::Street *input_east;
    track::Street *out_east;

    input_west_1 = new track::Street('A', "Input West 1", 2000);
    out_west_1 = new track::Street('A', "Output West 1", 2000);

    input_north_1 = new track::Street('A', "Input North 1", 500);
    out_north_1 = new track::Street('A', "Output North 1", 500);

    input_north_2 = new track::Street('A', "Input North 2", 500);
    out_north_2 = new track::Street('A', "Output North 2", 500);

    input_south_1 = new track::Street('A', "Input South 1", 500);
    out_south_1 = new track::Street('A', "Output South 1", 500);

    input_south_2 = new track::Street('A', "Input South 2", 500);
    out_south_2 = new track::Street('A', "Output South 2", 500);

    input_mid_1 = new track::Street('A', "Input Mid 1", 300);
    out_mid_1 = new track::Street('A', "Output Mid 1", 300);

    input_east = new track::Street('A', "Input East 1", 400);
    out_east = new track::Street('A', "Output East 1", 400);

    input_horizontal->push_back(*input_west_1);
    input_horizontal->push_back(*input_east);
    input_vertical->push_back(*input_north_1);
    input_vertical->push_back(*input_north_2);
    input_vertical->push_back(*input_south_1);
    input_vertical->push_back(*input_south_2);

    input_west_1->add_street_as_output(*out_north_1);
    input_west_1->add_street_as_output(*out_mid_1);
    input_west_1->add_street_as_output(*out_south_1);

    input_north_1->add_street_as_output(*out_south_1);
    input_north_1->add_street_as_output(*out_mid_1);
    input_north_1->add_street_as_output(*out_west_1);

    input_south_1->add_street_as_output(*out_north_1);
    input_south_1->add_street_as_output(*out_mid_1);
    input_south_1->add_street_as_output(*out_west_1);

    input_mid_1->add_street_as_output(*out_north_1);
    input_mid_1->add_street_as_output(*out_south_1);
    input_mid_1->add_street_as_output(*out_west_1);
    input_mid_1->add_street_as_output(*out_north_2);
    input_mid_1->add_street_as_output(*out_south_2);


    input_north_2->add_street_as_output(*out_east );
    input_north_2->add_street_as_output(*out_mid_1);
    input_north_2->add_street_as_output(*out_south_2);

    input_south_2->add_street_as_output(*out_north_2);
    input_south_2->add_street_as_output(*out_mid_1);
    input_south_2->add_street_as_output(*out_east);

    input_east->add_street_as_output(*out_north_2);
    input_east->add_street_as_output(*out_mid_1);
    input_east->add_street_as_output(*out_south_2);


    obj.run(input_horizontal, input_vertical);
    return 0;

}
