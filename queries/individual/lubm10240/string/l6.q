SELECT ?x ?y WHERE { 
	?y <http://swat.cse.lehigh.edu/onto/univ-bench.owl#subOrganizationOf> <http://www.University0.edu> . 
	?y <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#Department> . 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#worksFor> ?y . 
	?x <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#FullProfessor> . 
}
