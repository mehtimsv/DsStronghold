#include <iostream>
#include <string>
#include <queue>
#include <vector>
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
    Queue(){

    }
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
    T getFront(){
        return queue[front];
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


class Soldier{
public:
    int power;
    int castleIndex;
    int status;//0 alive
    Soldier(){

    }

    Soldier(int _power, int _castleIndex)  {
        power = _power;
        castleIndex = _castleIndex;
        status = 0;
    }
    bool operator<(const Soldier s){
        return power < s.power;
    }
    friend ostream &operator<<( ostream &output, const Soldier &soldier ){
        output<<soldier.power<<endl;
        return output;
    }
};



template<class T>
struct node {
    struct node *left;
    T data;
    int height;
    struct node *right;

};
template<class T>
class AVL
{
private:

public:
    struct node<T> * root;
    AVL(){
        this->root = NULL;
    }

    int calheight(struct node<Soldier> *p){

        if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
        }
        else if(p->left && p->right == NULL){
            return p->left->height + 1;
        }
        else if(p->left ==NULL && p->right){
            return p->right->height + 1;
        }
        return 0;

    }

    int bf(struct node<T> *n){
        if(n->left && n->right){
            return n->left->height - n->right->height;
        }
        else if(n->left && n->right == NULL){
            return n->left->height;
        }
        else if(n->left== NULL && n->right ){
            return -n->right->height;
        }
    }

    struct node<T> * llrotation(struct node<T> *n){
        struct node<T> *p;
        struct node<T> *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;

        return tp;
    }


    struct node<T> * rrrotation(struct node<T> *n){
        struct node<T> *p;
        struct node<T> *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;

        return tp;
    }


    struct node<T> * rlrotation(struct node<T> *n){
        struct node<T> *p;
        struct node<T> *tp;
        struct node<T> *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp;

        return tp2;
    }

    struct node<T> * lrrotation(struct node<T> *n){
        struct node<T> *p;
        struct node<T> *tp;
        struct node<T> *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp;

        return tp2;
    }

    struct node<T>* insert(struct node<T> *r,T data){

        if(r==NULL){
            struct node<T> *n;
            n = new struct node<T>;
            n->data = data;
            r = n;
            r->left = r->right = NULL;
            r->height = 1;
            return r;
        }
        else{
            if(data < r->data)
                r->left = insert(r->left,data);
            else
                r->right = insert(r->right,data);
        }

        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }

        return r;

    }

    void levelorder_newline(){
        if (this->root == NULL){
            cout<<"\n"<<"Empty tree"<<"\n";
            return;
        }
        levelorder_newline(this->root);
    }

    void levelorder_newline(struct node<T> *v){
        queue <struct node<T> *> q;
        struct node<T> *cur;
        q.push(v);
        q.push(NULL);

        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur == NULL && q.size()!=0){
                cout<<"\n";

                q.push(NULL);
                continue;
            }
            if(cur!=NULL){
                cout<<" "<<cur->data.power;

                if (cur->left!=NULL){
                    q.push(cur->left);
                }
                if (cur->right!=NULL){
                    q.push(cur->right);
                }
            }


        }
    }

    struct node<T> * deleteNode(struct node<T> *p,T data){

        if(p->left == NULL && p->right == NULL){
            if(p==this->root)
                this->root = NULL;
            delete p;
            return NULL;
        }

        struct node<T> *t;
        struct node<T> *q;
        if(p->data < data){
            p->right = deleteNode(p->right,data);
        }
        else if(p->data > data){
            p->left = deleteNode(p->left,data);
        }
        else{
            if(p->left != NULL){
                q = inpre(p->left);
                p->data = q->data;
                p->left=deleteNode(p->left,q->data);
            }
            else{
                q = insuc(p->right);
                p->data = q->data;
                p->right = deleteNode(p->right,q->data);
            }
        }

        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }
        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }


        return p;
    }

    struct node<T>* inpre(struct node<T>* p){
        while(p->right!=NULL)
            p = p->right;
        return p;
    }

    struct node<T>* insuc(struct node<T>* p){
        while(p->left!=NULL)
            p = p->left;

        return p;
    }

    ~AVL(){

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





class Castle{
public:
    int index;
    string name;
    string owner;
    int capacity;
    queue<int> inputQueue;
//    AVL<Soldier> soldiers;
    vector<Soldier> soldiers;

    Castle(){

    }

    Castle(int _index, const string &name, const string &owner, int _capacity){
//        soldiers = new Soldier[capacity];
        index = _index;
        capacity = _capacity;
    }

    void setInfo(int _index, int _capacity){
        index = _index;
        capacity = _capacity;
    }

    void addSoldiers(int s[]){
        int len = sizeof(s)/sizeof(s[0]);
        for (int i = 0; i < len; ++i) {
             soldiers.push_back(Soldier(s[i] , index));
        }
    }
    void printSoldiers(){
        for (int i = 0; i < soldiers.size(); ++i) {
            cout<<soldiers[i];
        }
    }
};

class Army{
public:

    queue<Soldier> soldiers;
    int src ,dest , distance;
    int count;
    bool isArrived = false;
    Army(){

    }
    Army(int src, int dest, int distance,int count) : src(src), dest(dest), distance(distance) ,count(count) {

    }

    bool move(int speed){
        distance -= speed;
        return distance <= 0;
    }




};

class Game {
public:
    int** adjMatrix;
    int castleCount;
//    Castle* castles;
    vector<Castle> castles;
    int outputCapacity;
    int speed;
    vector<Army> armies;

    // Initialize the matrix to zero
    Game(int count , int _outputCapacity , int _speed) {
        this->castleCount = count;
        this->outputCapacity = _outputCapacity;
        this->speed = _speed;
        adjMatrix = new int*[count];
//        castles = new Castle[count];
        castles.resize(count);
        for (int i = 0; i < count; i++) {
            adjMatrix[i] = new int[count];
            for (int j = 0; j < count; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }


    vector<int> getTargets(int index){
        // Castle targetCastles[castleCount];
//        int targetCastlesIndex[castleCount];
        vector<int> targets;

        for (int i = 0; i < castleCount; i++) {
            if(adjMatrix[index][i] > 0){
                targets.push_back(i);
            }
        }
        return targets;
    }
    int getAttackTargetCapacitySum(vector<int> v){
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += castles[v[i]].soldiers.size();
        }
        return sum;
    }
    void attack(int castleIndex){
        vector<int> targets = getTargets(castleIndex);

        int sumOfTargetCapacities = getAttackTargetCapacitySum(targets);


        int sumSoldiersToAttack=0;
        for (int i = 0; i < targets.size(); ++i) {
                int countSoldiers = getSoldierCountForAttack(castleIndex ,targets[i] ,sumOfTargetCapacities );
                sumSoldiersToAttack += countSoldiers;
                Army a(castleIndex , targets[i] ,getDistance(castleIndex ,targets[i]) , countSoldiers);
                armies.push_back(a);
        }
        int output = (castles[castleIndex].soldiers.size() > outputCapacity) ? outputCapacity : castles[castleIndex].soldiers.size();
        int lowestArmyIndex = getArmyIndexBySrcDes(castleIndex , getLowestCapacityDesIndex(targets) ,targets.size());
        armies[lowestArmyIndex].count += (output - sumSoldiersToAttack);

    }
    int getArmyIndexBySrcDes(int src , int des , int lastAttackTargetsCount){
        for (int i = armies.size() - lastAttackTargetsCount; i < armies.size(); ++i) {
            if(armies[i].src == src && armies[i].dest == des){
                return i;
            }
        }
    }
    int getLowestCapacityDesIndex(vector<int> targets){
        int min = 100000;
        int minIndex;
        for (int i = 0; i < targets.size(); ++i) {
            if(castles[targets[i]].soldiers.size() <= min){
                min = castles[targets[i]].soldiers.size();
                minIndex = targets[i];
            }
        }
        return minIndex;
    }
    int getDistance(int srcCastleIndex ,int desCastleIndex){
        return adjMatrix[srcCastleIndex][desCastleIndex];
    }

    int getSoldierCountForAttack(int srcCastleIndex ,int desCastleIndex , int sumAllCastle){
        int output = (castles[srcCastleIndex].soldiers.size() > outputCapacity) ? outputCapacity : castles[srcCastleIndex].soldiers.size();

        float s = (float)sumAllCastle;
        return castles[desCastleIndex].soldiers.size() / s * output;
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


class Attack{
public:
    vector<int> targets;
    Game *game;
    void n(){

    }

    void setGame(Game *game) {
        Attack::game = game;
    }

};


int main() {




    // adj matrix :
    Game g(5 , 10 , 50);
    g.addEdge(0, 1,60);
    g.addEdge(1, 2,210);
    g.addEdge(1, 3,366);
    g.addEdge(1, 4,400);
    g.addEdge(2, 3,120);
    g.addEdge(3, 4,200);

    g.toString();

    //castle info :
    g.castles[0].setInfo(0 , 50);
    g.castles[1].setInfo(1 , 200);
    g.castles[2].setInfo(2 , 300);
    g.castles[3].setInfo(3 , 400);
    g.castles[4].setInfo(4 , 500);

//    int s[5] = {5,4,3,2,1};
//    g.castles[0].addSoldiers(s);
    for (int i = 0; i < 50; ++i) {
            g.castles[0].soldiers.push_back(Soldier(5 , 0));
        if(i >= 10)
            g.castles[1].soldiers.push_back(Soldier(6 , 0));
        if(i >= 20)
            g.castles[2].soldiers.push_back(Soldier(7 , 0));
        if(i >= 25)
            g.castles[3].soldiers.push_back(Soldier(8 , 0));
        if(i >= 30)
            g.castles[4].soldiers.push_back(Soldier(5 , 0));
    }
    int c = 0;
    while (true){

        for (int i = 0; i < g.castleCount; ++i) {
            g.attack(i);
        }
        for (int i = 0; i <g.armies.size(); ++i) {
            if(g.armies[i].move(g.speed) && !g.armies[i].isArrived){
                int targetDes = g.armies[i].dest;


                //TODO: add soldiers to input queue
                g.castles[targetDes].inputQueue.push(g.armies[i].count);
                g.armies[i].isArrived = true;

            }

        }

        c++;
        if(c == 10)
            break;
    }



//    g.toString();

}

