#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> updatedcfileline;

std::string invalidarg = "Invalid option \n Try ./main --help for more information. \n";
 	
std::string help = "\n Usage: ./main [SOURCE_FILE.C]... [NEW_FILE.C]... [OPTIONS]... "
					  "\n see --options for a list of avalailable options arguments. \n";

std::string options = "\n Empty options will replace every variable"
					  "\n  -oi 		Replace only int variables"
					  "\n  -of 		Replace only float variables"
					  "\n  -od 		Replace only double variables"
					  "\n  -oc 		Replace only char variables"
					  "\n  -ol 		Replace only long variables"
					  "\n  -bi 		Replace everything but int variables"
					  "\n  -bf 		Replace everything but float variables"
					  "\n  -bd 		Replace everything but double variables"
					  "\n  -bc 		Replace everything but char variables"
					  "\n  -bl 		Replace everything but long variables \n";

const char* flags[] = {"-oi","-of","-od","-oc","-oc","-ol","-bi","-bf","-bd","-bc","-bl"};

void readInstructions(std::vector<std::string> cfileLine,std::string option);

std::string sourcefile;
std::string destfile;

#endif
