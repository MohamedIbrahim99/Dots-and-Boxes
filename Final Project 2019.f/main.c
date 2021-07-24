
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <ctype.h>
#include <time.h>

int deleteLine=0,m,n,maxLine,lineNumber,gameDiff,playerNum=1,remainingMoves,flag=0,score1=0,score2=0,GameMode,playsCounter=0,maxPlaysNumber,APlays=0,BPlays=0; clock_t gameTime,gameTimeStart;
int checkBoxEmpty[26]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
char playerOneName[257], playerTwoName[257]; errorLoading=0;
int plays[61] = {0};
char playsChar[64]={0};
char loadArray[64]={0};
int saveNumber,gameSave;
int redoArray[61] = {0};
int redoFlag = 0 , c = 0 ,hh=0;
int saveIndication=0,loadIndication=0; gotoMenu=0;
char rankScores[10]={0};
char rankNames[10][257];

//restart
void restart(){int i;
deleteLine=0;playerNum=1;errorLoading=0;score1=0;score2=0;playsCounter=0;APlays=0;BPlays=0;redoFlag = 0 ; hh=0;saveIndication=0;loadIndication=0; gotoMenu=0; flag=0;
for(i=0;i<26;i++){
    checkBoxEmpty[i]=i;
}
for(i=0;i<61;i++){
    plays[i]=0; redoArray[i]=0;
}
for(i=0;i<64;i++){
    playsChar[i]=0; loadArray[i]=0;
}
}


//split time
typedef struct{

int minutes;
int seconds;
}Time;


Time split_time(long long total_seconds){
    Time logic_time;
    logic_time.minutes=total_seconds/60; total_seconds%=60;
    logic_time.seconds=total_seconds;
    return logic_time;
}
//-------------------delay
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
//Loading-----------------------------
void load(int x){
int dead=1;
if(x==1){
FILE *p=fopen("save1.data","rb");
dead=fread(loadArray,sizeof(char),sizeof(loadArray),p);
fclose(p);
FILE *o=fopen("11.data","rb");
fread(playerOneName,sizeof(char),sizeof(loadArray),o);
fclose(o);
FILE *i=fopen("12.data","rb");
fread(playerTwoName,sizeof(char),sizeof(loadArray),i);
fclose(i);
}
else if(x==2){
  FILE *p=fopen("save2.data","rb");
dead=fread(loadArray,sizeof(char),sizeof(loadArray),p);
fclose(p);
FILE *o=fopen("21.data","rb");
fread(playerOneName,sizeof(char),sizeof(loadArray),o);
fclose(o);
FILE *i=fopen("22.data","rb");
fread(playerTwoName,sizeof(char),sizeof(loadArray),i);
fclose(i);
}else if(x==3){
FILE *p=fopen("save3.data","rb");
dead=fread(loadArray,sizeof(char),sizeof(loadArray),p);
fclose(p);
FILE *o=fopen("31.data","rb");
fread(playerOneName,sizeof(char),sizeof(loadArray),o);
fclose(o);
FILE *i=fopen("32.data","rb");
fread(playerTwoName,sizeof(char),sizeof(loadArray),i);
fclose(i);
}
gameDiff=(int)loadArray[62]; GameMode=(int)loadArray[63];
if(dead==0){
    errorLoading=1;
}
}


//Saving------------------------------
void save(){
int x;
clr();
printf("\n\n\n\n\n\t\t\t\t1--->Save 1\n\t\t\t\t2--->Save 2\n\t\t\t\t3--->Save 3");
printf("\n\n\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");
scanf("%d",&x);
clr();
if(x==1){
FILE *p=fopen("save1.data","wb");
fwrite(playsChar,sizeof(char),sizeof(playsChar),p);
fclose(p);
FILE *pt1=fopen("11.data","wb");
fwrite(playerOneName,sizeof(char),sizeof(playerOneName),pt1);
fclose(pt1);
FILE *pt2=fopen("12.data","wb");
fwrite(playerTwoName,sizeof(char),sizeof(playerTwoName),pt2);
fclose(pt2); saveIndication=1;
}else if(x==2){
FILE *p=fopen("save2.data","wb");
fwrite(playsChar,sizeof(char),sizeof(playsChar),p);
fclose(p);
FILE *pt1=fopen("21.data","wb");
fwrite(playerOneName,sizeof(char),sizeof(playerOneName),pt1);
fclose(pt1);
FILE *pt2=fopen("22.data","wb");
fwrite(playerTwoName,sizeof(char),sizeof(playerTwoName),pt2);
fclose(pt2);saveIndication=1;
}else if(x==3){
FILE *p=fopen("save3.data","wb");
fwrite(playsChar,sizeof(char),sizeof(playsChar),p);
fclose(p);
FILE *pt1=fopen("31.data","wb");
fwrite(playerOneName,sizeof(char),sizeof(playerOneName),pt1);
fclose(pt1);
FILE *pt2=fopen("32.data","wb");
fwrite(playerTwoName,sizeof(char),sizeof(playerTwoName),pt2);
fclose(pt2);saveIndication=1;
}
}


