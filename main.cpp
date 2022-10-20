// BubbenSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream inputFile("numbers.txt");
    std::string numberString = "";

    inputFile >> numberString;
    std::cout << "File content: " << numberString << std::endl;

    std::vector<int> numberVector;
    for (int i = 0; i < numberString.length(); i++) {
        numberVector.push_back((int)(numberString.c_str()[i]));
    }
    std::cout << numberVector.data();
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
}

