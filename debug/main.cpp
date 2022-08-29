#include <random>
#include <iostream>
#include <cmath>

using namespace std;

const int gridSize = 10;
const int n_generations = 10; 
const int seed = 3; 
const float sparsity = 0.5;

void printGrid(bool **gridOne, int size){
    for(int a = 0; a < size; a++)
        {
        for(int b = 0; b < size; b++)
        {
            if(gridOne[a][b])
            {
                cout << " 1 ";
            }
            else
            {
                cout << " 0 ";
            }
            if(b == size-1)
            {
                cout << endl;
            }
        }
    } 
    cout << "\n\n";
}  

int countLiveNeighs(bool **gridOne, int i, int j)
{
    int row_below = gridOne[i+1][j]+gridOne[i+1][j-1]+gridOne[i+1][j+1]; 
    int row_above = gridOne[i-1][j]+gridOne[i-1][j-1]+gridOne[i-1][j+1]; 
    int row_same = gridOne[i][j+1]+gridOne[i][j-1];
    return row_above+row_below+row_same;  
}

void generateGrid(bool **gridOne, int N){
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0,1.0);
    for (int i = 2; i < N; i++)
    {
        for (int j = 2; j < N; j++)
        {
           bool entry = round(distribution(generator)-0.50+sparsity);
           gridOne[i][j] = entry; 
        }

    }   
}

void updateGrid(bool **gridOne, bool **gridTwo, int N){
    for (int i = 1; i < N; i++){
            for (int j = 1; j < N; j++){
               int live_neigh = countLiveNeighs(gridOne,i,j); 
               if (live_neigh == 3)
               {
                    gridTwo[i+1][j+1] = 1;             
               }
               else if (gridOne[i][j]==1 && live_neigh == 2)
               {
                    gridTwo[i+1][j+1] = 1;
               }
               else
               {
                gridTwo[i+1][j+1] = 0;
               }              
    }
    } 
}



int main()
{   
    bool **gridOne;
    gridOne = new bool *[gridSize];
    for(int i = 0; i < (gridSize); i++){
        gridOne[i] = new bool[gridSize];
    }
    generateGrid(gridOne,gridSize-2);
    
    int size = gridSize;
    for (int j = 0; j < n_generations; j++) {
        printGrid(gridOne,size);
        bool **gridTwo;
        gridTwo = new bool *[size+2];
        for(int i = 0; i < (size+2); i++){
            gridTwo[i] = new bool[size+2];
        }
        updateGrid(gridOne,gridTwo,size-1);
        gridOne = gridTwo;
        size+=2;
        free(gridTwo);
    }
    return 0;
}





