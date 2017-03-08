//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "utils.h"
#include <iostream>
#include <dirent.h>
#include <errno.h>
#include "SPARQLLexer.hpp"
#include "SPARQLParser.hpp"

using namespace std;

int getdir (string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		if(((int)dirp->d_type) == 8)
			files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

bool is_star(SPARQLParser & parser, int &type, bool subj){
	bool first = true;
	string first_val;

	if(subj){
		for(unsigned i= 0; i < parser.patterns.patterns.size(); i++){
			if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::Variable){
				if(first){
					first_val = parser.getVariableName(parser.patterns.patterns[i].subject.id);
					first = false;
					type = 0;
				}
				if(parser.getVariableName(parser.patterns.patterns[i].subject.id) != first_val){
					return false;
				}
			}
			else if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::IRI){
				if(first){
					first_val = parser.patterns.patterns[i].subject.value;
					first = false;
					type = 1;
				}
				if(parser.patterns.patterns[i].subject.value != first_val){
					return false;
				}
			}
			else{
				if(first){
					first_val = parser.patterns.patterns[i].subject.value;
					first = false;
					type = 2;
				}
				if(parser.patterns.patterns[i].subject.value != first_val){
					return false;
				}
			}
		}
		return true;
	}
	else{
		for(unsigned i= 0; i < parser.patterns.patterns.size(); i++){
			if(parser.patterns.patterns[i].object.type == SPARQLParser::Element::Variable){
				if(first){
					first_val = parser.getVariableName(parser.patterns.patterns[i].object.id);
					first = false;
					type = 0;
				}
				if(parser.getVariableName(parser.patterns.patterns[i].object.id) != first_val){
					return false;
				}
			}
			else if(parser.patterns.patterns[i].object.type == SPARQLParser::Element::IRI){
				if(first){
					first_val = parser.patterns.patterns[i].object.value;
					first = false;
					type = 1;
				}
				if(parser.patterns.patterns[i].object.value != first_val){
					return false;
				}
			}
			else{
				if(first){
					first_val = parser.patterns.patterns[i].object.value;
					first = false;
					type = 2;
				}
				if(parser.patterns.patterns[i].object.value != first_val){
					return false;
				}
			}
		}
		return true;
	}
}
int var_s_star = 0;
int var_o_star = 0;
int uri_s_star = 0;
int const_s_star = 0;
int uri_o_star = 0;
int const_o_star = 0;
int total_s_star = 0;
int total_o_star = 0;
int total_queries = 0;
int single_pattern = 0;
int complex_pattern = 0;
int max_complex_patterns = 0;
int empty_body = 0;
int encoded_queries = 0;
bool analyze_query(SPARQLParser & parser, string &query_string){
	int type;

	total_queries++;
	if(parser.patterns.patterns.size() > 1){
		if(is_star(parser, type, true)){
			if(type == 0)
				var_s_star++;
			else if(type == 1){
				uri_s_star++;
			}
			else if(type == 2){
				const_s_star++;
			}
			total_s_star++;
			return true;
		}
		else if(is_star(parser, type, false)){
			total_o_star++;
			if(type == 0){
				var_o_star++;
				return true;
			}
			else if(type == 1){
				uri_o_star++;
				return false;
			}
			else if(type == 2){
				const_o_star++;
				return false;
			}
		}
		else{
			complex_pattern++;
			if(parser.patterns.patterns.size() > max_complex_patterns){
				max_complex_patterns = parser.patterns.patterns.size();
			}
			return true;
		}
		return true;
	}
	else{
		single_pattern++;
		return true;
	}
}
void  encode_query(SPARQLParser & parser, ofstream &stream, boost::unordered_map<string, long long>& predicate_map, boost::unordered_map<string, long long>& subj_map, long long max_predicate, long long max_verts) {
	boost::unordered_map<string, long long>::iterator it;

	stream<<"SELECT ";
	for(unsigned i = 0 ; i < parser.projection.size() ;i++){
		stream<<"?"<<parser.getVariableName(parser.projection[i])<<" ";
	}
	stream<<"WHERE {"<<endl;

	for(unsigned i= 0; i < parser.patterns.patterns.size(); i++){
		if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::Variable){
			stream<<"\t?"<<parser.getVariableName(parser.patterns.patterns[i].subject.id)<<" ";
		}
		else if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::IRI){
			it = subj_map.find(parser.patterns.patterns[i].subject.value);
			if (it == subj_map.end()) {
				stream<<"\t<"<<max_verts<<"> ";
			}
			else
				stream<<"\t<"<<it->second<<"> ";
		}
		else{
			it = subj_map.find(parser.patterns.patterns[i].subject.value);
			if (it == subj_map.end()) {
				stream<<"\t\""<<max_verts<<"\" ";
			}
			else
				stream<<"\t\""<<it->second<<"\" ";
		}

		it = predicate_map.find(parser.patterns.patterns[i].predicate.value);
		if (it == predicate_map.end()) {
			stream<<"<"<<max_predicate<<"> ";
		}
		else
			stream<<"<"<<it->second<<"> ";

		if(parser.patterns.patterns[i].object.type == SPARQLParser::Element::Variable){
			stream<<"?"<<parser.getVariableName(parser.patterns.patterns[i].object.id)<<" ."<<endl;
		}
		else if(parser.patterns.patterns[i].object.type == SPARQLParser::Element::IRI){
			it = subj_map.find(parser.patterns.patterns[i].object.value);
			if (it == subj_map.end()) {
				stream<<"<"<<max_verts<<"> ."<<endl;
			}
			else
				stream<<"<"<<it->second<<"> ."<<endl;
		}
		else{
			it = subj_map.find(parser.patterns.patterns[i].object.value);
			if (it == subj_map.end()) {
				stream<<"\""<<max_verts<<"\" ."<<endl;
			}
			else
				stream<<"\""<<it->second<<"\" ."<<endl;
		}
	}
	stream<<"}\n#EOQ#"<<endl;
}

