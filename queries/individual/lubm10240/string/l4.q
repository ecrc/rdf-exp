SELECT ?x ?y1 ?y2 ?y3 WHERE { 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#worksFor> <http://www.Department0.University0.edu> . 
	?x <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#FullProfessor> .
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#name> ?y1 . 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#emailAddress> ?y2 . 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#telephone> ?y3 . 
}
