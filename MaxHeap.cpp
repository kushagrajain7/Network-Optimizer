#include "MaxHeap.h"
#include <iostream>

MaxHeap::MaxHeap() {

	// Initialize the values of the three arrays
	for (size_t i = 0; i < nNodes; i++)
	{
		nodeID[i] = -1; // array to find the ID of the node given the position in the heap
		valueNodes[i] = -1; // array to find the value of a node given the position in the heap
		posInHeap[i] = -1; // array to find the position of the vertex in the heap
	}
}


void MaxHeap::swapAll(int posNode1, int posNode2) {

	//std::swap(posInTheHeap[posNode1], posInTheHeap[nodeID[posNode2]]);
	std::swap(valueNodes[posNode1], valueNodes[posNode2]);
	std::swap(nodeID[posNode1], nodeID[posNode2]);


}


void MaxHeap::deleteNode(int node) {

	//std::cout << "\nDelete node: " << node << std::endl;

	// Find the location  of the node in the heap
	int pos = posInHeap[node];

	// Find the value of the node
	int value = valueNodes[pos];

	// Delete this node from the H and D array
	// Record this changes into P array
	int temp = posInHeap[nodeID[nCurrNodes - 1]];
	posInHeap[node] = -1;
	nodeID[pos] = -1;
	valueNodes[pos] = -1;

	if (temp != pos) {

		posInHeap[nodeID[nCurrNodes - 1]] = pos;

		// Place the last element of the heap in the position where node is deleted
		swapAll(pos, nCurrNodes - 1);

		// Call heapify to fix everthing
		heapify(1, nodeID[pos]);
		heapify(0, nodeID[pos]);
	}


	// Decrease the number of current nodes
	nCurrNodes--;

	//print();

}



void MaxHeap::heapify(bool up, int node) {

	int pos = posInHeap[node];
	int parent = (pos - 1) / 2;

	int l = 2 * pos + 1;
	int r = 2 * pos + 2;

	if (up) {
		// Go up
		// Check if the node is the root
		if (pos == 0)
			return;
		else {
			// Check the parent
			if (valueNodes[pos] > valueNodes[parent]) {


				std::swap(posInHeap[node], posInHeap[nodeID[parent]]);
				swapAll(pos, parent);

			/*	edge temp = heap[parent];

				temp.position = heap[pos].position;
				heap[pos].position = heap[parent].position;

				heap[parent] = heap[pos];
				heap[pos] = temp;*/

				heapify(1, node);
			}
			else
				// The node is at the correct position 
				return;
		}
	}
	else {
		//  Go down
		int child;

		if (r >= nCurrNodes) {

			if (l >= nCurrNodes)
				// The node is a leaf => done
				return;

			// Only one child
			else if (valueNodes[l] > valueNodes[pos])
				child = l;
			else
				return;
		}
		// Two children
		else if (valueNodes[l] >= valueNodes[r] && valueNodes[l] > valueNodes[pos])
			child = l;
		else if (valueNodes[r] > valueNodes[l] && valueNodes[r] > valueNodes[pos])
			child = r;
		else
			return;


		std::swap(posInHeap[node], posInHeap[nodeID[child]]);
		swapAll(pos, child);
		heapify(0, node);
		/*edge temp = heap[child];

		temp.position = heap[pos].position;
		heap[pos].position = heap[child].position;

		heap[child] = heap[pos];
		heap[pos] = temp;

		heapify(0, heap[child]);*/
	}


}

void MaxHeap::insertNode(int node, int value) {

	// Increase the number of nodes
	nCurrNodes++;

	// Place the new node at the end of the heap
	nodeID[nCurrNodes - 1] = node;
	valueNodes[nCurrNodes - 1] = value;
	posInHeap[node] = nCurrNodes - 1;

	// Call heapify to fix everything
	heapify(1, node);

}





void MaxHeap::printIdxNodes() {

	std::cout << "Print the Tree of the indices\n";
	for (size_t i = 0; i < nNodes; i++)
	{
		std::cout << nodeID[i] << " ";
		if (i % 2 == 0)
			std::cout << "\n";
	}


}
void MaxHeap::printValuesNodes() {

	std::cout << "Print the Tree of the values\n";
	for (size_t i = 0; i < nNodes; i++)
	{
		std::cout << valueNodes[i] << " ";
		if (i % 2 == 0)
			std::cout << "\n";
	}

}
void MaxHeap::printposInTheHeap() {

	std::cout << "Print the Tree of the positions\n";
	for (size_t i = 0; i < nNodes; i++)
	{
		std::cout << posInHeap[i] << " ";
	}

}

void MaxHeap::print() {
	std::cout << "\n";
	printIdxNodes();
	std::cout << "\n";
	printValuesNodes();
	std::cout << "\n";
	printposInTheHeap();
}


//void MaxHeap::heapify(bool up, int node) {
//
//
//	int pos = posInHeap[node];
//	int parent = (pos - 1) / 2;
//
//	int l = 2 * pos + 1;
//	int r = 2 * pos + 2;
//
//
//
//	if (up) {
//		// Go up
//		// Check if the node is the root
//		if (pos == 0)
//			return;
//		else {
//			// Check the parent
//			if (valueNodes[pos] > valueNodes[parent]) {
//				std::swap(posInHeap[node], posInHeap[nodeID[parent]]);
//				swapAll(pos, parent);
//				heapify(1, node);
//			}
//			else
//				// The node is at the correct position 
//				return;
//		}
//	}
//	else {
//		//  Go down
//		int child;
//
//		if (r >= nCurrNodes - 1) {
//			// The node is a leaf => done
//			if (l >= nCurrNodes - 1)
//				return;
//			// Only one child
//			else if (valueNodes[l] > valueNodes[pos])
//				child = l;
//			else
//				return;
//		}
//		// Two children
//		else if (valueNodes[l] > valueNodes[r])
//			child = l;
//		else if (valueNodes[l] < valueNodes[r])
//			child = r;
//		else
//			return;
//
//		std::swap(posInHeap[node], posInHeap[nodeID[child]]);
//		swapAll(pos, child);
//		heapify(0, node);
//	}
//
//
//}