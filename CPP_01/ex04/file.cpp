#include "file.h"

// I used c_str() function because i needed to convert from string to c_style string
// why ? because in c++98 ifstream and ofstream expect c_style string

void    redirectFile(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   fileInput(filename.c_str());
    std::ofstream   fileOutput((filename + ".replace").c_str());

    if (fileInput.is_open() && fileOutput.is_open())
    {
        std::string line;
        while (getline(fileInput, line))
        {
            size_t  pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            fileOutput << line << std::endl;
        }
    }
    else
    {
        std::cout << "Error openning the file " << filename << std::endl;
    }
    fileInput.close();
    fileOutput.close();
}