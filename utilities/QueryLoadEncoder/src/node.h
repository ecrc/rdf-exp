//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef NODE_H
#define	 NODE_H

#include "utils.h"

enum node_variables {
	/* 0 	*/V_SUBJ,
	/* 1 	*/V_BOTH,
	/* 2 	*/V_OBJ
};

class Node {
public:

	Node();
	Node(vector<string> &tokens);
	Node(string &subquery);

	bool operator<(const Node& n2) const {
		return row[0] < n2.row[0];
	}

	vector<string> row;

	// indicates whether it has a path predicate
	//bool hasPathPredicate;

	int num_variables;
	vector<string> getColumnNames();
	void buildFromArray(vector<string> tokens);
	void get_join_node_and_cols(Node &n2, vector<pair<int, int> > &join_cols, Node &res);
	vector<string> getVarNames();
	string encode_query();
	static Node parseNode(string str);
	void analyze_variables();
	long long cardinality;
	bool temp_query;
	string print();
	node_variables variables;
};

#endif	/* NODE_HPP */

