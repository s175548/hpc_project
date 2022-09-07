#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <string>
#include "../include/gof_serial_contig_mem.h"

using namespace std;


const int s = 2;
const int g = 4;
const int t = 1;
int generations = 10;
int seed = 0;
int gridSizes[g]={10, 100, 1000, 2000}; 
float sparsities[s] = {0.1,0.9}; 
float times[s][g][t];


float avg(float *arr) {
    float sum = 0;
    for (int i = 0; i < t; i++) {
        sum += arr[i];
    }
    return sum / t;
}

float var(float *arr) {
    float sum = 0;
    float mean = avg(arr);
    for (int i = 0; i < t; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sum / t;
}


void save_stats(float (*stats)[s][g]) {
    ofstream file;
    file.open("../output/performance_stats/stats_contig_mem.txt");
    string stat_types[2] = {"average ","variance "}; 

    for (int i = 0; i < s; i++){
        file << "sparsity: " << sparsities[i] << "\n\n";
        file << left << setw(20) << "gridsize: ";
        for (int j = 0; j < g; j++){
                file << left << setw(15) << gridSizes[j];
            }  
        file << "\n";    
        for (int k=0; k<2; k++){
            file << right << setw(20) << stat_types[k];
                    for (int j = 0; j < g; j++){
                        file << left << setw(15) << stats[k][i][j];
            }
            file << "\n";  
        }
    file << "\n\n\n";
    }
}

void compute_and_save_stats(float (*time)[g][t]) {
    float stats[2][s][g];
    for (int i = 0; i < s; i++){
        for (int j = 0; j < g; j++){
             stats[0][i][j]= avg(time[i][j]);
             stats[1][i][j]= var(time[i][j]);
        }
    }
    save_stats(stats);
}



int main() {
    for (int i = 0; i < s; i++){
        for (int j = 0; j < g; j++){
                for (int k = 0; k < t; k++){ 
                        auto start = chrono::high_resolution_clock::now();
                        rollOut(gridSizes[j], generations,sparsities[i], seed, false,false,"");
                        auto stop = chrono::high_resolution_clock::now();
                        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
                        times[i][j][k]=duration;
                }
        }
    }
    compute_and_save_stats(times);

    return 0;
}