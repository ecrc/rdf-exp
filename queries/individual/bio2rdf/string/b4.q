PREFIX pharmkb:<http://bio2rdf.org/pharmgkb_vocabulary>
PREFIX irefindex:<http://bio2rdf.org/irefindex_vocabulary>
PREFIX pubmd:<http://bio2rdf.org/pubmed_vocabulary>
PREFIX pubmdrc:<http://bio2rdf.org/pubmed_resource>
PREFIX omim:<http://bio2rdf.org/omim_vocabulary>
PREFIX drug:<http://bio2rdf.org/drugbank>
PREFIX uniprot:<http://bio2rdf.org/uniprot>


SELECT ?pharmgkbid WHERE{
	?pharmgkbid pharmkb:xref drug:DB00126 .
	?pharmgkbid pharmkb:xref ?pccid .
	?DDIassociation pharmkb:chemical ?pccid .
	?DDIassociation pharmkb:event ?DDIevent .
	?DDIassociation pharmkb:chemical ?drug2 .
	?DDIassociation pharmkb:p-value ?pvalue .
}
