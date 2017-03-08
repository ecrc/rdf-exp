//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef UTILS_H_
#define UTILS_H_

#include "constants.h"

void throwException(string exc);
bool isVariable(string name);
string trim(char * s);
std::string trim_right_copy(const std::string& s);
std::string trim_left_copy(char * s);
double gini_coef(vector<long long>& vec);
void split_string(string& text, string delim, vector<string>& splits);
//----------------------------------------------------------------------------------------------------------------------------
template<class T>
std::string toString(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}

template<class T>
string print_list(const vector<T>& vec, string delim) {

	string printout = "";

	for (unsigned i = 0; i < vec.size(); i++) {
		printout += toString(vec[i]);

		if (i < vec.size() - 1)
			printout += delim;
	}

	return printout;
}

#endif /* UTILS_H_ */

