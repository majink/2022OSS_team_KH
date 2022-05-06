typedef struct{
char name[10];
int id;
int start[2];
int last[2];
int room;
} s[100];

void menu();

int Reservation(s *s, int count);
int PrintList(s *s, int count);
int Update(s *s, int count);
int Delete_r(s *s, int count);


int input();
