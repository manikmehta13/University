#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SENTENCES 6
#define MAX_LEN 300

/* Sentences the user can be asked to type */
const char *sentences[NUM_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "Practice makes a man perfect, so keep coding every day.",
    "C is a powerful language that gives you control over memory.",
    "A journey of a thousand miles begins with a single step.",
    "Pointers and arrays are closely related in the C language.",
    "Good programmers write code that humans can easily understand."
};

void showHeader(void);
void removeNewline(char *str);
int  countWords(const char *str);
int  countCorrectChars(const char *original, const char *typed);
const char *getRating(double wpm, double accuracy);
void showResult(const char *original, const char *typed, double seconds);

int main(void)
{
    char typed[MAX_LEN];
    char again = 'y';
    int index;
    time_t startTime, endTime;

    srand((unsigned int)time(NULL));

    while (again == 'y' || again == 'Y')
    {
        showHeader();

        index = rand() % NUM_SENTENCES;

        printf("Type the following sentence exactly:\n\n");
        printf("  %s\n\n", sentences[index]);
        printf("Press ENTER to start, then type and press ENTER when done.");
        getchar();

        printf("\nGO! > ");

        startTime = time(NULL);
        fgets(typed, MAX_LEN, stdin);
        endTime = time(NULL);

        removeNewline(typed);

        showResult(sentences[index], typed, difftime(endTime, startTime));

        printf("\nTry again? (y/n): ");
        scanf(" %c", &again);
        getchar();   /* consume leftover newline */
    }

    printf("\nThanks for playing!\n");
    return 0;
}

void showHeader(void)
{
    printf("\n==============================\n");
    printf("      TYPING SPEED TEST\n");
    printf("==============================\n\n");
}

/* Remove the '\n' that fgets stores at the end of the input */
void removeNewline(char *str)
{
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

/* Count words by counting transitions from space to a letter */
int countWords(const char *str)
{
    int count = 0, inWord = 0;

    while (*str)
    {
        if (*str != ' ' && !inWord)
        {
            inWord = 1;
            count++;
        }
        else if (*str == ' ')
        {
            inWord = 0;
        }
        str++;
    }

    return count;
}

/* Compare both strings position by position */
int countCorrectChars(const char *original, const char *typed)
{
    int i, correct = 0;
    int lenO = strlen(original);
    int lenT = strlen(typed);
    int limit = (lenO < lenT) ? lenO : lenT;

    for (i = 0; i < limit; i++)
    {
        if (original[i] == typed[i])
            correct++;
    }

    return correct;
}

const char *getRating(double wpm, double accuracy)
{
    if (accuracy < 70)  return "NEEDS PRACTICE (focus on accuracy)";
    if (wpm >= 60)      return "EXCELLENT";
    if (wpm >= 40)      return "GOOD";
    if (wpm >= 25)      return "AVERAGE";
    return "BEGINNER";
}

void showResult(const char *original, const char *typed, double seconds)
{
    int lenO = strlen(original);
    int lenT = strlen(typed);
    int correct = countCorrectChars(original, typed);
    int wrong, wordsTyped;
    double accuracy, wpm, minutes;

    /* Missing or extra characters also count as mistakes */
    wrong = ((lenO > lenT) ? lenO : lenT) - correct;

    if (seconds < 1)
        seconds = 1;                  /* avoid division by zero */

    minutes    = seconds / 60.0;
    wordsTyped = countWords(typed);

    accuracy = (lenO > 0) ? (correct * 100.0) / lenO : 0;

    /* Standard WPM: 5 characters = 1 word */
    wpm = (correct / 5.0) / minutes;

    printf("\n========== RESULT ==========\n");
    printf("Time taken        : %.0f seconds\n", seconds);
    printf("Characters typed  : %d\n", lenT);
    printf("Correct chars     : %d\n", correct);
    printf("Wrong/missing     : %d\n", wrong);
    printf("Words typed       : %d\n", wordsTyped);
    printf("Accuracy          : %.2f%%\n", accuracy);
    printf("Speed             : %.1f WPM\n", wpm);
    printf("Rating            : %s\n", getRating(wpm, accuracy));
    printf("============================\n");

    if (correct != lenO || lenT != lenO)
    {
        printf("\nOriginal : %s\n", original);
        printf("You typed: %s\n", typed);
    }
}
