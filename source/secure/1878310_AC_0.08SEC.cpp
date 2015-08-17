#include <stdio.h>
//SECURE

#define VOWEL_NUM 5

//모음
char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };
//아스키코드의 영어 소문자의 배열
char small_char[300] = { 0 };
char password[30] = { 0 };
char cPosible[30] = { 0 };
int L, C;

void func(int index, int nVowel, int nConsonant, int cntAlpha){
	if (index == L){
		if (nVowel >= 1 && nConsonant >= 2){
			for (int i = 0; i < L; i++)
			{
				printf("%c", password[i]);
			}
			printf("\n");
		}
		return;
	}
	int ok = 0;
	while (cntAlpha < C){
		if (vowel[0] == cPosible[cntAlpha] ||
			vowel[1] == cPosible[cntAlpha] ||
			vowel[2] == cPosible[cntAlpha] ||
			vowel[3] == cPosible[cntAlpha] ||
			vowel[4] == cPosible[cntAlpha]){
			password[index] = cPosible[cntAlpha];
			func(index + 1, nVowel + 1, nConsonant, cntAlpha + 1);
		}
		else{
			password[index] = cPosible[cntAlpha];
			func(index + 1, nVowel, nConsonant + 1, cntAlpha + 1);
		}
		cntAlpha++;
	}
}


int main(){

	char tmp_char = 0;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
	{
		scanf(" %c", &tmp_char);
		small_char[tmp_char] = 1;
	}
	for (int i = 'a',k = 0; i <= 'z'; i++)
	{
		if (small_char[i] == 1){
			cPosible[k++] = i;
		}
	}
	func(0, 0, 0, 0);
	return 0;
}