PREFIX pharmkb:<http://bio2rdf.org/pharmgkb_vocabulary>
PREFIX irefindex:<http://bio2rdf.org/irefindex_vocabulary>
PREFIX pubmd:<http://bio2rdf.org/pubmed_vocabulary>
PREFIX pubmdrc:<http://bio2rdf.org/pubmed_resource>
PREFIX omim:<http://bio2rdf.org/omim_vocabulary>
PREFIX drug:<http://bio2rdf.org/drugbank>
PREFIX uniprot:<http://bio2rdf.org/uniprot>

SELECT ?o WHERE{
	pubmdrc:1374967_INVESTIGATOR_1 pubmd:last_name ?o .
	pubmdrc:1374967_AUTHOR_1 pubmd:last_name ?o .
}
