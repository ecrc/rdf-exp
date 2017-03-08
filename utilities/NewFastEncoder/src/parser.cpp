//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "parser.h"

void trimIt(string & trimmed) {
	// trim spaces, greather than and less than signs
	if (trimmed[trimmed.length() - 1] == ' ')
		trimmed = trimmed.substr(0, trimmed.length() - 1);

	if (trimmed[trimmed.length() - 1] == '>')
		trimmed = trimmed.substr(0, trimmed.length() - 1);

	if (trimmed[0] == '<')
		trimmed = trimmed.substr(1, trimmed.length() - 1);

}

vector<row<string> > parse_triple(string& text) {

	vector<row<string> > tripleSet;
	row<string> triple;
	string tok, subject, predicate, object;
	char c;

	stringstream streamin(text);

	streamin >> subject;
	if (subject[0] == '<') {
		while (subject[subject.length() - 1] != '>') {
			streamin.get(c);
			subject += c;
		}
	}
    trimIt(subject);
    triple.add(subject);

	streamin >> predicate;

	if (predicate[0] == '<') {
		while (predicate[predicate.length() - 1] != '>') {
			streamin.get(c);
			predicate += c;
		}
	}
    trimIt(predicate);
    triple.add(predicate);

	if (streamin.peek() == ' ')
		streamin.ignore();

    c = streamin.get();
    while (!(c == '.' && (streamin.peek() == '\n' || streamin.eof()))) {
        object += c;
        c = streamin.get();
    }
	trimIt(object);
	triple.add(object);

	tripleSet.push_back(triple);
	return tripleSet;
}
void readRDFLine(ifstream &stream, vector<string> &lines) {
	char c;
	string str = "";
	long long read, to_read = 512 * 1024; //512KB
	vector<char> buffer(to_read);
	unsigned long long i, last_valid;

	load_block_from_file(stream, buffer, to_read, read);
	for (i = 0; i < buffer.size() - 1; i++) {
		c = buffer[i];
		str += c;

		if (c == '.' && (i + 1 == buffer.size() || buffer[i + 1] == '\n'
				|| buffer[i + 1] == '\r')) {
			lines.push_back(trim(str));
			i++;
			last_valid = i + 1;
			str = "";
		}
	}

	if ((read - last_valid) > 0 && !stream.eof()) {
		stream.seekg(-(read - last_valid), ios::cur);
	}
}

/**
 * This function loads into the buffer to_read characters from the stream and put the number of characters read in read
 */
void load_block_from_file(ifstream &stream, vector<char> &buffer,
		long long to_read, long long &read) {
	stream.read(&buffer.front(), to_read);
	read = stream.gcount();
}

void load_RDF_ascii_into_indecies(string file, map<string, pair<ll, ll> > &subject_map, map<string, pair<ll, ll> > &object_map, map<string, pair<ll, ll> > &predicate_map, vector<row<ll> > &rdf_data, ll &num_rec){
	map<string, ll>::iterator map_it;
	ll subject_id = 0;
	ll object_id = 0;
	ll predicate_id = 0;
	ofstream fileStream;
	ifstream fin(file.c_str());
	vector<string> lines;
	num_rec = 0;

	row<ll> tmp_row;
	tmp_row.record.resize(3);
	if (fin) {
		print_to_screen("Reading triples from file: " + file);
		while (!fin.eof()) {
			readRDFLine(fin, lines);
			for (unsigned i = 0; i < lines.size(); i++) {
				vector<row<string> > tripleSet = parse_triple(lines[i]);
				for (unsigned j = 0; j < tripleSet.size(); j++) {
					if(subject_map.find(tripleSet[j][0]) == subject_map.end()){
						subject_map[tripleSet[j][0]] = pair<ll,ll>(subject_id++,0);
					}
					if(object_map.find(tripleSet[j][2]) == object_map.end()){
						object_map[tripleSet[j][2]] = pair<ll,ll>(object_id++, 0);
					}
					if(predicate_map.find(tripleSet[j][1]) == predicate_map.end()){
						predicate_map[tripleSet[j][1]] = pair<ll,ll>(predicate_id++, 0);
					}
					subject_map[tripleSet[j][0]].second++;
					object_map[tripleSet[j][2]].second++;
					predicate_map[tripleSet[j][1]].second++;
					tmp_row.record[0] = subject_map[tripleSet[j][0]].first;
					tmp_row.record[1] = predicate_map[tripleSet[j][1]].first;
					tmp_row.record[2] = object_map[tripleSet[j][2]].first;
					rdf_data.push_back(tmp_row);
					num_rec++;
					if (num_rec % 1000000 == 0){
						print_to_screen("Read " + toString(num_rec) + " triples..");
					}
				}
			}
			lines.clear();
		}
	} else
		print_to_screen("File " + file + " not found.");

}
void output_map(string file, map<string,pair<ll,ll> > data_map, bool reverse){
	ofstream fileStream(file.c_str());
	for(map<string,pair<ll,ll> >::iterator it = data_map.begin(); it != data_map.end(); it++){
		if(reverse)
			fileStream<<(*it).second.first<<" "<<(*it).first<<endl;
		else
			fileStream<<(*it).first<<" "<<(*it).second.first<<endl;
	}
	fileStream.close();
}
void output_vector(string file, vector<row<ll> > data_vec){
	ofstream fileStream(file.c_str());
	for(unsigned i = 0; i != data_vec.size(); i++){
		fileStream<<data_vec[i].print_rdf()<<endl;
	}
	fileStream.close();
}
void output_stats(string file, map<string,pair<ll,ll> > data_map){
	ofstream fileStream(file.c_str());
	multimap<ll, string> mmap;
	for(map<string,pair<ll,ll> >::iterator it = data_map.begin(); it != data_map.end(); it++){
		mmap.insert(pair<ll,string>((*it).second.second, (*it).first));
	}
	for(multimap<ll,string>::iterator it = mmap.begin(); it != mmap.end(); it++){
		fileStream<<(*it).first<<" "<<(*it).second<<endl;
	}
	fileStream.close();
}
