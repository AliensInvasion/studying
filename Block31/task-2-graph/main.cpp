#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

class IGraph {
public:
    virtual ~IGraph() {};
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() = 0;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) = 0;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) = 0;
    virtual void show() = 0;
};

class ListGraph : public IGraph
{
    std::map<int, std::vector<int>> fromList{};
    std::map<int, std::vector<int>> toList{};

    void GetVertices(int &vertex, std::vector<int> &vertices, std::map<int, std::vector<int>> &list)
    {
        if (list[vertex].empty())
            return;
        for (size_t i = 0; i < list[vertex].size(); ++i) {
            vertices.push_back(list[vertex][i]);
        }
    }

public:

    ListGraph() {};
    ListGraph(IGraph *other)
    {
        std::vector<std::vector<int>> list{};
        const int count = other->VerticesCount();
        for (int i = 0; i < count; ++i) {
            std::vector<int> stringOfList{i};
            other->GetNextVertices(i, stringOfList);
            if (stringOfList.size() > 1)
                list.push_back(stringOfList);
        }
        for (int i = 0; i < list.size(); ++i) {
            for (int j = 1; j < list[i].size(); ++j) {
                AddEdge(list[i][0], list[i][j]);
            }
        }
    }
    virtual ~ListGraph() override {}
    std::unique_ptr<IGraph> operator=(IGraph *other)
    {
        return std::make_unique<ListGraph>(other);
    }
    virtual void AddEdge(int from, int to) override
    {
        if (from == to)
            return;
        for (int i = 0; i < fromList[from].size(); ++i) {
            if (fromList[from][i] == to) return;
        }

        fromList[from].push_back(to);
        toList[to].push_back(from);
    }
    virtual int VerticesCount() override
    {
        return (int)fromList.size();
    }
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) override
    {
        GetVertices(vertex, vertices, fromList);
    }
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) override
    {
        GetVertices(vertex, vertices, toList);
    }
    virtual void show() override
    {
        for (auto & i : fromList) {
            std::cout << std::setw(5) << i.first << " -> ";
            for (int j : i.second) {
                std::cout << j << " ";
            } std::cout << std::endl;
        }
    }
};

class MatrixGraph : public IGraph
{
    std::vector<std::vector<int>> matrix{};
    int edgesCount{0};

    void adaptMatrix(const int &newMax)
    {

        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i].push_back(0);
        }

        while (matrix.size() <= newMax) {
            std::vector<int> vec{};
            for (int i = 0; i <= edgesCount; ++i) { //!
                vec.push_back(0);
            }
            matrix.push_back(vec);
        }

    }
    void GetVertices(int &vertex, std::vector<int> &vertices, int factor = 1)
    {
        if (vertex > matrix.size())
            return;
        for (int i = 0; i < edgesCount; ++i) {
            if (matrix[vertex][i] == 1 * factor) {
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[j][i] == -1 * factor)
                        vertices.push_back(j);
                }
            }
        }
    }

public:

    MatrixGraph() {};
    MatrixGraph(IGraph *other)
    {
        std::vector<std::vector<int>> list{};
        for (int i = 0; i < other->VerticesCount(); ++i) {
            std::vector<int> stringOfList{i};
            other->GetNextVertices(i, stringOfList);
            if (stringOfList.size() > 1)
                list.push_back(stringOfList);
        }
        for (int i = 0; i < list.size(); ++i) {
            for (int j = 1; j < list[i].size(); ++j) {
                AddEdge(list[i][0], list[i][j]);
            }
        }
    }
    virtual ~MatrixGraph() override {}
    std::unique_ptr<IGraph> operator=(IGraph *other)
    {
        return std::make_unique<MatrixGraph>(other);
    }
    virtual void AddEdge(int from, int to) override
    {
        if (from == to)
            return;

        for (int i = 0; from < matrix.size() && to < matrix.size() && i < edgesCount; ++i) {
            if (matrix[from][i] == 1 && matrix[to][i] == -1) return;
        }

        (from > to) ? adaptMatrix(from) : adaptMatrix(to);

        matrix[from][edgesCount] = 1;
        matrix[to][edgesCount] = -1;

        ++edgesCount;

    }
    virtual int VerticesCount() override
    {
        return matrix.size();
    }
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) override
    {
        GetVertices(vertex, vertices);
    }
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) override
    {
        GetVertices(vertex, vertices, -1);
    }
    virtual void show() override
    {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                std::cout << std::right << std::setw(5) << matrix[i][j];
            } std::cout << std::endl;
        }
    }

};

void operate(IGraph* graph, std::string &request)
{
    std::cout << "Graph " << request << ". ";
    do
    {
        std::cout << "Enter request (add/get/count/show/exit):" << std::endl;
        std::cin >> request;
        if (request == "add")
        {
            std::cout << "Add new link:" << std::endl;
            int from, to;
            std::cin >> from >> to;
            graph->AddEdge(from, to);

        }
        if (request == "get")
        {
            std::cout << "Enter the vertex:" << std::endl;
            int vertex{};
            std::cin >> vertex;

            do {
                std::cout << "next or prev?" << std::endl;
                std::cin >> request;
            } while (request != "next" && request != "prev");


            std::vector<int> vertices{};

            if (request == "next")
                graph->GetNextVertices(vertex, vertices);
            if (request == "prev")
                graph->GetPrevVertices(vertex, vertices);

            for (int i = 0; i < vertices.size(); ++i) {
                std::cout << vertices[i] << " ";
            } std::cout << std::endl;

        }
        if (request == "count")
        {
            std::cout << "Sum of vertices = " << graph->VerticesCount() << std::endl;
        }
        if (request == "show")
        {
            graph->show();
        }

    } while (request != "exit");
}

int main() {

    IGraph *list = new ListGraph;
    IGraph *matrix = new MatrixGraph;
    std::string request{};
    do {
        std::cout << "Choose matrix or list(or end):" << std::endl;
        std::cin >> request;
        if (request == "list")
        {
            operate(list, request);
        }
        if (request == "matrix")
        {
            operate(matrix, request);
        }
    } while (request != "end");

    std::cout << "\nOriginal:\n" << std::endl;
    list->show();
    std::cout << std::endl;
    matrix->show();

    std::cout << "\nSwapped:\n" << std::endl;
    MatrixGraph mGraph = list;
    ListGraph lGraph = matrix;
    mGraph.show();
    std::cout << std::endl;
    lGraph.show();

    delete list;
    delete matrix;
}
