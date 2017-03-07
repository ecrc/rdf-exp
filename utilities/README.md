###Data Encoder
Some RDF systems require encoding the data 

RDF data contain long strings in the form of URIs and literals. To avoid the storage, processing, and communication overheads, several systems; e.g. TriAD, H2RDF+ and AdPart, encode RDF strings into numerical IDs and build a bi-directional dictionary.
To prepare the input data for these systems, we use our utility project "NewFastEncoder". It gets as input the directory which contains the RDF data and output the encoded data in ntriples format and two separate dictionaries for predicates and vertices.

#### Compiling and Running
 * Change your current working directory to the NewFastEncoder directory. 
 ```
 cd Release
 ```
* Generate the make files by running qmake.
  ```
make clean
 ```
* Compile NewFastEncoder. 
  ```
make all
 ```

