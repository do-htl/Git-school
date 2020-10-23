#include <stdio.h>

int main()
{
    char *c[] = {"GeksQuiz", "MCQ", "TEST", "QUIZ"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;

    /*
     * *++cpp   ->  c + 2               // cpp wird permanent um 1 erhöht!!!
     * *(c+2)   ->  "TEST"
     */
    printf("%s ", **++cpp);

    /*
     * *++cpp           ->  c + 1       // nicht vergessen, cpp wert wurde geändert
     * *(c+1)           ->  "MCQ"
     * --"MCQ"          ->  "GeksQuiz"
     * *"GeksQuiz" + 3  ->  "sQuiz"
     */
    printf("%s ", *--*++cpp + 3);

    /*
     * cpp[-2]      ->  c + 3
     * *(c+3)       ->  "QUIZ"
     * "QUIZ" + 3   ->  "Z"
     */
    printf("%s ", *cpp[-2] + 3);

    /*
     * cpp[-1]      ->  c + 2   (-> "TEST")
     * (c + 2)[-1]  ->  "MCQ"
     * "MCQ" + 1    ->  "CQ"
     */
    printf("%s ", cpp[-1][-1] + 1);

    printf("\n");
    return 0;
}
//  TEST sQuit Z CQ
