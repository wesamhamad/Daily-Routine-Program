#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define SIZE 20
int z = 0;

char *fullCourse(char r);
char *fullDay(int x);
char *fullHour(int y);
int countSteps(int goal , int y);
int secondPart(int z,int steps,int* goal);
void PlayAgain(int press);

/*___________________Reminder starts here____________________________*/
int count[60]={0};
void current_time(){
    time_t  now;
    struct  tm *ctime;
    char a[80];
    now = time(NULL);
    ctime = localtime(&now);
    strftime(a, sizeof(a),"Now it's %I:%M%p.",ctime);
    puts(a);
}
void header(){
    printf("%52s","");
    current_time();
    printf("%45s"," ");
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=30; j++) {
            if(i==1||i==6||j==1||j==30){
                printf("#");
            }
            else
            printf(" ");
        }
        puts("");
        if(i==2){
            printf("%45s#\t\tWelcome!          #\n", "");
            printf("%80s\n","# new day means new goals ❤️  #");
        }
        printf("%45s","");
    }
}
int my_clock(int hour){
    static int clock=0;
    clock+=hour;
    return clock;
}
void timer(int count[], int index, int size ){
    if (index <=size) {
        timer(count,index +1, size);
        if(index <10){
            printf("%55s","");
            printf("00:0%d:00 \n",count[index]);
        }
        else if(index>=10){
            printf("%55s","");
            printf("00:%d:00 \n",count[index]);
        }

    }
}
void reminder(int hour){
    switch (hour) {
        case 1:
            printf ("\n%52s<alarm ⏱️%1s🛑🛑>\n%65s\n\a","","","Time to study" );
            timer(count, 0, 10);
            printf("\n%63s\n\n%73s\n","NOW ⏳"," \"Remember time is money\"\n"); break;
        case 5:
            printf ("\n%52s<alarm ⏱️%1s🛑🛑>\n%76s\n\a","","","Now it's time to complete your steps ");
            timer(count, 0, 5);
            printf("\n%63s\n%68s\n","NOW ⏳"," \" You can do it\"\n"); break;
        case 9:
            printf ("\n%52s<alarm ⏱️%1s🛑🛑>\n%93s\n\a","","","Now you deserve to have a break and play a game 🕹️  🎮  " );
            timer(count, 0, 15);
            printf("\n%63s\n%66s\n","NOW ⏳"," \"Have fun !\"\n"); break;
        case 12 :
            printf ("\n%52s<alarm ⏱️%1s🛑🛑>\n%69s\n\a","","","Time to sleep 💤" );
            printf("\n%67s\n"," \"Good night !\"\n"); break;
    }
}
 void to_do_list(){
    char *to_do[6]={"Computer Program ✅","Math✅ ","Physics ✅","Information Technology ✅","Arab ✅","walk ✅"};
    char *done[6]={"","","","","",""};
    int did ,checked=0;
    printf ("\n%30cWhich of the following did you finish enter their numbers? \n", ' ');
    printf ("%40c0 >> Computer Program 1 >> Math 2 >> Physics \n"
            "%40c3 >> Information Technology 4 >> Arab 5 >> walk\n %50c >>> to end enter -1 <<<\n",  ' ', ' ',' ');
    scanf("%d",&did);
    while(did!=-1) {
        done[did]=to_do[did];
        scanf("%d",&did);
    }
    puts("My-checklist 📰 ✅ :");
    for (int j =0; j<6 ;j++) {
        if (strcmp(done[j],"") == 0)
            continue;
        printf("%s\n",done[j]);
        checked++;
        }
    if(checked==6){
        puts("\nYou did a great job today ! ");
    }
    else if(checked==0)
        puts("Ops!you didn't finish any thing today \n you have to try it better tomorrow ");
}

