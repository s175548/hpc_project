#include <string>



void printGrid(bool **gridOne, int size);

int countLiveNeighs(bool **gridOne, int i, int j);

void generateGrid(bool **gridOne, int N,int sparsity, int seed);

void updateGrid(bool **gridOne, bool **gridTwo, int N);

void rollOut(int gridSize, int n_generations,int sparsity, int seed, bool verbose, bool load_grid, std::string filename);









