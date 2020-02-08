#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;
class SteelStickCutter{
public:
	SteelStickCutter(){};
	int CutCut(string a){
		int CuttedStick = 0;
		int n = a.size();
		stack<int> s;
		for (int i = 0; i < n; i++){
			if (a[i] == '('){//여는괄호
				s.push(i);
			}
			else{//a[i] == ) 닫는괄호
				if (i - s.top() == 1){//레이저임
					s.pop();
					CuttedStick += s.size(); //핵심코드인듯;
				}
				else {
					CuttedStick++;
					s.pop();
					//막대기 끝남
				}
			}
		}
		return CuttedStick;
	};
};
	int main(){
		string bowls;
		cin >> bowls;
		SteelStickCutter stick = SteelStickCutter();
		printf("%d", stick.CutCut(bowls));
		system("pause");
		return 0;
	}