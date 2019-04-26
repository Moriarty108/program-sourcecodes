#include <fstream>
#include <cstdlib>
#include <time.h>

class InputFileGen
{
    std::fstream fileStream;
    std::string filename;

  public:
    static const int ARRAY_END = 0xc000;

    InputFileGen()
    {
        fileStream.flush();
        filename.clear();
        srand(time(NULL));
    }

    void openFile(const std::string &filename)
    {
        this->filename = filename;
        fileStream.open(filename.c_str(), std::fstream::out | std::fstream::in | std::fstream::app);
    }

    void openFile()
    {
        if (!filename.empty())
            fileStream.open(filename.c_str(), std::fstream::out | std::fstream::in | std::fstream::app);
    }

    InputFileGen(std::string filename)
    {
        this->openFile(filename);
    }

    InputFileGen(const char *filename)
    {
        this->filename = filename;
    }

    void closeFile()
    {
        fileStream.close();
    }

    std::string getFileName()
    {
        return this->filename;
    }

    void generate(int n_space, int lowerLimit, int range)
    {
        for (int i = 0; i < n_space; i++)
        {
            int num = rand() % (range + 1) + lowerLimit;
            fileStream << num << " ";
        }
    }
    int read(int *buffer)
    {
        fileStream.seekg(std::ios::beg);
        int i = 0;
        while (!InputFileGen::fileStream.eof())
        {
            fileStream >> buffer[i++];
        }
        buffer[i - 1] = InputFileGen::ARRAY_END;
        return (i - 1);
    }
};
