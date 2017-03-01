SELECT ?y ?x ?z WHERE { 
	?x <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#UndergraduateStudent> .
	?z <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#FullProfessor> .
	?y <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#Course> .
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#advisor> ?z .
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#takesCourse> ?y .
	?z <http://swat.cse.lehigh.edu/onto/univ-bench.owl#teacherOf> ?y .
}
