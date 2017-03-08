//============================================================================
// Name        : RDFDataEncoder
// Version     :
// Copyright   : KAUST-Infocloud
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "partitioner_store.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char** argv) {
	if(argc < 3){
		print_to_screen("USAGE: RDFEncoder input_dir output_file_path");
		exit(-1);
	}
	string input_dir = string(argv[1]);
	string output_file_name = string(argv[2]);
	partitioner_store * store;

	store = new partitioner_store();
	store->load_encode_rdf_data(input_dir, output_file_name);
	//store->dump_encoded_data(file_name);


	delete store;
	print_to_screen(part_string);
	print_to_screen("Run Finished Successfully");
	return 0;
}
