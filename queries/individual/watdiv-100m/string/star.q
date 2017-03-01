SELECT ?v0 ?v1 ?v3 ?v4 ?v5 ?v6 ?v7 ?v8 ?v9 
WHERE {
        ?v0 <http://purl.org/goodrelations/includes> ?v1 .
        <http://db.uwaterloo.ca/~galuc/wsdbm/Retailer9> <http://purl.org/goodrelations/offers> ?v0 .
        ?v0 <http://purl.org/goodrelations/price> ?v3 .
        ?v0 <http://purl.org/goodrelations/serialNumber> ?v4 .
        ?v0 <http://purl.org/goodrelations/validFrom> ?v5 .
        ?v0 <http://purl.org/goodrelations/validThrough> ?v6 .
        ?v0 <http://schema.org/eligibleQuantity> ?v7 .
        ?v0 <http://schema.org/eligibleRegion> ?v8 .
        ?v0 <http://schema.org/priceValidUntil> ?v9 .
}
#EOQ#



SELECT ?v0 ?v1 ?v3 ?v4 ?v5 ?v6 ?v7 ?v8 ?v9 
WHERE {
        ?v0 <http://purl.org/goodrelations/includes> ?v1 .
        <http://db.uwaterloo.ca/~galuc/wsdbm/Retailer4> <http://purl.org/goodrelations/offers> ?v0 .
        ?v0 <http://purl.org/goodrelations/price> ?v3 .
        ?v0 <http://purl.org/goodrelations/serialNumber> ?v4 .
        ?v0 <http://purl.org/goodrelations/validFrom> ?v5 .
        ?v0 <http://purl.org/goodrelations/validThrough> ?v6 .
        ?v0 <http://schema.org/eligibleQuantity> ?v7 .
        ?v0 <http://schema.org/eligibleRegion> ?v8 .
        ?v0 <http://schema.org/priceValidUntil> ?v9 .
}
#EOQ#



SELECT ?v0 ?v1 ?v3 ?v4 ?v5 ?v6 ?v7 ?v8 ?v9 
WHERE {
        ?v0 <http://purl.org/goodrelations/includes> ?v1 .
        <http://db.uwaterloo.ca/~galuc/wsdbm/Retailer10> <http://purl.org/goodrelations/offers> ?v0 .
        ?v0 <http://purl.org/goodrelations/price> ?v3 .
        ?v0 <http://purl.org/goodrelations/serialNumber> ?v4 .
        ?v0 <http://purl.org/goodrelations/validFrom> ?v5 .
        ?v0 <http://purl.org/goodrelations/validThrough> ?v6 .
        ?v0 <http://schema.org/eligibleQuantity> ?v7 .
        ?v0 <http://schema.org/eligibleRegion> ?v8 .
        ?v0 <http://schema.org/priceValidUntil> ?v9 .
}
#EOQ#


SELECT ?v0 ?v1 ?v3 
WHERE {
        ?v0 <http://purl.org/dc/terms/Location> ?v1 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country19> .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/gender> ?v3 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/Role2> .
}
#EOQ#



SELECT ?v0 ?v1 ?v3 
WHERE {
        ?v0 <http://purl.org/dc/terms/Location> ?v1 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country7> .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/gender> ?v3 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/Role2> .
}
#EOQ#



SELECT ?v0 ?v1 ?v3 
WHERE {
        ?v0 <http://purl.org/dc/terms/Location> ?v1 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country8> .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/gender> ?v3 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/Role2> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 ?v4 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory12> .
        ?v0 <http://schema.org/caption> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> ?v3 .
        ?v0 <http://schema.org/publisher> ?v4 .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 ?v4 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory4> .
        ?v0 <http://schema.org/caption> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> ?v3 .
        ?v0 <http://schema.org/publisher> ?v4 .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 ?v4 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory5> .
        ?v0 <http://schema.org/caption> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> ?v3 .
        ?v0 <http://schema.org/publisher> ?v4 .
}
#EOQ#


SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://xmlns.com/foaf/age> <http://db.uwaterloo.ca/~galuc/wsdbm/AgeGroup2> .
        ?v0 <http://xmlns.com/foaf/familyName> ?v2 .
        ?v3 <http://purl.org/ontology/mo/artist> ?v0 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country1> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://xmlns.com/foaf/age> <http://db.uwaterloo.ca/~galuc/wsdbm/AgeGroup6> .
        ?v0 <http://xmlns.com/foaf/familyName> ?v2 .
        ?v3 <http://purl.org/ontology/mo/artist> ?v0 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country1> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://xmlns.com/foaf/age> <http://db.uwaterloo.ca/~galuc/wsdbm/AgeGroup2> .
        ?v0 <http://xmlns.com/foaf/familyName> ?v2 .
        ?v3 <http://purl.org/ontology/mo/artist> ?v0 .
        ?v0 <http://schema.org/nationality> <http://db.uwaterloo.ca/~galuc/wsdbm/Country1> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory4> .
        ?v0 <http://schema.org/description> ?v2 .
        ?v0 <http://schema.org/keywords> ?v3 .
        ?v0 <http://schema.org/language> <http://db.uwaterloo.ca/~galuc/wsdbm/Language0> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory10> .
        ?v0 <http://schema.org/description> ?v2 .
        ?v0 <http://schema.org/keywords> ?v3 .
        ?v0 <http://schema.org/language> <http://db.uwaterloo.ca/~galuc/wsdbm/Language0> .
}
#EOQ#



SELECT ?v0 ?v2 ?v3 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://db.uwaterloo.ca/~galuc/wsdbm/ProductCategory3> .
        ?v0 <http://schema.org/description> ?v2 .
        ?v0 <http://schema.org/keywords> ?v3 .
        ?v0 <http://schema.org/language> <http://db.uwaterloo.ca/~galuc/wsdbm/Language0> .
}
#EOQ#


SELECT ?v0 ?v1 ?v2 
WHERE {
        ?v0 <http://purl.org/ontology/mo/conductor> ?v1 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> <http://db.uwaterloo.ca/~galuc/wsdbm/SubGenre37> .
}
#EOQ#



SELECT ?v0 ?v1 ?v2 
WHERE {
        ?v0 <http://purl.org/ontology/mo/conductor> ?v1 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> <http://db.uwaterloo.ca/~galuc/wsdbm/SubGenre73> .
}
#EOQ#



SELECT ?v0 ?v1 ?v2 
WHERE {
        ?v0 <http://purl.org/ontology/mo/conductor> ?v1 .
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ?v2 .
        ?v0 <http://db.uwaterloo.ca/~galuc/wsdbm/hasGenre> <http://db.uwaterloo.ca/~galuc/wsdbm/SubGenre141> .
}
#EOQ#


SELECT ?v0 ?v1 ?v2 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ?v1 .
        ?v0 <http://schema.org/text> ?v2 .
        <http://db.uwaterloo.ca/~galuc/wsdbm/User258> <http://db.uwaterloo.ca/~galuc/wsdbm/likes> ?v0 .
}
#EOQ#



SELECT ?v0 ?v1 ?v2 
WHERE {
        ?v0 <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> ?v1 .
        ?v0 <http://schema.org/text> ?v2 .
        <http://db.uwaterloo.ca/~galuc/wsdbm/User506> <http://db.uwaterloo.ca/~galuc/wsdbm/likes> ?v0 .
}
#EOQ#