int main(){
    system("COLOR F0 ");
    for (int i=59; i>0; i--) {
        count[i]=i;
    }
    /*____________________Study time starts here____________________________*/
    header();
    puts("");
    reminder(my_clock(1));
    char s[7][6] = {
        {'C', 'M', 'P', 'I', 'A'},
        {'I', 'C', 'M', 'A', 'P'},
        {'A', 'P', 'C', 'I', 'M'},
        {'M', 'I', 'P', 'A', 'C'},
        {'P', 'C', 'M', 'P', 'I'},
        {'I', 'P', 'C', 'M', 'A'},
        {'C', 'M', 'P', 'A', 'I'}
    };
    int day, hour, ans; char com = 'Y';
    char search[25];

    printf ("%50c*** STUDY TIME *** \n%48cWelcome in your schedule..."
        "\n\n%40cuse a number to select day\n", ' ', ' ', ' ');
    printf ("%40c1 >> Sunday,    2 >> Monday,   3 >> Tuesday \n"
        "%40c4 >> Wednesday, 5 >> Thursday, 6 >> Friday\n%40c7 >> Saturday\n",  ' ', ' ', ' ');

    do {
        printf ("\n\nAre you want to inquire about something? \"Y\" or \"N\": "); scanf ("%s", &com);
        while ((toupper(com) != 'Y') && (toupper(com) != 'N')) {
            printf("Please Enter \"Y\" or \"N\": "); scanf ("%s", &com);
        }
        if (toupper(com) == 'N') break;
           printf ("\n%20cWhat do you want do? \n", ' ');
           printf ("%20c1 >> show certain hour \n%20c2 >> show certain day"
                "\n%20c3 >> search about times certain subject \n:", ' ', ' ', ' '); // List of choices
            scanf ("%d", &ans);

           if (ans == 1){ // Select certain hour:
               printf ("Enter a day and hour: "); scanf ("%d%d", &day, &hour);
               if (day > 7 || hour > 5){
                   printf ("Invalid input, TRY AGAIN.. Day between 1 and 7, Hour between 1 and 5");
                   continue;
                }
                printf ("\nYou should study: %s", fullCourse(s[day-1][hour-1]));
            }
            else if (ans == 2){ // Select certain day:
                printf ("Enter a day: "); scanf ("%d", &day); printf ("\n");
                for (int i = 0; i < 5; i++){
                    if (day > 7) {
                        printf ("Invalid input, TRY AGAIN.. Day between 1 and 7");
                        break;
                    }
                    printf ("%s%5s", fullCourse(s[day-1][i]), " ");
                }
            } else if (ans == 3){ // search by subject name:
                    printf ("Enter a name of subject: ");
                    gets(search); gets(search); //This is a problem on IDE, we can't fix it.
                    puts(""); int count = 0;
                    for (int i = 0; i < 7; i++){
                        for (int j = 0; j < 5; j++){
                            if (strncasecmp(search, fullCourse(s[i][j]), 8) == 0) {
                            printf ("You have %s on %s, At %s \n", fullCourse(s[i][j]), fullDay(i+1), fullHour(j+1));
                            } else count++;
                        }
                    }
                    if (count == 35) printf("This course not in your schedule!");

            } else printf ("Invalid Choice!! \n");
        } while (toupper(com) == 'Y');

    printf ("\n%53cGOOD LUCK 💕\n\n\a",' ');

    /*____________________walk time starts here____________________________*/
    reminder(my_clock(4)); // alarme to starts walk
    int steps,goal ;
     printf("ENTER your daily steps goal: "); scanf("%d",&goal);
    z=goal/2;
    printf("\nEnter your recent steps: "); scanf("%d",&steps);
    printf("%d steps..you did great!!\n", countSteps(goal ,steps));
    if (z >= goal) printf("No second part for today, you did all your steps.. KEEP FIT 💪\n");
    else {
    printf("\nnow for the second part of the day\n");
    secondPart(z,steps,&goal);
    }

    /*____________________Game time starts here____________________________*/
    reminder(my_clock(4));//alarme to starts game
    printf("\n\n%65s%70s%85s%77s%68s%77s%81s%76s%70s","* PLAY TIME *\n","HELLO BEAUTIFUL <3!!\n",
        " AFTER ALL THIS HARD WORK YOU DESERVE SOME FUN :)!!\n",
        "LET'S PLAY A GAME CALLED WHO'S LUCKY?\n","THE ROLES ARE SIMPLE:\n",
        "1-THIS GAME DEPENDS ON NUMBERS ONLY!\n","2-YOU SHOULD ENTER NUMBERS IN SEQUENCE TO WIN!\n",
        "3-WHOEVER REACHES 20 IS THE WINNER!\n","WISH YOU A GOOD LUCK!\n"
    );
    int press;
    printf("\n%75s","ENTER 1 TO START ,, -1 TO END!\n");
    printf("%60c",' ');
    scanf("%d",&press);
    PlayAgain(press);
    to_do_list();
    reminder(my_clock(3));//alarme to sleep
    return 0;
}
char *fullCourse (char r){ // Display full name of course:
    char *res[1];
    switch (r) {
        case 'C': res[0] = "Computer Program"; break;
        case 'M': res[0] = "Math"; break;
        case 'P': res[0] = "Physics"; break;
        case 'I': res[0] = "Information Technology"; break;
        case 'A': res[0] = "Arab"; break;
        default: res[0] = "This course not in your schedule";
    }
    return *res;
}
char *fullDay(int x) { // Display full name of day:
    char *res[1];
    switch (x) {
        case 1: res[0] = "Sunday"; break;
        case 2: res[0] = "Monday"; break;
        case 3: res[0] = "Tuesday"; break;
        case 4: res[0] = "Wednesday"; break;
        case 5: res[0] = "Thursday"; break;
        case 6: res[0] = "Friday"; break;
        case 7: res[0] = "Saturday"; break;
    }
    return *res;
}
char *fullHour(int y) { // Display hour with letter:
    char *res[1];
    switch (y) {
        case 1: res[0] = "First Hour"; break; break;
        case 2: res[0] = "Second Hour"; break;
        case 3: res[0] = "3rd Hour"; break;
        case 4: res[0] = "4th Hour"; break;
        case 5: res[0] = "5th Hour"; break;
    }
    return *res;
}

