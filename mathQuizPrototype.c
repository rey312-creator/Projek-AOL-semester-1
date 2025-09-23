#include <stdio.h>
int num1;
int num2;
int num3;
int res; //correct result
int plRes; //player input result
int lvl = 1; //current level
int stg = 1; //current stage
int randop; //random operation 1-4 (1 = "+", 2 = "-", 1 = "*", 1 = "^")
int startAgain = 1; 
int lives = 3;
int score;

int main(){
    printf ("Welcome To Math Quiz!\n");
    while (startAgain == 1){ // check if player want to start again
        score = 0;  /* reset all score, lives and level*/
        lives = 3;
        lvl = 1;
        while (lvl<=3 && lives != 0){ //level loop
            stg = 1; //reset stage
            srand(time(0)); //generate rand seed base on current time
            printf ("Press any key to start level %d\n", lvl); 
            getchar(); //press key to start
            if (lvl == 1) { // restore and state live amount per level
                printf("you have 3 lives");
            } else {
                lives = 3;
                printf("you lives has been restored to 3");
            };
                while(stg <= 5 && lives != 0){ //stage loop
                    printf("stage %i\n", stg);
                    printf("lives = %d\n\n", lives);
                    genEquation();
                    printf ("enter the result\n");
                    scanf("%i", &plRes);
                    scoreTabulation();
            //lvl++;
            };
        };
        if (lives == 0){ // gameover
            printf("gameover!\n");
        } else { //win
            printf("you win!\n");
        };
        printf ("want to play again? (1/0)\n");
        scanf ("%d", &startAgain); //set 1 to play again and 0/other input for no
    };
    return 0;
};

void genEquation() { //generate equation
    switch (lvl){
        case 1: //lvl 1 equation
            num1 = rand()%11;
            num2 = rand()%11;
            randop = rand()%4;
            switch (randop){
                case 0:
                    printf("%i", num1);
                    printf("+%i\n", num2);
                    res = num1 + num2;
                    break;
                case 1:
                    printf("%i", num1);
                    printf("-%i\n", num2);
                    res = num1 - num2;
                    break;
                case 2:
                    printf("%i", num1);
                    printf("*%i\n", num2);
                    res = num1 * num2;
                    break;
                case 3:
                    printf("%i", num1);
                    printf("^2\n");
                    res = num1 * num1;
                    break;
            };
        //case 2:
    };     
};

void scoreTabulation(){ //check wrong right and calculate score accordingly
    int multiplier = 0;
    switch (lvl) {
        case 1:
             if (res == plRes){
                printf("correct!\n");
                stg++;
                multiplier++;
                score = (100 * multiplier) + score;
                printf("score +%d\n", 100 * multiplier);
                printf ("your current score is %d\n\n", score);
                break;
             } else {
                printf("wrong!\n");
                lives--;
                multiplier = 0;
                score = score - 100;
                printf("score -100");
                printf ("your current score is %d\n\n", score);
                break;
            };
        //case 2:
    };
};

