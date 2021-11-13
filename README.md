# Daily Routine Program 
A project for CS181 course, presented to Dr. Abeer Alhujaylan, the software development process of a Daily Routine Program .

## Project idea
The projectis based on team work, each group consists of 4 students each student will program a part then we integrated it  as one program, parts of project are :

### 1.Study Time:
   * Design a schedule that helps you to study for five hours a day. 

I use 2D array to store each course name in order to answer user queryes .

```c
 char s[7][6] = {
        {'C', 'M', 'P', 'I', 'A'},
        {'I', 'C', 'M', 'A', 'P'},
        {'A', 'P', 'C', 'I', 'M'},
        {'M', 'I', 'P', 'A', 'C'},
        {'P', 'C', 'M', 'P', 'I'},
        {'I', 'P', 'C', 'M', 'A'},
        {'C', 'M', 'P', 'A', 'I'}
    };
```

### 2.Sport time: 
   * A program that’s count your steps in your day,I implement this idea with a help of recursive function .

```c
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
```
### 3.Play time: 
   * After you finished your study and your daily exercise,Let's play the game: "Whoever reaches 20 first is a winner!"
   
  ### The rules of the game are as follows: 
  * The computer randomly determines who starts playing first. o The computer randomly determines whether you are allowed to use one or two 
numbers.
  * The player who reaches the number 20 is the winner .  
      ``
      The winner and is congratulated by typing “Congratulations! The first / second player is the winner!” then the game end.
      ``
      
      The game implemented by help of srand function which will generate numbers base on you current time & nested loop to decide the conditions of the game  :
      ```c
      srand(time(NULL));
      ```
      
      ```c
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
      ```
### 4.Creative time ( which my part of programming  )

   * I think of an idea for a program which is reminder and to do list that’s help us to plan our day and at the end we check what we have finished .

#### The concept of the program is :
* In each part of the code which represent a part of the day, I call the function reminder and send my_clock(currentTime) as an argument :
``` c
reminder(my_clock(4));
```
* Then base on the time send it's will decide which alarm will be alaret with a timer, timer done by help of recursion concept  :
```c
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
```
* At the end of program (which represent end of the day),function to_do_list() is called to ask user which task he have finished :

```c
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
```
``
Note: above to do list code done by help of Array of pointers instead of using 2D array which take more space in (Dynamic-1D consumes less memory than the 2D).
``
   
   ## Output Samples 
   
* ### OutPut1
https://user-images.githubusercontent.com/74800962/126849103-621b2e2c-d6e5-41fd-85af-4e171a2d2a35.mov



* ### OutPut2
https://user-images.githubusercontent.com/74800962/126848684-3ebee785-b3c9-43a1-a870-9f8d5ecb8af2.mov


   
   ### You can see the [paper](https://github.com/wesamhamad/CS/blob/main/Project_Paper.pdf) of project which contain more details. Also, you can [download](https://drive.google.com/u/0/uc?id=1byijDxjfOPzIRyQ_CL6Pqnbm2kAc5ksp&export=download) it.
   
