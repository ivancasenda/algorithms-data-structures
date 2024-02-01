#pragma once


class Edge {

public:
	int source;
	int destination;
	int weight;

	Edge(int source, int destination, int weight) : source(source), destination(destination), weight(weight) {}
};
