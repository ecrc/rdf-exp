//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef QUERY_H
#define QUERY_H
#include "node.h"
#include "SPARQLParser.hpp"
enum TYPE{SELECT, DELETE, INSERT};
class Query {

public:
	Query();
	Query(SPARQLParser & parser);
	string prefix;

	string querystring;

	// list of projections
	vector<string> projections;

	// list of nodes
	vector<Node> nodes;

	// list of variables
	vector<string> variables;

	TYPE type;
	int qid;
	string print();
};

#endif
