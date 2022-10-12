# disk_profile

profile write (and read) performance over time.

## Status

This project has been moved to [bitbucket](https://gitlab.com/HankB/disk_profile) due to Microsoft's cavalier use of my code via Copilot. Some progress was made there (which I shall commit and push in a moment.)

Then I more or less abandoned this effort. I decided it would make more sense to leverage something like `iostat` or `sar` to collect statistics while any convenient disk benchmark was run. Woops... Gitlab pissed me off with their decision to remove stagnant projects. I overreacted and moved it to my private Git server. That is (as of late 2022) WIP on my private Git server. Someday it will probably return to Github. If you want to be notified, the best way is probably to file an issue here.

## Motivation

This is intended to be a somewhat different kind of disk benchmark. Looking at the results of the Gnome Disks benchmarks, it is apparent that disk performance varies over time as a benchmark procedes. The purpose of this effort is to record the performance through a write (and read) benchmark so the performance variation can be observed.

## Requirements and environment.

Developed and tested in Linux (Debian, Raspbian.)

`cmake` and `g++`

## Build

```bash
mkdir build
cd build
cmake ..
make
./dpf
```
