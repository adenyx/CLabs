#include <stdio.h>
#include <string.h>

//Ввести с клавиатуры строку символов.
//Программа должна определить длину введенной строки,
//и если длина четная, то удаляются 2 первых и 2 последних символа.
int first() {
    char userString[100];
    int length;

    printf("Input the line here: ");
    scanf("%s", userString);
    length = strlen(userString);
    if (length % 2 > 0) {
        userString[0] = (char) "\0";
        userString[1] = (char) "\0";
        userString[length-1] = (char) "\0";
        userString[length] = (char) "\0";
        for (int i = 0; i < length; i++) {
            if ((char *) userString[i] != "\0") {
                printf("%c", userString[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choose;
    printf("1 / 2: ");
    scanf("%d\n", &choose);
    /*if (choose == 1) {
        first();
    } else {
        printf("Input Error!");
    }*/
    first();
    return 0;
}
