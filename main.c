#include <stdio.h>
#include "crud.h"

int main(){
    s s[100];
    int count = 0, num;
    count = loadData(s);
    if(count > 0)printf("=>파일 읽기 완료!\n\n");
    else printf("=>파일 없음!\n\n");

    while (1){
    menu();
    printf("원하는 메뉴는? : ");
    num = input();
    if (num == 0) break;
    else if (num == 1) count += Reservation(s,count);
    else if (num == 2){
      if(count>0)PrintList(s,count);
      else printf("예약자가 없습니다.\n");
    }
    else if (num == 3) Update(s,count);
  //   {
  //   int no = selectNo(s,count);
  //   Update(s,count);
  //   printf("=>수정됨!\n");
  //   if(no==0){
  //     printf("=> 예약자 명단에 없어 수정이 취소되었습니다!\n");
  //     continue;
  //   }
  //   else {
  //     Update(s,no);
  //     printf("=>수정됨!\n");
  //   }          
  // }
    else if (num== 4) Delete_r(s,count);
          //int no = selectNo(s,count);
    //  Delete_r(s,count);
        //     if(no==0){
        //     printf("=> 예약자 명단에 없어 삭제가 취소되었습니다!\n");
        //     continue;
        //       }
        //    else {
        //     Delete_r(s,no);
        //     printf("=>삭제됨!\n");
        //    }   
        
    else if(num == 5) SaveData(s, count);
    else if(num == 6) findroom(s, count);
    else if(num == 7) findtime(s, count);
    else break;
  }
  printf("종료됨!\n");
  return 0;
}
