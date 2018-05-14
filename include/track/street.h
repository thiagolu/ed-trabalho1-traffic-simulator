#include<iostream>
#include <string>
#include "../track/queue.h"
#include "../structures/ArrayList.h"
#include "../vehicles/Car.h"

#ifndef STREET_H
#define STREET_H
namespace track {
    class Street {
    private:
        std::size_t track_number;
        char id;
        std::string novas;

    public:
        track::Queue *input_queue;
        structures::ArrayList<Street> *output_list;
        Street() {
        }

        Street(char id, std::string novas) {
            track_number = 5;
            input_queue = new Queue();
            output_list = new structures::ArrayList<Street>();
            this->id = id;
            this->novas = novas;
        }

        Street(char id, std::string novas, int size) {
            track_number = 5;
            input_queue = new Queue(size/5);
            output_list = new structures::ArrayList<Street>();
            this->id = id;
            this->novas = novas;
        }

        void insert_vehicle(vehicles::Car& car) {
            std::cout << "\n[Event] Vehicle arrived: " << get_name() << " car_id=";
            printf("%i", car.info);
            std::cout<< "\n";

            input_queue->insert_vehicle(car);
            if (output_list->empty() && input_queue->has_element()) {
                remove_vehicle();
            }
        }

        vehicles::Car remove_vehicle() {
            vehicles::Car car = input_queue->remove_vehicle();

            return car;
        }

        void add_street_as_output(const Street& street) {
            output_list->push_back(street);
        }

        bool empty() {
            return input_queue->has_element();
        }

        char get_id() {
            return id;
        }
        std::string get_name() {
            return novas;
        }

        uint64_t doit(uint64_t);
    };
}

#endif
