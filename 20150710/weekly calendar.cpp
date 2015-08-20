#include <stdio.h>
#include <string.h>

int main(){
	int nCount;
	int i, j, k, month, day, day_count;
	int limit;
	char dateArr[][22] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	char dateCh[22];

	scanf("%d", &nCount);
	for (i = 0; i < nCount; i++){
		scanf("%d %d %s", &month, &day, dateCh);

		if (month == 2){
			limit = 28;
		}else if (month < 8){
			if (month % 2 == 0)
				limit = 30;
			else
				limit = 31;
		}else{
			if (month % 2 == 0)
				limit = 31;
			else
				limit = 30;
		}

		day_count = 0;
		for (j = 0; j < 7; j++){
			if (strcmp(dateCh, dateArr[j]) == 0){
				day_count = j;
			}
		}
		if (day - day_count < 1){
			if (month == 3){
				limit = 28;
			}
			else if (month == 1){
				limit = 31;
			}
			else if (month == 8){
				limit = 31;
			}
			else if (month < 8){
				if (month % 2 == 0)
					limit = 31;
				else
					limit = 30;
			}else{
				if (month % 2 == 0)
					limit= 30;
				else
					limit= 31;
			}
			day = limit - (day_count - day);
		} else{
			day -= day_count;
		}
		
		for (j = 0; j < 7; j++){
			if (day > limit)
				day = 1;

			printf("%d ", day++);
		}
		printf("\n");
	}
	return 0;
}