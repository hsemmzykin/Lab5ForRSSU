#include <iostream>
#include <omp.h>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <string>

// #define TIME_SEQUENTIAL
// #define OMP

#include "Palindromes.h"
#include "RSGen.h"
using namespace std::chrono;

int main(){
    srand(time(0));
    GenerateFile("TEXT.txt");
    std::fstream infile;
    std::fstream outfile;
    infile.open("TEXT.txt", std::ios::in);
    outfile.open("OUT.txt", std::ios::out);
#ifdef TIME_SEQUENTIAL
    auto begin = high_resolution_clock::now();
#endif
#ifdef OMP
    double start, end;
#endif
    if (infile.is_open()){
        std::string tmp;
    #ifdef TIME_SEQUENTIAL
    #endif
        #ifdef OMP
        double start = omp_get_wtime();
        #pragma omp parallel for
        #endif
        for (; std::getline(infile, tmp);){
            if (isPalindrome(tmp)){
                outfile << tmp << " ";
            }
        }
    }
    infile.close();
    outfile.close();
#ifdef OMP
    end = omp_get_wtime();
    std::cout << "TIME WITH OMP IN SECONDS: " << (double) end - (double) start << std::endl;
#endif
#ifdef TIME_SEQUENTIAL
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - begin);
    std::cout << "TIME WITH 1 THREAD IN MICROSECONDS: " << duration.count() << std::endl;
#endif
}
