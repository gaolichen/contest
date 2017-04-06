#include<stdio.h>
void main() {
	char b = '\"';
	char d = '\'';
	char e = '\\';
	char f = '\n';
	char* g = "\n\t";
	char* a = "#include<stdio.h>%cvoid main() {%schar b = %c%c%c%c;%schar d = %c%c%c%c;%schar e = %c%c%c%c;%schar f = %c%cn%c;%schar* g = %c%cn%ct%c;%schar* a = %c%s%c;%sprintf(a, f, g, d, e, b, d, g, d, e, d, d, g, d, e, e, d, g, d, e, d, g, b, e, e, b, g, b, a, b, g, f);%c}";
	printf(a, f, g, d, e, b, d, g, d, e, d, d, g, d, e, e, d, g, d, e, d, g, b, e, e, b, g, b, a, b, g, f);
}