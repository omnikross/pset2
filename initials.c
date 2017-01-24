#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
int main(void)
{
    string s = GetString(); 
    char a; 
    printf("%c", toupper(s[0])); 
    for(int j = 0; j < strlen(s); j++)
        {
            if(s[j] == ' ')
            {   
                a = s[j + 1];
                printf("%c", toupper(a)); 
            }
        }
    printf("\n");
}