//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "utils.h"
#include "profiler.h"
#include "row.h"

#ifndef PARSER_H
#define PARSER_H

void readRDFLine(ifstream &stream, vector<string> &lines);
void load_block_from_file(ifstream &stream, vector<char> &buffer,long long to_read, long long &read);
vector<row<string> > parse_triple(string& text);
void trimIt(string & trimmed);
void load_RDF_ascii_into_indecies(string file, map<string, pair<ll, ll> > &subject_map, map<string, pair<ll, ll> > &object_map, map<string, pair<ll, ll> > &predicate_map, vector<row<ll> > &rdf_data, ll &num_rec);
void output_map(string file, map<string,pair<ll,ll> > data_map, bool reverse);
void output_vector(string file, vector<row<ll> > data_vec);
void output_stats(string file, map<string,pair<ll,ll> > data_map);
#endif
