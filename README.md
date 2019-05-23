# disk_profile
profile write (and read) performance over time.

## Motivation

This is intended to be a somewhat different kind of disk benchmark. Looking at the results of the Gnome Disks benchmarks, it is apparent that disk performance varies over time as a benchmark procedes. The purpose of this effort is to record the performance through a write (and read) benchmark so the performance variation can be observed.

## Requirements and environment.

Developed and tested in Linux (Debian, Raspbian.)

`cmake` and `g++`

## Status

Initial `cmake` config (`CMakeLists.txt`) copied and tailored.
"Hello World" C++ source coded, built and run to validate `cmake` config.

## Build

```bash
mkdir build
cd build
cmake ..
make
./dpf
```
