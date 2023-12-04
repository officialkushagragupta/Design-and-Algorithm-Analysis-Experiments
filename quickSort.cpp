/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int cnt = 0;
	int pivot = input[start];
	for(int i=start+1;i<=end;i++){
		if(pivot > input[i]){
			cnt++;
		}
	}

	int pivotIndex=start + cnt;
	swap(input[start],input[pivotIndex]);
	int i=start,j=end;
	while(i<pivotIndex && j>pivotIndex){
		while(input[i]<input[pivotIndex]){
			i++;
		}
		while(input[j]>input[pivotIndex]){
			j--;
		}
		if(input[i]>input[pivotIndex] && input[j]<input[pivotIndex]){
			swap(input[i++],input[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int input[], int start, int end) {
	//Base Case
	if(start>=end){
		return;
	}

	int pivotIndex = partitionArray( input, start, end);

	quickSort(input, start, pivotIndex-1);
	quickSort(input, pivotIndex+1, end);
}