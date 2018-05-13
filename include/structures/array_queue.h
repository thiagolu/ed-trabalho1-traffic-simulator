//
// Created by tlu on 5/13/18.
//

#ifndef QUEUE_H
#define QUEUE_H


#include <cstdint>  // std::size_t
#include <stdexcept>

namespace structures {
    template<typename T>

//! Generic Array Queue
    class ArrayQueue {
    public:
        // Empty initializer
        ArrayQueue() {
            max_size_ = DEFAULT_SIZE;
            size_ = -1;
            contents = new T[max_size_];
        }

        //! Generic Array Queue parameterized
        explicit ArrayQueue(std::size_t max) {

            max_size_ = max;
            size_ = -1;
            contents = new T[max_size_];
        }

        ~ArrayQueue() {
            delete[] contents;
        }

        //! Add data to queue
        void enqueue(const T& data) {
            full_check();
            contents[++size_] = data;
        }

        //! Remove from queue
        T dequeue() {
            empty_check();
            T result;
            result = contents[0];
            for (std::size_t position = 0; position <= size_; position++) {
                contents[position] = contents[position+1];
            }
            size_ = size_ - 1;
            return result;
        }

        //! Return last position
        T& back() {
            empty_check();
            return contents[size_];
        }

        //! Clear queue
        void clear() {
            empty_check();
            size_ = static_cast<size_t>(-1);
        }

        //! Queue size
        std::size_t size() {
            return size_ + (unsigned)1;
        }

        //! Maximum queue size
        std::size_t max_size() {
            return max_size_;
        }

        //! Check if is empty
        bool empty() {
            return size_ == -1;
        }

        //! Check if queue is full
        bool full() {
            return size_ == max_size_ -1;
        }

    private:
        T* contents;
        int size_;
        std::size_t max_size_;

        static const auto DEFAULT_SIZE = 10u;

        void full_check() {
            if (full()) {
                throw std::out_of_range("Queue is full");
            }
        }

        void empty_check() {
            if (empty()) {
                throw std::out_of_range("Queue is empty");
            }
        }
    };
}


#endif //TRACK_SIMULATOR_QUEUE_H
