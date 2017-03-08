###Data Encoder
RDF data contain long strings in the form of URIs and literals. To avoid the storage, processing, and communication overheads, several systems; e.g. TriAD, H2RDF+ and AdPart, encode RDF strings into numerical IDs and build a bi-directional dictionary.
To prepare the input data for these systems, we use our utility project "NewFastEncoder". It gets as input the directory which contains the RDF data and output the encoded data in ntriples format and two separate dictionaries for predicates and vertices.

#### Compiling and Running
 * Change your current working directory to the NewFastEncoder directory. 

 ```
 cd Release

 make clean
 ```

* Compile NewFastEncoder. 
  ```
make all
 ```
* Usage:  
  ```
NewFastEncoder <input_dir> <encoded_file_path>
 ```
input_dir is the path of the RDF data files while encoded_file_path is the location where the encoded data will be located. Notice that the dictionaries will be created at the directory of the encoded data. 




###Query Encoder
Query Load Encoder encodes a workload of queries (separated by #EOQ#) using the predicates and vertices dictionaries created in the previous step. 

#### Compiling and Running
 * Change your current working directory to the QueryLoadEncoder directory. 

 ```
 cd Release

make clean
 ```

* Compile QueryLoadEncoder. 
  ```
make all
 ```
* Usage:  
  ```
QueryLoadEncoder <predicate_map_file> <vertices_map_file> <query_files_directory>
 ```
The encoded query file will be located in query_files_directory.




