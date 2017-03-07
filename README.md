## A Survey and Experimental Comparison of Distributed SPARQL Engines for Very Large RDF Data


###Overview:
The versatility of the Resource Description Framework (RDF) has allowed many web services to publish very large datasets that are impractical to process on a single computer. Therefore, many distributed SPARQL engines on shared-nothing computer clusters have emerged. Some utilize distributed frameworks such as MapReduce; others implement proprietary distributed processing; and some rely on expensive pre-processing for data partitioning. These systems exhibit a variety of trade-offs that are not well-understood, due to the lack of any comprehensive quantitative and qualitative evaluation. 
In this paper, we present a survey of 21 state-of-the-art systems that cover the entire spectrum of distributed RDF data processing, categorize them by several characteristics, and explain their similarities and differences. Then, we select 11 representative systems and perform extensive experimental evaluation with respect to pre-processing cost, query performance, scalability and workload adaptability, using a variety of synthetic and real large datasets with up to 4.2B triples. Our results provide valuable insights for practitioners to understand the trade-offs for their usage scenarios.
Finally, we publish online our evaluation framework, including all datasets and workloads, for researchers to compare their novel systems against the existing ones.      


###Dataset Statistics:
|*Dataset* | *Download* | *Triples (M)* | *#S (M)* | *#O (M)* | *#S∩O (M)* | *#P* | *Indegree (Avg/StDev)* | *Outdegree (Avg/StDev)*|
|----------|------------|---------------|----------|----------|------------|------|------------------------|------------------------|
 [WatDiv] (http://db.uwaterloo.ca/watdiv)  | [Download] (https://www.dropbox.com/s/hzctwcrjdz812ax/wsdts_100m.tar.gz?dl=0) | 109.23  | 5.21 | 17.93 | 4.72 | 86 | 22.49/960.44 | 42.20/89.25  | 
 [YAGO2] (http://www.yago-knowledge.org) | [Download] (https://www.dropbox.com/s/6smvv4s3ix46tdq/yago.tar.gz?dl=0) | 284.30 | 10.12 | 52.34 | 1.77 | 98 | 5.43/2962.93 | 28.09/35.89 |
 [WatDiv-1B] (http://db.uwaterloo.ca/watdiv) | [Download] (https://www.dropbox.com/s/6iyltrnxttjbo46/watdiv.1000M.tar.gz?dl=0) | 1,092.16 | 52.12 | 179.09 | 46.95 | 86 | 23.69/2783.40 | 41.91/89.05 |
 [LUBM-10240] (http://swat.cse.lehigh.edu/projects/lubm/) | [Download] (https://www.dropbox.com/s/4ifouv5n5pa4vdk/10240_new_str.tar.gz?dl=0) | 1,366.71 | 222.21 | 165.29 | 51.00 | 18 | 16.54/26000.00 | 12.30/5.97 |
 [Bio2RDF] (http://download.bio2rdf.org/release/2/release.html) | [Download] (https://www.dropbox.com/s/qr4y4j00add7okx/all_bio2rdf_r2_str.nt.tar.gz?dl=0) | 4,287.59 | 552.08 | 1,075.58 | 491.73 | 1,714 | 8.64/21110.00 | 16.83/195.44 |


### Benchmark Queries 
All queries used in our experimental evaluation exists in #queries# folder including the individual benchmark queries or the query workloads.

####Individual Queries
* [LUBM-10240] (https://github.com/ecrc/rdf-exp/tree/master/queries/individual/lubm10240/string) 

* [WatDiv] (https://github.com/ecrc/rdf-exp/tree/master/queries/individual/watdiv-100m/string) 

* [YAGO2] (https://github.com/ecrc/rdf-exp/tree/master/queries/individual/yago2/string)

* [Bio2RDF] (https://github.com/ecrc/rdf-exp/tree/master/queries/individual/bio2rdf/string)


####Workloads
* [LUBM-10240 10K] (https://github.com/ecrc/rdf-exp/tree/master/queries/workloads/lubm10240/string/workload_10k)

* [WatDiv-1B 20K] (https://github.com/ecrc/rdf-exp/tree/master/queries/workloads/watdiv-1b/string/workload_20k)

###Tested Systems:

|*System* | *Download* |
|----------|------------------|
AdPart | https://github.com/razen-alharbi/AdPart |
TriAD | Contact Author: mailto:gurajada@mpi-inf.mpg.de |
SHAPE | https://sites.google.com/site/gtshape/ |
DREAM | https://github.com/CMU-Q/DREAM |
H2RDF+ | https://github.com/zcourts/h2rdf/tree/master/H2RDF%2Bv0.2 |
S2RDF | http://dbis.informatik.uni-freiburg.de/forschung/projekte/DiPoS/S2RDF.html | 
S2X | http://dbis.informatik.uni-freiburg.de/forschung/projekte/DiPoS/S2X.html | 
CliqueSquare | https://team.inria.fr/oak/projects/cliquesquare/ |
SHARD | https://svn.code.sf.net/p/shard-3store/code/ | 
H-RDF-3X | Contact Author: jiewen.huang@yale.edu |


