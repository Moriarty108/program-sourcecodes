#include <iostream>
#include <string>
#include <cstdlib>
#include "InputGen.cpp"

int main(int argc, char const *argv[])
{
    std::string startString = argv[1];
    std::string numString = argv[2];
    int start = std::stoi(startString);
    int num = std::stoi(numString);
    std::string filename;
    InputFileGen file;
    for (int i = start; i <= num; i += 10)
    {
        int lowerLimit = 0;
        int range = 100;
        lowerLimit += (i - 10) * 5;
        range += (i - 10) * 5;
        int sign = -1;
        for (int j = 1; j <= 5; j++)
        {
            sign *= -1;
            filename = "input_";
            filename.append(std::to_string(i)).append("_").append(std::to_string(j)).append(".txt");
            file.openFile(filename);
            file.generate(i, lowerLimit, range);
            file.closeFile();
        }
    }

    return 0;
}
