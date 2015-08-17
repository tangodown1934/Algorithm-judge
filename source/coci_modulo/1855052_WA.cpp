#include <stdio.h>
#include <stdbool.h>

int len(int* mods){
	for(int i=0;i<11;i++) {
		if(mods[i]==0) {
			return i;
		}
	}
}

bool isExist(int* mods, int mod) {
	for(int i=0;i<10;i++) {
		if(mods[i]==mod) {
			return true;
		}
	}
	return false;
}

int main() {

	int arr[10];
	int mods[11];

	for(int i=0;i<11;i++) {
		mods[i]=0;
	}

	for(int i=0;i<10;i++) {
		scanf("%d",&arr[i]);
	}

	for(int i=0;i<10;i++) {
		int mod = arr[i]%42;

		if(isExist(mods,mod)){
			mods[len(mods)]=mod;
		}
	}

	printf("%d",len(mods));

	return 0;
}
