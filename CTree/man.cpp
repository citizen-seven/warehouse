#include "Math.h"
#include "Tree.h"

int main()
{
    Math test;
    test.PutStr(test.GetEquation());
    test.PutStr(test.PrepareEquation());
    CNode* node = test.GetExp();
    node -> GoDump(1);

    delete node;
    return 0;
}

/*
+    1) мусор из папки(убрать объектные и исполняемые файлы ) 
+    2) CodeStile и настройки Subl 
+    3) Include
++    4) Сделать функцию GetEqv() и PrepereEqv(){удаляет пробелы и каидает exception, а так же возращает скопированную строку}
+    5) Exception
+    6) нестандартный конструктор CNode(c_type, char* data, CNode* left, CNode* right) CNode(double)
(+)    7) отследить пробел между двумя числами 
+   8) переделать 4
    9) ссылки
+   10) доделать функции
    */