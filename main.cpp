#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <cmath>
#include <stack>
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

    T pop() {
        if (top == -1) throw "Stack is already empty";
        T p = stack[top];
        stack[top--].~T();
        return p;
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
int getRandomInt(){
    return rand() % 1000000 + 1000000;
}
int getSumMultiDice(int count){
    int s = 0;
    for (int i = 0; i < count; ++i) {
        s += (rand() % 6 +1);
        cout<<"dice"<<s;
    }
    cout<<"\n";
    return s;
}

class Soldier{
public:
    int id;
    int power;
    int castleIndex;
    int status;//0 alive
    Soldier(){

    }

    Soldier(int _power, int _castleIndex)  {
        id = getRandomInt();
        power = _power;
        castleIndex = _castleIndex;
        status = 0;
    }
    bool operator<(const Soldier s){
        return power < s.power;
    }
    bool operator>=(const Soldier s){
        return power >= s.power;
    }
    friend ostream &operator<<( ostream &output, const Soldier &soldier ){
        output<<soldier.castleIndex<<"-"<<soldier.power<<endl;
        return output;
    }
};


/*
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
*//*
struct AvlNode
{
    Soldier data;
    AvlNode* left;
    AvlNode* right;
    int height;
};

class AVL
{
    friend class Castle;

    AvlNode* root;

    void makeEmpty(AvlNode* t)
    {
        if (t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    AvlNode* insert(Soldier x, AvlNode* t)
    {
        if (t == nullptr)
        {
            t = new AvlNode;
            t->data = x;
            t->height = 0;
            t->left = t->right = nullptr;
        }
        else if (x < t->data)
        {
            t->left = insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
            {
                if (x.power < t->left->data.power)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if (x.power >= t->data.power)
        {
            t->right = insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x.power > t->right->data.power)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }
        else if (x.power == t->data.power)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;
        return t;
    }

    AvlNode* singleRightRotate(AvlNode*& t)
    {
        if (t->left != nullptr) {
            AvlNode* u = t->left;
            t->left = u->right;
            u->right = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(u->left), t->height) + 1;
            return u;
        }
        return t;
    }
    AvlNode* singleLeftRotate(AvlNode*& t)
    {
        if (t->right != nullptr) {
            AvlNode* u = t->right;
            t->right = u->left;
            u->left = t;
            t->height = max(height(t->left), height(t->right)) + 1;
            u->height = max(height(t->right), t->height) + 1;
            return u;
        }
        return t;
    }

    AvlNode* doubleLeftRotate(AvlNode*& t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    AvlNode* doubleRightRotate(AvlNode*& t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    AvlNode* findMin(AvlNode* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    AvlNode* findMax(AvlNode* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    AvlNode* remove(Soldier x, AvlNode* t)
    {
        AvlNode* temp;

        if (t == nullptr)
            return nullptr;

        else if (x.power < t->data.power)
            t->left = remove(x, t->left);
        else if (x.power > t->data.power)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }
        if (t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right)) + 1;
        if (height(t->left) - height(t->right) == 2)
        {
            if (height(t->left->left) - height(t->left->right) == 1)
                return singleRightRotate(t);
            else
                return doubleRightRotate(t);
        }
        else if (height(t->right) - height(t->left) == 2)
        {
            if (height(t->right->right) - height(t->right->left) == 1) {
                return singleLeftRotate(t);
            }
            else
                return doubleLeftRotate(t);
        }
        return t;
    }

    int height(AvlNode* t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    int getBalance(AvlNode* t)
    {
        if (t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(AvlNode* t)
    {
        if (t == nullptr)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

public:
    AVL()
    {
        root = nullptr;
    }

    void insert(Soldier x)
    {
        root = insert(x, root);
    }

    void remove(Soldier x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    int root_height()
    {
        return root->height;
    }
};*/
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
    int capacity;
    int conqueredBy = -1;
    queue<Soldier> inputQueue;
    queue<Soldier> enemyQueue;
//    AVL soldiersAVL;
    vector<Soldier> soldiers;
    stack<Soldier> deadStack;

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
    queue<Soldier> topPopSoldier(int count){
        queue<Soldier> tmp;
        for (int i = 0; i < count; ++i) {
            tmp.push(soldiers[i]);
        }
        for (int i = 0; i < count; ++i) {
            soldiers.erase(soldiers.begin() + i);
        }
        return tmp;
    }
    Soldier chooseSoldierToWar(int enemyPower){
        int minPowerDifrence = 100000;
        int minIndexSolder;
        for (int i = 0; i < soldiers.size(); ++i) {
            if(abs(enemyPower - soldiers[i].power) < minPowerDifrence){
                minPowerDifrence = abs(enemyPower - soldiers[i].power);
                minIndexSolder = i;
            }
        }
        Soldier chosen = soldiers[minIndexSolder];
        soldiers.erase(soldiers.begin() + minIndexSolder);
        return chosen;
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
    Army(int src, int dest, int distance,int count,queue<Soldier> attackers) : src(src), dest(dest), distance(distance) ,count(count) {
        soldiers = attackers;
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
    float healSpeed;
    vector<Army> armies;

    // Initialize the matrix to zero
    Game(int count , int _outputCapacity , int _speed , float _healSpeed) {
        this->castleCount = count;
        this->outputCapacity = _outputCapacity;
        this->speed = _speed;
        this->healSpeed = _healSpeed;
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
    void buildArmyToAttack(){
        for (int castleIndex = 0; castleIndex < castles.size(); ++castleIndex) {
            if(!castles[castleIndex].soldiers.empty()){
                vector<int> targets = getTargets(castleIndex);

                int sumOfTargetCapacities = getAttackTargetCapacitySum(targets);


                int sumSoldiersToAttack=0;
                for (int i = 0; i < targets.size(); ++i) {
                    int countSoldiers = getSoldierCountForAttack(castleIndex ,targets[i] ,sumOfTargetCapacities );
                    if(countSoldiers > 0){
                        queue<Soldier> qAttackers = castles[castleIndex].topPopSoldier(countSoldiers);
                        sumSoldiersToAttack += countSoldiers;
                        Army a(castleIndex , targets[i] ,getDistance(castleIndex ,targets[i]) , countSoldiers , qAttackers);
                        armies.push_back(a);
                    }
                }
                int output = (castles[castleIndex].soldiers.size() > outputCapacity) ? outputCapacity : castles[castleIndex].soldiers.size();
                int lowestArmyIndex = getArmyIndexBySrcDes(castleIndex , getLowestCapacityDesIndex(targets) ,targets.size());
                int remainCount = (output - sumSoldiersToAttack);
                armies[lowestArmyIndex].count += remainCount;

                queue<Soldier> qRemainAttackers = castles[castleIndex].topPopSoldier(remainCount);
                while (!qRemainAttackers.empty()){
                    armies[lowestArmyIndex].soldiers.push(qRemainAttackers.front());
                    qRemainAttackers.pop();
                }
            }

        }
        /*for (int castleIndex = 0; castleIndex < castles.size(); ++castleIndex) {
            int output = (castles[castleIndex].soldiers.size() > outputCapacity) ? outputCapacity : castles[castleIndex].soldiers.size();
        }*/
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
        cout<<srcCastleIndex<<"-"<<desCastleIndex<<"-"<<sumAllCastle<<"-"<<castles[desCastleIndex].soldiers.size() / s * output<<endl;
        return castles[desCastleIndex].soldiers.size() / s * output;
    }
    void armyMovement(){
        for (int i = 0; i <armies.size(); ++i) {
            if(armies[i].move(speed) && !armies[i].isArrived){
                int targetDes = armies[i].dest;
                setArmyArrived(i);
            }
        }
    }
    void crossTheGate(){
        for (int castleIndex = 0; castleIndex < castles.size(); castleIndex++) {
            if(!castles[castleIndex].inputQueue.empty()){

                float behindGateCount = (float)castles[castleIndex].inputQueue.size();
                int countCanCrossTheGate =  ceil(behindGateCount / castles[castleIndex].soldiers.size());
//                cout<<"cross the gate "<<castleIndex<<":"<<countCanCrossTheGate<<endl;
                for (int i = 0; i < countCanCrossTheGate; ++i) {
                    castles[castleIndex].enemyQueue.push(castles[castleIndex].inputQueue.front());
                    castles[castleIndex].inputQueue.pop();
                }
            }

        }
    }


    void war(){
        for (int castleIndex = 0; castleIndex < castles.size(); castleIndex++) {
            int warCount = castles[castleIndex].enemyQueue.size();
            while(!castles[castleIndex].enemyQueue.empty() && warCount > 0){

                Soldier attackerEnemy = castles[castleIndex].enemyQueue.front();
                castles[castleIndex].enemyQueue.pop();
                Soldier defencer = castles[castleIndex].chooseSoldierToWar(attackerEnemy.power);
                if(isEnemyWon(attackerEnemy , defencer)){
                    castles[castleIndex].enemyQueue.push(attackerEnemy);
                    castles[castleIndex].deadStack.push(defencer);
                }else{
                    castles[castleIndex].soldiers.push_back(defencer);
                    castles[attackerEnemy.castleIndex].deadStack.push(attackerEnemy);
                }

                warCount--;
            }
        }
    }

    bool isEnemyWon(Soldier enemy , Soldier defencer){
        if(getSumMultiDice(enemy.power) > getSumMultiDice(defencer.power)){
            return true;
        }
        return false;
    }
    void riseOfDeads(){
        static float healProgress = 0;
        healProgress += healSpeed;
        if(healProgress >= 1){
            for (int castleIndex = 0; castleIndex < castles.size(); castleIndex++) {
                if(!castles[castleIndex].deadStack.empty() && castles[castleIndex].conqueredBy == -1){
                    for (int i = 0; i <healProgress; ++i) {
                        castles[castleIndex].soldiers.push_back(castles[castleIndex].deadStack.top());
                        castles[castleIndex].deadStack.pop();
                    }
                }
            }
            healProgress = 0;
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
    void setArmyArrived(int armyIndex ){
        int targetDes = armies[armyIndex].dest;
        while (!armies[armyIndex].soldiers.empty()) {
            castles[targetDes].inputQueue.push(armies[armyIndex].soldiers.front());
            armies[armyIndex].soldiers.pop();
        }
        armies[armyIndex].isArrived = true;
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
    srand (time(0));



    // adj matrix :
    Game g(5 , 10 , 50 , 0.5);
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
//            g.castles[0].soldiersAVL.insert(Soldier(getRandomInt() , 0));
        if(i >= 10)
            g.castles[1].soldiers.push_back(Soldier(6 , 1));
//            g.castles[1].soldiersAVL.insert(Soldier(6 , 1));
        if(i >= 20)
            g.castles[2].soldiers.push_back(Soldier(7 , 2));
//            g.castles[2].soldiersAVL.insert(Soldier(7 , 2));
        if(i >= 25){
            g.castles[3].soldiers.push_back(Soldier(8 , 3));
//            g.castles[3].soldiersAVL.insert(Soldier(8 , 3));
        }
        if(i >= 30){
            g.castles[4].soldiers.push_back(Soldier(5 , 4));
//            g.castles[4].soldiersAVL.insert(Soldier(5 , 4));
        }

    }

//    g.castles[0].soldiersAVL.display();
    int c = 0;
    while (true){

        /*for (int i = 0; i < g.castleCount; ++i) {
            g.attack(i);
        }*/
        g.buildArmyToAttack();
        /*for (int i = 0; i <g.armies.size(); ++i) {
            if(g.armies[i].move(g.speed) && !g.armies[i].isArrived){
                int targetDes = g.armies[i].dest;

                g.setArmyArrived(i);
            }

        }*/
        g.armyMovement();
        g.crossTheGate();

        g.war();

        //TODO: rise of deads
        g.riseOfDeads();
        c++;
        if(c == 3)
            break;
    }



//    g.toString();

}

