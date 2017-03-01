SELECT ?x ?y ?z WHERE { 
	?z <http://swat.cse.lehigh.edu/onto/univ-bench.owl#subOrganizationOf> ?y . 
	?z <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#Department> . 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#memberOf> ?z . 
	?x <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#GraduateStudent> . 
	?x <http://swat.cse.lehigh.edu/onto/univ-bench.owl#undergraduateDegreeFrom> ?y . 
	?y <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://swat.cse.lehigh.edu/onto/univ-bench.owl#University> . 
}
