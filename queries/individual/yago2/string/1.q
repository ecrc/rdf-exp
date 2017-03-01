SELECT ?GivenName ?FamilyName WHERE{
    ?p <http://yago-knowledge.org/resource/hasGivenName> ?GivenName . 
    ?p <http://yago-knowledge.org/resource/hasFamilyName> ?FamilyName . 
    ?p <http://yago-knowledge.org/resource/wasBornIn> ?city . 
    ?p <http://yago-knowledge.org/resource/hasAcademicAdvisor> ?a .
    ?a <http://yago-knowledge.org/resource/wasBornIn> ?city .
}
