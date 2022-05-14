#ifndef LAB5FORRSSU_PALINDROMES_H
#define LAB5FORRSSU_PALINDROMES_H
#include <omp.h>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string s){
std::string tmp = s;
#ifdef OMP
#pragma parallel for
#endif
    for (size_t i = 0; i < s.size() / 2; ++i){
        std::swap(s[i], s[s.size() - 1 - i]);
    }
    return s == tmp;
}

#endif
