/*
-------------------------------------
File:    graph_components.h
Project: R12
file description
-------------------------------------
Author:  Will Roberts
ID:      191023880
Email:   robe3880@mylaurier.ca
Version  2021-07-27
-------------------------------------
 */

#ifndef GRAPH_COMPONENTS_H_
#define GRAPH_COMPONENTS_H_

# define True 1
# define False 0

typedef struct{
	int num;		// a unique number for the vertex
	char name[20];	// optional number
	
	
}Vertex;

Vertex* create_vertex(int num, char *name);
void print_vertex(Vertex *v);
void destroy_vertex(Vertex **v);
int is_equal_vertex(Vertex *v1, Vertex *v2);

typedef struct{
	Vertex *v1; 	// first vertex
	Vertex *v2;		// second vertex
	int weight;		// non weighted graph set to zero
	int directed; 	// undirected graph set to zero
}Edge;

Edge* create_edge(Vertex *v1, Vertex *v2, int w, int d);
void print_edge(Edge *e);
void destroy_edge(Edge **e);
int is_equal_edge(Edge *e1, Edge *e2);

#endif /* GRAPH_COMPONENTS_H_ */
