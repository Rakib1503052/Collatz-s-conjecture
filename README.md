# Collatz-s-conjecture
A program to simulate Collatz conjecture for any range of numbers. It takes a custom input of the range and then simulates Collatz conjecture for each number in the range and plots out the maximum number reached in the sequence and the total steps in the sequence for each number.
________________________________________________________________________________________________________________

# Pre-requisits
Python installed and added to path variable. Numpy and Matplotlib installed.
Compiled with gcc 8.1.0. Uses embedded python via "matplotlibcpp.h" library for plotting.
The src has CodeBlocks project file included which on Windows 10 default (python 3.10 installation) can compile as is. For other compilers/IDEs, indicate the include directories of python and numpy and link to python static library (python3.lib on Windows 10).
________________________________________________________________________________________________________________

# Running the program
Fairly simple. Set the starting number of the range, ending number of the range, number of threads to use. Using multiple threads in multicore processor can significantly increases the speed. Once started plots the maximum of sequence and steps in sequence for each number in animated graph (will make optional later) and saves the graph at the end.
________________________________________________________________________________________________________________

# Caution
Avoid closing the program before it finishes. It might cause a few killobytes of memory leak.
