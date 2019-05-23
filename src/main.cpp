#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) 
{
    cout << "Hello World" << endl;

    int dataBlockSize       = 1024;     // size of each write (in ints)
    int writeCount = 256*1024;          // times to write the buffer
    string filename = "test.dat";

    clock_t     previous;               // used to measure clock() intervals
    clock_t     now;                    // for each write


    int* buffer = new int[dataBlockSize];   // data buffer to write
    clock_t* timeMarks = new clock_t[writeCount];   // buffer to store time marks

    cout <<"sizeof int = " << sizeof buffer[0] << endl;
    cout <<"sizeof buffer = " << sizeof buffer[0]*dataBlockSize << endl;
    cout <<"max random number = " << RAND_MAX << endl;
    cout <<"CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl;

    // populate buffer with random data
    srand(time(NULL));
    for(int i=0; i<dataBlockSize; i++)
        buffer[i] = rand();

    // write the data
    ofstream        testFile(filename);
    previous = clock();
    for(int i=0; i<writeCount; i++) {
        testFile.write((const char*)buffer, sizeof buffer[0]*dataBlockSize);
        now = clock();
        timeMarks[i] = now - previous;
        previous = now;
    }
    testFile.close();

    // report the results
    for(int i=0; i<writeCount; i++) {
        cout << timeMarks[i] << endl;
    }


    delete[] buffer;
    delete[] timeMarks;
    return 0;
}