//game_action
//game_action
void action(int check[],int grid[m][n],int color[m][n],int ser[m][n],int copyGrid[m][n]){

while(playsCounter<maxPlaysNumber){
if(gotoMenu==1){
   clr(); break;
}
   if(saveIndication==1){
   play:
   shape_printer(grid,color);
   saveIndication=0;
   }
   if(playerNum==1){
    SetColor(12);
    printf("\n\n\n\n%s turn:  ",playerOneName);
    while(playerNum==1){
    if(flag==1){
        SetColor(12);
        printf("\n\n\n\n%s turn again:  ",playerOneName);
    }flag=0;playy1:
    if(loadIndication==0){
    char str[999];
    scanf("%s",str); fflush(stdin);
    char *ptr;
    lineNumber = strtol(str, &ptr, 10);}
    else if(loadIndication==1){
        if((int)loadArray[hh]==0){loadIndication=0; goto playy1;}
        lineNumber=(int)loadArray[hh];hh++;
    }
    if(lineNumber==400){
       gotoMenu=1; break;
    }
    if(lineNumber==300){
        save();
        goto play;
    }
    if(lineNumber==100){
        undo(check,grid,color,ser);clr();
        shape_printer(grid,color);
        SetColor(12);
        printf("\n\n\n\n%s turn:  ",playerOneName);
    }
    else{
    if (lineNumber == 200){
        redoAgain2:
        lineNumber = redo();
    }
    if(lineNumber<(maxLine+1)&&lineNumber>0){

            if(check[lineNumber]!=lineNumber){
                goto again1;
            }
            else if(check[lineNumber]==lineNumber){
             check[lineNumber]=0;
             plays[playsCounter]=lineNumber ;
             playsChar[playsCounter]=lineNumber ;
             prepare(check,grid,color,ser,copyGrid,deleteLine); clr();
             playsCounter++;
    // In Redo Case
            if (redoFlag == 1){
                playerNum=playerNum*-1;
                if (GameMode==1){
                    goto redoAgain1 ;
                }else {
                    goto redoAgain3 ;
                }
            } //

             shape_printer(grid,color);
             if(playsCounter==maxPlaysNumber){
                break;
            }
             playerNum=playerNum*-1;
            }else{}
    }
    else{
        again1:
        clr();
        shape_printer(grid,color);
        printf("\n\n\n\n");
        SetColor(12);
        printf("Enter a valid line number\n");
        printf("%s turn: ",playerOneName);
        continue;
    }
    }}
    }else if (playerNum==-1){
        if(GameMode==1){
    SetColor(9);
    printf("\n\n\n\n%s turn:  ",playerTwoName);
    /// ---------------player 2 stuff
    while(playerNum==-1){
    if(flag==1){
        SetColor(9);
        printf("\n\n\n\n%s turn again:  ",playerTwoName);
    }flag=0;
       playy2:
    if(loadIndication==0){
    char str[999];
    scanf("%s",str);fflush(stdin);
    char *ptr;
    lineNumber = strtol(str, &ptr, 10);}
    else if(loadIndication==1){
        if((int)loadArray[hh]==0){loadIndication=0; goto playy2;}
        lineNumber=(int)loadArray[hh];hh++;
    }
    if(lineNumber==400){
       gotoMenu=1; break;
    }
    if(lineNumber==300){
        save();
        goto play;
    }
    if(lineNumber==100){
        undo(check,grid,color,ser);clr();
        shape_printer(grid,color);
        SetColor(9);
        printf("\n\n\n\n%s turn again:  ",playerTwoName);
    }else{
    if (lineNumber == 200){
        redoAgain1:
        lineNumber = redo();
    }
    if(lineNumber<maxLine&&lineNumber>0){
            if(check[lineNumber]!=lineNumber){
                goto again2;
            }
            else if(check[lineNumber]==lineNumber){

             check[lineNumber]=0;
             plays[playsCounter]=lineNumber ;
              playsChar[playsCounter]=lineNumber ;
             prepare(check,grid,color,ser,copyGrid,deleteLine);
            playsCounter++;

        // In Redo Case
            if (redoFlag == 1){
                playerNum=playerNum*-1;
                goto redoAgain2;
            } //

             clr();
             shape_printer(grid,color);
             if(playsCounter==maxPlaysNumber){
                break;
              }
             playerNum=playerNum*-1;
            }else{}
    }
    else{
        again2:
        clr();
        shape_printer(grid,color);
        printf("\n\n\n\n");
        SetColor(9);
        printf("Enter a valid line number\n");
        printf("%s turn: ",playerTwoName);
        continue;
    }
    }}

}
else if(GameMode==2){
    while(playerNum==-1){
    playy3:
    if(loadIndication==0){
    lineNumber=computerGameAI(check);
    // In Redo case
    if (redoFlag==1){
        redoAgain3:
        lineNumber = redo();
    }//

    }
       else if(loadIndication==1){
        if((int)loadArray[hh]==0){loadIndication=0; goto playy3;}
        lineNumber=(int)loadArray[hh];hh++;
    }
    if(lineNumber<maxLine&&lineNumber>0){
            if(check[lineNumber]!=lineNumber){
                goto again3;
            }
            else if(check[lineNumber]==lineNumber){

             check[lineNumber]=0;
             plays[playsCounter]=lineNumber ;
             playsChar[playsCounter]=lineNumber ;
             prepare(check,grid,color,ser,copyGrid,deleteLine); clr();

             playsCounter++;
             shape_printer(grid,color);
             if(playsCounter==maxPlaysNumber){
                break;
              }
             playerNum=playerNum*-1;
            }else{}
    }
    else{
        again3:

        continue;
    }
    }flag=0;
}
}
}
}

//Undo function
    void undo(int check[],int grid[m][n],int color[m][n],int ser[m][n],int copyGrid[m][n])
    {
        int i ;
        int numlineUndo ;
    if (plays[0] != 0){
        for (i = 60 ; i >= 0 ; i--){
            if(plays[i] != 0){
                lineNumber = plays[i] ;
                break ;
            }
        }
        deleteLine = 1 ;
        prepare(check,grid,color,ser,copyGrid,deleteLine);
        check[lineNumber] = lineNumber ;
        numlineUndo = 1 ;
        undoCheckBox(check,grid,numlineUndo) ;
        redoArray[i] = lineNumber ;

    // To Edit the 10 printing
        if(lineNumber==10 && gameDiff ==1){
            grid[9][19]=49;
        }

    // Undo till the last user play When you play with computer if there is odd computer plays
        if (GameMode == 2 && playerNum == -1 && c == 1){
            c=0;
            plays[i] = 0 ;
            deleteLine = 0 ;
            playsCounter -= 1 ;
            if(playerNum==1){
                APlays-= 1 ;
                BPlays-- ;
            }
            else{
                APlays-- ;
                BPlays-= 1 ;
            }
            playerNum=playerNum*-1;
            return ;
        }

    // If there is only first move
       if (plays[0] != 0 && plays[1] == 0){
            plays[i] = 0 ;
            deleteLine = 0 ;
            playsCounter -= 1 ;
            if(playerNum==1){
                APlays-= 1 ;
                BPlays-- ;
            }
            else{
                APlays-- ;
                BPlays-= 1 ;
            }
            playerNum=playerNum*-1;
        }
        else{
            lineNumber = plays[i-1] ;
            prepare(check,grid,color,ser,copyGrid,deleteLine);
            check[lineNumber] = lineNumber ;
            numlineUndo = 2 ;
            undoCheckBox(check,grid,numlineUndo) ;
            redoArray[i-1] = lineNumber ;

    // To Edit the 10 printing
            if(lineNumber==10 && gameDiff ==1){
            grid[9][19]=49;
            } //

            plays[i] = 0 ;
            plays[i-1] = 0 ;
            deleteLine = 0 ;
            playsCounter -= 2 ;
            if(playerNum==1){
                APlays-= 3 ;
                BPlays-- ;
            }
            else{
                APlays-- ;
                BPlays-= 3 ;
            }
        }

// Undo till the last user play When you play with computer if there is even computer plays and send a flag to odd condition
        if (GameMode == 2 && playerNum == -1){
            c=1;
            undo(check,grid,color,ser,copyGrid);
        }
    }
    }

    //Redo function
    int redo()
    {
        int i ;
        for (i = 0 ; i <= 60 ; i++){
            if(redoArray[i] != 0){
                lineNumber = redoArray[i];
                break;
            }
        }
        redoArray[i] = 0;
        if (redoFlag == 0){
            redoFlag = 1 ;
        }
        else if (redoFlag == 1) {
            redoFlag = 0 ;
        }
    // If the only redo move is the first move
       if (plays[0] == 0 && redoArray[1] == 0 ){
            redoFlag = 0 ;
       }

        return lineNumber ;
    }


