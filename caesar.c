#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
int main(int argc, string argv[])
{   
    bool keySucces = false;
    int key = 0;
    int leight = 0;
    string message = "";
    do
    {
            if (argc != 2)
        {
            printf("Print another key.\n");
            return 1;
        }
        
        else
        {
            key = atoi(argv[1]); //Перевод ключа с String в Int
            keySucces = true;
        }   
    }
    while(!keySucces);
    message = GetString();
    leight  = strlen(message);
     
    for (int i = 0; i < leight; i++)
    {
        if(isalpha(message[i]))
        
            if (islower (message[i])) //Если буква в верхнем регистре
            {
                printf("%c", ((((message[i] - 97)+key)%26)+97));    
            }
            else 
            {
                printf("%c", ((((message[i] - 65)+key)%26)+65));
            }
     
        else 
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
    return 0;    
}
 