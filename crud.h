typedef struct{
char name[10];
int id;
int start[2];
int last[2];
int room;
} s[100];

void menu();//메뉴 출력

int Reservation(s *s, int count);//예약하는 함수
int PrintList(s *s, int count);//예약 리스트 출력 함수
int Update(s *s, int count);//수정하는 함수
int Delete_r(s *s, int count);//삭제한는 함수
void SaveData(s *s);//파일 저장 함수
int loadData(s *s);//파일 읽는 함수

int selectNo(s* s,int count);//수정 또는 삭제할 Data를 물어보는 함수
int input();/
