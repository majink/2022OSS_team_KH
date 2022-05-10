typedef struct{
char name[10];
int id;
int start[2];
int end[2];
int room;
} s[100];

void menu();//메뉴 출력

int Reservation(s *s, int count);//예약하는 함수
void PrintList(s *s, int count);//예약 리스트 출력 함수
int Update(s *s, int count);//수정하는 함수
int Delete_r(s *s, int count);//삭제하는 함수
void SaveData(s *s, int count);//파일 저장 함수
int loadData(s *s);//파일 읽는 함수
int selectNo(s* s,int count);//수정 또는 삭제할 Data를 물어보는 함수
int input();//입력한 메뉴 번호를 받는 함수
int findroom(s *s, int count);//방번호를 입력받아서 예약 여부 목록을 보여주는 함수

