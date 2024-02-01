#include <iostream>
#include <vector>
#include "Graph.h"
#include "linked_list.h"

void BFS() {

	Graph graph;
	
	Vertex vertex0(0);
	vertex0.addNeighbors(1);
	vertex0.addNeighbors(2);
	graph.addVertex(vertex0);

	Vertex vertex1(1);
	vertex1.addNeighbors(3);
	graph.addVertex(vertex1);

	Vertex vertex2(2);
	vertex2.addNeighbors(1);
	vertex2.addNeighbors(3);
	graph.addVertex(vertex2);
	
	Vertex vertex3(3);
	graph.addVertex(vertex3);


	for (int i = 0; i < graph.verticies.size(); i++) {
		std::cout << graph.verticies[i].id << std::endl;
		for (int j = 0; j < graph.verticies[i].neighbors.size(); j++) {
			std::cout << graph.verticies[i].neighbors[j].source << " " << graph.verticies[i].neighbors[j].destination << std::endl;
		}
		std::cout << std::endl;
	}
	int find = 3;
	std::vector<Vertex> visited;
	LinkedList<Vertex> queue;
	graph.verticies[0].length = 0;
	queue.push(graph.verticies[0]);
	while (queue.size() != 0) { 
		Vertex curr = queue.pop();
		visited.push_back(curr);
		if (curr.id == find) {
			std::cout << std::endl << curr.id << " " << curr.length;
		}
		for (int i = 0; i < curr.neighbors.size(); i++) {
			
		}

	}

}