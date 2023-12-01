#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

string concatenateFirstAndLast(const string &inputString)
{
    string result;

    if (!inputString.empty())
    {
        result = inputString.front(); 

        if (inputString.length() > 1)
        {
            result += inputString.back();
        }
    }
    return result;
}

int getNumber(const string& inputString){

    string temp;
    for (int i = 0; i < inputString.length(); i++){
        if(isdigit(inputString[i])){
            temp.push_back(inputString[i]);
        }
    }
    string firstAndLast = concatenateFirstAndLast(temp);
    int number;
    number = std::stoi(firstAndLast);
    cout << number << endl;
    return number;
}

int main()
{
    ifstream inputFile("input.txt");
    vector<int> numbers;

    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return 1; 
    }

    string line;
    while (getline(inputFile, line))
    {
        int number = getNumber(line);
        numbers.push_back(number);
    }


    inputFile.close();
    int sum_of_elems;
    sum_of_elems = std::accumulate(numbers.begin(), numbers.end(),
                                   decltype(numbers)::value_type(0));
    
    cout << sum_of_elems << endl;

    return 0;
}