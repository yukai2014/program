/**
 * UnweightedGraph Class
 * Stub written by Sorrachai Yingchareonthawornchai, 29 OCT 2014
 * Completed by [Your Name]
 */
#include "UnweightedGraph.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string.h>

using namespace std;

UnweightedGraph::UnweightedGraph(const string& t)
{
	 //You may add any construction to your private attribute.
	ifstream in(t);
	if(!in.is_open()) {
		cerr << "cannot open file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	string line;
	while(getline(in,line)) {
		istringstream iss(line);
		int v;
		list<int> list_temp;
		while( iss >> v) {
			list_temp.push_back(v);
		}
		adjList.push_back(list_temp);
	}
//
//	for(auto it = adjList.begin(); it != adjList.end(); ++it) {
//		list<int> list_temp = *it;
//		for (auto item = list_temp.begin(); item != list_temp.end(); ++item) {
//			cout<<*item<<" ";
//		}
//		cout<<endl;
//	}
}

void UnweightedGraph::DisplayInfo() const{
	cout << "Adjacency list of the graph \n";
	auto printItem = [](const list<int>& alist) {
		copy(begin(alist),end(alist), ostream_iterator<int>(cout, " "));
		cout << endl;
	};
	for_each(begin(adjList),end(adjList), printItem);
}

bool UnweightedGraph::IsConnected() const {
	//TODO
	//You can use either DFS or BFS approach
	unsigned int i = 0;
	unsigned int max_count = 10000;
	bool visited[max_count];	// visited vertex
	for (i = 0; i < max_count; ++i)
		visited[i] = false;
	bool used[adjList.size()];	// visited list
	for (i = 0; i < adjList.size(); ++i)
			used[i] = false;

	// add vertex in first list
	list<int> list_temp = *adjList.begin();
	for (auto item = list_temp.begin(); item != list_temp.end(); ++item) {
		visited[*item] = true;
	}
	used[0] = true;	// list 0 is used

	bool has_new_list = true;
	while (has_new_list) {
		has_new_list = false;
		for (i = 1; i < adjList.size(); ++i) { // i = 1 because we have added list 0
			if (used[i]) continue;

			list<int> list_temp = adjList.at(i);
			for (auto item = list_temp.begin(); item != list_temp.end(); ++item) {

				if (visited[*item] == true) {	// if list has a vertex which is visited, then all vertex in list will be visited
					has_new_list = true;	// because of adding new list into visited
					used[i] = true;
					for (auto it = list_temp.begin(); it != list_temp.end(); ++it) {
						visited[*it] = true;
					}
					break;
				}//end if

			}//end for
		}
	}//end while

	for (i = 0; i < adjList.size(); ++i) {
		if (used[i] == false)
			return false;
	}
	return true;
}

bool UnweightedGraph::IsEulerian() const {
	//TODO
	int i = 0, j = 0;
	int vertex_count = 0;
	int max_count = 1000;
	int degrees[max_count][max_count];
	memset(degrees, 0, sizeof(degrees));
	for(auto it = adjList.begin(); it != adjList.end(); ++it) {	// transform adjList into matrix, also get the vertex count
		auto item = it->begin();
		int f = *item;
		vertex_count = vertex_count > f?vertex_count: f;
		for (item++; item != it->end(); ++item) {
			vertex_count = vertex_count > *item?vertex_count: *item;
			degrees[f][*item] = 1;
			degrees[*item][f] = 1;
		}
	}

//	for (i = 0; i <= vertex_count; ++i) {
//		for (j = 0; j <= vertex_count; ++j) {
//			cout<<degrees[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for (i = 0; i <= vertex_count; ++i) {
		int degree = 0;
		for (j = 0; j <= vertex_count; ++j) {
			if (degrees[i][j] == 1)
				++degree;
		}
		if (degree % 2 != 0)	// if degree % 2 = 0 then this graph must be Eulerian
			return false;
	}
	return true;
}

