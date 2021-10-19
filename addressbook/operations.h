#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>
void welcome();
void newcontact();
void loop();
void back();
// void open_database();
// void create_table();

/**************************
*****所需的全局变量定义*****
***************************/
sqlite3 *db;
char *zErrMsg = 0;
int rc;
char *sql1, *sql2;

/********函数源码***********/
void welcome(){
    printf("这是一个通讯录软件，欢迎使用！\n");
}

//打印主界面
void display(){
    welcome();
    printf("--------------------\n");
    printf("你可以进行以下的操作：\n");
    printf("1.添加联系人\n");
    printf("2.删除联系人\n");
    printf("3.显示所有联系人\n");
    printf("4.查询联系人\n");
    printf("5.退出程序\n");
    printf("--------------------\n");
    printf("现在请输入你要进行的操作：");
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    int i;
    for ( i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


//打开数据库addressbook.db，如果不存在则自动创建一个新的数据库
void open_database(){
    //打开数据库
   rc = sqlite3_open(".\\addressbook\\contacts.db", &db);
   if(rc){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(EXIT_FAILURE);
   }
   else{
      fprintf(stdout, "Opened database successfully!\n");
   }
}
//创建一个新的表contacts用来保存联系人
void create_table(){
    sql1 = "CREATE TABLE contacts("\
           "ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
           "NAME TEXT NOT NULL,"\
           "TELNUM TEXT NOT NULL,"\
           "ADDRESS TEXT NOT NULL);";

   //执行sql语句
   rc = sqlite3_exec(db, sql1, callback, 0, &zErrMsg);
   if(rc != SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      }
   else{
      fprintf(stdout, "Table created successfully!\n");
   }
}
//新建联系人的操作
void newcontact(){
    char *newname = "";
    char *newtelnum = "";
    char *newaddress = "";
    printf("请输入新联系人的信息：\n");
    printf("姓名：");
    scanf("%s", newname);
    printf("电话：");
    scanf("%s", newtelnum);
    printf("地址：");
    scanf("%s", newaddress);
    contacts contact;
    contact = create_contact(newname, newtelnum, newaddress);
    // printf("%s,%s,%s\n", contact.name, contact.telnum, contact.address);

    //这是原来的想法，想把获得的信息保存到txt文件中，但是那样更麻烦
    // FILE *fp = NULL;
    // fp = fopen(".\\addressbook\\addressbook.txt", "a+");
    // if(fp == NULL){
    //     printf("文件打开失败，请检查addressbook.txt！");
    // }else
    // {
    //     fprintf(fp, "\n");
    //     fputs(contact.name, fp);
    //     fprintf(fp, "\t");
    //     fputs(contact.telnum, fp);
    //     fprintf(fp, "\t");
    //     fputs(contact.address, fp);
    //     fprintf(fp, "\t");
    //     fclose(fp);

     //所以后来学习了sqlite3之后
     //选择将该新联系人保存到addressbook.db数据库中的contacts表中
    sql2 = strcpy("INSERT INTO contacts (NAME, TELNUM, ADDRESS) ","VALUES ('");
    sql2 = strcpy(sql2, contact.name);
    sql2 = strcpy(sql2, "', '");
    sql2 = strcpy(sql2, contact.telnum);
    sql2 = strcpy(sql2, "', '");
    sql2 = strcpy(sql2, contact.address);
    sql2 = strcpy(sql2, "');");

    //打开数据库
    open_database();
    //执行sql语句
    rc = sqlite3_exec(db, sql2, callback, 0, &zErrMsg);
    if(rc != SQLITE_OK){
       fprintf(stderr, "SQL error: %s\n", zErrMsg);
       sqlite3_free(zErrMsg);
    }
    else{
        fprintf(stdout, "Records created successfully!\n");
        sqlite3_close(db);
    }
    }
//删除联系人的操作
void delete(){
    FILE *fp = NULL;
    fp = fopen(".\\addressbook\\addressbook.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败，请检查adressbook.txt！");
    }else
    {

    }
}
//返回主菜单
void back(){
    int choice;
    printf("你要返回主界面吗？返回请输入1，退出输入0：");
    scanf("%d", &choice);
    if(choice == 1)
    {
        loop();
    }
    else if(choice == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else
    {    
        printf("您的输入有误，请重新输入：\n");
        back();
    }
}
//主要的逻辑判断部分
void loop(){

    open_database();
    create_table();
    sqlite3_close(db);
    display();
    int choice;
    scanf("%d", &choice);
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            newcontact();
            break;
        
        case 2:
            delete();
            break;
        default:
            break;
        }
      back();
    }
}



