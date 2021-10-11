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

void generate_path(std::list<int> &path, std::vector<int> prev, int s, int t) {
    //As long as the previous node is not "undefined"
    if (prev[t] != -1) {
        path.push_front(prev[t]);
        generate_path(path, prev, s, prev[t]);
    }
}

void dijkstra(adjacency_list_t list, int s, int t) {
    //Defining the found flag
    bool found = false;

    //List containing all the node visited throughout the path
    std::list<int> path;

    //Defining a large number
    double INF = 1000.000;

    //Distance list
    std::vector<double> dist(48, INF);

    //Previous list
    std::vector<int> prev(48, -1);

    //Queue
    std::set<std::pair<double, int>> queue;

    //Setting the source distance to 0
    dist[s] = 0;

    //Adding the source to the queue
    queue.insert(std::make_pair(0, s));

    while (!queue.empty()) {
        //The set is sorted by the weight of each node so the first element in the queue
        //represents the cheapest adjacent node to the previous current node
        std::pair<double, int> u = *(queue.begin());

        //Remove the current node from the queue
        queue.erase(queue.begin());

        //Checks if the target node has been found
        if (u.second == t) {
            found = true;
        }

        //Run only if the target node has not been found
        if (!found) {
            for (auto i = list.second.begin(); i != list.second.end(); i++) {
                //If the node in the list is adjacent to the first node in the queue
                if (u.second == i->n1) {
                    //The new weight
                    double alt = dist[u.second] + i->weight;
                    //Check if the new weight is smaller then the current weight of that node
                    if (alt < dist[i->n2]) {
                        //Update the weight
                        dist[i->n2] = alt;
                        //Add the node into the queue
                        queue.insert(std::make_pair(alt, i->n2));
                        //Set previous node to the current node
                        prev[i->n2] = u.second;
                    }
                }
            }
        }
    }

    generate_path(path, prev, s, t);
    
    std::cout << "Path: ";

    for (auto i : path) {
        std::cout << i << " -> ";
    }

    std::cout << t << std::endl;
    std::cout << "Total distance: " << dist[t] << std::endl << std::endl;
}

int main() {
    adjacency_list_t list = parse_file("export.txt");
    dijkstra(list, 23, 37); //M 23 Bergsgatan Nackstavägen -> M 37 Förrådet
}