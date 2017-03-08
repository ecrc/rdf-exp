//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "utils.h"

void throwException(string exc) {
	long myId = 0;

	if (myId == 0)
		cout << myId << " - RUNTIME ERROR: " << exc << endl;
	exit(0);
}

bool isVariable(string name) {

	if (name[0] == '?')
		return true;

	return false;
}
std::string trim_right_copy(const std::string& s){
	return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

std::string trim_left_copy(const std::string& s){
	return s.substr( s.find_first_not_of( delimiters ) );
}

std::string trim(char * s){
	string str(s);
	return trim_left_copy( trim_right_copy(str));
}
/*string trim(const string & s) {

	string str(s);
	string::size_type pos = str.find_last_not_of(' ');

	if (pos != string::npos) {
		str.erase(pos + 1);
		pos = str.find_first_not_of(" \t\r\n");
		if (pos != string::npos)
			str.erase(0, pos);
	} else
		str.erase(str.begin(), str.end());

	return str;
}*/
double gini_coef(vector<long long>& vec) {
	double gini = 0.0, mean = 0.0;

	// calculate the mean
	for (unsigned i = 1; i < vec.size(); i++)
		mean += vec[i];

	mean /= vec.size()-1;

	for (unsigned i = 1; i < vec.size(); i++)
		for (unsigned j = 1; j < vec.size(); j++)
			gini += fabs(vec[i] - vec[j]);

	gini /= mean;
	gini /= (2 * (vec.size()-1) * (vec.size()-1));

	return gini;
}

void split_string(string& text, string delim, vector<string>& splits) {
	size_t  start = 0, end = 0;
	splits.clear();
	if(text.length() > 0){
		while ( end != string::npos)
		{
			end = text.find( delim, start);
			splits.push_back( text.substr( start,	(end == string::npos) ? string::npos : end - start));
			start = (   ( end > (string::npos - delim.size()) )
					?  string::npos  :  end + delim.size());
		}
	}
}
