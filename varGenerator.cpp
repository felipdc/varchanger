#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include "varGenerator.h"

using namespace std;

string varGen(){

	int i;
	int what_list;
	string new_var;
	size_t randomLetterIdx = rand()%25;
	new_var.push_back(ilet[randomLetterIdx]);

	for (i=1;i<DEFAULT_VAR_SIZE;i++) {

		what_list = rand()%3;

		switch (what_list) {
			case 0:
				new_var.push_back(ilet[rand()%25]);
				break;
			case 1:
				new_var.push_back(clet[rand()%25]);
				break;
			case 2:
				new_var.push_back(num[rand()%9]);
		}

	}

	return new_var;
}

