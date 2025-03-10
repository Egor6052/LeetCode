#include <iostream>
#include <string.h>

#include "../../lib/File.h"

File::File(){
    this->pathToFile = "";
    this->newFileName = "NEW.dump";
}

File::~File(){    }

void File::setPathToFile(std::string valuePath){
    this->pathToFile = valuePath;
}


