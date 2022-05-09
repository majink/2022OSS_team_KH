#include <stdio.h>
#include "crud.h"

int main(){
    s s[100];

    int count = 0, num;

    count = loadData(s);

    if(count >0)printf("=>파일 읽기 완료!\n");
    else printf("=>파일 없음!\n");

while (1){

        menu();
        num = input();
        int check=0;
        if (num == 0) break;
        else if (num == 1){
        count += Reservation(&s[count],count);
        }
        else if (num == 2){
            if(count>0)PrintList(s,count);
        }
        else if (num == 3){
          int no = selectNo(s,count);
            if(no==0){
            printf("=> 예약자 명단에 없어 수정이 취소되었습니다!\n");
            continue;
              }
           else {
            Update(s,no);
            printf("=>수정됨!\n");
           }          
        }
        else if (num== 4){
          int no = selectNo(s,count);
            if(no==0){
            printf("=> 예약자 명단에 없어 삭제가 취소되었습니다!\n");
            continue;
              }
           else {
            Delete_r(s,no);
            printf("=>삭제됨!\n");
           }   
        }
        else if(num == 5){

          SaveData(s, count);
        }
       else break;
    }
    printf("종료됨!\n");
    return 0;
}
