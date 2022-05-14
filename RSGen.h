#ifndef LAB5FORRSSU_RSGEN_H
#define LAB5FORRSSU_RSGEN_H
#include <string>
#include <random>
#include <fstream>
#include <iostream>
std::string randomStrGen() {
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    size_t length = rand() % 1000;
    result.resize(length);

    for (int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}
void GenerateFile(std::string PATH){
    std::ofstream o(PATH.c_str());
    for (int i = 0; i < 1000; ++i){
        o << randomStrGen() << " ";
    }
}

#endif
