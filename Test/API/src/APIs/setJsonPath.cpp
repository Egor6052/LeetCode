#include "../../lib/API.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

void API::setJsonPath(std::string valueJsonPath) {
    this->pathJSON = valueJsonPath;
}