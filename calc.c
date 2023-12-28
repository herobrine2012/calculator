#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>


int main() {
    setlocale(LC_ALL, "RUS");
    int kolvo_upakovok; // количество упаковок, нужное для покрытия крыши
    char vibor; // выбор пользователя
    float ostatok, KRISHA_DLINA, KRISHA_SHIRINA, SHIFER_DLINA, SHIFER_SHIRINA,
        METCHEREPITSA_DLINA, METCHEREPITSA_SHIRINA, PLOSCHAD_KRISHI, PLOSCHAD_UPAKOVKI; // длина и ширина крыши, шифера или металлочерепицы (вводится пользователем), площадь крыши и материала в упаковке
    printf("Здравствуйте, это калькулятор расчёта для расчета количества шифера или металлочерепицы для покрытия крыши с учетом\nразмеров и проемов");
    puts("\nВыберите желаемый материал(для этого введите соответствующую цифру)"); // пользователю нужно ввести цифру для выбора
    printf("1. Шифер\n2. Металлочерепица\n");
    scanf("%c", &vibor);
    {
        {
            while (vibor != '1' & vibor != '2') { // цикл -пока-, для того, чтобы каждый раз когда пользователь вводит цифру, если эта цифра неправильная, он мог выбрать заново
                scanf("%c", &vibor);
                switch (vibor) {
                case '1': puts("Вы выбрали шифер"); break;
                case '2': puts("Вы выбрали металлочерепицу"); break;
                default:  puts("Вы выбрали неправильную цифру, попробуйте ещё раз"); break;
                }

            }

        }

        printf("Введите длину вашей крыши\n"); // ввод длины крыши
        scanf("%f", &KRISHA_DLINA);
        if (KRISHA_DLINA < 0) {
            printf("Неправильное значение. Попробуйте ещё раз\n"); // если неправильное значение (меньше нуля), то пользователь может ввести длину заново
            scanf("%f", &KRISHA_DLINA);
            printf("Введите ширину вашей крыши\n");
            scanf("%f", &KRISHA_SHIRINA);
        }
        else {

            printf("Введите ширину вашей крыши\n");
            scanf("%f", &KRISHA_SHIRINA);

        }

        if (KRISHA_SHIRINA < 0) { // ввод ширины крыши

            printf("Неправильное значение. Попробуйте ещё раз\n"); // если неправильное значение (меньше нуля), то пользователь может ввести ширину заново
            scanf("%f", &KRISHA_SHIRINA);
            PLOSCHAD_KRISHI = KRISHA_DLINA * KRISHA_SHIRINA; // расчёт площади крыши
            printf("Площадь вашей крыши = %.2f м^2\n", PLOSCHAD_KRISHI);

        }

        else
            PLOSCHAD_KRISHI = KRISHA_DLINA * KRISHA_SHIRINA; // расчёт площади крыши
        printf("Площадь вашей крыши = %.2f м^2\n", PLOSCHAD_KRISHI);
    }
    if (vibor == '1') { // расчёт площади материала в одной упаковке, в зависимости от выбранного материала

        printf("Введите длину вашего материала в одной упаковке\n");
        scanf("%f", &SHIFER_DLINA);

        if (SHIFER_DLINA < 0) {

            printf("Неправильное значение. Попробуйте ещё раз\n");
            scanf("%f", &SHIFER_DLINA);
            printf("Введите ширину вашего материала в одной упаковке\n");
            scanf("%f", &SHIFER_SHIRINA);

        }
        else {

            printf("Введите ширину вашего материала в одной упаковке\n");
            scanf("%f", &SHIFER_SHIRINA);

        }

        if (SHIFER_SHIRINA < 0) {

            printf("Неправильное значение. Попробуйте ещё раз\n");
            scanf("%f", &SHIFER_SHIRINA);
            PLOSCHAD_UPAKOVKI = SHIFER_DLINA * SHIFER_SHIRINA;
            printf("Площадь шифера в одной упаковке = %.2f м^2\n", PLOSCHAD_UPAKOVKI);

        }

        else {

            PLOSCHAD_UPAKOVKI = SHIFER_DLINA * SHIFER_SHIRINA;
            printf("Площадь шифера в одной упаковке = %.2f м^2\n", PLOSCHAD_UPAKOVKI);
        }
    }

    else if (vibor == '2') {

        printf("Введите длину вашего материала в одной упаковке\n");
        scanf("%f", &METCHEREPITSA_DLINA);

        if (METCHEREPITSA_DLINA < 0) {

            printf("Неправильное значение. Попробуйте ещё раз\n");
            scanf("%f", &METCHEREPITSA_DLINA);
            printf("Введите ширину вашего материала в одной упаковке\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);

        }

        else {

            printf("Введите ширину вашего материала в одной упаковке\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);

        }

        if (METCHEREPITSA_SHIRINA < 0) {

            printf("Неправильное значение. Попробуйте ещё раз\n");
            scanf("%f", &METCHEREPITSA_SHIRINA);
            PLOSCHAD_UPAKOVKI = METCHEREPITSA_DLINA * METCHEREPITSA_SHIRINA;
            printf("Площадь металочерепицы в одной упаковке = %.2f м^2\n", PLOSCHAD_UPAKOVKI);

        }

        else {

            PLOSCHAD_UPAKOVKI = METCHEREPITSA_DLINA * METCHEREPITSA_SHIRINA;
            printf("Площадь металочерепицы в одной упаковке = %.2f м^2\n", PLOSCHAD_UPAKOVKI);
        }
    }

    // расчёт кол-ва упаковок 

    kolvo_upakovok = (PLOSCHAD_KRISHI / PLOSCHAD_UPAKOVKI);
    ostatok = (PLOSCHAD_KRISHI / PLOSCHAD_UPAKOVKI) - kolvo_upakovok;
    if (ostatok != 0)
        kolvo_upakovok = kolvo_upakovok + 1;
    printf("Количество упаковок необходимое для всей крыши: %d", kolvo_upakovok);



}
