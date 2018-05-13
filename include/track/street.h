#include<iostream>
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

    public:
        track::Queue *input_queue;
        structures::ArrayList<Street> *output_list;
        Street() {
        }

        Street(char id) {
            track_number = 5;
            input_queue = new Queue();
            output_list = new structures::ArrayList<Street>();
            this->id = id;
        }

        void insert_vehicle(vehicles::Car& car) {
            printf("%s", "Vehicle received in street => ");
            printf("%c\n", get_id());
            input_queue->insert_vehicle(car);

            if (output_list->empty() && input_queue->has_element()) {
                printf("%s", "Output street Removing vehicle => ");
                remove_vehicle();
            }
        }

        vehicles::Car remove_vehicle() {
            vehicles::Car car = input_queue->remove_vehicle();
            printf("%i\n", car.info);

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

        uint64_t doit(uint64_t);
    };
}

#endif
