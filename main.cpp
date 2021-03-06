#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <cmath>
#include <stack>
#define SIZE 1000
#define CHECK true
#if CHECK
#define STACK stack
#define QUEUE queue
#define VECTOR vector
#else
#define STACK Stack
#define QUEUE Queue
#define VECTOR vector
#endif
using namespace std;
template <typename T>
class Vector{
private:
    T* value;
    int isize = 0;
public:
    Vector(){

    }
    Vector(int maxSize) {
        isize = maxSize;
        value = (T*)malloc(maxSize * sizeof(T));
        for (int i = 0; i < maxSize; i++)
            value[i] = 0;
    }
    Vector(int maxSize, T data) {
        isize = maxSize;
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
    friend ostream &operator<<( ostream &output, const Vector<T> &vector ){
        for (int i = 0; i < vector.isize; i++)
            output << vector[i] << " ";
        output << "\n";
        return output;
    }
    void insert(int index, T val){
        isize++;
        value = (T*)realloc(value, (isize) * sizeof(T));
        int i = isize + 1;
        while(i != index){
            value[i] = value[i - 1];
            i--;
        }
        value[index] = val;
    }
    void push_front(T val) {
        isize++;
        value = (T*)realloc(value, (isize) * sizeof(T));
        int i = isize + 1;
        while(i != 0){
            value[i] = value[i - 1];
            i--;
        }
        value[0] = val;
    }
    void push_back(T val){
        value = (T*)realloc(value, (isize + 1) * sizeof(T));
        value[isize] = val;
        isize++;
    }
    void pop(){
        value[isize] = NULL;
        isize--;
        value = (T*)realloc(value, (isize) * sizeof(T));
    }
    void erase(int index){
        value[index] = NULL;
        while(index <= isize){
            value[index] = value[index + 1];
            index++;
        }
        isize--;
        value = (T*)realloc(value, (isize) * sizeof(T));
    }
    int find(T data){
        for (int i = 0; i < isize; i++)
            if (data == value[i])
                return i;
        return NULL;
    }
    int size(){
        return isize;
    }
    ~Vector() {
        free(value);
    }
};

template<class T>
class Queue
{
    T *arr;
    int capacity,ifront,rear,count;

public:
    Queue(int size = SIZE){
        arr = new T[size];
        capacity = size;
        ifront = 0;
        rear = -1;
        count = 0;
    }
    ~Queue(){
        delete[] arr;
    }

