# graph-coloring
Planar 6 coloring

Program to color a given undirected planar graph using 6 color method \

*Algorithm* : \
1.If G contains only one vertex, assign is color a.\
2. Otherwise, pick a vertex, say v, with degree at most 5 from V(G) and recursively 6-color the
graph G \ v.The algorithm must pick a vertex with the smallest label from the set of all eligible
vertices. \
3. After returning from the recursion, assign v a color that none of its neighbors have been
assigned.The algorithm must assign the possible smallest color (assume that the colors are
ordered alphabetically, with a being the smallest and f being the large. \
