#include <iostream>
#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data * deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main(void) {

    Data data;

    data.x = 42;
    data.y = 66;

    Data * dataptr = &data;

    uintptr_t serialized = serialize(dataptr);
    Data * deserialized = deserialize(serialized);

    data.x = 43;
    data.y = 67;

    std::cout << "data.x = " << data.x <<  std::endl;    
    std::cout << "data.y = " << data.y <<  std::endl; 
    std::cout << std::endl;

    std::cout << "Deserialized.x = " << deserialized->x << std::endl;
    std::cout << "deserialized.y = " << deserialized->y << std::endl; 

    return 0;
}