int secondPart(int z,int steps,int* goal) {
    int i=1;

    printf("Your steps now = %d\n",z);
    printf("\t\t\tWe will ask you every 1 hour about your progress starting from 7pm till 9pm, KEEP IT UP!\n");
    while (z < *goal) {
        printf("\t\t\t\t\t-- After %d hours --\n\t\t\thow many steps did you walk in the last  hours?", i);scanf("%10d",&steps);
        z+=steps;
        printf("Your steps now = %d\n",z);
        if(z>*goal){
            printf("Bravo! you hit the goal\n");
            break;
        }
        ++i;
        if(i==4) break;
    }
    if(z==*goal|| z>*goal )
        printf("\n\t\t\twow you are doing great\n");
    else if(z<*goal) {
        printf("\n\t\t\tyou did not reach you steps goal, try again tommowor\n");
        printf("\n\t\t\ttotal of your today's steps: %d \n",/**goal*/z);
    }
    return 0;
}
//countsteps recursion
int countSteps(int goal , int y){
    int n;

    // printf("Z=%d\n",z);
    if(z==y||y>z){
        if(y>z){z=y;}
        return y ;
    }
    else {
        printf("Your steps now %d, few more steps to reach the goal...\n",y);
        printf("\nHow many steps did you walk now? "); scanf("%d",&n);
        return countSteps(z,y+n);
    }

}//end of recursion

void PlayAgain(int press){
    int n[SIZE]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n1,n2;
    int computer,player,choose,flag;
    size_t i;
    srand(time(NULL));

    while(press!=-1){
        flag=1;
        if(press==1){
            choose=1+rand()%2;
            printf("\t\tThe player who starts first:%d\n\n",choose);
            if(choose==1)
                player=1;
            else
                player=2;
            for(i=0;i<SIZE;i++){
                computer=1+rand()%2;
                if(i==19)
                    computer=1;
                printf("\n\t\t*Computer's decision:%d\n",computer);
                if((computer==1)&&(player==1)){
                    printf("%18c",' ');
                    printf("-First Player: "); scanf("%d",&n1);
                    if(n1==n[i]){
                        player=2;
                        continue;
                    }
                    else{
                        printf("%79s","GAMEOVER, you should play the game in sequence to win!\a\n");
                        flag=2;
                        break;
                    }
                }
                else if((computer==1)&&(player==2)){
                    printf("%18c",' ');
                    printf("-Second Player: %d \n",n[i]);
                    player=1;
                }
                if((computer==2)&&(player==1)){
                    printf("\t\t  -First Player: "); scanf("%d%d",&n1,&n2);
                    if((n1!=n[i])&&(n2!=n[i+1])){
                        printf("%79s","GAMEOVER, you should play the game in sequence to win!\a\n");
                        flag=2;
                        break;
                    }
                    else {
                        i++;
                        player=2;
                        continue;
                    }
                }
                else if((computer==2)&&(player==2)){
                    printf("\t\t  -Second Player: %d %d\n",n[i],n[i+1]);
                    i++;
                    player=1;
                }
            }

            if((player==1)&&(flag==1)){
                printf("\n\t\tOH,YOU LOST THE GAME :(!!\a\n");
            }
            else if((player==2)&&(flag==1)){
                printf("\n\t\tCONGRATULATIONS YOU WON THE GAME :)!!\a\n");
            }
        }//End if
        if((press!=1)&&(flag==1)){
            printf("%79s%70s","OH,SORRY THIS IS INCORRECT INPUT :(\n","LET'S TRY AGAIN:)!\n\n");
        }
        printf("\n%75s%79s","IF YOU WANT TO PLAY AGAIN ,, \n","ENTER 1 TO START ,, -1 TO END:)!\n");
        printf("%60c",' ');
        scanf("%d",&press);
    }//End while

    printf("%84s","THE GAME ENDED HOPE YOU HAVE A GREATE TIME<3\n");
}

