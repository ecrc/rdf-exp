//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "query_parser.h"

void load_queries(string queryFile, vector<Query>& queries) {
	ifstream queryIn(queryFile.c_str());
	string querystring, str;
	int qid = 1;

	if (!queryIn) {
		throwException("Query file '" + queryFile
				+ "' was not found. Please try again!\n");
	}
	// read the query string
	querystring = "";

	while (true) {
		queryIn >> str;
		if ((str == query_delim || queryIn.eof()) && !querystring.empty()) {
			Query query = parse_sparql_query(querystring);
			query.qid = qid++;
			queries.push_back(query);
			querystring = "";
			if (queryIn.eof())
				break;

			continue;
		}
		querystring += str + " ";
	}
	queryIn.close();
}

Query parse_sparql_query(string text) {

	//	cout << "parsing query: " << text << endl;
	Query query;
	query.querystring = text;
	char* querystringDup = strdup(text.c_str());
	char* token;

	token = strtok(querystringDup, " {}<>\n");

	// query prefix

	if (strcmp(token, "PREFIX") == 0) {
		token = strtok(NULL, " {}<>\n");
		if (strcmp(token, ":") != 0)
			throwException("Expected ':' but found '" + string(token) + "'\n");

		query.prefix = strtok(NULL, " {}<>\n");
		token = strtok(NULL, " {}<>\n");
	}

	//check for the operation. i.e. SELECT, INSERT DATA, DELETE DATA
	if (strcmp(token, "SELECT") == 0){
		parse_select_query(query);
		query.type = SELECT;
	}
	else if (strcmp(token, "DELETE") == 0){
		parse_delete_query(query);
		query.type = DELETE;
	}
	else if (strcmp(token, "INSERT") == 0){
		parse_insert_query(query);
		query.type = INSERT;
	}
	else{
		throwException("Only SELECT, INSERT DATA and DELETE DATA queries are supported. Found token: \""+ string(token) + "\"\n");
	}

	return query;

}


void trimIt(string & trimmed) {
	// trim spaces, greater than and less than signs
	if (trimmed[trimmed.length() - 1] == ' ')
		trimmed = trimmed.substr(0, trimmed.length() - 1);

	if (trimmed[trimmed.length() - 1] == '>')
		trimmed = trimmed.substr(0, trimmed.length() - 1);

	if (trimmed[0] == '<')
		trimmed = trimmed.substr(1, trimmed.length() - 1);

}

void parse_select_query(Query &query){
	char* token;
	// query projections
	token = strtok(NULL, " {}<>\n");

	while (strcmp(token, "WHERE") != 0) {
		query.projections.push_back(string(token));
		token = strtok(NULL, " {}<>\n");

	}

	// query selection nodes

	vector<string> triple;

	while (token != NULL) {

		triple.clear();

		token = strtok(NULL, " {}<>\n");

		if (!token)
			break;

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (strcmp(token, ".") != 0)
			throwException("Expected end-of-line character '.'\n");

		Node tmpNode(triple);
		query.nodes.push_back(tmpNode);

		for (unsigned i = 0; i < triple.size(); i++) {
			if (triple[i][0] == '?')
				if (find(query.variables.begin(), query.variables.end(),
						triple[i]) == query.variables.end())
					query.variables.push_back(triple[i]);
		}

	}

	for (unsigned i = 0; i < query.projections.size(); i++) {
		if (find(query.variables.begin(), query.variables.end(),
				query.projections[i]) == query.projections.end())
			throwException("Variable '" + query.projections[i]
			                                                + "' was not found in the query.");
	}
}
void parse_delete_query(Query &query){
	char* token;
	// query projections
	token = strtok(NULL, " {}<>\n");

	if (strcmp(token, "DATA") != 0) {
		throwException("Syntax Error: Expected Token Data, Found: "+string(token));
	}

	// query selection nodes

	vector<string> triple;

	while (token != NULL) {

		triple.clear();

		token = strtok(NULL, " {}<>\n");

		if (!token)
			break;

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (strcmp(token, ".") != 0)
			throwException("Expected end-of-line character '.'\n");

		Node tmpNode(triple);
		query.nodes.push_back(tmpNode);

		for (unsigned i = 0; i < triple.size(); i++) {
			if (triple[i][0] == '?')
				throwException("Variables not allowed in DELETE Data!");
		}

	}
}
void parse_insert_query(Query &query){
	char* token;
	// query projections
	token = strtok(NULL, " {}<>\n");

	if (strcmp(token, "DATA") != 0) {
		throwException("Syntax Error: Expected Token Data, Found: "+string(token));
	}

	// query selection nodes

	vector<string> triple;

	while (token != NULL) {

		triple.clear();

		token = strtok(NULL, " {}<>\n");

		if (!token)
			break;

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		triple.push_back(trim(token));
		token = strtok(NULL, " {}<>\n");

		if (strcmp(token, ".") != 0)
			throwException("Expected end-of-line character '.'\n");

		Node tmpNode(triple);
		query.nodes.push_back(tmpNode);

		for (unsigned i = 0; i < triple.size(); i++) {
			if (triple[i][0] == '?')
				throwException("Variables not allowed in INSERT Data!");
		}

	}
}


void parse_query_body(string &text, vector<int>& data){
	char* token = NULL;
	char* querystringDup = strdup(text.c_str());

	data.clear();
	token = strtok(querystringDup, " {}<>\n");

	while (token != NULL) {
		if (!token)
			break;

		data.push_back(atoi(trim(token).c_str()));
		token = strtok(NULL, " {}<>\n");
		if (token == NULL)
			throwException("Unexpected end of query.\n");

		data.push_back(atoi(trim(token).c_str()));
		token = strtok(NULL, " {}<>\n");

		if (token == NULL)
			throwException("Unexpected end of query.\n");

		data.push_back(atoi(trim(token).c_str()));
		token = strtok(NULL, " {}<>\n");
		if (strcmp(token, ".") != 0)
			throwException("Expected end-of-line character '.'\n");
		token = strtok(NULL, " {}<>\n");

	}
}



void load_query_body(string queryFile, vector<int>& data) {
	Profiler profiler;
	cout<<part_string<<endl;
	profiler.startTimer("load_query_body");
	cout<<"Started Loading Query Body!"<<endl;

	ifstream queryIn(queryFile.c_str());
	string querystring, str;

	if (!queryIn) {
		throwException("Query file '" + queryFile+ "' was not found. Please try again!\n");
	} else {
		cout<<"Loading query body from file: " + queryFile<<endl;
	}

	// read the query string
	querystring = "";

	while (true) {
		queryIn >> str;
		if ((str == query_delim || queryIn.eof()) && !querystring.empty()) {
			parse_query_body(querystring, data);
			querystring = "";
			if (queryIn.eof())
				break;

			continue;
		}
		querystring += str + " ";
	}
	queryIn.close();

	profiler.pauseTimer("load_query_body");
	cout<<"Done with loading query body in "<<toString(profiler.readPeriod("load_query_body"))<<" sec"<<endl;;
	profiler.clearTimer("load_query_body");

}
