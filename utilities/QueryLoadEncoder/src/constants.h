//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

//#define RETURN_RESULTS
//#define REVERSE_WALK
//#define MAX_SUM
//#define BATCH_UPDATE
#define PERCENTILE
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <set>
#include <queue>
#include "assert.h"
/*
#include <sys/time.h>
#include "assert.h"
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <queue>
#include <cmath>
#include <stack>
#include <limits>
#include "semaphore.h"
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>
#include "fastlz.h"
 */

using namespace std;

//---------------------------------------------------------------CONSTANTS-----------------------------------------------------
const string intermediate_delim = "|";
const string part_string = "********************************************************************";
const string query_delim = "#EOQ#";
const string cmd_delimiter = "^";
const int RETURN_RESULTS = 0;
const int DISPLAY_RESULTS = 0;
const std::string delimiters = " \f\n\r\t\v";
//---------------------------------------------------------------ENUMS---------------------------------------------------------
enum hash_type {
	HS,
	HO,
	RAND,
	HSO
};
enum trav_col {
	/* 0 	*/SUBJ,
	/* 1 	*/PRED,
	/* 2 	*/OBJ
};
enum PLAN_OP {SEMI_JOIN, STAR, PARALLEL, PHD};
enum PREPARE_AHEAD {PREPARE_RANDOM, PREPARE_LOCALITY, NO_PREPARE};

#endif /* CONSTANTS_H_ */

