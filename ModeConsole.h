#ifndef MODECONSOLE_H
#define MODECONSOLE_H

#include <string>
#include "Jeu.h"

class ModeConsole {
private:
    std::string inputFile;
    std::string outputDir;

public:
    ModeConsole(const std::string& inputFile, const std::string& outputDir);
    void run();
};

#endif // MODECONSOLE_H
