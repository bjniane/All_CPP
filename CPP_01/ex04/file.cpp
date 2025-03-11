#include "file.h"

void    redirectFile(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   inputFile(filename.c_str());
    std::ofstream   outputFile((filename + ".replace").c_str());

    if (inputFile.is_open() && outputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            size_t  pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            outputFile << line << std::endl;
        }
    }
    else
        std::cout << "Error openning the file" << std::endl;
    inputFile.close();
    outputFile.close();
}