#include <vector>
#include <string>
#include "../include/gof_serial_contig_mem.h"
using namespace std;

vector<string> test_init = {"init_1.txt","init_2.txt","init_3.txt","init_4.txt"};

int main(){
    for(auto filename: test_init) {
        rollOut(4, 5, 1, 1, true, true, filename);

    }
    return 0;
}