//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <boost/unordered_map.hpp>
#include <map>
using namespace std;
typedef unsigned int ll;
const string intermediate_delim = "|";
const string part_string = "********************************************************************";
void writeToLog(string record);
void print_to_screen(string record);
string trim(const string & s);
template<class T>
std::string toString(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}
void compare_and_swap(ll &u, ll &v);
template<class T, class Y>
void dump_map(boost::unordered_map<T,Y> my_map, string file, bool inverse){
	ofstream mapStream(file.c_str());
	typename boost::unordered_map<T,Y>::iterator i;
	for(i = my_map.begin(); i != my_map.end(); i++){
		if(inverse){
			mapStream<<toString((*i).second)<<" "<<toString((*i).first)<<endl;
		}
		else{
			mapStream<<toString((*i).first)<<" "<<toString((*i).second)<<endl;
		}
	}
	mapStream.close();
}
template<class T>
string print_list(const set<T>& s, string delim) {

	string printout = "";

	typename set<T>::iterator s_it;
	for (s_it = s.begin(); s_it != s.end(); s_it++) {
		if (s_it != s.begin())
			printout += delim;
		printout += toString(*s_it);
	}

	return printout;
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

