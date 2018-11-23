/*
 * References:
 *
 *   [1] http://stackoverflow.com/questions/13074689/maximum-memory-that-can-be-allocated-dynamically-and-at-compile-time-in-c
 */

#include <cstddef>
#include <iostream>
#include <new>

int main()
{
    bool atMaximum = false;
    unsigned long long nbBytesAllocated = 0;
    
    do {
       char *test = NULL;
       try {
           test = new char[1]();
           nbBytesAllocated++;
       } catch(const std::bad_alloc& e) {
           atMaximum = true;
       }
    } while (!atMaximum);

    std::cout << "Maximum number of bytes allocated: " << nbBytesAllocated << std::endl;
}
