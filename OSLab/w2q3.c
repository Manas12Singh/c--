#include <stdio.h>
#include <string.h>
#include <unistd.h>

void func(char fname[])
{
    char name[20], section[3], gender;
    int age, rollNo;
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender: ");
    scanf(" %c", &gender);
    printf("Section: ");
    scanf("%s", section);
    printf("Roll No.: ");
    scanf(" %d%*c", &rollNo);
    FILE *f1 = fopen(fname, "w");
    if (f1 == NULL)
    {
        perror("Error opening file");
        return;
    }
    char s[100];
    sprintf(s, "Name: %s\nAge: %d\nGender: %c\nSection: %s\nRoll No: %d", name, age, gender, section, rollNo);
    fprintf(f1, s);
    fclose(f1);
    printf("Details written to %s\n", fname);
}

int main()
{
    printf("Your Details:\n");
    func("myFile.txt");
    printf("Friend's Details:\n");
    func("friendFile.txt");
    printf("\nCommon lines:\n");
    execlp("grep", "grep", "-f", "myFile.txt", "friendFile.txt", NULL);
    return 0;
}
