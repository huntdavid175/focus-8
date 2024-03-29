#include <stdio.h>

struct MyData
{
    int howMany;
    char theText[21];
    char directoryPath[21];
    char filename[21];
};

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    if (argc != 5)
    {
        printf("Error");
        return -1;
    }

    struct MyData myArgs;
    myArgs.howMany = atoi(argv[0]);

    strcpy(myArgs.theText, argv[1]);
    strcpy(myArgs.directoryPath, argv[2]);
    strcpy(myArgs.filename, argv[3]);

    char fileFullPath[42];

    strcat(myArgs.directoryPath, myArgs.filename);

    fp = fopen(fileFullPath, "w");

    if (fp == NULL)
    {
        printf("Error, couldn't open file");
        return -1;
    }

    int isPrinted = fprintf(fp, myArgs.theText);
    if (isPrinted < 0)
    {
        printf("Couldn't write to file");
        return -1;
    }

    return 0;
}