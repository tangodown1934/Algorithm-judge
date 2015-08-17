
#include <iostream>
using namespace std;
#define SIZE 12

void permutation(int idx, int cnt);
void combination(int idx, int cnt);

int n,r,p,q;
char arr[SIZE];
bool fixAlpha[SIZE];

int main()
{
	cin >> n >> r >> p >> q;

	for(int i=0; i<n; i++) {
		arr[i] = i+'A';
		if(i<r-1)
			fixAlpha[i]=false;
		else
			fixAlpha[i]=true;
	}

	permutation(0, 1);

	for(int i=0; i<n; i++) {
		if(i<r-1)
			fixAlpha[i]=false;
		else
			fixAlpha[i]=true;
	}

	combination(0, 1);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}

void permutation(int idx, int cnt) {

	if(idx == n) {
		idx=0;
		int lastIdx, mIdx=1, tmp=0;
		for(int i=n-1; i>=0; i--) {
			if(fixAlpha[i]) break;
			mIdx++;
		}
		for(lastIdx=n-1; lastIdx>=0; lastIdx--) {
			if(!fixAlpha[lastIdx]) {
				tmp++;
				fixAlpha[lastIdx]=true;
			}
			if(tmp == mIdx) break;
		}
		for(int i=1; i<=mIdx; i++) {
			fixAlpha[i+lastIdx]=false;
		}
		
	}

	if(cnt == p && fixAlpha[idx]) {
		for(int i=0; i<n; i++)
			if(!fixAlpha[i]) cout << arr[i];
		
		cout << arr[idx] << endl;
		return;
	}
 
	if(!fixAlpha[idx]) 
		permutation(idx+1, cnt);
	else
		permutation(idx+1, cnt+1);
}


void combination(int idx, int cnt) {
	if(idx == n) {
		int lastIdx, mIdx=1, tmp=0;
		for(int i=n-1; i>=0; i--) {
			if(fixAlpha[i]) break;
			mIdx++;
		}
		for(lastIdx=n-1; lastIdx>=0; lastIdx--) {
			if(!fixAlpha[lastIdx]) {
				tmp++;
				fixAlpha[lastIdx]=true;
			}
			if(tmp == mIdx) break;
		}
		for(int i=1; i<=mIdx; i++)
			fixAlpha[i+lastIdx]=false;

		idx = lastIdx+mIdx;
	}

	if(cnt == q && fixAlpha[idx]) {
		for(int i=0; i<n; i++)
			if(!fixAlpha[i]) cout << arr[i];
		
		cout << arr[idx] << endl;
		return;
	}
 
	if(!fixAlpha[idx]) 
		combination(idx+1, cnt);
	else
		combination(idx+1, cnt+1);
}
