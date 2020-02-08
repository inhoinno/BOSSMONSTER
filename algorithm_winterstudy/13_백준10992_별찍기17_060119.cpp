#include <iostream>
#include <cstdio>
class Star{
private:
	int n;
public:
	Star(){}
	Star(int N){ n = N; }

	void DrawStar(){
		for (int i = 0; i<n - 1; i++){
			for (int j = 0; j<n - 1 - i; j++)printf(" ");
			printf("*");
			for (int j = 0; j<2 * i - 1; j++)printf(" ");
			if (i != 0)printf("*");
			puts("");
		}
		for (int i = 0; i<2 * n - 1; i++) printf("*");
	}
};
int main(){

	int N;
	scanf("%d", &N);
	Star K = Star(N);

	K.DrawStar();
	system("pause");
	return 0;
}