// Computer Game AI
    int computerGameAI(int check[])
    {
    int i =1;
    if(gameDiff == 2){
        while (i <= 49){
            if (check[i]==0&&check[i+5]==0&&check[i+6]==0&&check[i+11]!=0){
                lineNumber = check[i+11] ;
                break ;
            }
            else if (check[i]==0&&check[i+5]==0&&check[i+11]==0&&check[i+6]!=0){
                lineNumber = check[i+6] ;
                break ;
            }
            else if (check[i]==0&&check[i+6]==0&&check[i+11]==0&&check[i+5]!=0){
                lineNumber = check[i+5] ;
                break ;
            }
            else if (check[i+5]==0&&check[i+6]==0&&check[i+11]==0&&check[i]!=0){
                lineNumber = check[i] ;
                break ;
            }
            else {
                    lineNumber = (rand()%maxLine)+1;
            }
            i++ ;
           if (i==6 || i==17 || i==28 || i==39 ){
            i += 6 ;
           }
        }
    }
    else if (gameDiff == 1){
            while (i <= 7){
            if (check[i]==0&&check[i+2]==0&&check[i+3]==0&&check[i+5]==i+5){
                lineNumber = check[i+5] ;
                break ;
            }
            else if (check[i]==0&&check[i+2]==0&&check[i+5]==0&&check[i+3]==i+3){
                lineNumber = check[i+3] ;
                break ;
            }
            else if (check[i]==0&&check[i+3]==0&&check[i+5]==0&&check[i+2]==i+2){
                lineNumber = check[i+2] ;
                break ;
            }
            else if (check[i+2]==0&&check[i+3]==0&&check[i+5]==0&&check[i]==i){
                lineNumber = check[i] ;
                break ;
            }
            else {
                    lineNumber = (rand()%maxLine)+1;
            }
            i++ ;
           if (i==3){
            i += 3 ;
           }
        }
    }
        return lineNumber ;
    }


//player num check to close a box
void closeBox(int i,int j,int grid[m][n],int color[m][n]){
if(playerNum==1){
    color[i][j]=12;
    grid[i][j]=65;
    flag=1;score1++;

}else{
    color[i][j]=9;
    grid[i][j]=66;
    flag=1;score2++;
}

}
//check blockBox
int checkBlock(int i){
int x;
if(checkBoxEmpty[i]==i){
    x=1; checkBoxEmpty[i]=0;
}else{
x=0;
}
return x;
}

//check box 2x2,5x5
void checkBox(int check[],int grid[m][n],int color[m][n]){
int x; int b = 0 ;
switch (gameDiff){
    case 1:
if(check[1]==0&&check[3]==0&&check[4]==0&&check[6]==0){
    x=checkBlock(1);
    if(x==1){
    closeBox(3,5,grid,color);b = 1;
    }else{}
}
if(check[2]==0&&check[4]==0&&check[5]==0&&check[7]==0){
   x=checkBlock(2);
    if(x==1){
    closeBox(3,15,grid,color);b = 1;
    }else{}
}
if(check[6]==0&&check[8]==0&&check[9]==0&&check[11]==0){
   x=checkBlock(3);
    if(x==1){
    closeBox(9,5,grid,color);b = 1;
    }else{}
}
if(check[7]==0&&check[9]==0&&check[10]==0&&check[12]==0){
   x=checkBlock(4);
    if(x==1){
    closeBox(9,15,grid,color);b = 1;
    }else{}
}break;
case 2:
if(check[1]==0&&check[6]==0&&check[7]==0&&check[12]==0){
    x=checkBlock(1);
    if(x==1){
    closeBox(3,5,grid,color);b = 1;
    }else{}

}
if(check[2]==0&&check[8]==0&&check[13]==0&&check[7]==0){
    x=checkBlock(2);
    if(x==1){
    closeBox(3,15,grid,color);b = 1;
    }else{}
}
if(check[3]==0&&check[8]==0&&check[9]==0&&check[14]==0){
    x=checkBlock(3);
    if(x==1){
    closeBox(3,25,grid,color);b = 1;
    }else{}
}
if(check[4]==0&&check[9]==0&&check[10]==0&&check[15]==0){
    x=checkBlock(4);
    if(x==1){
    closeBox(3,35,grid,color);b = 1;
    }else{}
}
if(check[5]==0&&check[10]==0&&check[11]==0&&check[16]==0){
    x=checkBlock(5);
    if(x==1){
    closeBox(3,45,grid,color);b = 1;
    }else{}
}
if(check[12]==0&&check[17]==0&&check[18]==0&&check[23]==0){
    x=checkBlock(6);
    if(x==1){
    closeBox(9,5,grid,color);b = 1;
    }else{}
}
if(check[13]==0&&check[18]==0&&check[19]==0&&check[24]==0){
    x=checkBlock(7);
    if(x==1){
    closeBox(9,15,grid,color);b = 1;
    }else{}
}
if(check[14]==0&&check[19]==0&&check[20]==0&&check[25]==0){
    x=checkBlock(8);
    if(x==1){
    closeBox(9,25,grid,color);b = 1;
    }else{}
}
if(check[15]==0&&check[20]==0&&check[21]==0&&check[26]==0){
    x=checkBlock(9);
    if(x==1){
    closeBox(9,35,grid,color);b = 1;
    }else{}
}
if(check[16]==0&&check[21]==0&&check[22]==0&&check[27]==0){
    x=checkBlock(10);
    if(x==1){
    closeBox(9,45,grid,color);b = 1;
    }else{}
}
if(check[23]==0&&check[28]==0&&check[29]==0&&check[34]==0){
    x=checkBlock(11);
    if(x==1){
    closeBox(15,5,grid,color);b = 1;
    }else{}
}
if(check[24]==0&&check[29]==0&&check[30]==0&&check[35]==0){
    x=checkBlock(12);
    if(x==1){
    closeBox(15,15,grid,color);b = 1;
    }else{}
}
if(check[25]==0&&check[30]==0&&check[31]==0&&check[36]==0){
    x=checkBlock(13);
    if(x==1){
    closeBox(15,25,grid,color);b = 1;
    }else{}
}
if(check[26]==0&&check[31]==0&&check[32]==0&&check[37]==0){
    x=checkBlock(14);
    if(x==1){
    closeBox(15,35,grid,color);b = 1;
    }else{}
}
if(check[27]==0&&check[32]==0&&check[33]==0&&check[38]==0){
    x=checkBlock(15);
    if(x==1){
    closeBox(15,45,grid,color);b = 1;
    }else{}
}
if(check[34]==0&&check[39]==0&&check[40]==0&&check[45]==0){
    x=checkBlock(16);
    if(x==1){
    closeBox(21,5,grid,color);b = 1;
    }else{}
}
if(check[35]==0&&check[40]==0&&check[41]==0&&check[46]==0){
    x=checkBlock(17);
    if(x==1){
    closeBox(21,15,grid,color);b = 1;
    }else{}
}
if(check[36]==0&&check[41]==0&&check[42]==0&&check[47]==0){
    x=checkBlock(18);
    if(x==1){
    closeBox(21,25,grid,color);b = 1;
    }else{}
}
if(check[37]==0&&check[42]==0&&check[43]==0&&check[48]==0){
    x=checkBlock(19);
    if(x==1){
    closeBox(21,35,grid,color);b = 1;
    }else{}
}
if(check[38]==0&&check[43]==0&&check[44]==0&&check[49]==0){
    x=checkBlock(20);
    if(x==1){
    closeBox(21,45,grid,color);b = 1;
    }else{}
}
if(check[45]==0&&check[50]==0&&check[51]==0&&check[56]==0){
    x=checkBlock(21);
    if(x==1){
    closeBox(27,5,grid,color);b = 1;
    }else{}
}
if(check[46]==0&&check[51]==0&&check[52]==0&&check[57]==0){
    x=checkBlock(22);
    if(x==1){
    closeBox(27,15,grid,color);b = 1;
    }else{}
}
if(check[47]==0&&check[52]==0&&check[53]==0&&check[58]==0){
    x=checkBlock(23);
    if(x==1){
    closeBox(27,25,grid,color);b = 1;
    }else{}
}
if(check[48]==0&&check[53]==0&&check[54]==0&&check[59]==0){
    x=checkBlock(24);
    if(x==1){
    closeBox(27,35,grid,color);b = 1;
    }else{}
}
if(check[49]==0&&check[54]==0&&check[55]==0&&check[60]==0){
    x=checkBlock(25);
    if(x==1){
    closeBox(27,45,grid,color);b = 1;
    }else{}
}break;
}
if(b!=0){
    playerNum*=-1;
}
}

    //Open a box and edit the score in undo case
