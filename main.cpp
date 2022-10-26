// BubbenSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


int main(int argc, char **argv)
{
    if (!(argc > 1)) {
        std::cout << "No provided input file. Closing program...\n";
        std::cout << "Usage: ./sort <input file> <output file (optional)> \n";
        return 0;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile.good()) {
        std::cout << "Provided input file was not found. Closing program...\n";
        std::cout << "Usage: ./sort <input file> <output file (optional)> \n";

        return 0;
    }
    std::string numberString = "";
    
    while (1) {
        char c;
        c = inputFile.get();
        if (inputFile.eof())
            break;
        numberString += c;
    }
    
    std::vector<std::string> splittedString = split(numberString, "\n");

    std::vector<int> numberVector;
    for (int i = 0; i < splittedString.size(); i++) {
        numberVector.push_back(std::stoi(splittedString[i]));
    }
    //std::cout << numberVector.data() 
    std::vector<int> numbers = numberVector;

    int swaps = 1;
    int iterations = 0;
    int len = numberVector.size();
    
    while (swaps != 0) {
        swaps = 0;
        iterations++;
        for (int i = 0; i < len - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                swaps += 1;
                int t1 = numbers[i];
                int t2 = numbers[i + 1];
                numbers[i] = t2;
                numbers[i + 1] = t1;
            }
        }
    }
    
    std::string numbersS = "";

    for (auto l : numbers) {
        numbersS += std::to_string(l) + "\n";
    }
    std::cout << "Sorting took " << iterations << " iterations\n";
    if (argc > 2) {
        std::cout << "Writing to file " << argv[2] << "...\n";
        std::ofstream outputfile(argv[2]);
        outputfile << numbersS;
        outputfile.close();
    } else {
        std::cout << "No output file was provided. Writing to default out.txt\n";
        std::ofstream outputfile("out.txt");
        outputfile << numbersS;
        outputfile.close();
    }
    
    inputFile.close();
    return 0;
}

