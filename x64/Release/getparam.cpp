//const char comment = ';';

/////////////////////////////////////////////////////////////////////////////
// filetostr
// ���������� ����� � ����������� � ������, ��������� �����������
//void filetostr(const char* fname, char* sp)
//{
  //  FILE* fp;
 //  if (!(fp = fopen(fname, "r"))) {
        printf("Can't open file %s", fname);
        exit(EXIT_FAILURE);
    }

  //  int c;

   // while ((c = getc(fp)) != EOF) { // �������������� ����� � ������
        if (c == comment || c == 0x0A) {
            *sp = c;		// ��������� ��� ����� ����� �����������
            continue;
        }
        if (*sp != comment)	// ���� �� ���������� ���� �����������,
            *sp++ = c; 	// �� ���������� ������ �� ����� � ������
    }
    *sp = '\0';		// ���������� '\0' � ����� ������

    fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////
// findpar
// ���������� � ������ �������� ��������� � �������� ������
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
// ���������� ���������� �� �����
void getpar(const char* fname, const char** parname,
    unsigned par_n, unsigned* parval)
{
    char inistr[2048];	// ��������� ������ ��� ����� � ���� ������

    filetostr(fname, inistr);

    while (par_n--)
    {
        // ����� �� ����� ��������� � ������������ ��������� ��������
        char* s = findpar(inistr, parname[par_n]);
        if (s)
            parval[par_n] = atoi(s);
        else {
            printf("\nCan't find parameter: %s", parname[par_n]);
            exit(EXIT_FAILURE);
        }
    }
}