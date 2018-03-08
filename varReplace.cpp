#include <iostream>
#include <string>
#include <vector>
#include "varReplace.h"

using namespace std;

int findVarPos(vector<string> cfileLine, int op){
	int varFound[256][2];
	int j=0;
	int casesFound=0;
	string varstring;
	int varsize;

	switch (op) {
		case 1: 
			varstring = "int";
			varsize = INT_NAME_SIZE;
			break;
		case 2: 
			varstring = "float";
			varsize = FLOAT_NAME_SIZE;
			break;
		case 3: 
			varstring = "long";
			varsize = LONG_NAME_SIZE;
			break;
		case 4: 
			varstring = "char";
			varsize = CHAR_NAME_SIZE;
			break;
		case 5: 
			varstring = "double";
			varsize = DOUBLE_NAME_SIZE;
			break;
		default:
			return 0;
	}

	for (int i = 0 ; i < cfileLine.size() ; i++) {

		size_t found = cfileLine[i].find(varstring);

		if (found!=string::npos) {
			if (CheckForFalsePositives(i, found, cfileLine, varsize)) {
    			varFound[j][0]=i;
    			varFound[j][1]=found;
    			cout << "First '"<< varstring << "'found at line : " << varFound[j][0] 
    			 << " and position " << varFound[j][1] << '\n';
    			casesFound++;
    			j++;
    		}
		}
	}

	findVarNames(varFound,cfileLine,casesFound,varsize);

}

int findVar(vector<string> varNames, vector<string> cfileLine){

	string newVarName;
	for (int j = 0 ; j < varNames.size() ; j++) {
		if (varNames[j]=="main") continue;
		newVarName = varGen();
		cout << "Generating new variable name: " << newVarName << endl;
		for (int i = 0 ; i < cfileLine.size() ; i++) {
			size_t found = cfileLine[i].find(varNames[j]);
			if (found != string::npos) {
				if (CheckForFalsePositives(i, found, cfileLine, varNames[j].size())) {
					cout << "Variable " << varNames[j] << " found at position " << found << " and line " << i << endl;
					cfileLine[i].replace(found, varNames[j].size(), newVarName);
				}
			}
		}
	}

	writeToFile(cfileLine);

}


int findVarNames(int varFound[][2], vector<string> cfileLine, int casesFound, int varsize){
	vector<string> varNames(casesFound);
	int i=0;
	int j=varsize+1;

	for (i = 0 ; i < casesFound ; i++) {
		while (cfileLine[varFound[i][0]][varFound[i][1]+j]!=' '
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='	'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='{'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='}'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='('
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!=')'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='['
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!=']'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='=' 
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='!'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!=','
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='.'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!=';'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='<'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='>'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='+'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='-'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='*'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='/'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='|'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='&'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='%'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!=':'
			&& cfileLine[varFound[i][0]][varFound[i][1]+j]!='?') {

			varNames[i]+=cfileLine[varFound[i][0]][varFound[i][1]+j];
			j++;
			
		}

			j=varsize+1;

	}

	findVar(varNames, cfileLine);
}

bool CheckForFalsePositives(int line, int position, vector<string> cfileLine, int varSize){

	if (cfileLine[line][position-1]=='	'
		|| cfileLine[line][position-1]==' '
		|| cfileLine[line][position+varSize]==' '
		|| cfileLine[line][position+varSize]=='	') 
	{
		return true;
	}
	else{
		cout << "False positive detected at line " << line << " and position " << position << endl;
		return false;
	}

}