list<int> UnweightedGraph::FindEulerianCycle() const {
	list<int> current_cycle;
	int i, j;
	int k;
	int max_count = 1000;
	bool m[max_count][max_count];
	for (i = 0; i < max_count; ++i) {	// init matrix
		for (j = i; j < max_count; ++j) {
			m[i][j] = false;
			m[j][i] = false;
		}
	}

//	int visited_edge_count = 0;
	int vertex_count = 0;
	for (auto list:adjList) {	// transform adjList into matrix, also get the vertex count
		auto it = list.begin();
		int f = *(it++);
		vertex_count = vertex_count > f? vertex_count: f;

		for (;it != list.end(); ++it) {
			m[f][*it] = true;
			m[*it][f] = true;
			vertex_count = vertex_count > *it? vertex_count: *it;
		}
	}

//	for (i = 0; i <= vertex_count; ++i) {
//		for (j = 0; j <= vertex_count; ++j) {
//			cout<<m[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	cout<<"-----------"<<endl;

	// 找到随便一个圈，从圈上某个点找到另一个圈，加入到原来圈的合适位置。比如 第一圈为0-2-1-5-0，又从2找到一个圈2-3-4-2，则加入到第一圈为：0-2-3-4-2-1-5-0
	for (i = 0; i <= vertex_count; ++i) {
		for (j = i+1; j <= vertex_count; ++j) {
			if (m[i][j] == true) {	// 套圈法

				int init_vertex = i;
				auto pos = current_cycle.begin();
				while(pos != current_cycle.end()) {
					if (*(pos++) == init_vertex)
						break;
				}
				if (pos == current_cycle.end()) {	// find the appropriate position to insert
					current_cycle.insert(pos, i);
				}
				current_cycle.insert(pos, j);
				m[i][j] = false;
				m[j][i] = false;

				int next = -1;
				int now = j;
				while (next != init_vertex) {	// find a cycle from init_vertex
					for (k = 0; k <= vertex_count; ++k) {
						if (m[now][k] == true) {
							current_cycle.insert(pos, k);
							m[now][k] = false;
							m[k][now] = false;
							next = k;
							now = next;
							break;
						}
					}// end for
				}// end while
			}//end if

//			for (k = 0; k <= vertex_count; ++k) {
//				for (l = 0; l <= vertex_count; ++l) {
//					cout<<m[k][l]<<" ";
//				}
//				cout<<endl;
//			}
//			cout<<visited_edge_count<<endl;
//			std::copy(begin(current_cycle),end(current_cycle),std::ostream_iterator<int>(std::cout," "));
//			cout<<"============"<<i<<" "<<j<<" "<<k<<endl;

		}
	}

	return current_cycle;
}

bool UnweightedGraph::VerifyEulerCycle(const list<int>& cycle) const {
	//TODO
	int i, j;
	int max_count = 1000;
	bool m[max_count][max_count];
	for (i = 0; i < max_count; ++i) {// init matrix
		for (j = i; j < max_count; ++j) {
			m[i][j] = false;
			m[j][i] = false;
		}
	}

	int vertex_count = 0;
	for (auto list:adjList) {	// transform adjList into matrix, also get the vertex count
		auto it = list.begin();
		int f = *(it++);
		vertex_count = vertex_count > f? vertex_count: f;

		for (;it != list.end(); ++it) {
			m[f][*it] = true;
			m[*it][f] = true;
			vertex_count = vertex_count > *it? vertex_count: *it;
		}
	}
	auto item = cycle.begin();	// delete edge which got from cycle from matrix
	for (auto it = cycle.begin(); ; ++it) {
		item = it;
		if ((++item) == cycle.end()) break;

		if (m[*it][*item] == 1 && m[*item][*it] == 1) {
			m[*it][*item] = 0;
			m[*item][*it] = 0;
		}
		else {
			return false;
		}
	}
	int sum = 0;	// if matrix has no edge, then every edge is all in cycle, which means this cycle visited every edge, and this cycle is ok
	for (i = 0; i <= vertex_count; ++i) {
		for (j = 0; j <= vertex_count; ++j) {
			sum += m[i][j];
		}
	}
	if (sum != 0) return false;
	return true;
}
