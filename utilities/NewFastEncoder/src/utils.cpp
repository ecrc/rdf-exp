//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "utils.h"


void writeToLog(string record) {
	string logFile = "logs/log.txt";
	ofstream logStream(logFile.c_str(), ios::app);
	logStream << record << endl;
	logStream.flush();

}

void print_to_screen(string record) {
	cout<<record<<endl;
	cout.flush();
}

string trim(const string & s) {

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
} // end of trim

void compare_and_swap(ll &u, ll &v){
	if(u > v){
		ll tmp = u;
		u = v;
		v = tmp;
	}
}
