/*
 * FILE : f8.cpp
 * PROJECT : SENG1000 - Focus #8
 * PROGRAMMER : Fawaz Dogbe (8982570)
 * FIRST VERSION : 2024-03-29
 * DESCRIPTION :
 * This program receives commandline arguments and writes a file
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kSizeString 21
#define kSizePath 43

struct MyData
{
    int howMany;
    char theText[kSizeString];
    char directoryPath[kSizeString];
    char filename[kSizeString];
};

int main(int argc, char *argv[])
{
    FILE *fp = NULL; // File pointer

    if (argc != 5) // check if right number of arguments was passed
    {
        printf("Error");
        return -2;
    }

    if ((strlen(argv[2]) > (kSizeString - 1))) // Check text to print length
    {
        printf("Program ERROR, Argument text is longer than 20 characters");
        return -2;
    }
    else if (strlen(argv[3]) > (kSizeString - 1)) // Check file path name length
    {
        printf("Program ERROR, Argument destination path is longer than 20 character");
        return -2;
    }
    else if (strlen(argv[4]) > (kSizeString - 1)) // Check file name length
    {
        printf("Program ERROR, Argument file name is longer than 20 characters");
        return -2;
    }

    struct MyData myArgs; // Set struct with arguments passed
    myArgs.howMany = atoi(argv[1]);

    strcpy(myArgs.theText, argv[2]);
    strcpy(myArgs.directoryPath, argv[3]);
    strcpy(myArgs.filename, argv[4]);

    char fileFullPath[kSizePath]; // Create full path by concatenating

    strcpy(fileFullPath, myArgs.directoryPath);
    strcat(fileFullPath, "/");
    strcat(fileFullPath, myArgs.filename);

    fp = fopen(fileFullPath, "w"); // Open file

    if (fp == NULL) // Check if file opened
    {
        printf("Program ERROR: (File counldn't open)");
        return -2;
    }

    for (int i = 0; i < myArgs.howMany; i++) // Loop to write text to file
    {
        int writeToFile = fprintf(fp, "%s\n", myArgs.theText); // Write text to file in loop iteration

        if (writeToFile < 0) // check if text was written
        {
            printf("Program ERROR: (Couldn't write to file)");
            return -2;
        }
    }

    int closeFile = fclose(fp); // Close file
    if (closeFile != 0)         // Check if file closed
    {
        printf("Program ERROR: (Couldn't close file)");
    }

    return 0;
}