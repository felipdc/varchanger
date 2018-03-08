#ifndef INTREPLACE_H
#define INTREPLACE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define INT_NAME_SIZE 3
#define FLOAT_NAME_SIZE 5
#define LONG_NAME_SIZE 4
#define CHAR_NAME_SIZE 4
#define DOUBLE_NAME_SIZE 6

#define INT_OP 1
#define FLOAT_OP 2
#define LONG_OP 3
#define CHAR_OP 4
#define DOUBLE_OP 5

bool CheckForFalsePositives(int line, int position, std::vector<std::string> cfileLine, int wordLenght);
int findVarNames(int intFound[][2], std::vector<std::string> cfileLine, int casesFound, int varsize);
void writeToFile(std::vector<std::string> cfileLine);
int findVarPos(std::vector<std::string> cfileLine, int op);
int findVar(std::vector<std::string> varNames, std::vector<std::string> cfileLine);
std::string varGen();

#endif