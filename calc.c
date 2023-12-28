#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
    setlocale(LC_ALL, "RUS");
    int kolvo_upakovok; // ���������� ��������, ������ ��� �������� �����
    char vibor; // ����� ������������
    float ostatok, KRISHA_DLINA, KRISHA_SHIRINA, SHIFER_DLINA, SHIFER_SHIRINA,
        METCHEREPITSA_DLINA, METCHEREPITSA_SHIRINA, PLOSCHAD_KRISHI, PLOSCHAD_UPAKOVKI; // ����� � ������ �����, ������ ��� ��������������� (�������� �������������), ������� ����� � ��������� � ��������
    printf("������������, ��� ����������� ������� ��� ������� ���������� ������ ��� ��������������� ��� �������� ����� � ������\n�������� � �������");
    puts("\n�������� �������� ��������(��� ����� ������� ��������������� �����)"); // ������������ ����� ������ ����� ��� ������
    printf("1. �����\n2. ���������������\n");
    scanf("%c", &vibor);
    {
        {
            while (vibor != '1' & vibor != '2') { // ���� -����-, ��� ����, ����� ������ ��� ����� ������������ ������ �����, ���� ��� ����� ������������, �� ��� ������� ������
                scanf("%c", &vibor);
                switch (vibor) {
                case '1': puts("�� ������� �����"); break;
                case '2': puts("�� ������� ���������������"); break;
                default:  puts("�� ������� ������������ �����, ���������� ��� ���"); break;
                }

            }

        }

        printf("������� ����� ����� �����\n"); // ���� ����� �����
        scanf("%f", &KRISHA_DLINA);
        if (KRISHA_DLINA < 0) {
            printf("������������ ��������. ���������� ��� ���\n"); // ���� ������������ �������� (������ ����), �� ������������ ����� ������ ����� ������
            scanf("%f", &KRISHA_DLINA);
            printf("������� ������ ����� �����\n");
            scanf("%f", &KRISHA_SHIRINA);
        }
        else {

            printf("������� ������ ����� �����\n");
            scanf("%f", &KRISHA_SHIRINA);

        }

        if (KRISHA_SHIRINA < 0) { // ���� ������ �����

            printf("������������ ��������. ���������� ��� ���\n"); // ���� ������������ �������� (������ ����), �� ������������ ����� ������ ������ ������
            scanf("%f", &KRISHA_SHIRINA);
            PLOSCHAD_KRISHI = KRISHA_DLINA * KRISHA_SHIRINA; // ������ ������� �����
            printf("������� ����� ����� = %.2f �^2\n", PLOSCHAD_KRISHI);

        }

        else
            PLOSCHAD_KRISHI = KRISHA_DLINA * KRISHA_SHIRINA; // ������ ������� �����
        printf("������� ����� ����� = %.2f �^2\n", PLOSCHAD_KRISHI);
    }
    if (vibor == '1') { // ������ ������� ��������� � ����� ��������, � ����������� �� ���������� ���������

        printf("������� ����� ������ ��������� � ����� ��������\n");
        scanf("%f", &SHIFER_DLINA);

        if (SHIFER_DLINA < 0) {

            printf("������������ ��������. ���������� ��� ���\n");
            scanf("%f", &SHIFER_DLINA);
            printf("������� ������ ������ ��������� � ����� ��������\n");
            scanf("%f", &SHIFER_SHIRINA);

        }
        else {

            printf("������� ������ ������ ��������� � ����� ��������\n");
            scanf("%f", &SHIFER_SHIRINA);

        }

        if (SHIFER_SHIRINA < 0) {

            printf("������������ ��������. ���������� ��� ���\n");
            scanf("%f", &SHIFER_SHIRINA);
            PLOSCHAD_UPAKOVKI = SHIFER_DLINA * SHIFER_SHIRINA;
            printf("������� ������ � ����� �������� = %.2f �^2\n", PLOSCHAD_UPAKOVKI);

        }

        else {

            PLOSCHAD_UPAKOVKI = SHIFER_DLINA * SHIFER_SHIRINA;
            printf("������� ������ � ����� �������� = %.2f �^2\n", PLOSCHAD_UPAKOVKI);
        }
    }

    else if (vibor == '2') {

        printf("������� ����� ������ ��������� � ����� ��������\n");
        scanf("%f", &METCHEREPITSA_DLINA);

        if (METCHEREPITSA_DLINA < 0) {

            printf("������������ ��������. ���������� ��� ���\n");
            scanf("%f", &METCHEREPITSA_DLINA);
            printf("������� ������ ������ ��������� � ����� ��������\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);

        }

        else {

            printf("������� ������ ������ ��������� � ����� ��������\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);

        }

        if (METCHEREPITSA_SHIRINA < 0) {

            printf("������������ ��������. ���������� ��� ���\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);
            PLOSCHAD_UPAKOVKI = METCHEREPITSA_DLINA * METCHEREPITSA_SHIRINA;
            printf("������� �������������� � ����� �������� = %.2f �^2\n", PLOSCHAD_UPAKOVKI);

        }

        else {

            PLOSCHAD_UPAKOVKI = METCHEREPITSA_DLINA * METCHEREPITSA_SHIRINA;
            printf("������� �������������� � ����� �������� = %.2f �^2\n", PLOSCHAD_UPAKOVKI);
        }
    }

    // ������ ���-�� �������� 

    kolvo_upakovok = (PLOSCHAD_KRISHI / PLOSCHAD_UPAKOVKI);
    ostatok = (PLOSCHAD_KRISHI / PLOSCHAD_UPAKOVKI) - kolvo_upakovok;
    if (ostatok != 0)
        kolvo_upakovok = kolvo_upakovok + 1;
    printf("���������� �������� ����������� ��� ���� �����: %d", kolvo_upakovok);



}
