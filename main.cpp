#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "varGenerator.h"
#include "varReplace.h"
#include "options.h"

using namespace std;


void writeToFile(vector<string> cfileLine){

	ofstream newFile;
	updatedcfileline = cfileLine;
	newFile.open(destfile.c_str());

	if (newFile.is_open()) {
		for (int i = 0 ; i < cfileLine.size() ; i++)
		  newFile << cfileLine[i] << flush;
	}

	newFile.close();

}

void readInstructions(vector<string> cfileLine, string option){

	bool only = true;
	int instructions_only[5] = {0,0,0,0,0};
	int instructions_but[5] = {1,2,3,4,5};

	if (option == "-oi") instructions_only[0] = 1;
	else if (option == "-of") instructions_only[1] = 2;
	else if (option == "-od") instructions_only[2] = 3;
	else if (option == "-oc") instructions_only[3] = 4;
	else if (option == "-ol") instructions_only[4] = 5;
	else{
		only = false;
		if (option == "-bi") instructions_but[0] = 0;
		else if (option == "-bf") instructions_but[1] = 0;
		else if (option == "-bd") instructions_but[2] = 0;
		else if (option == "-bc") instructions_but[3] = 0;
		else if (option == "-bl") instructions_but[4] = 0;
		else{
			if (option != "") {
				cout << "Invalid option argument" << endl;
				return;
			}else{
				cout << "Empty option argument - All variables will be replaced" << endl;	
			}
		}
	}

	updatedcfileline=cfileLine;

	for (int i = 0 ; i < 5 ; i++) {
		if (only) {
		  findVarPos(updatedcfileline, instructions_only[i]);
		}else {
		  findVarPos(updatedcfileline, instructions_but[i]);
		}
	}

}


int main(int argc, char *argv[]){

	vector<string> params;

	for (int i = 0 ; i < argc ; i++) params.push_back(argv[i]);

	if (params[1] == "--help") {
		cout << help;
		return 0;
	}

	if (params[1] == "--options") {
		cout << options;
		return 0;
	}

	if (argc > 4 || argc < 3) {
		cout << invalidarg;
		return -1;
	}

	if (params[1].find(".c") == string::npos || params[2].find(".c") == string::npos) {
		cout << "\nError: Not .c extension" << endl;
		return -1;
	}


	sourcefile = params[1];
	destfile = params[2];

	srand(time(NULL));

	string line;
	vector<string> cfileLine;
	ifstream cfile(sourcefile.c_str());

	if (cfile.is_open()) {
		while (getline(cfile,line)) cfileLine.push_back(line+'\n');
		cout << "File opened" << endl;
	}

	else {
		cout << "Could not open file" << endl;
		return -1;
	}

	readInstructions(cfileLine,params[3]);


	//findVarPos(cfileLine, 1);
	cfile.close();

}