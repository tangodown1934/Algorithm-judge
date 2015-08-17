
#include <stdio.h>
#include <string.h>
//CCC_CHANCES
//ÁÁ¾ÆÇÏ´Â ÆÀÀÇ ¿ì½ÂÇÒ È®·ü

int T, G;
int TEAM[5][5] = { 0 };
int vis[5][5] = { 0 };

#define MAX_GAME 6

int func(int game, int A,int B){
	if (game == MAX_GAME){
		int sum = 0;

		//printf("MY TEAM\n");
		for (int i = 1; i <= 4; i++)
		{
			//printf("%d ", TEAM[T][i]);
			sum += TEAM[T][i];
		}
		//printf(": %d", sum);
		//printf("\n");


		//printf("==========\n");
		//printf("ENERMY\n");
		for (int i = 1; i <= 4; i++)
		{
			if (i == T)	continue;
			int enermySum = 0;
			for (int j = 1; j <= 4; j++)
			{
				//printf("%d ", TEAM[i][j]);
				enermySum += TEAM[i][j];
			}
			//printf(": %d", enermySum);
			//printf("\n");
			if ( enermySum >= sum)	return 0;
		}
		//printf("==========\n");
		return 1;
	}
	if (B > 4) return 0;
	int cnt = 0;
	if (vis[A][B] == 0 && A != B){
		TEAM[A][B] = 3;
		TEAM[B][A] = 0;
		if (B == 4)	cnt += func(game + 1, A + 1, A + 2);
		else        cnt += func(game + 1, A, B + 1);
		TEAM[A][B] = 0;
		TEAM[B][A] = 3;
		if (B == 4)	cnt += func(game + 1, A + 1, A + 2);
		else        cnt += func(game + 1, A, B + 1);
		TEAM[A][B] = 1;
		TEAM[B][A] = 1;
		if (B == 4)	cnt += func(game + 1, A + 1, A + 2);
		else        cnt += func(game + 1, A, B + 1);
	}
	else{
		if (B == 4)	cnt += func(game, A + 1, A + 2);
		else        cnt += func(game, A, B + 1);
	}

	return cnt;
}


int main(){
	memset(TEAM, -1, sizeof(TEAM));
	scanf("%d %d", &T, &G);
	for (int i = 0; i < G; i++)
	{
		int a, b, scoreA, scoreB;
		scanf("%d %d", &a, &b);
		scanf("%d %d", &scoreA, &scoreB);
		if (scoreA > scoreB){
			TEAM[a][b] = 3;
			TEAM[b][a] = 0;
			vis[a][b] = vis[b][a] = 1;
		}
		else if (scoreA == scoreB){
			TEAM[a][b] = 1;
			TEAM[b][a] = 1;
			vis[a][b] = vis[b][a] = 1;
		}
		else{
			TEAM[a][b] = 0;
			TEAM[b][a] = 3;
			vis[a][b] = vis[b][a] = 1;
		}
	}
	printf("%d\n",func(G, 1, 2));
	

	return 0;
}