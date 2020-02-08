
void Adv_Bubble_Sort(int *deck , int n){

    int i, j;
    for()

}

void Sort_Bubble(int * data, int size){
	int i, j, exch;
	for (i = size - 1; i>0; i--){
		exch = 0;
		for (j = 0; j<i; j++){
			if (data[j] > data[j + 1]){
				exch++;
				swap(&data[j], &data[j + 1]);
			}
		}
		if (exch == 0)
			break;
	}
	return;
}