#include<iostream>
using namespace std;

class Node
    {
    public:
        int vertex;
        class Node* next;
        Node(int v) :vertex(v), next(nullptr) {

            }
        Node() = default;
    };

class Graph
    {
    public:
        Graph(int v) :numVertices(v) {
            this->adjLists = new Node * [v];
            for (int i = 0; i < v; i++)
                {
                this->adjLists[i] = nullptr;
                }
            }
        int numVertices;
        class Node** adjLists;
    };

Node* createNode(int v)
    {
    return new Node(v);
    }

Graph* createGraph(int vertices)
    {
    return new Graph(vertices);
    }


void addEdge(Graph* graph, int src, int dest)
    {

    //! Add edge from Source to Destination  0-->1
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    //! Add edge from Destination to Source  1-->0
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
    }

void printGraph(Graph* graph)
    {
    for (int i = 0; i < graph->numVertices; i++)
        {
        Node* temp = graph->adjLists[i];
        cout << "Vertex  " << i << " --->";
        while (temp)
            {
            cout << temp->vertex;
            if (temp->next != nullptr)
                cout << "-->";
            temp = temp->next;
            }
        cout << "\n";
        }
    }

int main()
    {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);
    return 0;
    }