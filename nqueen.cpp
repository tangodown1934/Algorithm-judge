HeeJoong-Dominic



드라이브
.
폴더 경로
내 드라이브
자소서
새로 만들기 
폴더 및 보기
내 드라이브
공유 문서함
Google 포토
최근
중요
휴지통
.

Word
2010920023_김희중_과학에세이_수정.hwp

PDF
2010920023_김희중_과학에세이_수정.pdf

Word
2010920023_김희중_과학에세이.hwp

PDF
2010920023_김희중_과학에세이.pdf

C++
clocksync.cpp

텍스트
clocksync.txt

C++
color.cpp

텍스트
color.txt

C++
door.cpp

텍스트
door.txt

C++
narrow_path.cpp

텍스트
narrow_path.txt

C++
nqueen.cpp

텍스트
nqueen.txt

C++
scales.cpp

텍스트
scales.txt

Google 문서
sk 자소서

C++
sudoku.cpp

텍스트
sudoku.txt
텍스트
nqueen.txt
세부정보
활동
nqueen.txt
공유 정보
공유되지 않음
일반 정보
유형
텍스트
크기
2KB (1,601바이트)
위치
자소서
소유자
나
수정한 날짜
오후 8:37, 나
만든 날짜
오후 8:37
설명
설명 추가
다운로드 권한
보기 권한만 있는 사용자는 다운로드 금지
5GB 사용함(30%)
저장용량 추가 구입
닫힘 
nqueen.txt열기
/*
 
 VC, GCC에서 사용
 
 */

#include <stdio.h>

/*
    nqueen
 */

#define ABS(a) (a) > 0 ? (a) : -(a)

int N;
int ans;

int field[15][15];

bool is_available(int x, int y){
    //가로 검사
    for(int i=0; i<N; i++){
        if(field[x][i] == 1){
            return false;
        }
    }
    
    //세로 검사
    for(int i=0; i<N; i++){
        if(field[i][y] == 1){
            return false;
        }
    }
    
    //대각선 검사
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if((ABS(x-i)) == (ABS(y-j)) && field[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

void solve(int count){
    
    if(count == N){
        ans += 1;
        return;
    }
    
    for(int i=0; i<N; i++){
        if(is_available(count, i)){
            field[count][i] = 1;
            solve(count + 1);
            field[count][i] = 0;
        }
    }
}

int main()
{
    
    int itr;
    int nCount;		/* 문제의 테스트 케이스 */
    
    scanf("%d", &nCount);	/* 테스트 케이스 입력 */
    
    for(itr=0; itr<nCount; itr++)
    {
        
        printf("#testcase%d\n",itr+1);
        
        scanf("%d", &N);
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                field[i][j] = 0;
            }
        }
        ans = 0;
        solve(0);
        
        printf("%d\n", ans);
        
        /*
         
         알고리즘이 들어가는 부분
         
         */
        
    }
    
    return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
    
}