void load_encode_queries(string queryFile, boost::unordered_map<string, long long>& predicate_map, boost::unordered_map<string, long long>& subj_map, long long max_predicate, long long max_verts) {
	ifstream queryIn(queryFile.c_str());
	string outputFileName = queryFile+"_encoded";
	ofstream queryOut(outputFileName.c_str());
	string querystring, str;

	if (!queryIn) {
		throwException("Query file '" + queryFile
				+ "' was not found. Please try again!\n");
	}
	// read the query string
	querystring = "";

	int counter = 0;
	while (true) {
		getline(queryIn,str);
		if(str!=query_delim){
			querystring+=str;
			if (!queryIn.good())
				break;
			querystring+='\n';
		}
		else if ((str == query_delim || queryIn.eof()) && !querystring.empty()) {
			/*if(counter>2802102*/
			cout<<counter<<"\n"<<querystring<<endl;
			counter++;
			SPARQLLexer lexer(querystring);
			SPARQLParser parser(lexer);
			try {
				parser.parse();
			} catch (const SPARQLParser::ParserException& e) {
				cerr << "parse error: " << e.message << endl;
				return;
			}

			//Query query = Query(parser);
			//query.qid = qid++;
			//queries.push_back(query);
			if(parser.variableCount != 0){
				if(parser.patterns.patterns.size() == 0){
					empty_body++;
				}
				else{
					if(analyze_query(parser, querystring)){
						encode_query(parser, queryOut, predicate_map, subj_map, max_predicate, max_verts);
						encoded_queries++;
					}
				}
			}
			querystring = "";
		}
	}
	queryIn.close();
	queryOut.close();
}


int main(int argc, char** argv) {
	if (argc < 4) {
		throwException("Usage: QueryLoadEncoder <predicate_map_file> <subj_map_file> <query_files_directory>");
	}
	string line, directory = string(argv[3]);
	vector<string> files = vector<string>();
	boost::unordered_map<string, long long> verts_map, preds_map;
	long long id, max_predicate = numeric_limits<long long>::min(), max_verts = numeric_limits<long long>::min();
	char value[1000000];
	FILE * pFile;

	getdir(directory,files);
	cout<<"Will encode "<<(files.size())<<" query files."<<endl;

	//Reading predicates dictionary
	pFile = fopen(argv[1], "r");
	while(fscanf(pFile, "%lld %[^\r\n] ", &id, value)==2){
		if(id>max_predicate)
			max_predicate = id+1;
		preds_map[value] = id;
	}
	fclose(pFile);

	id = -1;
	value[0] = '\0';

	//Reading vertices dictionary
	pFile = fopen (argv[2],"r");
	while(fscanf(pFile, "%lld %[^\r\n] ", &id, value)==2){
		if(id>max_verts){
			max_verts = id+1;
		}
		verts_map[value] = id;
	}
	fclose(pFile);
	cout<<"Number of vertices: "<<max_verts<<", Number of Predicates: "<<max_predicate<<endl;
	for(unsigned q = 0 ; q < files.size(); q++){
		cout << "reading parsing and encoding queries from file: " << files[q] << endl;
		load_encode_queries(directory+files[q], preds_map, verts_map, max_predicate, max_verts);

		cout << "done" << endl;
		cout.flush();

	}
	//load_queries ("/home/harbir/razen/QueryLoadEncoder/ds/bio/fixed_bio.q", queries);
	//load_encode_queries("/home/harbir/razen/QueryLoadEncoder/queries/bio2rdf/string/bio2rdf.q", preds_map, verts_map, max_predicate, max_verts);
	//      load_encode_queries("/scratch/razen/data/bio2rdf/queries/string/bio2rdf.q", preds_map, verts_map, max_predicate, max_verts);

	cout<<part_string<<endl;
	cout<<"Queries Summary:"<<endl;
	cout<<part_string<<endl;
	cout<<"TOTAL NUMBER OF QUERIES: "<<total_queries<<endl;
	cout<<"TOTAL NUMBER OF ENCODED QUERIES: "<<encoded_queries<<endl;
	cout<<part_string<<endl;
	cout<<"EMPTY PATTERN: "<<empty_body<<endl;
	cout<<part_string<<endl;
	cout<<"SINGLE PATTERN: "<<single_pattern<<endl;
	cout<<part_string<<endl;
	cout<<"COMPLEX PATTERN: "<<complex_pattern<<endl;
	cout<<"MAXIMUM PATTERN SIZE: "<<max_complex_patterns<<endl;
	cout<<part_string<<endl;
	cout<<"SUBJECT STAR: "<<total_s_star<<endl;
	cout<<part_string<<endl;
	cout<<"VAR: "<<var_s_star<<endl;
	cout<<"URI: "<<uri_s_star<<endl;
	cout<<"CONST: "<<const_s_star<<endl;
	cout<<part_string<<endl;
	cout<<"OBJECT STAR: "<<total_o_star<<endl;
	cout<<part_string<<endl;
	cout<<"VAR: "<<var_o_star<<endl;
	cout<<"URI: "<<uri_o_star<<endl;
	cout<<"CONST: "<<const_o_star<<endl;
	return 0;

}
