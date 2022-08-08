const char comment = ';';

/////////////////////////////////////////////////////////////////////////////
// filetostr
// считывание файла с параметрами в строку, пропуская комментарии
void filetostr(const char* fname, char* sp)
{
    FILE* fp;
    if (!(fp = fopen(fname, "r"))) {
        printf("Can't open file %s", fname);
        exit(EXIT_FAILURE);
    }

    int c;

    while ((c = getc(fp)) != EOF) { // преобразование файла в строку
        if (c == comment || c == 0x0A) {
            *sp = c;		// установка или сброс флага комментария
            continue;
        }
        if (*sp != comment)	// если не установлен флаг комментария,
            *sp++ = c; 	// то копировать символ из файла в строку
    }
    *sp = '\0';		// добавление '\0' в конец строки

    fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////
// findpar
// нахождение в строке значения параметра с заданным именем
char* findpar(const char* str, const char* parname)
{
    char buf[128];
    char* name = strstr(str, strcat(strcpy(buf, parname), "="));
    if (name)
        return strchr(name, '=') + 1;
    else
        return NULL;
}
/////////////////////////////////////////////////////////////////////////////
// getpar
// считывание параметров из файла
void getpar(const char* fname, const char** parname,
    unsigned par_n, unsigned* parval)
{
    char inistr[2048];	// выделение памяти для файла в виде строки

    filetostr(fname, inistr);

    while (par_n--)
    {
        // поиск по имени параметра и присваивание параметру значения
        char* s = findpar(inistr, parname[par_n]);
        if (s)
            parval[par_n] = atoi(s);
        else {
            printf("\nCan't find parameter: %s", parname[par_n]);
            exit(EXIT_FAILURE);
        }
    }
}