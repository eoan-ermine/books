int main() {
    char string[100];
    int numberOfOtherCharsAppeared = 0;

    printf("Please enter your character set:\n");
    gets(string);

    int countOfLetters = '{' - 'a';
    int frequency[countOfLetters];
    
    for(int i = 0; string[i] != 0; ++i) {
        char character = string[i];

        if(character > 'a' && character < '{') {
            frequency[character - 'a'] += 1;
        } else {
            ++numberOfOtherCharsAppeared;
        }
    }

    for(int i = 0; i < countOfLetters; ++i) {
        printf("letter %c appeared %d time", i + 'a', frequency[i]);
    }
    printf(
        "number of other characters in the given set was: %d\n",
        numberOfOtherCharsAppeared
    );
}