void undoBox(int i,int j,int grid[m][n])
{
    if(grid[i][j]==65){
        score1-- ;
    }
    else if (grid[i][j]==66){
        score2--;
    }

    grid[i][j]=32 ;
}

//Check if a box is empty or not
int undoCheckBlock(int i){
    int x;
if(checkBoxEmpty[i]==0){
    x=1; checkBoxEmpty[i]=i;
}else{
x=0;
}
return x;
}

//Undo the closed box
void undoCheckBox(int check[],int grid[m][n],int lineUndo)
{
int x; int b = 0 ;
switch (gameDiff){
    case 1:
if(check[1]!=0||check[3]!=0||check[4]!=0||check[6]!=0){
    x=undoCheckBlock(1);
    if(x==1){
    undoBox(3,5,grid);b = 1;
    }else{}
}
if(check[2]!=0||check[4]!=0||check[5]!=0||check[7]!=0){
   x=undoCheckBlock(2);
    if(x==1){
    undoBox(3,15,grid);b = 1;
    }else{}
}
if(check[6]!=0||check[8]!=0||check[9]!=0||check[11]!=0){
   x=undoCheckBlock(3);
    if(x==1){
    undoBox(9,5,grid);b = 1;
    }else{}
}
if(check[7]!=0||check[9]!=0||check[10]!=0||check[12]!=0){
   x=undoCheckBlock(4);
    if(x==1){
    undoBox(9,15,grid);b = 1;
    }else{}
}break;
case 2:
if(check[1]!=0||check[6]!=0||check[7]!=0||check[12]!=0){
    x=undoCheckBlock(1);
    if(x==1){
    undoBox(3,5,grid);b = 1;
    }else{}

}
if(check[2]!=0||check[8]!=0||check[13]!=0||check[7]!=0){
    x=undoCheckBlock(2);
    if(x==1){
    undoBox(3,15,grid);b = 1;
    }else{}
}
if(check[3]!=0||check[8]!=0||check[9]!=0||check[14]!=0){
    x=undoCheckBlock(3);
    if(x==1){
    undoBox(3,25,grid);b = 1;
    }else{}
}
if(check[4]!=0||check[9]!=0||check[10]!=0||check[15]!=0){
    x=undoCheckBlock(4);
    if(x==1){
    undoBox(3,35,grid);b = 1;
    }else{}
}
if(check[5]!=0||check[10]!=0||check[11]!=0||check[16]!=0){
    x=undoCheckBlock(5);
    if(x==1){
    undoBox(3,45,grid);b = 1;
    }else{}
}
if(check[12]!=0||check[17]!=0||check[18]!=0||check[23]!=0){
    x=undoCheckBlock(6);
    if(x==1){
    undoBox(9,5,grid);b = 1;
    }else{}
}
if(check[13]!=0||check[18]!=0||check[19]!=0||check[24]!=0){
    x=undoCheckBlock(7);
    if(x==1){
    undoBox(9,15,grid);b = 1;
    }else{}
}
if(check[14]!=0||check[19]!=0||check[20]!=0||check[25]!=0){
    x=undoCheckBlock(8);
    if(x==1){
    undoBox(9,25,grid);b = 1;
    }else{}
}
if(check[15]!=0||check[20]!=0||check[21]!=0||check[26]!=0){
    x=undoCheckBlock(9);
    if(x==1){
    undoBox(9,35,grid);b = 1;
    }else{}
}
if(check[16]!=0||check[21]!=0||check[22]!=0||check[27]!=0){
    x=undoCheckBlock(10);
    if(x==1){
    undoBox(9,45,grid);b = 1;
    }else{}
}
if(check[23]!=0||check[28]!=0||check[29]!=0||check[34]!=0){
    x=undoCheckBlock(11);
    if(x==1){
    undoBox(15,5,grid);b = 1;
    }else{}
}
if(check[24]!=0||check[29]!=0||check[30]!=0||check[35]!=0){
    x=undoCheckBlock(12);
    if(x==1){
    undoBox(15,15,grid);b = 1;
    }else{}
}
if(check[25]!=0||check[30]!=0||check[31]!=0||check[36]!=0){
    x=undoCheckBlock(13);
    if(x==1){
    undoBox(15,25,grid);b = 1;
    }else{}
}
if(check[26]!=0||check[31]!=0||check[32]!=0||check[37]!=0){
    x=undoCheckBlock(14);
    if(x==1){
    undoBox(15,35,grid);b = 1;
    }else{}
}
if(check[27]!=0||check[32]!=0||check[33]!=0||check[38]!=0){
    x=undoCheckBlock(15);
    if(x==1){
    undoBox(15,45,grid);b = 1;
    }else{}
}
if(check[34]!=0||check[39]!=0||check[40]!=0||check[45]!=0){
    x=undoCheckBlock(16);
    if(x==1){
    undoBox(21,5,grid);b = 1;
    }else{}
}
if(check[35]!=0||check[40]!=0||check[41]!=0||check[46]!=0){
    x=undoCheckBlock(17);
    if(x==1){
    undoBox(21,15,grid);b = 1;
    }else{}
}
if(check[36]!=0||check[41]!=0||check[42]!=0||check[47]!=0){
    x=undoCheckBlock(18);
    if(x==1){
    undoBox(21,25,grid);b = 1;
    }else{}
}
if(check[37]!=0||check[42]!=0||check[43]!=0||check[48]!=0){
    x=undoCheckBlock(19);
    if(x==1){
    undoBox(21,35,grid);b = 1;
    }else{}
}
if(check[38]!=0||check[43]!=0||check[44]!=0||check[49]!=0){
    x=undoCheckBlock(20);
    if(x==1){
    undoBox(21,45,grid);b = 1;
    }else{}
}
if(check[45]!=0||check[50]!=0||check[51]!=0||check[56]!=0){
    x=undoCheckBlock(21);
    if(x==1){
    undoBox(27,5,grid);b = 1;
    }else{}
}
if(check[46]!=0||check[51]!=0||check[52]!=0||check[57]!=0){
    x=undoCheckBlock(22);
    if(x==1){
    undoBox(27,15,grid);b = 1;
    }else{}
}
if(check[47]!=0||check[52]!=0||check[53]!=0||check[58]!=0){
    x=undoCheckBlock(23);
    if(x==1){
    undoBox(27,25,grid);b = 1;
    }else{}
}
if(check[48]!=0||check[53]!=0||check[54]!=0||check[59]!=0){
    x=undoCheckBlock(24);
    if(x==1){
    undoBox(27,35,grid);b = 1;
    }else{}
}
if(check[49]!=0||check[54]!=0||check[55]!=0||check[60]!=0){
    x=undoCheckBlock(25);
    if(x==1){
    undoBox(27,45,grid);b = 1;
    }else{}
}break;
}
    // if the undo line was closing a box
if (b == 1){
    playerNum*=-1;
    if(playerNum==1){
        APlays++ ;
        BPlays-- ;
    }
    else{
        APlays--;
        BPlays++ ;
    }
}
}


