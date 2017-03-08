//============================================================================
// Name        : QueryLoadEncoder.cpp
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "query.h"
Query::Query(){

}

Query::Query(SPARQLParser & parser){
	string subj, pred, obj;
	for(unsigned i = 0 ; i < parser.projection.size() ;i++){
		this->projections.push_back("?"+parser.getVariableName(parser.projection[i]));
	}
	for(unsigned i= 0; i < parser.patterns.patterns.size(); i++){
		if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::Variable){
			subj = "?"+parser.getVariableName(parser.patterns.patterns[i].subject.id);
		}
		else if(parser.patterns.patterns[i].subject.type == SPARQLParser::Element::IRI){
			subj = "?"+parser.getVariableName(parser.patterns.patterns[i].subject.id);
		}
		else{
			subj = parser.patterns.patterns[i].subject.value;
		}
		if(parser.patterns.patterns[i].object.type == SPARQLParser::Element::Variable){
			obj = "?"+parser.getVariableName(parser.patterns.patterns[i].object.id);
		}
		else{
			obj = parser.patterns.patterns[i].object.value;
		}
		pred = parser.patterns.patterns[i].predicate.value;
		cout<<subj<<" "<<pred<<" "<<obj<<endl;
	}
}
string Query::print(){
	string result = "";
	for(unsigned i = 0 ; i < this->nodes.size(); i++){
		result += nodes[i].encode_query()+"\n";
	}
	return result;
}
