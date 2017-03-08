//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef ROW_H_
#define ROW_H_

template<class T>
class row {

public:
	vector<T> record;
	row() {
	}
	row(ll s, ll p, ll o) {
		record.resize(3);
		record[0] = s;
		record[1] = p;
		record[2] = o;
	}
	virtual ~row() {
	}

	T operator[](int i) {
		return record[i];
	}

	int size() {
		return record.size();
	}

	void add(T itm) {
		record.push_back(itm);
	}

	void clear() {
		record.clear();
	}

	string print(string delim) {
		string out = "";
		for (unsigned i = 0; i < record.size(); i++) {
			out += toString(record[i]);
			if (i < record.size() - 1)
				out += delim;
		}

		return out;
	}
	string print_rdf() {
		return "<"+toString(record[0])+"> <"+toString(record[1])+"> <"+toString(record[2])+"> .";
	}

};

#endif /* ROW_H_ */
