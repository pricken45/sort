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



int main()
{
    std::ifstream inputFile("numbers.txt");
    std::string numberString = "";

    
    while (1) {
        char c;
        c = inputFile.get();
        if (inputFile.eof())
            break;
        numberString += c;
    }
    


    std::cout << numberString.length() << std::endl;
    char * cstr = new char [numberString.length()+1];
    std::strcpy (cstr, numberString.c_str());
    std::cout<<"cstr: " << cstr << std::endl;
    std::vector<int> numberVector;
    for (int i = 0; i < numberString.length(); i++) {
        //numberVector.push_back(atoi(cstr[i]));
        //std::cout << numberVector[i];
        
        //std::cout << numberString.c_str()[i];
    }
    //std::cout << numberVector.data();
    std::vector<int> nC = numberVector;
    int b = nC.size();
    int a[b];
    for (int i = 0; i < nC.size(); i++)
    {
        a[i] = nC[i];
    }

    int numbers[] = {0,4,3,5,3,5,3};
    int swaps = 1;
    int iterations = 0;

    int len = sizeof(numbers) / sizeof(numbers[0]);
    
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
    std::cout << numbersS;
    std::cout << "This took " << iterations << " iterations";
    char ch;
    
    std::cin >> ch;

    inputFile.close();
}

