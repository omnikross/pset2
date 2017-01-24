#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char caesar(char token, int key);

int main(int argc, string argv[])
{
    bool keySucces  = false;
    string word_key = "";
    int key_length  = 0;
    string message  = ""; 
    int message_length;
    int key_count = 0;
    do 
    {
        if(argc != 2)//кол-во аргументов введенных в командную строку неправильное
        {
            printf("You didn't enter the correct number of keywords.\n");
            return 1;
        }
        else if(argv[1])
        {
            int lenght = strlen(argv[1]);
            for (int i = 0; i < lenght; i++)
                {
                if (!isalpha(argv[1][i]))//буква ли
                {
                    printf("Incorrect characters.\n");
                    return 1;
                }
                else//если всё хорошо и ключ принимаеться
                {
                    keySucces = true;
                    word_key  = argv[1];
                }
            }
        }
    }
    while(!keySucces); 
    //вызначаем длину слова и масив с этой длиной
    key_length = strlen(word_key);
    int kcodes[key_length];
    //преобразования букв в чиса
    //а = 0, z = 25 без учёта регистра 
    for (int i = 0; i < key_length; i++)
    {
        kcodes[i] = toupper(word_key[i]) - 65;
    }
    //считывание послания и измирение длины
    message = GetString();
    message_length = strlen(message);
    
    for(int i = 0; i < message_length; i++)
    {   //если не буква то дзеркальн отображаем
        if(!isalpha(message[i]))
        {
            printf("%c", message[i]);
        }
        //выход данных  процеса
        else
        {
            printf("%c", caesar(message[i], kcodes[key_count]));
            //увеличения счётчика положений для масива kcodes
            if(key_count < key_length - 1)
            {
                key_count++;
            }
            else
            {
                key_count = 0;
            }
        }
    }    
    printf("\n");
    return 0;
}
/*
Эта функция применяется с учетом регистра для шифра
Цезаря (если ключ-один символ)
*/
char caesar(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 97) + key) % 26) + 97);
    }   
    else 
    {
        return ((((token - 65) + key) % 26) + 65);
    }   
}