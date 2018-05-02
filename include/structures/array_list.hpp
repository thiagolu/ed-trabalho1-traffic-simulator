// Copyright [2018] <Thiago Lu Silva>

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

template<typename T>

/*!
* List data estructure
*/

class ArrayList {
 public:
   /*!
   * Empty constructor
   */
    ArrayList() {
      max_size_ = DEFAULT_MAX;
      contents = new T[max_size_];
      size_ = 0;
    }

    /*!
    * Explicit Parameterized constructor
    */
    explicit ArrayList(std::size_t max_size) {
      max_size_ = max_size;
      contents = new T[max_size_];
      size_ = 0;
    }

    /*!
    * Destructor
    */
    ~ArrayList() {
      delete[] contents;
    }

    /*!
    * Clear List data
    */
    void clear() {
      size_ = 0;
    }

    /*!
    * Pushes element to the last position from array
    */
    void push_back(const T& data) {
      full_check();
      contents[size_++] = data;
    }

    /*!
    * Pushes element in the first position from array
    */
    void push_front(const T& data) {
      full_check();
      int position = size_++;
      while (position > 0) {
        contents[position] = contents[position-1];
        position--;
      }
      contents[0] = data;
    }

    /*!
    * Inserts Element on given position
    *
    */
    void insert(const T& data, std::size_t index) {
      full_check();
      index_check(index);
      int current;

      current = size_++;
      while (current > index) {
        contents[current] = contents[current-1];
        current--;
      }

      contents[index] = data;
    }
    /*!
    * List data estructure
    */
    void insert_sorted(const T& data) {
      full_check();
      int index = 0;
      while (index < size_ && data > contents[index]) {
        index++;
      }
      insert(data, index);
    }

    /*!
    * List data estructure
    */
    T pop(std::size_t index) {
      if (index >= size_ || index < 0) {
        throw std::out_of_range("Invalid Index");
     }

      empty_check();

      size_--;
      T result = contents[index];
      int current_index = index;

      while (current_index < size_) {
        contents[current_index] = contents[current_index+1];
        current_index++;
      }
      return result;
    }

    /*!
    * List data estructure
    */
    T pop_back() {
      empty_check();
      --size_;
      return size_;
    }

    /*!
    * List data estructure
    */
    T pop_front() {
      empty_check();
      T value = contents[0];

      for (size_t i = 0; i < size_-1; i++) {
        contents[i] = contents[i+1];
      }
      --size_;
      return value;
    }

    /*!
    * Remove elements from list
    */
    void remove(const T& data) {
      empty_check();
      std::size_t position = find(data);
      if (position != size_) {
        int index = 0;
        while (data != contents[index])
            ++index;
        for (std::size_t i = index; i < size_; --i)
          contents[i] = contents[i + 1];
        --size_;
      }
    }

    /*!
    * Check if list is full
    */
    bool full() const {
      return size_ == max_size_;
    }

    /*!
    * Check if list is empty
    */
    bool empty() const {
      return size_ == 0;
    }

    /*!
    * List data estructure
    */
    bool contains(const T& data) const {
      if (find(data) == size_) {
        return false;
      }
      return true;
    }

    /*!
    * find in position
    */
    std::size_t find(const T& data) const {
      for (std::size_t i = 0; i < size_; i++) {
        if (contents[i] == data) {
          return i;
        }
      }
      return size_;
    }

    /*!
    * List size
    */
    std::size_t size() const {
      return size_;
    }

    /*!
    * Maximum size allowed
    */
    std::size_t max_size() const {
      return max_size_;
    }

    /*!
    * Return the element in given position
    */
    T& at(std::size_t index) {
      if (index < 0 || index > size_-1) {
        throw std::out_of_range("No element with that index");
      }
      return contents[index];
    }

    /*!
    * operator []
    */
    T& operator[](std::size_t index) {
      return contents[index];
    }

    /*!
    * const at
    */
    const T& at(std::size_t index) const {
      index_check(index);
      return contents[index];
    }

    /*!
    * const operator []
    */
    const T& operator[](std::size_t index) const {
      return contents[index];
    }

 private:
     T* contents;
     std::size_t size_;
     std::size_t max_size_;

     static const auto DEFAULT_MAX = 10u;

    void full_check() {
      if (full()) {
        throw std::out_of_range("The list is full");
      }
    }

    void empty_check() {
      if (empty()) {
        throw std::out_of_range("The list is empty");
      }
    }

    void index_check(std::size_t index) {
      if (index < 0 || index > size_) {
        throw std::out_of_range("Invalid index");
      }
    }
};

}  //  namespace structures

#endif
