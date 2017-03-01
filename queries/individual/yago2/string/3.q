SELECT ?name1 ?name2 WHERE{
    ?a1 <http://yago-knowledge.org/resource/hasPreferredName> ?name1 . 
    ?a2 <http://yago-knowledge.org/resource/hasPreferredName> ?name2 .
    ?a1 <http://yago-knowledge.org/resource/actedIn> ?movie .
    ?a2 <http://yago-knowledge.org/resource/actedIn> ?movie .
}
