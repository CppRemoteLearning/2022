#include <fstream>
#include <sstream>

class FileOperations {
    public:
        static std::string readStringFromFile(std::string filePath);

        static void writeStringToFile(std::string stringToWrite, std::string filePath);
};