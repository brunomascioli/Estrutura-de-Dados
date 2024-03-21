#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

typedef struct {
  int cols;
  int lines;
  int whiteColor;
  FILE *ptrFile;
  char type[3];
  char **matrix;
} PgmFile;

FILE *openFile(const char *filename, const char *mode);

void compress(PgmFile imageStruct, FILE *outputFile);

void writePixel(FILE *outputFile, char *value, int count);

void decompress(PgmFile imageStruct, FILE *outputFile);

void loadMatrix(PgmFile *imageStruct);

char **alocateMatrix(int cols, int lines);

PgmFile createStruct(FILE *ptrFile);

void freeMatrix(PgmFile *imageStruct);

#endif