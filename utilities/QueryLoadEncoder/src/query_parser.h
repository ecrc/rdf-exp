//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef PARSER_H
#define PARSER_H
#include "utils.h"
#include "query.h"
#include "profiler.h"


void load_queries(string queryFile, vector<Query>& queries);
Query parse_sparql_query(string text);
void parse_select_query(Query &query);
void parse_delete_query(Query &query);
void parse_insert_query(Query &query);
void trimIt(string & trimmed);
void load_query_body(string queryFile, vector<int>& data);

#endif
