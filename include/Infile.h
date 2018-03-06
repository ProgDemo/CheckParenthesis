#ifndef INFILE_H
#define INFILE_H

#include <fstream>

class Infile
{
    private:
        enum status {NORM, ABNORM};
        std::ifstream file;
        status sf;
        int df;
    public:
        Infile();
};

#endif // INFILE_H