//-----------print tabs to center the game
void taper(){
 printf("\t\t\t\t\t\t");
}
//-----------print grid of games with colors
void shape_printer(int grid[m][n],int color[m][n]){

     int i,j;
     SetColor(14);
     printf("\n\t\t100 --> Undo | 200 --> Redo(if available) | 300 --> Save | 400 --> Main menu");
     SetColor(10);
     printf("\n\n\t\t\t\t\t\t\t     Min Sec");
     SetColor(12);
     printf("\n\t\t\t%s score: %d",playerOneName,score1);
     SetColor(10);
     Time dispTime=split_time(gameTime/1000);
     printf("\t\tTime Passed: %0.2d : %0.2d",dispTime.minutes,dispTime.seconds);
     SetColor(9);
     printf("\t\t%s score: %d",playerTwoName,score2);
     SetColor(12);
     printf("\n\t\t\tNumber of moves: %d",APlays);
    SetColor(9);
     printf("\t\t\t\t\tNumber of moves: %d",BPlays);
     printf("\n\n\n");
     taper();
     for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            SetColor(color[i][j]);
            printf("%c",grid[i][j]);
        }
        printf("\n");
        taper();
     }
     SetColor(10);
     printf("\n\t\t\t\t\t\t\t\t\t\tNumber of remaining lines: %d",maxPlaysNumber-(BPlays+APlays));


}
//function to draw a horiz line.....to be continued
void drawLine(int a,int b,int check[],int grid[m][n],int color[m][n],int copyGrid[m][n],int deleteLine){
if (deleteLine == 1){
    grid[a][b] = copyGrid[a][b];
    color[a][b]= 15;
}
else {
grid[a][b]=254;
if(playerNum==1){
    color[a][b]=12;
}else{
    color[a][b]=9;
}
gameTime=clock()-gameTimeStart;
}
}
//---------------draw vertical line
void drawLine1(int a,int b,int check[],int grid[m][n],int color[m][n],int copyGrid[m][n],int deleteLine){
if (deleteLine == 1){
    grid[a][b] = copyGrid[a][b];
    color[a][b]= 15;
}
else {
grid[a][b]=219;
if(playerNum==1){
    color[a][b]=12;
}else{
    color[a][b]=9;
}
gameTime=clock()-gameTimeStart;
}
}
//prepare function
void prepare(int check[],int grid[m][n],int color[m][n],int ser[m][n],int copyGrid[m][n]){
int i,j,k;

    switch (gameDiff){
        case 1 :
        if(lineNumber==10){
            grid[9][19]=32;
        }
    if (lineNumber==1 || lineNumber==2 || lineNumber==6 || lineNumber==7 || lineNumber==11 || lineNumber==12){
        for (i = 0 ; i < 13 ; i += 6 ){
            for (j = 1 ; j < 12 ; j +=10){
                if (ser[i][j] == lineNumber){
                    for(k = j ; k < j+9 ;k++){
                        drawLine(i,k,check,grid,color,copyGrid,deleteLine) ;
                    }
                }
            }
        }
    }
   else if (lineNumber==3 || lineNumber==4 || lineNumber==5 || lineNumber==8 || lineNumber==9 || lineNumber==10){
   for(j=0;j<21;j+=10){
    for(i=1;i<8;i+=6){
        if(ser[i][j]==lineNumber){
        for(k=i;k<i+5;k++){
            drawLine1(k,j,check,grid,color,copyGrid,deleteLine);
        }break;}
    }
   }

    }
    break ;
       case 2 :

           if (lineNumber==1 || lineNumber==2 || lineNumber==3 || lineNumber==4 || lineNumber==5 || lineNumber==12 || lineNumber==13 || lineNumber==14 || lineNumber==15 || lineNumber==16 || lineNumber==23 || lineNumber==24 || lineNumber==25 || lineNumber==26 || lineNumber==27 || lineNumber==34 || lineNumber==35 || lineNumber==36 || lineNumber==37 || lineNumber==38 || lineNumber==45 || lineNumber==46 || lineNumber==47 || lineNumber==48 || lineNumber==49 || lineNumber==56 || lineNumber==57 || lineNumber==58 || lineNumber==59 || lineNumber==60){
        for (i = 0 ; i <= 30 ; i += 6 ){
            for (j = 1 ; j <= 50 ; j +=10){
                if (ser[i][j] == lineNumber){
                    for(k = j ; k <= j+8 ;k++){
                        drawLine(i,k,check,grid,color,copyGrid,deleteLine) ;
                    }
                }
            }
        }
           }


           else if(lineNumber==6||lineNumber==7||lineNumber==8||lineNumber==9||lineNumber==10||lineNumber==11||lineNumber==17||lineNumber==18||lineNumber==19||lineNumber==20||lineNumber==21||lineNumber==22||lineNumber==28||lineNumber==29||lineNumber==30||lineNumber==31||lineNumber==32||lineNumber==33||lineNumber==39||lineNumber==40||lineNumber==41||lineNumber==42||lineNumber==43||lineNumber==44||lineNumber==50||lineNumber==51||lineNumber==52||lineNumber==53||lineNumber==54||lineNumber==55){
            for(j=0;j<51;j+=10){
             for(i=1;i<31;i+=6){
              if(ser[i][j]==lineNumber){
               for(k=i;k<i+5;k++){
                 drawLine1(k,j,check,grid,color,copyGrid,deleteLine);
              }break;}
    }
   }
           }
    break;
    }

    if(playerNum==1){
    APlays++;
    }else{BPlays++;}

checkBox(check,grid,color);




}
//Function to change text color
void SetColor(int ForgC)
{
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forground     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
//-------------------------------------------
void clr()
{
    system("@cls||clear");
}
//------------------------------------------
void swps(int i){char temp[257];char tempp;
strcpy(temp,rankNames[i]);  tempp=rankScores[i];
for(int k=i+1;k<10;k++){
    strcpy(rankNames[k-1],rankNames[k]); rankScores[k-1]=rankScores[k];
}strcpy(rankNames[9],temp); rankScores[9]=tempp;
}


void swp(int i,int j,int pnum){char temp[257];
int tempi=i+1,tempj=j; if(pnum==1){strcpy(rankNames[9],playerOneName);}else{strcpy(rankNames[9],playerTwoName);}
while(i<j){
   strcpy(temp,rankNames[i]);strcpy(rankNames[i],rankNames[j]);strcpy(rankNames[j],temp);
   i++;j--;
}while(tempi<tempj){
strcpy(temp,rankNames[tempi]);strcpy(rankNames[tempi],rankNames[tempj]);strcpy(rankNames[tempj],temp);
   tempi++;tempj--;
}
}
void swpn(int i,int j, int pnum){
char temp;
int tempi=i+1,tempj=j; if(pnum==1){rankScores[9]=score1;}else{rankScores[9]=score2;}
while(i<j){
    temp=rankScores[i]; rankScores[i]=rankScores[j]; rankScores[j]=temp;
    i++; j--;
}while((tempi)<tempj){
         temp=rankScores[tempi]; rankScores[tempi]=rankScores[tempj]; rankScores[tempj]=temp;
         tempi++; tempj--;
}
}

//-------------------------------------------
int main(){
//---------------------------


//----------------------------------intro
SetColor(10);
for(int s=0;s<=100;s+=5){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading ------- %d %%",s);
    clr();
}
SetColor(14);
for (int uu=0 ; uu <2;uu++){
printf("\n\n\n\n\n\n");
printf(" __          __  _\n");
printf(" \\ \\        / / | |\n");
printf("  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___\n");
printf("   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\\n");
printf("    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ \n");
printf("  _  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|        _   ____ \n");
printf(" | |        |  __ \\      | |                       | | |  _ \\ \n");
printf(" | |_ ___   | |  | | ___ | |_ ___    __ _ _ __   __| | | |_) | _____  _____  ___ \n");
printf(" | __/ _ \\  | |  | |/ _ \\| __/ __|  / _` | '_ \\ / _` | |  _ < / _ \\ \\/ / _ \\/ __|\n");
printf(" | || (_) | | |__| | (_) | |_\\__ \\ | (_| | | | | (_| | | |_) | (_) >  <  __/\\__ \\\n");
printf("  \\\__\\___/  |_____/ \\___/ \\__|___/  \\__,_|_| |_|\\__,_| |____/ \\___/_/\\_\\___||___/\n");
delay(1);
clr();
delay(1);
}


int lol=0;
menu: restart();

int testRank=1;
FILE *rk=fopen("scores.data","rb");
testRank=fread(rankScores,sizeof(char),sizeof(rankScores),rk);
fclose(rk);
if(testRank==0){
FILE *rk1=fopen("scores.data","wb");
fwrite(rankScores,sizeof(char),sizeof(rankScores),rk1);
fclose(rk1);
FILE *rk2=fopen("names.data","wb");
fwrite(rankNames,sizeof(char),sizeof(rankNames),rk2);
fclose(rk2);
}else{
FILE *io=fopen("names.data","rb");
fread(rankNames,sizeof(char),sizeof(rankNames),io);
fclose(io);
}


srand(time(0));
int mainMenu;
//--------Designing main menu
gameDDD:
clr();
SetColor(14);
printf("\t\t\t\t\t\t|----------------------|");
printf("\n\t\t\t\t\t\t|");
SetColor(10);
printf("Welcome to our project");
SetColor(14);
printf("|\n\t\t\t\t\t\t|----------------------|");
printf("\n\n\n\t\t\t\t\t\t 1---> Start game"); printf("\n\n\n\t\t\t\t\t\t 2---> Load game"); printf("\n\n\n\t\t\t\t\t\t 3---> Top 10 players"); printf("\n\n\n\t\t\t\t\t\t 4---> How to play"); printf("\n\n\n\t\t\t\t\t\t 5---> Exit");
if(lol==1){
    printf("\n\n\n\nPlease Choose a valid choice");lol=0;}
else if(lol==0){
    printf("\n\n\n\n");
}
printf("\n>>>>>>>>>>>>>>>>  ");
char strrrr[999];
    scanf("%s",strrrr); fflush(stdin);
    char *ptrrr;
    mainMenu = strtol(strrrr, &ptrrr, 10);
    if(mainMenu!=1&&mainMenu!=2&&mainMenu!=3&&mainMenu!=4&&mainMenu!=5){
     lol=1; goto gameDDD;
    }

   int i,j;


//----------------------
switch (mainMenu){
case 1:
    gameD:
    clr();
    printf("\n\n\n\t\t\t\t\t\t 1------> Beginner");
    printf("\n\t\t\t\t\t\t 2------> Expert");
    printf("\n\n\t\t\t\t\t\t 3------> Back");
    if(lol==1){
    printf("\n\n\n\nPlease Choose a valid choice");lol=0;}
    else if(lol==0){
            printf("\n\n\n\n");
    }
    printf("\n>>>>>>>>>>>>>>>>>>>> ");
    char strr[999];
    scanf("%s",strr); fflush(stdin);
    char *ptr;
    gameDiff = strtol(strr, &ptr, 10);
    if(gameDiff!=1&&gameDiff!=2&&gameDiff!=3){
     lol=1; goto gameD;
    }
    if(gameDiff==3){
        goto menu;
    }
    playsChar[62]=gameDiff;
    gameDM:
    clr();
    printf("\n\n\n\t\t\t\t\t\t 1------> Human VS Human");
    printf("\n\t\t\t\t\t\t 2------> Human VS Computer");
    printf("\n\n\t\t\t\t\t\t 3------> Back");
    if(lol==1){
    printf("\n\n\n\nPlease Choose a valid choice");lol=0;}
    else if(lol==0){
            printf("\n\n\n\n");
    }
    printf("\n>>>>>>>>>>>>>>>>>>>> ");
    char strrt[999];
    scanf("%s",strrt); fflush(stdin);
    char *ptrt;
    GameMode = strtol(strrt, &ptrt, 10);
    if(GameMode!=1&&GameMode!=2&&GameMode!=3){
     lol=1; goto gameDM;
    }
    if(GameMode==3){
        goto gameD;
    }
    playsChar[63]=GameMode;
    break;
case 2:
    gameDD:
    clr();
    printf("\n\n\n\t\t\t\t\t\t 1------> Save 1");
    printf("\n\t\t\t\t\t\t 2------> Save 2");
    printf("\n\t\t\t\t\t\t 3------> Save 3");
    printf("\n\n\t\t\t\t\t\t 4------> Back");

    if(errorLoading==1){
        printf("\n\n\n\nThis save file is empty\nPlease choose another one"); errorLoading=0;
    }
    else if(errorLoading==0){
            printf("\n\n\n\n");
    }
    if(lol==1){
    printf("Please Choose a valid choice");lol=0;}
    printf("\n>>>>>>>>>>>>>>>>>>>> ");
    char strrr[999];
    scanf("%s",strrr); fflush(stdin);
    char *ptrr;
    saveNumber = strtol(strrr, &ptrr, 10);
    if(saveNumber!=1&&saveNumber!=2&&saveNumber!=3&&saveNumber!=4){
     lol=1; goto gameDD;
    }
    if(saveNumber==4){
        goto menu;
    }


    load(saveNumber);
    if(errorLoading==1){
        goto gameDD;
    }
    loadIndication=1;
    playsChar[62]=gameDiff;playsChar[63]=GameMode;
    hh=0;
    break;
case 3:
        clr();
    printf("\n\n\n\t\tRank\t\tNames\t\tScores\n\n\n");
    for(i=0;i<10;i++){
        printf("\t\t %d",i+1);
        printf("\t\t%s",rankNames[i]);
        printf("\t\t%d\n",rankScores[i]);
    }
    printf("\n\n\n\n\n\t\t\t\tPress any key to return to menu.....");
    getch(); goto menu;
    break;
case 4:
    clr();
printf("\n\n\n\n\n\t\t\tDots and Boxes is a simple game for one or two players\n\t\t\twhere you can simply select a line to be drawn and if\n\t\t\tyour drawn line has just closed a box then your score\n\t\t\tincreases by 1 and a letter that indicate your turn\n\t\t\tis drawn inside the box. \n\t\t\tTo choose a line simply write the equivalent number\n\t\t\tof this line and press enter, that's it !!...");
printf("\n\n\n\n\n\t\t\t\tPress any key to return to menu....."); getch();
goto menu;
break;
case 5:
exit(0);
break;
//------------------------------------------------------------------------to be cont;
}
//----------------------




//---------function after choosing game difficulty and mode to take players names
SetColor(12);
if(GameMode==1){
if(loadIndication==0){
printf("\n\n\n\t\t\t\tEnter Player A Name: ");
fflush(stdin);
gets(playerOneName);}
    //--convert player one name to lowercase
for(int i = 0; playerOneName[i]; i++){
  playerOneName[i] = tolower(playerOneName[i]);
}

SetColor(9);
if(loadIndication==0){
printf("\n\n\n\t\t\t\tEnter Player B Name: ");
fflush(stdin);
gets(playerTwoName);}
    //--convert player two name to lowercase
for(int i = 0; playerTwoName[i]; i++){
  playerTwoName[i] = tolower(playerTwoName[i]);
}

}else if(GameMode==2){
if(loadIndication==0){
printf("\n\n\n\t\t\t\tEnter Player A Name: ");
fflush(stdin);
gets(playerOneName);}
    //--convert player one name to lowercase
for(int i = 0; playerOneName[i]; i++){
  playerOneName[i] = tolower(playerOneName[i]);
}

playerTwoName[0]='c';playerTwoName[1]='o';playerTwoName[2]='m';playerTwoName[3]='p';playerTwoName[4]='u';playerTwoName[5]='t';playerTwoName[6]='e';playerTwoName[7]='r';
}


if(gameDiff==1){
   m=13; n=21; maxLine=13; maxPlaysNumber=12;
   int grid[m][n];
   int copyGrid[m][n];
   int color[m][n];
   int ser[m][n];
   for(i=0;i<13;i++){
    for(j=0;j<21;j++){
        grid[i][j]=32;
        color[i][j]=15;
    }
   }
   grid[0][0]=grid[0][10]=grid[0][20]=grid[6][0]=grid[6][10]=grid[6][20]=grid[12][0]=grid[12][10]=grid[12][20]=219;
   grid[0][5]=49;grid[0][15]=50;grid[3][0]=51;grid[3][10]=52;grid[3][20]=53;grid[6][5]=54;grid[6][15]=55;grid[9][0]=56;grid[9][10]=57;grid[9][19]=49;grid[9][20]=48;grid[12][5]=49;grid[12][6]=49;grid[12][15]=49;grid[12][16]=50;
   clr();

   // Take a copy of the first grid
   for(i=0;i<13;i++){
    for(j=0;j<21;j++){
        copyGrid[i][j] = grid[i][j] ;
    }
   }

   shape_printer(grid,color);
   int check[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
   ser[0][1]=1;ser[0][11]=2;ser[1][0]=3;ser[1][10]=4;ser[1][20]=5;ser[6][1]=6;ser[6][11]=7;ser[7][0]=8;ser[7][10]=9;ser[7][20]=10;ser[12][1]=11;ser[12][11]=12;


   gameTimeStart=clock();
   action(check,grid,color,ser,copyGrid);
   if(gotoMenu==1){
    goto menu;
   }
}
else if(gameDiff==2){
   m=31; n=51; maxLine=61; maxPlaysNumber=60;
   int grid[m][n];
    int copyGrid[m][n];
   int color[m][n];
   int ser[m][n];

     for(i=0;i<31;i++){
        for(j=0;j<51;j++){
            grid[i][j]=32;
            color[i][j]=15;
        }
     }
     for(i=0;i<31;i=i+6){
        for(j=0;j<51;j=j+10){
            grid[i][j]=219;
        }
     }
       grid[0][5]=49;grid[0][15]=50;grid[0][25]=51;grid[0][35]=52;grid[0][45]=53;grid[3][0]=54;grid[3][10]=55;grid[3][20]=56;grid[3][30]=57;grid[3][40]=49;grid[4][40]=48;grid[3][50]=49;grid[4][50]=49;
       grid[6][5]=49;grid[6][6]=50;grid[6][15]=49;grid[6][16]=51;grid[6][25]=49;grid[6][26]=52;grid[6][35]=49;grid[6][36]=53;grid[6][45]=49;grid[6][46]=54;grid[9][0]=49;grid[10][0]=55;grid[9][10]=49;grid[10][10]=56;grid[9][20]=49;grid[10][20]=57;
       grid[9][30]=50;grid[10][30]=48;grid[9][40]=50;grid[10][40]=49;grid[9][50]=50;grid[10][50]=50;
       grid[12][5]=50;grid[12][6]=51;grid[12][15]=50;grid[12][16]=52;grid[12][25]=50;grid[12][26]=53;grid[12][35]=50;grid[12][36]=54;grid[12][45]=50;grid[12][46]=55;
       grid[15][0]=50;grid[16][0]=56;grid[15][10]=50;grid[16][10]=57;grid[15][20]=51;grid[16][20]=48;grid[15][30]=51;grid[16][30]=49;grid[15][40]=51;grid[16][40]=50;grid[15][50]=51;grid[16][50]=51;
       grid[18][5]=51;grid[18][6]=52;grid[18][15]=51;grid[18][16]=53;grid[18][25]=51;grid[18][26]=54;grid[18][35]=51;grid[18][36]=55;grid[18][45]=51;grid[18][46]=56;
       grid[21][0]=51;grid[22][0]=57;grid[21][10]=52;grid[22][10]=48;grid[21][20]=52;grid[22][20]=49;grid[21][30]=52;grid[22][30]=50;grid[21][40]=52;grid[22][40]=51;grid[21][50]=52;grid[22][50]=52;
       grid[24][5]=52;grid[24][6]=53;grid[24][15]=52;grid[24][16]=54;grid[24][25]=52;grid[24][26]=55;grid[24][35]=52;grid[24][36]=56;grid[24][45]=52;grid[24][46]=57;
       grid[27][0]=53;grid[28][0]=48;grid[27][10]=53;grid[28][10]=49;grid[27][20]=53;grid[28][20]=50;grid[27][30]=53;grid[28][30]=51;grid[27][40]=53;grid[28][40]=52;grid[27][50]=53;grid[28][50]=53;
       grid[30][5]=53;grid[30][6]=54;grid[30][15]=53;grid[30][16]=55;grid[30][25]=53;grid[30][26]=56;grid[30][35]=53;grid[30][36]=57;grid[30][45]=54;grid[30][46]=48;
   clr();

      // Take a copy of the first grid
   for(i=0;i<31;i++){
        for(j=0;j<51;j++){
        copyGrid[i][j] = grid[i][j] ;
    }
   }

   int serVar=1;
   shape_printer(grid,color);
   for (i = 0 ; i < 31 ; i += 6 ){
            for (j = 1 ; j < 42 ; j +=10){
                ser[i][j]=serVar;
                serVar++;
                if(serVar==6||serVar==17||serVar==28||serVar==39||serVar==50){
                    serVar+=6;
                }
            }}
   serVar=6;
   for(i=1;i<26;i+=6){
        for(j=0;j<51;j+=10){
                ser[i][j]=serVar;
                serVar++;
                if(serVar==12||serVar==23||serVar==34||serVar==45){
                    serVar+=5;
                }
             }}
   int check[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
gameTimeStart=clock();
action(check,grid,color,ser,copyGrid);
if(gotoMenu==1){
    goto menu;
   }
}
int what;
//-----------finishing game
printf("\n\n");
if (score1 > score2){
    SetColor(12);
    taper();
    printf("Congratulations !! %s won ^-^\n\n\n",playerOneName);
}
else if (score1 < score2){
    SetColor(9);
    taper();
    if (GameMode == 2){
        printf("Unfortunately !! %s won\n",playerTwoName);
        taper();
        printf("   Try your luck again\n\n");
    }
    else{
        printf("Congratulations !! %s won ^-^\n\n\n",playerTwoName);
    }
}
else if (score1 == score2){
    SetColor(10);
    taper();
    printf("The Game is Draw !! ^.^\n\n\n");
}
//----------compare and save rank;
int amIThere=99;
for(i=0;i<10;i++){
    if(!strcmp(rankNames[i],playerOneName)){
       amIThere=i; break;
    }
}if(amIThere!=99){
if(score1>rankScores[amIThere]){
swps(amIThere);}
else{goto skip1;}
}

int rankCount1=0;
for(int oo=0;oo<10;oo++){
    if(score1>=(int)rankScores[oo]){
        rankCount1++;
    }
}switch (rankCount1){
case 1: swpn(9,9,1);swp(9,9,1);break;
case 2: swpn(8,9,1);swp(8,9,1);break;
case 3: swpn(7,9,1);swp(7,9,1);break;
case 4: swpn(6,9,1);swp(6,9,1);break;
case 5: swpn(5,9,1);swp(5,9,1);break;
case 6: swpn(4,9,1);swp(4,9,1);break;
case 7: swpn(3,9,1);swp(3,9,1);break;
case 8: swpn(2,9,1);swp(2,9,1);break;
case 9: swpn(1,9,1);swp(1,9,1);break;
case 10: swpn(0,9,1);swp(0,9,1);break;
}
skip1:

amIThere=99;
for(i=0;i<10;i++){
    if(!strcmp(rankNames[i],playerTwoName)){
       amIThere=i; break;
    }
}if(amIThere!=99){
if(score2>rankScores[amIThere]){
swps(amIThere);}
else{goto skip2;}
}

int rankCount2=0;
for(int pp=0;pp<10;pp++){
    if(score2>=(int)rankScores[pp]){
        rankCount2++;
    }

}switch (rankCount2){
case 1: swpn(9,9,2);swp(9,9,2);break;
case 2: swpn(8,9,2);swp(8,9,2);break;
case 3: swpn(7,9,2);swp(7,9,2);break;
case 4: swpn(6,9,2);swp(6,9,2);break;
case 5: swpn(5,9,2);swp(5,9,2);break;
case 6: swpn(4,9,2);swp(4,9,2);break;
case 7: swpn(3,9,2);swp(3,9,2);break;
case 8: swpn(2,9,2);swp(2,9,2);break;
case 9: swpn(1,9,2);swp(1,9,2);break;
case 10: swpn(0,9,2);swp(0,9,2);break;
}
skip2:
amIThere=99;

//dont forget to write again after comparison

FILE *rk3=fopen("scores.data","wb");
fwrite(rankScores,sizeof(char),sizeof(rankScores),rk3);
fclose(rk3);

FILE *rk4=fopen("names.data","wb");
fwrite(rankNames,sizeof(char),sizeof(rankNames),rk4);
fclose(rk4);


printf("1---> Return to main menu.  2--->Exit"); printf("\n>>>>>>>>>>>>>>> "); scanf("%d",&what);
if(what==1){
      clr(); goto menu;
}else{exit(0);}

    SetColor(15);



return 0;

}
