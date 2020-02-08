#include <iostream>
using namespace std;
class Node {
    friend class List;
    private:
    int value;
    Node *next;
    Node (int v, Node *n) : value(v), next(n) {}

};
class List {
    private:
    Node *head, *tail;  //각각 루트, 리프 노드
    int size; //노드의 갯수
    public:
    List(int);
    void pushBack(int); // 리스트 꼬리에 데이터 추가(insert)
    void popFront();  //리스트 맨 처음 노드를 제거
    void insert(int); //리스트의 중간에 노드를 삽입
    //리스트중 value보다 대소를 판단해서 특정 위치에 집어 넣음
}