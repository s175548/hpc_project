#include <string>

void printGrid(int *gridOne, int gridSize);

void saveGrid(int *gridOne, int gridSize, std::string filename);

int countLiveNeighs(int *gridOne,int *gridTwo, int i, int j, int N);


void generateGrid(int *gridOne, int gridSize,int n_generations,float sparsity, int seed);

void readGrid(std::string filename, int *gridOne,int gridSize,int n_generations);
   
void updateGrid(int *gridOne, int *gridTwo, int gridSize, int generations_left);

void rollOut(int gridSize_start, int n_generations, float sparsity, int seed, bool verbose, bool load_grid, 
            std::string filename);










