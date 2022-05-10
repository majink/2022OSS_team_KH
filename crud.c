#include <stdio.h>
#include <string.h>
#include "crud.h"

//메뉴 목록을 출력하기 위한 함수
void menu(){
    printf("~~~~~~ 상상랩 대여 ~~~~~~~\n");
    printf("1. 상상랩을 예약하고 싶어요 !\n");
    printf("2. 현재 예약 상황을 알고 싶어요 ! \n");
    printf("3. 예약을 수정하고 싶어요 !\n");
    printf("4. 예약을 취소하고 싶어요 !\n");
    printf("5. 예약 현황을 저장하고 싶어요 !\n");
    printf("6. 원하는 방의 예약 상황을 알고 싶어요 !\n"); 
    printf("0. 프로그램을 종료할게요 !\n\n");
}
//번호를 입력받기 위함 함수
int input(){
    int num;
    // printf("원하는 메뉴는? : ");
    scanf("%d", &num);
    return num;
}
//예약하기 위한 함수
int Reservation(s *s, int count){
    printf("이름을 입력해주세요! : ");
    scanf("%s", s[count]->name);
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
    printf("원하는 방의 번호를 입력해주세요!\n");
    printf("방 번호 : ");
    scanf("%d", &s[count]->room);
    printf("\n");
    return 1;
}
//예약 목록을 보여주는 함수
void PrintList(s *s, int count){
    printf("예약 상황을 보여줄게요 !\n");
    printf("----------------------------------\n");
    printf("번호  이름  사용시작  사용종료  방번호\n");
    for(int i=0;i<count;i++){
        if(s[i]->id != -1) printf("%d   %s   %d:%d   %d:%d   %d\n", i+1, 
        s[i]->name, s[i]->start[0], s[i]->start[1], s[i]->end[0], s[i]->end[1], s[i]->room);
        else continue;
    }
    printf("\n");
}
//예약 내용을 수정하는 함수
int Update(s *s, int count){
    int num;
    printf("수정하고자 하는 예약 번호를 입력해주세요 : ");
    num=input();
    getchar();
    printf("이름을 입력해주세요! : ");
    fgets(s[num-1]->name, 100, stdin);
    s[num-1]->name[strlen(s[num-1]->name) -1]= '\0';
    printf("학번을 입력해주세요! : ");
    scanf("%d", &s[num-1]->id);
    printf("사용 시작 시간을 입력해주세요!\n");
    printf("시(hour) : ");
    scanf("%d",&s[num-1]->start[0]);
    printf("분(min) : ");
    scanf("%d", &s[num-1]->start[1]);
    printf("언제까지 사용하고 싶은지 시간을 입력해주세요!\n");
    printf("시(hour) : ");
    scanf("%d", &s[num-1]->end[0]);
    printf("분(min) : ");
    scanf("%d", &s[num-1]->end[1]);
    printf("원하는 방의 번호를 입력해주세요!\n");
    printf("방 번호 : ");
    scanf("%d", &s[num-1]->room);
    printf("예약수정이 완료 되었습니다!\n\n");
    return 1;
}
//삭제, 수정할 예약 선택을 위한 함수
// int selectNo(s* s, int count){
// 	char search[100];
// 	int no;
//     int result;
// 	PrintList(s, count);
// 	getchar();
// 	printf("예약자 이름은?"); 
//     fgets(search, 100, stdin);
// 	for(int i=0 ; i<count ; i++){
// 	if(s[i]->id==-1) {
//         printf("삭제 완료!\n")
//     }
// 	else if(strstr(s[i]->name,search)){
//         result=i;
// 	return result;
// 	}
// 	}
// 	return 0;
// }

int Delete_r(s *s,int count){
    int num;
    printf("삭제하고자 하는 예약 번호를 입력해주세요 : ");
    num=input();
    if(num<=count) {
        printf("삭제 완료!\n");
        printf("\n");
        s[num-1]->id = -1;
    }
    else printf("해당 번호가 존재하지 않습니다.\n");
	return 1;
}

void SaveData(s *s, int count){
	FILE *fp;
	fp = fopen("reservation.txt", "w");
	for(int i=0; i<count ; i++){
	if(s[i]->id==-1)continue;
	else
	fprintf(fp, "%s %d %d %d %d %d %d\n",s[i]->name, s[i]->id, s[i]->start[0], s[i]->start[1], s[i]->end[0], s[i]->end[1], s[i]->room); 
			}
	fclose(fp);
	printf("=>저장됨!\n");
}

int loadData(s *s){
	int i=0;
	FILE *fp;
	fp = fopen("reservation.txt", "r");
	for(; i<100; i++){
	fscanf(fp, "%s", s[i]->name);
	if(feof(fp))break;
	fscanf(fp, "%d", &s[i]->id);
	fscanf(fp, "%d", &s[i]->start[0]);
    fscanf(fp, "%d", &s[i]->start[1]);
    fscanf(fp, "%d", &s[i]->end[0]);
    fscanf(fp, "%d", &s[i]->end[1]);
    fscanf(fp, "%d", &s[i]->room);
    }
    return 0;
}

int findroom(s *s, int count){
    //char find[10];
    int find;
    int c=0;
    printf("검색할 방 번호는 ? : ");
    scanf("%d",&find);
    printf("----------------------------------\n");
    printf("번호  이름  사용시작  사용종료  방번호\n");
    for(int i=0;i<count;i++){
        if(s[i]->id!=-1){
          if(find!=s[i]->room) continue;
          else {
            printf("%d  %s  %d:%d  %d:%d  %d\n", i+1, s[i]->name, s[i]->start[0], s[i]->start[1], s[i]->end[0], s[i]->end[1], s[i]->room);
            c++;
          }
        }
        else continue;
    }
    printf("\n총 %d개의 예약이 있습니다.\n\n\n",c);
    if(c==0) printf("=> 등록된 예약이 없음!\n\n");
    return 0;
}
