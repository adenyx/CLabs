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
    printf("Length = %d \n", length);
    if (length % 2 == 0) {
        userString[0] = (char) "0";
        userString[1] = (char) "0";
        userString[length-1] = (char) "0";
        userString[length] = (char) "0";
        for (int i = 2; i < length - 2; i++) {
            printf("%c", userString[i]);
        }
        printf("\n");
    }
    return 0;
}

//В тексте поменять слова местами (первое с последним, второе с предпоследним и тд)
//Слова имеют разную длину
//hello world mother fuckers
int second() {
    //TODO
    // - FINISH THE LAB
    char string[100];
    printf("Input the line here (2): ");
    scanf(" %s", string);
    printf("%s \n", string);

    int length = strlen(string);
    printf("%d \n", length);
    int numberOfWords = 1;
    for (int i = 0; i < length; i++) {
        if (string[i] == "_") {
            numberOfWords++;
        }
    }
    printf("%d", numberOfWords);

    int isCycleContinue;
    char words[numberOfWords][100];
    int k = 0;
    for (int i = 0; i < numberOfWords; i++) {
        int j = 0;
        isCycleContinue = 1;
        do {
            words[i][j] = string[k];
            k++;
            j++;
            if (string[k + 1] == "_") {
                isCycleContinue = 0;
                k++;
            }
        } while (isCycleContinue == 1);
        k++;
    }

    char variable;
    for (int i = 0; i < numberOfWords / 2; ++i) {
        for (int j = 0; j < length; ++j) {
            variable = words[i][j];
            words[i][j] = words[numberOfWords - i][j];
            words[numberOfWords - i][j] = variable;
        }
    }

    for (int i = 0; i < numberOfWords; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c", words[i][j]);
        }
        printf(" ");
    }

    /*int lengthOfWords[numberOfWords];
    int isSpaceDetected = 0;
    int i = 0, j = 0;
    do {
        if (isSpaceDetected == 0) {
            firstWord[i] = string[i];
            string[i] = "#";
            lengthOfWords[0] = i;
        } else if (isSpaceDetected == 1) {
            secondWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[1] = j;
        } else if (isSpaceDetected == 2) {
            thirdWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[2] = j;
        } else if (isSpaceDetected == 3) {
            fourthWord[j] = string[i];
            string[i] = "#";
            lengthOfWords[3] = j;
        } else if (isSpaceDetected == 4) {
            //something
        }
        if (string[i+1] == "_") {
            string[i+1] = "#";
            i++;
            isSpaceDetected++;
            j = 0;
        }
        i++;
    } while (string[i+1] != "\0");
    for (int i = 0; i < numberOfWords; i++) {
        for (int j = 0; j < lengthOfWords[i]; j++) {
            if (i = 0) {
                printf("%c", firstWord[j]);
            }
        }
        printf(" ");
    }*/
    return 0;
}

//Проверить, является ли слово палиндромом
int third() {
    char string[100], secondString[100];
    printf("Input line here: ");
    scanf(" %s", string);
    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        secondString[i] = string[length - 1 - i];
    }
    if (strcmp(string, secondString) == 0) {
        printf("Слово палиндром: ");
        printf("%s", string);
    } else {
        printf("Слово не палиндом :C");
    }
}

//Ввести строку и если длина кратна 4, то поменять местами первую часть строки и вторую
int fourth() {
    char string[100];
    char firstPart[50], secondPart[50];
    printf("Input line here: ");
    scanf(" %s", string);
    int length = strlen(string);

    if (length % 4 == 0) {
        int j = 0;
        for (int i = 0; i < length / 2; i++) {
            firstPart[i] = string[i];
        }
        for (int i = length / 2; i < length; i++) {
            secondPart[j] = string[i];
            j++;
        }
        printf("%s", secondPart);
        printf("%s", firstPart);
    }
    return 0;
}

//В строке символов поменять местами символы на четных и нечетных позициях
int fifth() {
    char string[100];
    printf("Input line here (5): ");
    scanf(" %s", string);

    int length = strlen(string);
    char variable;
    if (length % 2 == 0) {
        for (int i = 0; i < length - 1; i++) {
            variable = string[i];
            string[i] = string[i + 1];
            string[i + 1] = variable;
        }
    } else {
        printf("String should be multiple of two!");
    }
    printf("%s", string);
}

int main() {
    int choose;
    printf("1 / 2 / 3 / 4 / 5: ");
    scanf("%d", &choose);
    if (choose == 1) {
        first();
    } else if (choose == 2) {
        second();
    } else if (choose == 3) {
        third();
    } else if (choose == 4) {
        fourth();
    } else if (choose == 5) {
        fifth();
    } else {
        printf("Input Error!");
    }
    return 0;
}