#include <iostream>
#include <chrono>
#include <vector>
#include "gof_serial.h"

std::vector<int> > gridSizes = {10, 100, 1000, 10000}; 
int trials = 10;
int generations = 100;
int seed = 0
std::vector<int> > sparsities = {0.1,0.9}; 




int main(int argc, char *argv[]) {
    for (std::vector<int>::iterator s = sparsities.begin() ; s != sparsities.end(); ++s){
    for (std::vector<int>::iterator g = gridSizes.begin() ; g != gridSizes.end(); ++g){
                auto start = std::chrono::high_resolution_clock::now();
                rollOut(g, generations,s, seed, false)
                auto stop = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
                times.push_back(duration);
    return 0;
        }
    }
}