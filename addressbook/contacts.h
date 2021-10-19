#include<string.h>
typedef struct
{
    char *name;
    char *telnum;
    char *address;
}contacts;

contacts create_contact(char *name, char *telnum, char *address){
    contacts contact;
    contact.name = "";
    contact.telnum = "";
    contact.address = "";
    strcpy(contact.name, name);
    strcpy(contact.telnum, telnum);
    strcpy(contact.address, address);
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