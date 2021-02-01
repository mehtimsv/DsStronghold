#include <iostream>
#include <string>
using namespace std;
template <typename T>
class MyVector{
private:
    T* value;
    int size = 0;
public:
    MyVector(){

    }
    MyVector(int maxSize) {
        size = maxSize;
        value = (T*)malloc(maxSize * sizeof(T));
        for (int i = 0; i < maxSize; i++)
            value[i] = 0;
    }
    MyVector(int maxSize, T data) {
        size = maxSize;
        value = (T*)malloc(maxSize * sizeof(T));
        for (int i = 0; i < maxSize; i++)
            value[i] = data;
    }
    T operator [](int i) const {
        return value[i];
    }
    T& getAt(int index) {
        return value[index];
    }
    friend ostream &operator<<( ostream &output, const MyVector<T> &vector ){
        for (int i = 0; i < vector.size; i++)
            output << vector[i] << " ";
        output << "\n";
        return output;
    }
    void insert(int index, T val){
        size++;
        value = (T*)realloc(value, (size) * sizeof(T));
        int i = size+1;
        while(i != index){
            value[i] = value[i - 1];
            i--;
        }
        value[index] = val;
    }
    void push_front(T val) {
        size++;
        value = (T*)realloc(value, (size) * sizeof(T));
        int i = size+1;
        while(i != 0){
            value[i] = value[i - 1];
            i--;
        }
        value[0] = val;
    }
    void push_back(T val){
        value = (T*)realloc(value, (size + 1) * sizeof(T));
        value[size] = val;
        size++;
    }
    void pop(){
        value[size] = NULL;
        size--;
        value = (T*)realloc(value, (size) * sizeof(T));
    }
    void remove(int index){
        value[index] = NULL;
        while(index <= size){
            value[index] = value[index + 1];
            index++;
        }
        size--;
        value = (T*)realloc(value, (size) * sizeof(T));
    }
    int find(T data){
        for (int i = 0; i < size; i++)
            if (data == value[i])
                return i;
        return NULL;
    }
    int getSize(){
        return size;
    }
    ~MyVector() {
        free(value);
    }
};

template<class T>
class Queue {
    T *queue;
    int rear, front, capacity;


public:
    Queue(int qCapacity) : capacity(qCapacity) {
        rear = front = 0;
        queue = new T[capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    void push(T item) {
        if ((rear + 1) % capacity == front) throw "Queue is already full";
        else {
            queue[rear] = item;
            rear = (rear + 1) % capacity;
        }
    }

    void pop() {
        if (isEmpty())throw "Queue is already empty";
        else {
            // T last = queue[front];
            front = (front + 1) % capacity;
            queue[front].~T();
            //return (last);
        }
    }
    int search(T value) {
        for (int i = front+1; i != rear; i = (i + 1) % capacity)
            if (queue[i] == value)
                return i;
        return -1;
    }
    friend ostream &operator<<(ostream &output, const Queue <T> &queue) {
        for (int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity)
            output << queue.queue[i] << " ";
        output << "\n";
        return output;
    }

    int getSize() {
        if (rear >= front)
            return (rear - front) % capacity;
        return (front - rear) % capacity;
    }

    ~Queue() {
        delete queue;
    }

};

template<class T>
class Stack {
private:
    T *stack;
    int capacity;
    int top;
public:
    Stack(int stackCapacity) : capacity(stackCapacity) {
        stack = new T[capacity];
        top = -1;
    }

    void push(T item) {
        stack[++top] = item;
    }

    void pop() {
        if (top == -1) throw "Stack is already empty";
        stack[top--].~T();
    }

    int search(T value) {
        for (int i = 0; i <= top; i++)
            if (stack[i] == value)
                return i;
        return -1;
    }

    int getSize() {
        return top + 1;
    }

    friend ostream &operator<<(ostream &output, const Stack<T> &stack) {
        for (int i = 0; i <= stack.top; i++)
            output << stack.stack[i] << " ";
        output << "\n";
        return output;
    }

    ~Stack() {
        delete stack;
    }
};





/*
class Castle {
public:
    int src, dest, weight;
    Castle(){

    }

};

typedef pair<int, int> Pair;

// class to represent a graph object
class Game
{
public:
    // construct a vector of vectors of Pairs to represent an adjacency list
    MyVector<MyVector<Pair>> adjList;

    // Graph Constructor
    Game(MyVector<Castle>  edges, int N)
    {
        // resize the vector to N elements of type vector<Pair>


        // add edges to the directed graph
        for (int i = 0 ;i < edges.getSize();i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            // insert at the end
            adjList[src].push_back(make_pair(dest, weight));

            // Uncomment below line for undirected graph
            // adjList[dest].push_back(make_pair(src, weight));
        }
    }
};

// print adjacency list representation of graph
void printGraph(Graph const &graph, int N)
{
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of given vertex
        for (Pair v : graph.adjList[i])
            cout << "(" << i << ", " << v.first <<
                 ", " << v.second << ") ";
        cout << endl;
    }
}*/


class Soldier{
public:
    int power;
    string castle;
    int speed;
    int status; //




};


class Castle{
public:
    int index;
    string name;
    string owner;
    int capacity;
    Soldier* soldiers;

    Castle(){

    }

    Castle(int index, const string &name, const string &owner, int capacity) : index(index),name(name),owner(owner),capacity(capacity){
        soldiers = new Soldier[capacity];
    }

    void setInfo(int index, int capacity){
        index = index;
        capacity = capacity;
    }
    static Castle buildCastle(){
        return new Castle()
    }
};


class Game {
public:
    int** adjMatrix;
    int castleCount;
    Castle* castles;
    int outputCapacity;



    // Initialize the matrix to zero
    Game(int count , int _outputCapacity) {
        this->castleCount = count;
        this->outputCapacity = _outputCapacity;
        adjMatrix = new int*[count];
        castles = new Castle[count];

        for (int i = 0; i < count; i++) {
            adjMatrix[i] = new int[count];
            for (int j = 0; j < count; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }


    MyVector<int> getTargets(int index){
       // Castle targetCastles[castleCount];
//        int targetCastlesIndex[castleCount];
        MyVector<int> target(castleCount);

        for (int i = 0; i < castleCount; i++) {
            if(adjMatrix[index][i] > 0){
                target.push_back(i);
            }
        }

    }



    // Add edges
    void addEdge(int i, int j , int weight) {
        adjMatrix[i][j] = weight;
        adjMatrix[j][i] = weight;
    }

    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }

    // Print the martix
    void toString() {
        for (int i = 0; i < castleCount; i++) {
            cout << i << " : ";
            for (int j = 0; j < castleCount; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

    ~Game() {
        for (int i = 0; i < castleCount; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {


    Game g(5 , 25);

    // adj matrix :

    g.addEdge(0, 1,300);
    g.addEdge(1, 2,210);
    g.addEdge(1, 3,366);
    g.addEdge(1, 4,400);
    g.addEdge(2, 3,120);
    g.addEdge(3, 4,200);


    //castle info :
    g.castles[0].setInfo(0 , 100);
    g.castles[1].setInfo(0 , 200);
    g.castles[2].setInfo(0 , 300);
    g.castles[4].setInfo(0 , 400);
    g.castles[5].setInfo(0 , 500);




    g.toString();

}

