#include <stdio.h>
//순열과 조합
//20150717


int n, r, p, q, cnt;
char tmp[13] = { 0 };

void func(int selNum){
	if (cnt == p) return;
	if (selNum == r){
		cnt++;
		if (cnt == p){
			//printf("res\t : %s!\n", tmp);
			printf("%s\n", tmp);
		}
		//else{
		//	printf("%d\t : %s\n", cnt, tmp);
		//}
		
		//strcpy(abc[cnt++], tmp);
		return;
	}
	int alph = 'A', ok = 1;
	while (1){
		if ( (alph - 'A') == n) break;
		for (int i = 0; i < selNum; i++)
		{
			if (alph == tmp[i]){
				ok = 0;
				break;
			}
		}
		if (ok == 1){
			tmp[selNum] = alph;
			//printf("%c", alph);
			func(selNum + 1);
		}
		ok = 1;
		alph++;
	}
}


void func2(int selNum, int alph){
	if (cnt == q) return;
	if (selNum == r){
		cnt++;
		if (cnt == q){
			//printf("res\t : %s!\n", tmp);
			printf("%s\n", tmp);
		}
		//else{
		//	printf("%d\t : %s\n", cnt, tmp);
		//}

		//strcpy(abc2[cnt++], tmp);
		return;
	}
	while (1){
		if (alph == n) break;
		tmp[selNum] = 'A' + alph;
		//printf("%c", alph);
		func2(selNum + 1,alph + 1);
		alph++;
	}
}


int main(){

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	//for (itr = 0; itr<nCount; itr++)
	//{

		cnt = 0;
	//	printf("#testcase%d\n", itr + 1);

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);

		func(0);
		//printf("-----\n");
		cnt = 0;
		func2(0,0);
	//}


	return 0;
}