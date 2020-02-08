
int main(){
		int scn;
		
		while (1){
			printf("이용할 계산 선택...\n\t 1. Sorting\n\t 2.Matrix Mulitplication ");
			scanf("%d", &scn);
			switch (scn){
			case 1:
				boot_Sorting();
				break;
			case 2:
				boot_Matrix_Multiplication();
				break;
			default:
				printf("Input data Error!, 비정상적인 입력... System terminate... "); return 0;
			}//switch
		}//while
	printf("프로그램 종료..\n");
	return 0;
}