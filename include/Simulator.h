//
// Created by tlu on 5/13/18.
//
#include<cstdint>
#include<iostream>
#include "track/street.h"
#include <chrono>
#include <thread>

#ifndef TRACK_SIMULATOR_SIMULATOR_H
#define TRACK_SIMULATOR_SIMULATOR_H


class Simulator {
public:
    int run(structures::ArrayList<track::Street> *, structures::ArrayList<track::Street> *);
    void insert_vehicle(int);

    void log(std::time_t);
};


#endif //TRACK_SIMULATOR_SIMULATOR_H
