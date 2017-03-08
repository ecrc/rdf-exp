//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "node.h"
Node::Node() {
	cardinality = 0;
	temp_query = false;
	variables = V_BOTH;
	num_variables = 2;
}

Node::Node(vector<string> &tokens) {
	temp_query = true;
	num_variables = 0;
	buildFromArray(tokens);
	for(unsigned i = 0 ; i < row.size(); i++){
		if(!isVariable(row[i]))
			temp_query = false;
		else{
			num_variables++;
		}
	}
	cardinality = 0;
	variables = V_BOTH;
	if(!temp_query)
		this->analyze_variables();
}

Node::Node(string &subquery) {
	temp_query = true;
	row.clear();
	num_variables = 0;
	split_string(subquery, intermediate_delim, row);
	for(unsigned i = 0 ; i < row.size(); i++){
		if(!isVariable(row[i]))
			temp_query = false;
		else
			num_variables++;
	}
	cardinality = 0;
	variables = V_BOTH;
	if(!temp_query)
		this->analyze_variables();
}

vector<string> Node::getColumnNames() {

	vector<string> colNames;
	for (unsigned i = 0; i < row.size(); i++)
		colNames.push_back(row[i]);

	return colNames;
}

void Node::buildFromArray(vector<string> tokens) {

	row.clear();

	for (unsigned i = 0; i < tokens.size(); i++) {
		row.push_back(tokens[i]);
	}

}

void Node::get_join_node_and_cols(Node &n2, vector<pair<int, int> > &join_cols, Node &res) {
	boost::unordered_set<string> vars;
	res.row.clear();
	res.temp_query = true;
	res.cardinality = 0;
	res.num_variables = 0;
	for(unsigned i = 0 ; i < row.size(); i++){
		if(isVariable(row[i])){
			res.row.push_back(row[i]);
			res.num_variables++;
			vars.insert(row[i]);
		}
	}
	join_cols.clear();
	for (unsigned j = 0; j < n2.row.size(); j++) {
		if(isVariable(n2.row[j])){
			if(vars.find(n2.row[j]) == vars.end()){
				res.row.push_back(n2.row[j]);
				res.num_variables++;
			}
			for (unsigned i = 0; i < row.size(); i++) {

				// found a shared variable
				if (row[i] == n2.row[j]) {
					join_cols.push_back(make_pair(i, j));
				}

			}
		}
	}
}

/*void Node::get_join_result_node(Node &q2, Node &res){
	vector<string> vars;

	if(temp_query){

	}
	else{
		res.ro
	}

	for(unsigned i = 0 ; i < splits.size(); i++){
		if (isVariable(splits[i]))
			vars.push_back(splits[i]);
	}

	split_string(encoded_q2, "|", splits);

	for(unsigned i = 0 ; i < splits.size(); i++){
		if (isVariable(splits[i]) && searchVector(vars, splits[i]) == -1)
			vars.push_back(splits[i]);
	}

	vector<string>::iterator it;
	for (it = vars.begin(); it != vars.end(); it++) {
		join_string += (*it) + "|";
	}
	join_string.erase(join_string.length() - 1, 1);
}*/

vector<string> Node::getVarNames() {

	vector<string> varNames;

	for (unsigned i = 0; i < row.size(); i++) {
		if (isVariable(row[i]))
			varNames.push_back(row[i]);
	}

	return varNames;
}

string Node::encode_query() {
	string code = "";
	for (unsigned i = 0; i < this->row.size(); i++) {
		code += this->row[i];

		if (i < this->row.size() - 1)
			code += intermediate_delim;
	}
	return code;
}

void Node::analyze_variables(){
	if(isVariable(row[0])){
		if(isVariable(row[2])){
			this->variables = V_BOTH;
		}
		else
			this->variables = V_SUBJ;
	}
	else
		this->variables = V_OBJ;
}

string Node::print(){
	string result = this->encode_query()+"\n";
	result += toString(num_variables)+" "+toString(cardinality)+" "+toString(temp_query)+" "+toString(variables);
	return result;
}
