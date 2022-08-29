#include <random>
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

const int active_gridsize = 11;
const int n_generations = 10; 
const int gridSize = active_gridsize+n_generations+2;
const int seed = 1; 
const float sparsity = 0.5;

void printGrid(bool **gridOne, int size){
    for(int a = 1; a < size; a++)
        {
        for(int b = 1; b < size; b++)
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

void generateGrid(vector<vector<bool>> gridOne){
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0,1.0);
    int N = gridSize-1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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
                    gridTwo[i][j] = 1;             
               }
               else if (gridOne[i][j] && live_neigh == 2)
               {
                    gridTwo[i][j] = 1;
               }
               else
               {
                gridTwo[i][j] = 0;
               }              
    }
    } 
}






int main()
{   
    //bool gridOne[gridSize][gridSize] = { false };
    vector<vector<bool>> gridOne(gridSize,vector<int>(gridSize));

    generateGrid(gridOne);
    
    //vector<vector<bool>> gridO#include <random>
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

const int active_gridsize = 11;
const int n_generations = 10; 
const int gridSize = active_gridsize+n_generations+2;
const int seed = 1; 
const float sparsity = 0.5;

void printGrid(bool **gridOne, int size){
    for(int a = 1; a < size; a++)
        {
        for(int b = 1; b < size; b++)
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

void generateGrid(vector<vector<int> > gridOne){
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(0.0,1.0);
    int N = active_gridsize-1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
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
                    gridTwo[i][j] = 1;             
               }
               else if (gridOne[i][j] && live_neigh == 2)
               {
                    gridTwo[i][j] = 1;
               }
               else
               {
                gridTwo[i][j] = 0;
               }              
    }
    } 
}






int main()
{   
    //bool gridOne[gridSize][gridSize] = { false };
    vector<vector<int> > gridOne(gridSize,vector<int>(gridSize));

    generateGrid(gridOne);
    int size = active_gridsize+
    for (int j = 0; j < n_generations; j++) {
        printGrid(gridOne,gridSize-1);
        bool **gridTwo;
        gridTwo = new bool *[size+1];
        vector<vector<int> > gridTwo(gridSize,vector<int>(gridSize));
        updateGrid(gridTwo,gridTwo,size-1);
        size+=1;
        gridOne = gridTwo;
    }
    
    //vector<vector<bool>> gridOne(gridSize,vector<int>(gridSize));
    //int size = gridSize;
}




ne(gridSize,vector<int>(gridSize));
    //int size = gridSize;
    int size = gridSize;
    for (int j = 0; j < n_generations; j++) {
        printGrid(gridOne,size);
        bool **gridTwo;
        gridTwo = new bool *[size+1];
        for(int i = 0; i < (size+1); i++){
            gridTwo[i] = new bool[size+1];
        }
        updateGrid(gridOne,gridTwo,size-1);
        size+=1;
        gridOne = gridTwo;
    }
    return 0;
}