    void pop(){
        if (empty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        ifront = (ifront + 1) % capacity;
        count--;
    }
    void push(T item){
        if (full())
        {
            cout << "OverFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }
    T front(){
        if (empty())
        {
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[ifront];
    }
    int size(){
        return count;
    }
    bool empty(){
        return (size() == 0);
    }
    bool full(){
        return (size() == capacity);
    }
};

template<class T>
class Stack
{
    T *arr;
    int itop;
    int capacity;

public:
    Stack(int size = SIZE)
    {
        arr = new T[size];
        capacity = size;
        itop = -1;
    }
    ~Stack(){
        delete[] arr;
    }

    void push(T x)
    {
        if (full()){
            cout << "OverFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        arr[++itop] = x;
    }
    T pop() {
        if (empty()){
            cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[itop--];
    }
    T top() {
        if (!empty())
            return arr[itop];
        else
            exit(EXIT_FAILURE);
    }

    int size(){
        return itop + 1;
    }
    bool empty(){
        return itop == -1;    // or return size() == 0;
    }
    bool full(){
        return itop == capacity - 1;
    }
};

int getRandomInt(){
    return rand() % 1000000 + 1000000;
}
int getSumMultiDice(int count){
    int s = 0;
    for (int i = 0; i < count; ++i) {
        s += (rand() % 6 +1);
//        cout<<"dice"<<s;
    }
//    cout<<"\n";
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





class Castle{
public:
    char color;
    int d;
    int p;
    int index;
    int capacity;
    int conqueredBy = -1;
    QUEUE<Soldier> inputQueue;
    QUEUE<Soldier> enemyQueue;
//    AVL soldiersAVL;
    VECTOR<Soldier> soldiers;
    STACK<Soldier> deadStack;

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
    QUEUE<Soldier> topSoldier(int count){
        QUEUE<Soldier> tmp;
        for (int i = 0; i < count; ++i) {
            tmp.push(soldiers.back());
        }
        /*for (int i = 0; i < count; ++i) {
            soldiers.erase(soldiers.begin() + i);
        }*/
        return tmp;
    }
    void popSoldiers(int count){
        for (int i = 0; i < count; ++i) {
            soldiers.pop_back();
        }
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

    QUEUE<Soldier> soldiers;
    int src ,dest , distance;
    int count;
    bool isArrived = false;
    Army(){

    }
    Army(int src, int dest, int distance,int count,QUEUE<Soldier> attackers) : src(src), dest(dest), distance(distance) ,count(count) {
        soldiers = attackers;
    }

    bool move(int speed){
        if(!isArrived){
            distance -= speed;
            return distance <= 0;
        }
        return true;
    }




};

class Game {
private:
    void inputSoldiersToCastle(int castleIndex){

        cout<<"Input Soldiers Count For Castle "<<castleIndex<<": ";
        cin>>castles[castleIndex].capacity;
        cout<<"Enter Solders Power: ";
        for (int i = 0; i < castles[castleIndex].capacity; ++i) {
            int p;
            cin>>p;
            castles[castleIndex].soldiers.push_back(Soldier(p , castleIndex));
        }
    }
    VECTOR<int> getNeighbers(int castleIndex){
        VECTOR<int> neighbers;
        for (int i = 0; i < castleCount; i++) {
            if(adjMatrix[castleIndex][i] > 0){
                neighbers.push_back(i);
            }
        }
        return neighbers;
    }
    VECTOR<int> getTargets(int index){
        // Castle targetCastles[castleCount];
//        int targetCastlesIndex[castleCount];
        VECTOR<int> targets;

        for (int i = 0; i < castleCount; i++) {
            if(adjMatrix[index][i] > 0){
                if(castles[i].conqueredBy != index){
                    targets.push_back(i);
                }
            }
        }
        return targets;
    }
    int getAttackTargetCapacitySum(VECTOR<int> v){
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            sum += castles[v[i]].soldiers.size();
        }
        return sum;
    }

    int getArmyIndexBySrcDes(int src , int des , int lastAttackTargetsCount){
        for (int i = armies.size() - lastAttackTargetsCount; i < armies.size(); ++i) {
            if(armies[i].src == src && armies[i].dest == des){
                return i;
            }
        }
    }
    int getLowestCapacityDesIndex(VECTOR<int> targets){
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
//        cout<<srcCastleIndex<<"-"<<desCastleIndex<<"-"<<sumAllCastle<<"-"<<castles[desCastleIndex].soldiers.size() / s * output<<endl;
        return castles[desCastleIndex].soldiers.size() / s * output;
    }
    bool isEnemyWon(Soldier enemy , Soldier defencer){
        if(getSumMultiDice(enemy.power) > getSumMultiDice(defencer.power)){
            return true;
        }
        return false;
    }
    void setArmyArrived(int armyIndex ){
        int targetDes = armies[armyIndex].dest;
        while (!armies[armyIndex].soldiers.empty()) {
            castles[targetDes].inputQueue.push(armies[armyIndex].soldiers.front());
            armies[armyIndex].soldiers.pop();
        }
        armies[armyIndex].isArrived = true;
    }
public:
    int** adjMatrix;
    int castleCount;
//    Castle* castles;
    VECTOR<Castle> castles;
    int outputCapacity;
    int speed;
    float healSpeed;
    VECTOR<Army> armies;

    // Initialize the matrix to zero
    Game(int count , int _outputCapacity , int _speed , float _healSpeed) {
        this->castleCount = count;
        this->outputCapacity = _outputCapacity;
        this->speed = _speed;
        this->healSpeed = _healSpeed;
        adjMatrix = new int*[count];
//        castles = new Castle[count];
        castles.resize(count);
        for (int k = 0; k < count; ++k)
            castles[k].index = k;

        for (int i = 0; i < count; i++) {
            adjMatrix[i] = new int[count];
            for (int j = 0; j < count; j++){
                adjMatrix[i][j] = 0;
            }
        }
    }

    void BFS(){
        for (auto &v : castles) // access by reference to avoid copying
        {
            v.color = 'w';
            v.d = -1;
            v.p = -1;
        }
        castles[0].color = 'g';
        castles[0].d = 0;
        castles[0].p = -1;
        inputSoldiersToCastle(0);
        QUEUE<Castle> q;
        q.push(castles[0]);
        while (!q.empty()){
            Castle u = q.front();
            q.pop();
            for (auto &x : getNeighbers(u.index)) {
                if (castles[x].color == 'w'){
                    castles[x].color = 'g';
                    castles[x].d = u.d + 1;
                    castles[x].p = u.index;
                    inputSoldiersToCastle(x);
                    q.push(castles[x]);
                }
            }
            castles[u.index].color = 'b';

        }
    }

    void buildArmyToAttack(){
        VECTOR<int> popFromSoldersCount(castleCount , 0);
        for (int castleIndex = 0; castleIndex < castles.size(); ++castleIndex) {
            if(!castles[castleIndex].soldiers.empty()){
                VECTOR<int> targets = getTargets(castleIndex);

                int sumOfTargetCapacities = getAttackTargetCapacitySum(targets);


                int sumSoldiersToAttack=0;
                for (int i = 0; i < targets.size(); ++i) {
                    int countSoldiers = getSoldierCountForAttack(castleIndex ,targets[i] ,sumOfTargetCapacities );
                    if(countSoldiers > 0){
                        QUEUE<Soldier> qAttackers = castles[castleIndex].topSoldier(countSoldiers);
                        sumSoldiersToAttack += countSoldiers;
                        Army a(castleIndex , targets[i] ,getDistance(castleIndex ,targets[i]) , countSoldiers , qAttackers);
                        armies.push_back(a);
                    }
                }
                int output = (castles[castleIndex].soldiers.size() > outputCapacity) ? outputCapacity : castles[castleIndex].soldiers.size();
                int lowestArmyIndex = getArmyIndexBySrcDes(castleIndex , getLowestCapacityDesIndex(targets) ,targets.size());
                int remainCount = (output - sumSoldiersToAttack);
                armies[lowestArmyIndex].count += remainCount;

                QUEUE<Soldier> qRemainAttackers = castles[castleIndex].topSoldier(remainCount);
                while (!qRemainAttackers.empty()){
                    armies[lowestArmyIndex].soldiers.push(qRemainAttackers.front());
                    qRemainAttackers.pop();
                }
                popFromSoldersCount[castleIndex] = output;
            }

        }
        for (int castleIndex = 0; castleIndex < castles.size(); ++castleIndex) {
            castles[castleIndex].popSoldiers(popFromSoldersCount[castleIndex]);
        }
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
                int countCanCrossTheGate;
                if(castles[castleIndex].soldiers.size() == 0){
                    countCanCrossTheGate =  ceil(behindGateCount  / outputCapacity);
                }else{
                    countCanCrossTheGate =  ceil(behindGateCount / castles[castleIndex].soldiers.size());
                }

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
                if(!castles[castleIndex].soldiers.empty()){
                    Soldier defencer = castles[castleIndex].chooseSoldierToWar(attackerEnemy.power);
                    if(isEnemyWon(attackerEnemy , defencer)){
                        castles[castleIndex].enemyQueue.push(attackerEnemy);
                        castles[castleIndex].deadStack.push(defencer);
                    }else{
                        castles[castleIndex].soldiers.push_back(defencer);
                        castles[attackerEnemy.castleIndex].deadStack.push(attackerEnemy);
                    }
                }else{
                    castles[castleIndex].conqueredBy = attackerEnemy.castleIndex;
                }


                warCount--;
            }
        }
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
    void statusHandler(int timeLaps){
        cout<<"Status Handler TimeLaps #"<<timeLaps<<" :"<<endl;
        while (true){
            cout<<" Enter Castle Index To get Info Or (-1 -> next Next TimeLaps | -2 -> show All armies):";
            int cmd;
            cin>>cmd;
            if(cmd == -1)
                break;
            else if(cmd == -2){
                for (int i = 0; i < armies.size(); ++i) {
                    cout<<"Info of Army #"<<i<<" :"<<endl;
                    cout<<" Count:"<<armies[i].count<<" Src: "<<armies[i].src<<" Dest: "<<armies[i].dest<<" Distance: "<<armies[i].distance<<" isArrived: "<<armies[i].isArrived<<endl;
                }
            }else{
                cout<<"Castle Soldiers Count:"<<castles[cmd].soldiers.size()<<endl;
                cout<<"Castle inputQueue Size:"<<castles[cmd].inputQueue.size()<<endl;
                cout<<"Castle enemyQueue Size:"<<castles[cmd].enemyQueue.size()<<endl;
                cout<<"Castle deadStack Size:"<<castles[cmd].deadStack.size()<<endl;
                cout<<"Castle conqueredBy:"<<castles[cmd].conqueredBy<<endl;
            }
        }
    }
    void addEdge(int i, int j , int weight) {
        adjMatrix[i][j] = weight;
        adjMatrix[j][i] = weight;
    }

    void removeEdge(int i, int j) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }

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

    int outputCapacity , soldierSpeed ,castleCount;
    float healSpead;

    cout<<"Welcome To The Game ;) Lets Config The game:"<<endl;
    cout<<"outputCapacity:";
    cin>>outputCapacity;
    cout<<"solderSpeed:";
    cin>>soldierSpeed;
    cout<<"healSpeed:";
    cin>>healSpead;
    cout<<"castleCount:";
    cin>>castleCount;



    Game g(castleCount , outputCapacity , soldierSpeed , healSpead);

    cout<<"adjMatrix:"<<endl;
    for (int i = 0; i < castleCount; ++i) {
        for (int j = 0; j < castleCount; ++j) {
            int w;
            cin>>w;
            g.addEdge(i , j , w);
        }
    }
    g.BFS();
    // adj matrix :
//    Game g(5 , 10 , 50 , 0.5);
    /*g.addEdge(0, 1,60);
    g.addEdge(1, 2,210);
    g.addEdge(1, 3,366);
    g.addEdge(1, 4,400);
    g.addEdge(2, 3,120);
    g.addEdge(3, 4,200);*/

    g.toString();

    //castle info :
//    g.castles[0].setInfo(0 , 50);
//    g.castles[1].setInfo(1 , 200);
//    g.castles[2].setInfo(2 , 300);
//    g.castles[3].setInfo(3 , 400);
//    g.castles[4].setInfo(4 , 500);

//    int s[5] = {5,4,3,2,1};
//    g.castles[0].addSoldiers(s);
    /*for (int i = 0; i < 50; ++i) {
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

    }*/

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


        g.riseOfDeads();

        g.statusHandler(c);
        c++;
        if(c == 5)
            break;
    }



//    g.toString();

}

