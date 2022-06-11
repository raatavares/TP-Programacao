#include "ficheiros.h"

int existeFicheiro(char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "rb")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
