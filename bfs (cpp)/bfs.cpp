#include "reader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <set>
#include <stack>

enum token {
    COMMENT, META, EDGE, END_OF_FILE
};

token get_line_type(std::istream& is) {
    switch (is.peek()) {
    case std::istream::traits_type::eof():      return END_OF_FILE;
    case '#':                                   return COMMENT;
    case 'M':                                   return META;
    };
    return EDGE;
}

meta_t meta;

edge read_edge(std::istream& is) {
    edge e;
    is >> e.n1 >> e.n2 >> e.weight;
    std::getline(is, e.description);
    return e;
}

void read_meta(std::istream& is) {
    char discard;
    node_id_t vertex_id;
    std::string name;
    is >> discard >> vertex_id;
    std::getline(is, name);
    meta[vertex_id] = name;
}

adjacency_list_t parse_file(std::string filename) {
    std::ifstream in(filename);
    token l;
    edge_list_t edge_list;
    while ((l = get_line_type(in)) != END_OF_FILE) {
        edge e;
        switch (l) {
        case token::EDGE:
            e = read_edge(in);
            edge_list.push_back(e);
            break;
        case token::META:
            read_meta(in);
            break;
        default:
            std::string comment;
            std::getline(in, comment);
        }
    }
    return adjacency_list_t{ meta, edge_list };
}

void bfs(adjacency_list_t list, int s) {
    std::list<int> queue;
    std::vector<bool> visited(48, false);

    //Adding the starting node to the queue
    queue.push_back(s);

    //Setting start node to visited
    visited[s] = true;

    while (!queue.empty()) {
        //Stores the first node in the queue
        int first_node_in_queue = queue.front();
        
        //Removes the first node from the queue
        queue.pop_front();

        std::cout << "Checking for adjacent nodes that are connected to " << first_node_in_queue << std::endl;

        //Iterate through list of nodes
        for (auto i = list.second.begin(); i != list.second.end(); i++) {
            //If the node is connected to the first node in the queue
            if (i->n1 == first_node_in_queue) {
                //If the node is unvisited
                if (!visited[i->n2]) {
                    std::cout << "Visited " << i->n2 << std::endl;
                    //Mark it off as visited
                    visited[i->n2] = true;
                    //Add the node into the queue
                    queue.push_back(i->n2);
                }
            }
        }
    }

    //Double check to see if there are any unvisited nodes
    for (int i = 0; i < 48; i++) {
        if (!visited[i]) {
            std::cout << "Node " << i << " has not been visited" << std::endl;
        }
    }
}

int main() {
    adjacency_list_t list = parse_file("export.txt");
    bfs(list, 0);
}