// BubbenSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <chrono>
#include <iostream>
#include <cmath>

std::vector<int> quickSort(std::vector<int> sequence) {
    int length = sequence.size();
    if (length <= 1) {
        return sequence;
    } else {

        //std::cout << elems[1];
        int pivot = sequence[length - 1];
        sequence.pop_back();
        std::vector<int> less;
        std::vector<int> more;
        for (int item: sequence) {
            if (item > pivot) {
                more.push_back(item);
            } else {
                less.push_back(item);
            }
        }
        less = quickSort(less);
        more = quickSort(more);
        std::vector<int> returnation;
        returnation.reserve(less.size() + more.size());
        returnation.insert( returnation.end(), less.begin(), less.end());
        returnation.push_back(pivot);
        returnation.insert( returnation.end(), more.begin(), more.end());

        return returnation;
    }
}
 

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
    auto start = std::chrono::system_clock::now();
    if (!(argc > 1)) {
        std::cout << "Error: No provided input file. Closing program...\n";
        std::cout << "Usage: ./sort <input file> <output file (optional)> \n";
        return 0;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile.good()) {
        std::cout << "Error: Provided input file was not found. Closing program...\n";
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
    std::vector<int>& numbers = numberVector;

    int swaps = 1;
    int iterations = 0;
    int len = numberVector.size() - 1;

    std::vector<int> sorted;
    sorted = quickSort(numbers);

    std::string numbersS = "";

    for (auto l : sorted) {
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
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Sorting took " << elapsed_seconds.count() << " seconds\n";
    return 0;
}