#include<road/street.hpp>
#include<structures/array_list.hpp>

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
    list->push_front(*streetA);
    std::cout << "Pushed street 1" << '\n';
    list->push_front(*streetB);
    std::cout << "Pushed street 2" << '\n';
    list->push_front(*streetC);
    std::cout << "Pushed street 3" << '\n';
  }

  void add_car(std::size_t number) {
    streetA->insert_vehicles(number);
  }

  void show_output() {
    Road::Street result = list->pop_front();
    printf("%c\n", result.get_id());
    result = list->pop_front();
    printf("%c\n", result.get_id());
    result = list->pop_front();
    printf("%c\n", result.get_id());
  }
};
#endif
