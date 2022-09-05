#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include "../include/gof_serial_contig_mem.h"
using namespace std;

vector<int> gridSizes= {10, 100, 1000}; 
int g = gridSizes.size();
vector<float> sparsities = {0.1,0.9}; 
int s = sparsities.size();
int trials = 5;
int generations = 10;
int seed = 0;


float avg(vector<float> arr) {
    float sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum / arr.size();
}

float var(vector<float> arr) {
    if (arr.size() <= 1) {
        return 0;
    }
    float sum = 0;
    float mean = avg(arr);
    for (int i = 0; i < arr.size(); i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sum / (arr.size() - 1);
}

vector<vector<vector<float> > > compute_stats(vector<vector<vector<float> > > &times,
                                     float (*func)(vector<float>) ){
    vector<vector<vector<float> > > stats (2,vector<vector<float> >(s,vector <float>(g,0)));
    for (int i = 0; i < s; i++){
        for (int j = 0; j < g; j++){
             stats[0][i][j]= avg(times[i][j]);
             stats[1][i][j]= var(times[i][j]);
        }
    }
    return stats;
}

void save_stats(vector<vector<vector<float> > > &stats) {
    ofstream file;
    file.open("../output/performance_stats/stats_contig_mem.txt");
    string stat_types[2] = {"average ","variance "}; 

    for (int i = 0; i < s; i++){
        file << "sparsity: " << sparsities[i] << "\n\n";
        file << left << setw(20) << "gridsize: ";
        for (int j = 0; j < g; j++){
                file << left << setw(10) << gridSizes[j];
            }  
        file << "\n";    
        for (int k=0; k<2; k++){
            file << right << setw(20) << stat_types[k];
                    for (int j = 0; j < g; j++){
                        file << left << setw(10) << stats[k][i][j];
            }
            file << "\n";  
        }
    file << "\n\n\n";
    }
}



int main() {
    vector<vector<vector<float> > > times (s,vector<vector<float> >(g,vector <float>(trials,0)));
    for (int i = 0; i < s; i++){
        for (int j = 0; j < g; j++){
                for (int k = 0; k < trials; k++){ 
                        auto start = chrono::high_resolution_clock::now();
                        rollOut(gridSizes[j], generations,sparsities[i], seed, false,false,"");
                        auto stop = chrono::high_resolution_clock::now();
                        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start).count();
                        times[i][j][k]=duration;
                }
        }
    }
    vector<vector<vector<float> > > stats = compute_stats(times,avg);
    save_stats(stats);
    return 0;
}