#include<string.h>
#define MAX_NAME 10
#define MAX_TELNUM 12
#define MAX_ADRESS 20
typedef struct
{
    char name[MAX_NAME];
    char telnum[MAX_TELNUM];
    char adress[MAX_ADRESS];
}contacts;

contacts create_contact(char name[], char telum[], char adress[]){
    contacts contact;
    strcpy(contact.name, name);
    strcpy(contact.telnum, telum);
    strcpy(contact.adress, adress);
    return contact;
}

// typedef struct
// {
//     int a;
//     int b;
// }Stu;

// Stu getStu(int x, int y){
//     Stu result;
//     result.a = x;
//     result.b = y;
//     return result;
// }