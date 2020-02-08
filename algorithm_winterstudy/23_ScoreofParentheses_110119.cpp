#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
class ScoreField{
private:
	string F;
	int Score;
public:
	ScoreField(){};
	ScoreField(string f){
		F = f;
	}

	void Calculate(){
		int slen = F.length();
		stack <int> s;
		int score = 0;
		int temp = 0;
		for (int i = 0; i<slen; i++){
			if (F[i] == '(') { s.push(i); if(temp!=0){score += temp; temp =0;} } //여는괄호
			else { //여는괄호 1.() 2.AB 3.(())
				if (i - s.top() == 1) { //1.()
					temp++; s.pop();
					if (s.empty()) {
						score += temp; temp = 0; continue;
					}
					else continue;
				}
				else{
					temp *= 2; s.pop(); 

					if (s.empty()){
						score +=temp; temp = 0; continue;
					}
					else{ score += temp; temp =0; continue; }
				}

			}
		}
		this->Score = score;

	}/*
	 int Calculate(string f){
		int slen = f.length();
		stack<int> s;
		int score = 0;
		int temp = 0;
		for (int i = 0; i<slen; i++){
	
			if (f[i] == '(') s.push(i); //여는괄호
			else { //여는괄호 1.() 2.AB 3.(())
			if (i - s.top() == 1) { //1.()
				 temp++; s.pop();
			if (s.empty()) {
				score += temp; temp = 0; continue;
			}
			else continue;
			}
	 else{
	 temp *= 2; s.pop();
	 if (s.empty()){
	 score += temp; temp = 0; continue;
	 }
	 else continue;
	 }

	 }
	 }
	 return score;

	 }*/
	 
	 void ShowScore(){
	 cout << Score;
	 }
};
int main(){
	string h;
	getline(cin, h, '\n');
	ScoreField Field_a(h); //생성자로 생성!
	Field_a.Calculate();
	Field_a.ShowScore();
	return 0;

}