#pragma once

#include <iostream>
#include <string.h>

class File {
    private:
        std::string pathToFile;
        std::string newFileName;

    public:
        File();
        ~File();

        void setPathToFile(std::string valuePath);
        void printFileContents(std::string filename);
        void createUniqueFile();
};
