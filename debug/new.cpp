#include <vector>
#include <iostream>

void a(std::vector<std::vector<int> > &s,int rows, int cols){
        std::cout<<"1";
}
int main(){
    std::vector<std::vector<int> > s(10,std::vector<int>(10)); 
    a(s,10,10);
    return 0;
}