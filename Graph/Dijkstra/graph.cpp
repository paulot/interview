#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <limits.h>
#include "Helpers.cpp"

using namespace std;

template <class T>
class Graph {
    public:
        Graph () { };
        Graph (T item) { };
        void                   Insert         (T item);
        void                   Connect        (T from, T to);
        void                   Print          ();
        map <T, int>           getConnections (T from);
    private:
        map <T, vector<T> > connections;
        bool    isPresent     (T item);
};

template <class T>
void Graph<T>::Insert (T item) {
    connections[item];
}

// Connect two nodes
// If the from node does not exist, it is created
template <class T>
void Graph<T>::Connect (T from, T to) {
    if (isPresent(to))
        connections[from].push_back(to);
}

template <class T>
bool Graph<T>::isPresent (T item) {
    return connections.find(item) != connections.end();
}

template <class T>
void Graph<T>::Print () {
    typename map<T, vector<T> >::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); ++iter) {
        cout << iter->first << ": ";
        for (int j = 0; j < iter->second.size(); j++) {
            cout << iter->second[j] << ", ";
        }
        cout << endl;
    }
}

template <class T>
map <T, int> Graph<T>::getConnections (T from) {
    priority_queue<T, vector<T>, Order<T> > toVisit;
    map<T, int> ans;
    map<T, bool> seen;
    typename map<T, vector<T> >::iterator iter;
    for (iter = connections.begin(); iter != connections.end(); ++iter) {
        ans[iter->first] = INT_MAX;
        seen[iter->first] = false;
    }

    ans[from] = 0;
    toVisit.push(from);

    while (not toVisit.empty()) {
        T checking;
        checking = toVisit.top();
        toVisit.pop();
        seen[checking] = true;

        // Check all of "checking's" connections
        for (int i = 0; i < connections[checking].size(); i++) {
            if (not seen[connections[checking][i]] and ans[connections[checking][i]] > ans[checking] + 1) {
                ans[connections[checking][i]] = ans[checking] + 1;
                toVisit.push(connections[checking][i]);
            }
        }
    }


    return ans;
}

int main() {
    Graph<string> graph;
    graph.Insert("andres");
    graph.Insert("crystal");
    graph.Insert("eric");
    graph.Insert("may");
    graph.Insert("denis");
    graph.Insert("dustin");

    graph.Connect("andres", "crystal");
    graph.Connect("crystal", "andres");
    graph.Connect("crystal", "eric");
    graph.Connect("eric", "andres");
    graph.Connect("may", "crystal");
    graph.Connect("denis", "may");
    graph.Connect("denis", "dustin");
    graph.Connect("dustin", "may");
    

    cout << "denis" << endl;
    map<string, int> m = graph.getConnections("denis");
    map<string, int >::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << "crystal" << endl;
    m = graph.getConnections("crystal");
    for (iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << "may" << endl;
    m = graph.getConnections("may");
    for (iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    cout << "dustin" << endl;
    m = graph.getConnections("dustin");
    for (iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

