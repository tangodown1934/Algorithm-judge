/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
#define SIZE 30

int n,k;
void pattern(int *arr, int idx, int num);
int main()
{

	int idx=0, arr[SIZE];
	cin >> n >> k;

	for(int i=0; i<n; i++) arr[i]=0;

	pattern(arr, 0, 0);

	return 0;

}

void pattern(int *arr, int idx, int num) {
	if(num>k) return;

	if(idx == n) {
		if(num == k) {
			for(int i=0; i<n; i++)
				cout << arr[i];
			cout << endl;
		}
		return;
	}

	arr[idx]=1;
	pattern(arr, idx+1, num);
	arr[idx]=0;	
	pattern(arr, idx+1, num+1);

}