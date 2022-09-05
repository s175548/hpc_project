#include <vector>
#include <iostream>

void a(bool &s, int rows, int cols){
        std::cout<<s[9][9];
}
int main(int argc, char *argv[]){
    int gridSize = atoi(argv[0]);
    bool s[gridSize][gridSize];
    s[gridSize][gridSize] = 1; 
    a(**s,10,10);
    return 0;
}