#include "poly.h"
/*32152332 송인호 32152332@dankook.ac.kr*/
/*
1. 폴리노미
2. 20개 원형큐
3. 희소행렬
-1 정수값을 입력받아 희소행렬 크기를 결정
-2 주어진 행렬 내 원소의 약 10% 이하가 0이아닌값으로 임의의 수를 생성 , 대입
-3 계산결과의 비교
4. INFIX -> Postfix로 변환 시키는 프로그램을 설계하고 구현

4.
*/
/*
폴리노미
fx = 6.7 x ^ 4 + 3.2 x^3 - x^2 +x -2, 여기서 x 는 -100 ~ 100

-1  함수 fx의ㅏ 계산은 독립된 함수로 작성하고 계산 후에 그래프를 그리시오
-2 fx = 0를 만족하는 x를 구하는 방법을 기술하시오
-3 주어진 구간에서 fx가 최소값을 갖는 x를 구ㅏ는 방법을 기술하시오
-4 선형리스트를 이용한 fx를 구현하시오

*/
// struct List * Lf = myList();
// add(Lf, 6.7 , 4);
// add(Lf, 3.2 , 3);
// add(Lf, -1 , 2);
// add(Lf, 1 , 1);
// add(Lf, -2 , 0);
// showList(Lf);
// double d = cal(Lf);
// //fwrite d on file
/*
선형리스트를 이용한 fx 구현
구조체 x {
x^p , p = 차수
ax , a = 계수
}

선형리스트
struct term
* struct 주소 link

*/
//1 data를 구조체 : term으로 갖는 선형리스트 구현
//2 term 구조체 구현. 
// int * p = malloc(sizeof(int))
//head생성자
struct List * myList(){
	struct List * L = malloc(sizeof(struct List));
	L->head = NULL;
	L->count = 0;
	// 해석 : 맨첨 Term의 주소(head)를 가지는 리스트 L 
	//if()
	return L;
}
//노드 생성자
struct Term * make_node(double c, int degree){
	//c는 계수, degree는 차수
	struct Term * t = malloc(sizeof(struct Term));
	t->gge = c;
	t->cha = degree;
	t->next = NULL;
	//if()
	return t;
}
// gx 시 구현
/*
void add(struct List * List, int c, int d){ //add 함수  다항식의 차수 계산해서 덧셈
if(c == 0 ){ //계수가 0이면 에러에 해당한다
printf("0을 더하셨습니다.\n");
return;
}
///처음 들어온 차수 이면
///이미 있는 차수이면

}*/
//void addTerm_After(int index, 

//일반적으로 맨 뒤에 추가

void addTerm_Last(struct List * L, double c, int d){ //계수를 생각해서 다시 짜야함
	if (L->head == NULL){
		addTerm_First(L, c, d);
		return;
	}
	struct Term * tnode = malloc(sizeof(struct Term));
	tnode = L->head;
	while (tnode->next != NULL){
		tnode = tnode->next;
	}//tnode가 마지막 항을 가리킨다.
	struct Term * Newnode = make_node(c, d); //Newnode -> next = NULL
	tnode->next = Newnode;
	L->count += 1;
	return;
}
//맨 앞에 항 삽입 하는
void addTerm_First(struct List* List, double c, int d){
	//이미 List->head 가 NULL임을 알고 왔다!
	//그래도 하자
	struct Term * Newnode = make_node(c, d); //Newnode->next =NULL
	if (List->head != NULL){ //New node 가 Head 가 됨
		Newnode->next = List->head;
	}
	List->head = Newnode;
	List->count += 1;
	return;
}
void rmAll(struct List * L){   //리스트 전부 삭제 -> 일일이 노드에 가서 free해줄수가 없다. 선형 리스트의 한계
	//recursion
	struct Term * tnode = malloc(sizeof(struct Term));
	if (L->head != NULL) {//List is not Empty then
		tnode = L->head;
		rm(tnode);
	}
	L->head = NULL;
	L->count = 0;
	return;
}
void rm(struct Term * t){
	if (t->next != NULL){
		rm(t->next);
		free(t);
		return;
	}
	else if (t->next == NULL){
		free(t);
		return;
	}
}
//일반적으로 data의 인덱스를 삭제
//void rmTerm(){}
//마지막 노드 삭제
//void rmTerm_Last(){}

//리스트 탐색하면서 식 보여주기
void showList(struct List * L){
	struct Term * tL = L->head;
	if (!isEmpty(L)) {
		printf("List is Empty");
			return;
	} //리스트에 암것도 없는경우
	printf("리스트에 있는 항의 개수 : %d\n", L->count);
	while (1){
		if (tL->cha != 0) // 0이면 상수항임
			printf("%.3fx^%d + ", tL->gge, tL->cha);
		else if (tL->cha == 0)//상수항이라면
			printf("%.3f", tL->gge);
		if (tL->next != NULL)
			tL = tL->next;
		else break;
	}
	printf("\n");
	return;
}
int isEmpty(struct List * L){
	if (L->head == NULL){
		return 0; // 리스트가 비어있다면 false를 반환 응 비어있어
	}
	else if (L->head != NULL){
		//아니, 비어있진 않아
		return 1;
	}
}