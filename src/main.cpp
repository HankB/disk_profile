#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    int dataBlockSize = 1024;    // size of each write (in ints)
    int writeCount = 256 * 1024; // times to write the buffer
    string filename = "test.dat";

    clock_t previous; // used to measure clock() intervals
    clock_t now;      // for each write

    int *buffer = new int[dataBlockSize];         // data buffer to write
    clock_t *timeMarks = new clock_t[writeCount]; // buffer to store time marks

    cerr << "sizeof int = " << sizeof buffer[0] << endl;
    cerr << "sizeof buffer = " << sizeof buffer[0] * dataBlockSize << endl;
    cerr << "max random number = " << RAND_MAX << endl;
    cerr << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl;

    // populate buffer with random data
    srand(time(NULL));
    for (int i = 0; i < dataBlockSize; i++)
        buffer[i] = rand();

    // write the data
    ofstream testFile;
    testFile.rdbuf()->pubsetbuf(0, 0);
    testFile.open(filename);
    previous = clock();
    for (int i = 0; i < writeCount; i++)
    {
        testFile.write((const char *)buffer, sizeof buffer[0] * dataBlockSize);
        //testFile.flush();
        now = clock();
        timeMarks[i] = now - previous;
        previous = now;
    }
    testFile.close();

    int coalesce = 200; // coalesce readings to report

    // report the results
    for (int i = 0; i < writeCount / coalesce; i++)
    {
        int accum = 0;
        for (int j = 0; j < coalesce; j++)
            accum += timeMarks[i * coalesce + j];
        cout << accum << endl;
    }

    delete[] buffer;
    delete[] timeMarks;
    return 0;
}