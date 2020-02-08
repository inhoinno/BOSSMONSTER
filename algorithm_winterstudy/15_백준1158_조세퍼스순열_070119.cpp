#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
class DeadsList{
private:
	int member;
	int count;
public:
	DeadsList(){};
	DeadsList(int n, int m){
		member = n;
		count = m;
	};
	void DeadBodyList(){
		queue <int> q;
		for (int i = 0; i<member; i++){
			q.push(i + 1); // 1 2 3 4 5 6 7
		}
		while (!q.empty()){
			for (int i = 0; i<count - 1; i++){
				q.push(q.front());
				q.pop();
			}
			printf("%d ", q.front());
			q.pop();
		}
	};
};
int main(){
	int n;
	int m;
	scanf_s("%d", &n);//사람수 7
	scanf_s("%d", &m);//번째가 주금 3
	DeadsList table1 = DeadsList(n, m);
	table1.DeadBodyList();
	system("pause");
	return 0;
}