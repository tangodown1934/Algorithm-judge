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
sudoku.txt
세부정보
활동
sudoku.txt
공유 정보
공유되지 않음
일반 정보
유형
텍스트
크기
2KB (1,846바이트)
위치
자소서
소유자
나
수정한 날짜
오후 8:37, 나
열어본 날짜
오후 8:40, 나
만든 날짜
오후 8:37
설명
설명 추가
다운로드 권한
보기 권한만 있는 사용자는 다운로드 금지
5GB 사용함(30%)
저장용량 추가 구입
닫힘 
sudoku.txt열기
//
//  sudoku.cpp
//  edu0720
//
//  Created by HeeJoong Kim on 2015. 7. 20..
//  Copyright (c) 2015년 HeeJoong Kim. All rights reserved.
//

#include <stdio.h>

bool is_end;

char field[11][11];

int x_arr[100];
int y_arr[100];
int size=0;

void print_fields(){
    for(int i=0; i<9; i++){
        printf("%s\n", field[i]);
    }
}

bool is_finish(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(field[i][j] == '0'){
                return false;
            }
        }
    }
    return true;
}

bool is_available(int x, int y, int num){
    
    //가로
    for(int i=0; i<9; i++){
        if(field[x][i] == '0' + num){
            return false;
        }
    }
    
    //세로
    for(int i=0; i<9; i++){
        if(field[i][y] == '0' + num){
            return false;
        }
    }
    
    int sx, sy;
    sx = x/3*3;
    sy = y/3*3;

    //3x3 부분 검사
    for(int i=sx; i<sx+3; i++){
        for(int j=sy; j<sy+3; j++){
            if(field[i][j] == '0' + num){
                return false;
            }
        }
    }
    return true;
}

void solve(int count){
    if(is_end){
        return;
    }
    
    if(count == size){
        is_end = true;
        print_fields();
        return;
    }
    
    for(int i=1; i<=9; i++){
        if(is_available(x_arr[count], y_arr[count], i)){
            field[x_arr[count]][y_arr[count]] = '0' + i;
            solve(count+1);
            field[x_arr[count]][y_arr[count]] = '0';
        }
    }
    
}

int main(void){
    
    for(int i=0; i<9; i++){
        scanf("%s", field[i]);
    }
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(field[i][j] == '0'){
                x_arr[size] = i;
                y_arr[size++] = j;
            }
        }
    }
    
    is_end = false;
    solve(0);
    
    return 0;
}