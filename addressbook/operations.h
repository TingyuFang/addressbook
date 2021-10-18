#include<stdio.h>
#include<stdlib.h>
void welcome();
void newcontact();
void loop();
void back();

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
//新建联系人的操作
void newcontact(){
    char newname[MAX_NAME];
    char newtelnum[MAX_TELNUM];
    char newadress[MAX_ADRESS];
    printf("请输入新联系人的信息：\n");
    printf("姓名：");
    scanf("%s", newname);
    printf("电话：");
    scanf("%s", newtelnum);
    printf("地址：");
    scanf("%s", newadress);
    contacts contact;
    contact = create_contact(newname, newtelnum, newadress);
    printf("%s,%s,%s\n", contact.name, contact.telnum, contact.adress);
    //将该新联系人保存到adressbook.txt文本文件当中去
    FILE *fp = NULL;
    fp = fopen(".\\addressbook\\addressbook.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败，请检查adressbook.txt！");
    }else
    {
        fprintf(fp, "\n");
        fputs(contact.name, fp);
        fprintf(fp, "\t");
        fputs(contact.telnum, fp);
        fprintf(fp, "\t");
        fputs(contact.adress, fp);
        fprintf(fp, "\t");
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
        
        default:
            break;
        }
      back();
    }
}



