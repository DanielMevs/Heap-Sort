//In this file we will try to implement insertion sort
#define SIZE_MAX 50001
#define RAND_MAX 32568
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &vect, int heapSize, int i);
void buildMaxHeap(vector<int> &vect);
void swap(vector<int> &vect, int i, int j);
void heap_sort(vector<int> &vect);
int parent(int i);
int left(int i);
int right(int i);

int parent(int i) {
	return(i - 1) / 2;
}
int left(int i) {
	return((2*i) + 1);
}
int right(int i) {
	return 2 * (i + 1);
}
void swap(vector<int> &vect, int i, int j)
{
	int temp = vect[j];
	vect[j] = vect[i];
	vect[i] = temp;
}

void buildMaxHeap(vector<int> &vect)
{
	int heapSize = vect.size();
	for (int i = ((heapSize / 2) - 1); i >= 0; i--)
	{
		maxHeapify(vect, heapSize, i);
	}
}
void heap_sort(vector<int> &vect)
{
	buildMaxHeap(vect);
	int heapSize = vect.size() - 1;
	while (heapSize >= 0) {
		swap(vect, 0, heapSize);
		
		
		
		maxHeapify(vect, heapSize, 0);
		heapSize = heapSize - 1;
	}
	
}
void maxHeapify(vector<int> &vect, int heapSize, int i)
{
	int leftChildIndex = left(i);
	int rightChildIndex = right(i);
	int indexOfLargest = i;
	if (leftChildIndex < heapSize && vect[leftChildIndex] > vect[i]) {
		indexOfLargest = leftChildIndex;
	}
	/*else {
		indexOfLargest = i;
	}*/
	if (rightChildIndex < heapSize && vect[rightChildIndex]> vect[indexOfLargest]) {
		indexOfLargest = rightChildIndex;
	}
	if (indexOfLargest != i) {
		swap(vect, i, indexOfLargest);
		maxHeapify(vect, heapSize, indexOfLargest);
	}
}

/*void bad_func(vector<int> vect)
{
vect.push_back(30);
}
void good_func(vector<int> &vect)
{
vect.push_back(30);
}*/



int main() {
	srand(time(NULL));
	vector<int> v = { 3,44,5,47,15,36,26,27,2,46 };
	/*for (int i : v) { //This print the entire contents of the vector
		cout << i << ', ';
	}*/
	cout << "Array before sorted: "; 
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout << "\nArray after sorted: ";
	heap_sort(v);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	

	return 0;
}

//cout << v.size() << endl;
//v.resize(9);
//cout << v.size() << endl;
/*for (int i : v) { //This print the entire contents of the vector
//cout << i << endl;
}*/

/*for (int i = 0; i<v.size(); i++) {
v[i] = rand() % RAND_MAX;
cout << v[i] << endl;
}*/

//alternate version
/*for (int i=0;i<v.size();i++){
cout << v[i]; << endl;
}*/
//insertion_sort(v);



/*bad_func(v);
for (int i : v) { //done to demonstrate that to change the value of the vector, you must pass by reference
cout << i << endl;

}
good_func(v);
for (int i : v) { //done to demonstrate that to change the value of the vector, you must pass by reference
cout << i << endl;

}*/
