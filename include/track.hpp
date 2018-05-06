#include<road/street.hpp>
#include<vehicles/car.hpp>
#include<traffic_light.hpp>

#ifndef TRACK_H
#define TRACK_H

// Track object
// List of streets
// It has all the streets displayed as queues
// Contains a list from all the output streets

class Track {
private:
  structures::ArrayList<Road::Street> *list;

public:

  virtual ~Track () {
  }

  Track() {
    list = new structures::ArrayList<Road::Street>();
  }

  void add_street_to_list(Road::Street& street) {
    list->push_front(street);
  }

  void change_street(Road::Street& source, Road::Street& destination) {
    vehicles::Car car = source.remove_vehicle();
    printf("%p\n", car);
    destination.insert_vehicle(car);
  }

  void show_output() {
    Road::Street street1 = list->pop_front();
    Road::Street result3 = list->pop_back();
    change_street(result3, street1);
    printf("%i\n",street1.remove_vehicle().info );
  }
};
#endif
