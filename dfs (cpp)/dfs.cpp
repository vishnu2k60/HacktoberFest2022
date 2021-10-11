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

void dfs(adjacency_list_t list, int s, bool* visited) {
    std::cout << "Visiting node " << s << std::endl;
    visited[s] = true;

    for (auto i = list.second.begin(); i != list.second.end(); i++) {
        if (i->n1 == s) {
            if (!visited[i->n2]) {
                std::cout << "Going to vertex " << i->n2 << " from vertex " << s << std::endl;
                dfs(list, i->n2, visited);
            }
        }
    }
}

void dfs_helper(adjacency_list_t list, int s) {
    bool* visited = new bool[48];

    for (int i = 0; i < 48; i++) {
        visited[i] = false;
    }

    dfs(list, s, visited);

    //Double check to see if there are any unvisited nodes
    for (int i = 0; i < 48; i++) {
        if (!visited[i]) {
            std::cout << "Node " << i << " has not been visited" << std::endl;
        }
    }
}

int main() {
    adjacency_list_t list = parse_file("export.txt");
    dfs_helper(list, 0);
}