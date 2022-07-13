#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int getUserIndex(char users[300][20], int user_count, char user[20])
{
    char ch[100];
    strcpy(ch,user);
    strcat(ch,"\n");
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i], ch) == 0) return i;
    }

    return -1;
}
int main(){
char adad[200];
int menu;
int sizechar;
//login
int IDnumber;
int user_count = 0;
char users[300][20];
char passwords[300][20];
char user[3000];
char password[3000];
int end=0;
int wpc = 0;
char save[50];
//send
char all_messages[1000][200];
char message[3000];
int messageIDs[1000];
int message_i=1;
int message_ii = 1;
//edit
int editID;
int sizecheck;
char edited[3000];
//view
char checkviwe[1000][50];
int w;
//change
char passedit[3000];
//logout


////////////////////////////////////////////////////////////////////////////


FILE *file_username;
FILE *file_password;
FILE *file_messagei;
FILE *file_message;
FILE *file_messageID;


char check[100];

file_username = fopen("twitter_username.txt","a+");
fgets(users[user_count],100,file_username);
while(!feof(file_username)){
    //printf("%s",users[user_count]);
    user_count++;
    fgets(users[user_count],100,file_username);
}
fclose(file_username);


file_password = fopen("twitter_password.txt","a+");

for(int i = 0; i < user_count; i++){
    fgets(passwords[i],100,file_password);
}
fclose(file_password);
//printf("%d",strcmp("mmd\n",users[0]));


file_messagei = fopen("twitter_messagei.txt","a+");
while(!feof(file_messagei)){
    fgets(check,100,file_messagei);
    if(strlen(check) <= 2){
    message_i = *check - 48;
    }
    else if(strlen(check) == 3){
    message_i = (*check - 48) * 10 + *(check + 1) - 48;
    }
    else if(strlen(check) == 4){
    message_i = (*check - 48) * 100 + (*(check + 1) - 48) * 10 + *(check + 2) - 48;
    }
}
if(message_i < 0){
    message_i = 0;
}
message_i++;
message_ii = message_i;
//printf("%d\n", message_i);
//printf("%d\n", strlen(check));
fclose(file_messagei);


file_message = fopen("twitter_message.txt","a+");
for(int i = 1; i < message_i; i++){
    fgets(all_messages[i],100,file_message);
    //printf("%s",all_messages[i]);
}
fclose(file_message);

file_messageID = fopen("twitter_messageID.txt","a+");
for(int i = 1; i < message_i; i++){
    fgets(check,100,file_messagei);
    if(strlen(check) <= 2){
        messageIDs[i] = *check - 48;
    }
    else if(strlen(check) == 3){
        messageIDs[i] = (*check - 48) * 10 + *(check + 1) - 48;
    }
}
fclose(file_messageID);







////////////////////////////////////////////////////////////////////////////
int regi = 0;
int logi = 0;


////login
login:
regi = 0;
logi = 0;
while(end!=1){
    user2 :
    printf("please enter your username(max:20)\n");
    gets(user);
    sizechar = strlen(user);
    if (sizechar > 20){
        printf("\nyour username is more than 20 character. please try again.\n");
        goto user2;
    }
    for(int i = 0; i <= sizechar; i++){
        if(user[i] == 32){
            printf("\nyou can not use space!\nchoose another username.\n\n");
            goto user2;
        }
    }
    pass2 :
    printf("please enter your password(max:20)\n");
    gets(password);
    sizechar = strlen(password);
    if (sizechar > 20){
        printf("\nyour password is more than 20 character. please try again.\n\n");
        goto pass2;
    }
    for(int i = 0; i <= sizechar; i++){
        if(password[i] == 32){
            printf("\nyou can not use space!\nchoose another password.\n");
            goto pass2;
        }
    }
    printf("\n1.Login\n2.Register\nEnter the number of the action:\n");
    gets(adad);
    if(strlen(adad) > 1){
    goto wrong;
    }
    menu = *adad - 48;
    if(menu == 1){
        logi = 1;
    }
    else if(menu == 2){
        regi = 1;
    }
    int index=getUserIndex(users,user_count,user);
    if(index==-1){
        if(logi == 1){
            printf("\nno username matches '%s'\n",user);
            logi = 0;
            goto login;
        }

        ////
        strcat(user,"\n");
        file_username = fopen("twitter_username.txt","a+");
        fputs(user,file_username);
        fclose(file_username);
        strcat(password,"\n");
        file_password = fopen("twitter_password.txt","a+");
        fputs(password,file_password);
        fclose(file_password);
        ////

        strcpy(users[user_count], user);
        strcpy(passwords[user_count], password);
        IDnumber=user_count;
        user_count++;
        if(regi == 1){
            printf("\nwelcome to twitter!\n");
            regi = 0;
        }
        end = 1;
    }
    else{

       if(strcmp(passwords[index],strcat(password,"\n"))==0){
        IDnumber=index;
        if(regi == 1){
            printf("\nusername '%s' already exists\n", user);
            regi = 0;
            goto login;
        }
        if(logi == 1){
            printf("\nlogin successfuly!\n\n");
            wpc = 0;
            logi = 0;
        }
        end = 1;
       }
       else{
        if(logi == 1){
            printf("\nwrong password :( please try again\n\n");
            if(strcmp(save,user) == 0){
                wpc++;
            }
            else{
            strcpy(save,user);
            logi = 0;
            wpc = 1;
            }
            if(wpc == 3){
                printf("\npassword entered wrong 3 times!\nbye bye\n");
                return 0;
            }
        }
        if(regi == 1){
            printf("\nusername '%s' already exists\n", user);
            regi = 0;
            goto login;
        }
       }
    }
}
firstmenu:
printf("\nhome menu \n1.send message\n2.edit message\n3.view all messages\n4.change password\n5.exit\nenter number of menu : ");
gets(adad);
if(strlen(adad) > 1){
    goto wrong;
}
menu = *adad - 48;
if(menu == 1){
    goto send;
}
else if(menu == 2){
    goto edit;
}
else if(menu == 3){
    goto view;
}
else if(menu == 4){
    goto change;
}
else if(menu == 5){
    goto logout;
}
else{
    wrong :
    printf("\nwrong command!\n");
    goto firstmenu;
}
////send
send:
printf("\nsend message menu : \n1.send message\n2.exit\nenter number of menu : ");
gets(adad);
if(strlen(adad) > 1){
    goto bale;
}
menu = *adad - 48;
if(menu == 2){
    goto firstmenu;
}
else if(menu != 1){
    bale :
    printf("\nwrong command!\n");
    goto send;
}
send2 :
printf("\nwrite your message(max:200) \n");
gets(message);
sizechar = strlen(message);
if (sizechar > 200){
    printf("\nyour message is more than 200 character. please try again.\n");
    goto send2;
}
printf("\nyour message saved\n");
strcpy(all_messages[message_i],message);
messageIDs[message_i]=IDnumber;
//printf("%d",IDnumber);
sprintf(check,"%d", messageIDs[message_i]);
file_messageID = fopen("twitter_messageID.txt","a+");
fputs(check,file_messageID);
fputs("\n",file_messageID);
fclose(file_messageID);
sprintf(check, "%d", message_i);
file_messagei = fopen("twitter_messagei.txt","a+");
fputs(check,file_messagei);
fputs("\n",file_messagei);
fclose(file_messagei);
file_message = fopen("twitter_message.txt","a+");
fputs(message,file_message);
fputs("\n",file_message);
fclose(file_message);
message_i++;
goto send;
////edit
edit:
printf("\nedit message menu  \n1.edit message\n2.exit\nenter number of menu : ");
gets(adad);
if(strlen(adad) > 1){
    goto bahbah;
}
menu = *adad - 48;
if(menu == 2){
    goto firstmenu;
}
else if(menu != 1){
    bahbah :
    printf("\nwrong command!\n");
    goto edit;
}
edit3 :
printf("\nplease enter message ID\n");
gets(adad);
sizechar = strlen(adad);
for(int i = 0; i < sizechar; i++){
    if(adad[i] < 48 || adad[i] > 57){
        printf("\nwrong command!\n");
        goto edit3;
    }
}
editID = atoi(adad);
if(editID >= message_i || editID <= 0){
    printf("\nthe entered message ID is wrong!\n");
    goto edit3;
}
else if(messageIDs[editID]==IDnumber){
    edit2 :
    printf("your message:\n%s\n",all_messages[editID]);
    printf("\nenter your edited message(max:200)\n");
    gets(edited);
    sizechar = strlen(edited);
    if (sizechar > 200){
        printf("\nyour message is more than 200 character. please try again.\n");
        goto edit2;
    }
    file_message = fopen("twitter_message.txt","w+");
    for(int i = 1; i < message_i; i++){
        if(i == editID){
            fputs(edited,file_message);
            fputs("\n",file_message);
        }
        else{
            fputs(all_messages[i],file_message);
        }
    }
    fclose(file_message);
    printf("your message edited.\n");
    strcpy(all_messages[editID],edited);
    goto edit;
}
else{
    printf("\nyou can not edit this message\n");
    goto edit;
}
////view
view:
printf("\nview all messages menu  \n1.view all messages\n2.exit\nenter number of menu : ");
gets(adad);
if(strlen(adad) > 1){
    goto gharghar;
}
menu = *adad - 48;
if(menu == 2){
    goto firstmenu;
}
else if(menu != 1){
    gharghar :
    printf("\nwrong command!\n");
    goto view;
}
for(int j=1;j<message_i;j++){
   w=messageIDs[j];
   printf("%d:\n",j);
   strncpy(checkviwe[j], users[w], strlen(users[w]) - 1);
   printf("%s : ",checkviwe[j]);
   printf("%s \n",all_messages[j]);
}
printf("\nthese are all messages . \n");
scan:
printf("press 0 to exit .\n");
gets(adad);
if(strlen(adad) > 1){
    goto arar;
}
menu = *adad - 48;
if(menu == 0){
    goto firstmenu;
}
else{
    arar :
    printf("\nwrong command\n");
    goto scan;
}
////change
change:
printf("\nchange password menu  \n1.change password\n2.exit\nenter number of menu : ");
gets(adad);
if(strlen(adad) > 1){
    goto aree;
}
menu = *adad - 48;
if(menu == 2){
    goto firstmenu;
}
else if(menu != 1){
    aree :
    printf("\nwrong command!\n");
    goto change;
}
pass3 :
printf("\nenter your new password\n");
gets(passedit);
    sizechar = strlen(passedit);
    if (sizechar > 20){
        printf("\nyour new password is more than 20 character. please try again.\n");
        goto pass3;
    }
    for(int i = 0; i <= sizechar; i++){
        if(passedit[i] == 32){
            printf("\nyou can not use space!\nchoose another password.\n");
            goto pass3;
        }
    }
file_password = fopen("twitter_password.txt","w+");
//printf("%d\n%d",IDnumber,user_count);
for(int i = 0; i < user_count; i++){
    if(i == IDnumber){
        fputs(passedit,file_password);
        fputs("\n",file_password);
    }
    else{
        fputs(passwords[i],file_password);
    }
}
fclose(file_password);
strcpy(passwords[IDnumber],strcat(passedit,"\n"));
printf("\nyour new password saved .\n");
goto firstmenu;
////logout
logout:
end = 0;
goto login;
return 0;
}
