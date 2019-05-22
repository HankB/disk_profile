#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) 
{
    std::cout << "Hello World" << std::endl;

    int dataBlockSize       = 1024;
    int* buffer = new int[dataBlockSize];
    std::cout <<"sizeof int = " << sizeof buffer[0] << std::endl;
    std::cout <<"sizeof buffer = " << sizeof buffer[0]*dataBlockSize << std::endl;
    std::cout <<"max random number = " << RAND_MAX << std::endl;
    srand(time(NULL));
    for(int i=0; i<dataBlockSize; i++)
        buffer[i] = rand();

    for(int i=0; i<10; i++)
        std::cout << buffer[i] << " ";
    std::cout << std::endl;

    delete[] buffer;
}