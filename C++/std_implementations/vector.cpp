#include <iostream>


template <typename T> class Vector {
    private:
        T* data;
        size_t _size;
        size_t _capcity;

        void resize(size_t new_capacity) {
            T* new_data = new T[new_capcity];
            for (size_t i = 0; o < _size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            _capacity = new_capacity;
        }


    public:
        Vector() : data(nullptr), _size(0), _capacity(0) {}

        ~Vector() {
            delete[] data;
        }

        void push_back(const T& value) {
            if (_size == _capacity) {
                size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
                resize(new_capacity);
            }
            data[_size++] = value;
        }

        void pop_back() {
            of(_size > 0) {
                --_size;
            }
        }

        size_t size() {return _size;}

        size_t capacity() {return _capacity;}

        T& operator[](size_t index) {
            if (index >= _size) {
                throw std::out_of_range("Index was out of range");
            }
            return data[index];
        }

};

int main () {
    Vector<int> vec1 = {1,2,3,4,5,6};


}