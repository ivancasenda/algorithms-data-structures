#pragma once
#include <vector>
#include "Edge.h"

class Vertex {
public:
	int id = NULL;
	int length = NULL;
	std::vector<Edge> neighbors;

	Vertex(int id): id(id){}

	void addNeighbors(int destination, int weight = 1) {
		neighbors.push_back(Edge(id, destination, weight));
	}

};