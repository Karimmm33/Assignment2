#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Graph {
	map<int, vector<int>> edges;

	//Specifications:
	//Requires: Two vectors vectors of type int including the edges start and end points.
	//Effects: Initializes the graph with the given edges.
	//Test cases: 
	//1- If the sizes of the vectors are not equal, we throw an invalid argument error.
	Graph(const vector<int> start, const vector<int>& end) {
		if (start.size() != end.size()) {
			throw invalid_argument("Sizes of start and end don't match!");
		}
		else {
			for (int i = 0; i < start.size(); i++) {
				int k = start.at(i);
				if (edges.count(k)) {
					edges[k].push_back(end.at(i));
				}
				else {
					edges.insert(pair<int, vector<int>>(k, { end.at(i) }));
				}
			}
		}
	}
	//Specifications:
	//Requires: An integer that is the nodeID
	//Effects: Returns the number of outgoing edges from the given nodeID.
	//Test cases: 
	//1- If the nodeID is not in the graph, we print "The node is not in the graph" and return -1.
	int numOutgoing(const int nodeID) {
		if (edges.count(nodeID)) {
			return(edges[nodeID].size());
		}
		else {
			cout << "The node is not in the graph";
			return -1;
		}
	}
	//Specifications:
	//Requires: An integer that is the nodeID
	//Effects: Returns a reference to the list of nodes which nodeID has outgoing edges
	//Test cases: 
	//1- If the nodeID is not in the graph, we print "The node is not in the graph" and return -1.
	const vector<int>& adjacent(const int NodeID) {
		if (edges.count(NodeID)) {
			return edges[NodeID];
		}
		else {
			cout << "The node is not in the graph";
			return {};
		}
	}
};