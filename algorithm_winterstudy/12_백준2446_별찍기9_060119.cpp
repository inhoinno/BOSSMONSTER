#include <iostream>
#include <cstdio>
class star{
private:
	int n;
public:
	star(){}
	star(int N){
		n = N;
	}
	void DrawStar(){
		for (int i = 0; i< 2 * n - 1; i++){
			if (i<n){
				for (int j = 0; j < i; j++) printf(" ");
				for (int j = 0; j<2*n - 2*i-1; j++) printf("*");
			}
			else{
				for (int j = 0; j < 2 * n - i -2; j++)printf(" ");
				for (int j = 0; j <  2*(i-n)+3; j++) printf("*");
			 
			}

			puts("");

		}



	}
	/*void DrawStar(int N){
		this.star(N);
		for (int i = 0; i< 2 * n - 1; i++){
			if (i<n){
				for (int j = 0; j < i; j++) printf(" ");
				for (int j = 0; j<n - i; j++) printf("*");
			}
			else{

			}

			puts("");




		}



	}

	*/


};
int main(){
	int N;
	scanf("%d", &N);
	star K = star(N);

	K.DrawStar();

	system("pause");
	return 0;
}