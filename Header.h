#ifndef Header_h
#define Header_h

struct Student
{
    char* name; //»м€
    int number; // номер зачетки
    float srMark; //—редн€€ оценка за сессию
    int scholarship; // это стипенди€: 0 - нет стипухи, 1 - обычна€, 2 - 50%, 3 - 100%
    int year;
};

float test(int mod);
char* inputName();
int newinfo(int leng, Student** temp);
void addSt(Student**& arr, int& leng);
void swaper(Student**& arr, int i, int j);
void sort(Student**& arr, int leng);
char* readName(FILE* file);
void readFl(FILE* file, Student**& readarr, int& lengadd);
void printFl(FILE* file1, Student** arr, int leng);
void out(Student** arr, int leng);
void deletSt(Student**& arr, int& leng);
#endif