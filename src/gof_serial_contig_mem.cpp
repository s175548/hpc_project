#include <iostream>
#include <cmath>
#include <random>
#include <array>
#include <fstream>
#include <string>



void printGrid(int *gridOne, int gridSize){
    for(int a = 2; a < gridSize-2; a++)
        {
        for(int b = 2; b < gridSize-2; b++)
        {
            if(gridOne[a*gridSize+b])
            {
                std::cout << " 1 ";
            }
            else
            {
                std::cout << " 0 ";
            }
            if(b == gridSize-3)
            {
               std::cout << std::endl;
            }
        }
    } 
    std::cout << "\n\n";
}  


void saveGrid(int *gridOne, int gridSize, std::string filename){
    filename = "../output/correctness_prints/last_grid_prints"+filename;
    std::ofstream file;
    file.open(filename);
    for(int a = 2; a < gridSize-2; a++)
        {
        for(int b = 2; b < gridSize-2; b++)
        {
            if(gridOne[a*gridSize+b])
            {
                file << " 1 ";
            }
            else
            {
                file << " 0 ";
            }
            if(b == gridSize-3)
            {
               file << '\n';
            }
        }
    } 
    file.close();
}  

int countLiveNeighs(int *gridOne,int *gridTwo, int i, int j, int N)
{
    int row_below = gridOne[(i+1)*N+j]+gridOne[(i+1)*N+j-1]+gridOne[(i+1)*N+j+1]; 
    int row_above = gridOne[(i-1)*N+j]+gridOne[(i-1)*N+j-1]+gridOne[(i-1)*N+j+1]; 
    int row_same = gridOne[i*N+j+1]+gridOne[i*N+j-1];
    return row_above+row_below+row_same;  
}

void generateGrid(int *gridOne, int gridSize,int n_generations,float sparsity, int seed){
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    for (int i = n_generations+2; i < gridSize-n_generations-2; i++)
    {
        for (int j = n_generations+2; j < gridSize-n_generations-2; j++)
        {
           bool entry = round(distribution(generator)-0.50+sparsity);
           gridOne[i*gridSize+j] = entry; 
        }

    }   
}

void readGrid(std::string filename, int *gridOne,int gridSize,int n_generations){
    
    std::string filepath = "../data/"+filename;
    std::ifstream file;
    file.open(filepath);
    int i = n_generations+2;
    int j = n_generations+2;
    char str = '0';
    file >> str;
    while ( !file.eof()) {
        if (str==',')
        {
            i += 1;
            j = n_generations+2;
        }
        else 
        {   
            if(str=='1')
            {
            gridOne[i*gridSize+j]=1;
            }
        j += 1;  
        }
    file >> str;
    } 
    file.close();
}
   
void updateGrid(int *gridOne, int *gridTwo, int gridSize, int generations_left){
    
    for (int i = generations_left+1; i < gridSize-generations_left-1; i++){
            for (int j = generations_left+1; j < gridSize-generations_left-1; j++){
               int live_neigh = countLiveNeighs(gridOne,gridTwo,i,j,gridSize); 
               if (live_neigh == 3)
               {
                    gridTwo[(i)*gridSize+j] = 1;         
               }
               else if (gridOne[i*gridSize+j]==1 && live_neigh == 2)
               {
                    gridTwo[(i)*gridSize+j] = 1;
               }
               else
               {
                gridTwo[(i)*gridSize+j]= 0;
               }
               gridOne[(i-1)*gridSize+j-1] = 0;                  
    }
    } 
}

void rollOut(int gridSize_start, int n_generations, float sparsity, int seed, bool verbose, bool load_grid, 
            std::string filename)
{   
    int gridSize = gridSize_start+4 + 2*n_generations;
    
    int gridsize_sq= std::pow(gridSize,2);
    int *gridOne = new int [gridsize_sq];
    int *gridTwo = new int [gridsize_sq];
    
    if(load_grid){
        readGrid(filename,gridOne,gridSize,n_generations);
    }
    else{
        generateGrid(gridOne,gridSize,n_generations,sparsity,seed);
    }
    int generations_left = n_generations;
    for (int j = 0; j < n_generations; j++) {
        generations_left-=1;  
        if(verbose)
        {
            printGrid(gridOne,gridSize);
        }
        updateGrid(gridOne, gridTwo,gridSize,generations_left);
    }
    if(verbose)
    {
        printGrid(gridOne,gridSize);
    }
    if(load_grid)
    {
        saveGrid(gridOne,gridSize,filename);
    }
    
}








