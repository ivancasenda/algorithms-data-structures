#pragma once

#include <vector>
#include "Vertex.h"

using namespace std;

class Graph {
public:
	vector<Vertex> verticies;

	Graph(){}

	void addVertex(Vertex& vertex) {
		verticies.push_back(vertex);
	}
};
