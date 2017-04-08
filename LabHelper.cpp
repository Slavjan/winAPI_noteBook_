#include "LabHelper.h"

// инициализировать статические переменные нужно в .cpp файлах
// начинаем с id = 10000
int PairIdComponent::count = 10000;

char buf[BUFSIZE];
char buf2[BUFSIZE];
char filename[] = "notebook.txt";