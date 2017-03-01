PREFIX pharmkb:<http://bio2rdf.org/pharmgkb_vocabulary>
PREFIX irefindex:<http://bio2rdf.org/irefindex_vocabulary>
PREFIX pubmd:<http://bio2rdf.org/pubmed_vocabulary>
PREFIX pubmdrc:<http://bio2rdf.org/pubmed_resource>
PREFIX omim:<http://bio2rdf.org/omim_vocabulary>
PREFIX drug:<http://bio2rdf.org/drugbank>
PREFIX uniprot:<http://bio2rdf.org/uniprot>

SELECT ?articleToMesh WHERE{
	<http://bio2rdf.org/pubmed:126183> pubmd:mesh_heading ?articleToMesh .
	?articleToMesh pubmd:mesh_descriptor_name ?mesh .
}
