/*
-------------------------------------
File:     graph.h
Project: R12
file description
-------------------------------------
Author:  Will Roberts
ID:      191023880
Email:   robe3880@mylaurier.ca
Version  2021-07-27
-------------------------------------
 */

#ifndef GRAPH_H_
#define GRAPH_H_

# include "graph_components.h"

# define True 1
# define False 0
# define BLOCK 5

typedef struct{
	int **matrix;
	Vertex *vertex_list;
	int vertex_count;
	int edge_count;
	int directed;		// 0 mean undireected 1 means directed 
	int weighted;		// 0 means unweighted 1 means weighted
}Graph;

Graph* create_graph(int w, int d);
void destroy_graph(Graph **g);
void print_graph(Graph *g);
int is_null_graph(Graph *g);
int is_empty_graph(Graph *g);
int add_vertex_graph(Graph *g, Vertex *v);
int has_vertex_graph(Graph *g, Vertex *v);
int remove_vertex_graph(Graph *g, Vertex *v);
int add_edge_graph(Graph *g, Edge *e);
int has_edge_graph(Graph *g, Edge *e);
int remove_edge_graph(Graph *g, Edge *e);


#endif /* GRAPH_H_ */
