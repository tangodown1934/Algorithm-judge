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

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for(int itr=0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr+1) << endl;
		int idx=0, arr[SIZE];
		cin >> n >> k;
		
		for(int i=0; i<n; i++) arr[i]=1;

		pattern(arr, idx, n);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void pattern(int *arr, int idx, int num) {

	if(idx == n) {
		if(num == k) {
			for(int i=0; i<n; i++)
				cout << arr[i];
			cout << endl;
		}
		return;
	}
	pattern(arr, idx+1, num);
	arr[idx]=0;
	pattern(arr, idx+1, num-1);
	arr[idx]=1;
}