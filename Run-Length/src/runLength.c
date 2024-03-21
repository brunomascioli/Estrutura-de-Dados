#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
// Made by: Lucas Santos, Ian Fernandes, Bruno Mascioli de Souza 
// Github: LucassSantoss, IofSoft, brunomascioli 

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <inputFile> <outputFile>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *inputName = argv[1];
  char *outputName = argv[2];
  FILE *inputFile = openFile(inputName, "r");
  FILE *outputFile = openFile(outputName, "w");
  char *inputType = strrchr(inputName, '.');

  if (strcmp(inputType, ".pgm") != 0 && strcmp(inputType, ".pgmc") != 0) {
    printf("Invalid extension!");
    exit(EXIT_FAILURE);
  }

  PgmFile imageStruct = createStruct(inputFile);

  if (strcmp(inputType, ".pgm") == 0) {
    compress(imageStruct, outputFile);
  }
  if (strcmp(inputType, ".pgmc") == 0) {
    decompress(imageStruct, outputFile);
  }
  
  fclose(inputFile);
  fclose(outputFile);
}