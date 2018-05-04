#include<road/street.hpp>
#include<vehicles/car.hpp>

#ifndef TRACK_H
#define TRACK_H

// Track object
// List of streets
// It has all the streets displayed as queues
// Contains a list from all the output streets

class Track {
private:
  Road::Street *streetA, *streetB, *streetC;
  structures::ArrayList<Road::Street> *list;

public:

  virtual ~Track () {
  }

  Track() {
    streetA = new Road::Street('A');
    streetB = new Road::Street('B');
    streetC = new Road::Street('C');
    list = new structures::ArrayList<Road::Street>();

    connect();
  }

  void connect() {
    streetA->add_street_as_output(*streetB);
    streetA->add_street_as_output(*streetC);
    list->push_front(*streetA);
    std::cout << "Pushed street 1" << '\n';
    list->push_front(*streetB);
    std::cout << "Pushed street 2" << '\n';
    list->push_front(*streetC);
    std::cout << "Pushed street 3" << '\n';
    vehicles::Car *car1 = new vehicles::Car();
    streetA->insert_vehicles(*car1);
  }

  void change_street(Road::Street destination, Road::Street source) {
    // destination
  }

  void show_output() {
    // Road::Street result1 = list->pop_front();
    // Road::Street result2 = list->pop_front();
    Road::Street result3 = list->pop_back();
    // std::size_t var1 = result1.remove_vehicle().info;
    // std::size_t var2 = result2.remove_vehicle().info;
    // printf("%p\n"  ,result3 );
    printf("%i\n",result3.remove_vehicle().info );
    // printf("%i\n",result3.remove_vehicle().info );
    // int var3 = .name();
    // printf("%p\n", var1);
    // printf("%lu\n", var2);
    // printf("%lu\n", var3);
  }
};
#endif
