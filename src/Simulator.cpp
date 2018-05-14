//
// Created by tlu on 5/13/18.
//

#include <zconf.h>
#include "Simulator.h"
#include "track/street.h"
#include "Track.h"
#include "TrafficLight.h"

void Simulator::log(std::time_t time) {
  std::cout << " time running: "
            << time << " seconds, Date: ";
  std::time_t result = std::time(nullptr);
  std::cout << std::asctime(std::localtime(&result));
}

int Simulator::run(structures::ArrayList<track::Street> *horizontal_list, structures::ArrayList<track::Street> *vertical_list) {

    int run_time;
    std::cout << "Input running time in seconds" << '\n';
    std::cin >> run_time;

    TrafficLight *traffic_light;

    traffic_light = new TrafficLight(horizontal_list, vertical_list);

    clock_t  timeStart = clock();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto time = (((static_cast<int>(clock()) - timeStart) / 100));

        if (time % 2 == 0) {
            track::Street source = horizontal_list->at(traffic_light->generate_random(horizontal_list));
            log(time);
            auto *temp_car1 = new vehicles::Car(rand() % 200);
            source.insert_vehicle(*temp_car1);
        }
        if (time % 3 == 0) {
           log(time);
            track::Street source = vertical_list->at(traffic_light->generate_random(vertical_list));
            auto *temp_car1 = new vehicles::Car(rand() % 200);
            source.insert_vehicle(*temp_car1);
        }
        if (time % 5 == 0) {
            log(time);
            traffic_light->change_multiple_states();
        }

        if (time >= run_time) {
          std::cout << " time running: "
                    << time << " seconds, Date: ";
          std::time_t result = std::time(nullptr);
            std::cout << "BREAKSON\n";

            break;
        }// time in seconds
    }

    return 0;
}
