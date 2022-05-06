#include <stdio.h>
#include <string.h>
#include "crud.h"

void menu(){
    printf("~~~~~~ 상상랩 대여 ~~~~~~~\n");
    printf("1. 상상랩을 예약하고 싶어요 !\n");
    printf("2. 현재 예약 상황을 알고 싶어요 ! \n");
    printf("3. 예약을 수정하고 싶어요 !\n");
    printf("4. 예약을 취소하고 싶어요 !\n");
}

int input(){
    int num;
    printf("원하는 번호를 입력해주세요 : ");
    scanf("%d", &num);
    return num;
}

int Reservation(s *s, int count){
    getchar();
    printf("이름을 입력해주세요! : ");
    fgets(s[count]->name, 100, stdin);
    s[count]->name[strlen(s[count]->name) -1]= '\0';
    printf("학번을 입력해주세요! : ");
    scanf("%d", &s[count]->id);
    printf("사용 시작 시간을 입력해주세요!\n");
    printf("시(hour) : ");
    scanf("%d",&s[count]->start[0]);
    printf("분(min) : ");
    scanf("%d", &s[count]->start[1]);
    printf("언제까지 사용하고 싶은지 시간을 입력해주세요!\n");
    printf("시(hour) : ");
    scanf("%d", &s[count]->end[0]);
    printf("분(min) : ");
    scanf("%d", &s[count]->end[1]);
    return 1;
}

int PrintList(s *s, int count){
    printf("예약 상황을 보여줄게요 !\n");
}
