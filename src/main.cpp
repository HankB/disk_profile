#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) 
{
    cout << "Hello World" << endl;

    int dataBlockSize       = 1024;
    int writeCount = 256*1024;
    string filename = "test.dat";

    int* buffer = new int[dataBlockSize];
    cout <<"sizeof int = " << sizeof buffer[0] << endl;
    cout <<"sizeof buffer = " << sizeof buffer[0]*dataBlockSize << endl;
    cout <<"max random number = " << RAND_MAX << endl;
    srand(time(NULL));
    for(int i=0; i<dataBlockSize; i++)
        buffer[i] = rand();

    for(int i=0; i<10; i++)
        cout << buffer[i] << " ";
    cout << endl;

    ofstream        testFile(filename);
    //testFile.open(filename);
    for(int i=0; i<writeCount; i++)
        testFile.write((const char*)buffer, sizeof buffer[0]*dataBlockSize);
    testFile.close();

    delete[] buffer;
    return 0;
}