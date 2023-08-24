#include"chessMoves.c" //chess moves functions
#include<stdio.h>
#include<time.h>
#include <string.h>
#include <sys/types.h>//mkdir module
#include<dirent.h>

int mkdir(const char *pathname);//function to create save folder

//function to put two strings togather
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void theLoadPage(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".\\chessSaves");
    if (d){
        int loadNumber = -1;
        while ((dir = readdir(d)) != NULL){   if(loadNumber>=1){
            printf("%d-%s\n",loadNumber, dir->d_name);
            }
            loadNumber++;
        }
        closedir(d);
        loadNumber = 0;
    }
}

int main(){
    system("chcp 65001"); 
    while(1){
        printf("1-Start New Game\n2-Load Previous Game\n3-Quit Game\nPlease choose a number:");
        int select;
        scanf("%d",&select);
        if(select == 1){
            int whiteTime = 300;
            int blackTime = 300;
            printf("A new game is now starting...\n");
             
        while(1){
            char move[] = "";
            createBoard(board);//first board
            changePlayer();

            if(whitePlays){
                printf("White moves, ");
                
            }else{
                printf("Black moves, ");
                
            }
            
            printf("please make a valid move(press m to exit to the main menu):");//Taking move input
            
            scanf("%s",&move);
            

            if(move[0] == 'm' || move[0] == 'M'){//breaking infinite loop
                FILE *f;
                char fname[100];
                printf(" Input the file name to be saved : ");
                scanf("%s",fname);
                mkdir(".\\chessSaves");//creates saves folder
                char* s = concat(".\\chessSaves\\",fname);//creating path of the saved file
                strcat(s,".txt");
                //saving the board data in the file
                f = fopen(s,"w");
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        fprintf(f,"%d\n",board[i][j]);
                    }
                }
                playerCount--;
                fprintf(f,"%d",playerCount);
                fclose(f);
                printf("Game is autosaved.\n");
                break;
            }else if(move[0] == 's' || move[0] == 'S'){
                //saving current board array
                
                FILE *f;
                char fname[100];
                printf(" Input the file name to be saved : ");
                scanf("%s",fname);
                mkdir(".\\chessSaves");//creates saves folder
                char* s = concat(".\\chessSaves\\",fname);//creating path of the saved file
                strcat(s,".txt");
                //saving the board data in the file
                f = fopen(s,"w");
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        fprintf(f,"%d\n",board[i][j]);
                    }
                }
                playerCount--;
                fprintf(f,"%d",playerCount);
                fclose(f);
                printf("Game is saved.\n");
                
                }
            

        char place[3] = {move[0],move[1],'\0'}; //getting first two digits of the move
        char toWhere[3] = {move[2],move[3],'\0'}; //geting other two digits of the move
        changePlace(place,toWhere); //the functon that makes the changes of a piece
        
        // system("cls"); 
                }
        }
        else if(select ==2){//Load game interface
        theLoadPage();

        char pickedSave[20];
        printf("Write the name of the save yo want to play without the extantion (press any key to go main menu):");
        scanf("%s",&pickedSave);
        FILE *fl;
    
        //picked save directory

        char* pickedDir = concat(".\\chessSaves\\",pickedSave);
        strcat(pickedDir,".txt");
        
        //getting loaded file
        
        if((fl = fopen(pickedDir,"r")) == NULL){//Error control
            printf("There is no such a file in that name please try again!");
            continue;
        }
        int a;
        int first=0;
        int second=0;
        int count = 1;
        while(!feof(fl)){
            fscanf(fl,"%d",&a);
            board[first][second] = a;
            second++;
            
            if(second == 8){
                second = 0;
                first++;
            }
            if(count == 65){
                playerCount = a;
            }
            count++;
        }
        while(1){
            char move[] = "";
            createBoard(board);//creates a board with current data
            changePlayer();
            if(whitePlays){
                printf("White moves, ");
                
            }else{
                printf("Black moves, ");
                
            }
            
            printf("please make a valid move(press m to exit to the main menu):");//Taking move input
            
            scanf("%s",&move);
            

            if(move[0] == 'm' || move[0] == 'M'){//breaking infinite loop
                FILE *f;
                char fname[100];
                printf(" Input the file name to be saved : ");
                scanf("%s",fname);
                mkdir(".\\chessSaves");//creates saves folder
                char* s = concat(".\\chessSaves\\",fname);//creating path of the saved file
                strcat(s,".txt");
                //saving the board data in the file
                f = fopen(s,"w");
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        fprintf(f,"%d\n",board[i][j]);
                    }
                }
                playerCount--;
                fprintf(f,"%d",playerCount);
                fclose(f);
                printf("Game is autosaved.\n");
                break;
            }else if(move[0] == 's' || move[0] == 'S'){
                //saving current board array

                FILE *f;
                char fname[100];
                printf(" Input the file name to be saved : ");
                scanf("%s",fname);
                mkdir(".\\chessSaves");//creates saves folder
                char* s = concat(".\\chessSaves\\",fname);//creating path of the saved file
                strcat(s,".txt");
                //saving the board data in the file
                f = fopen(s,"w");
                for (int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        fprintf(f,"%d\n",board[i][j]);
                    }
                }
                playerCount--;
                fprintf(f,"%d",playerCount);
                fclose(f);
                printf("Game is saved.\n");
                }
            

        char place[3] = {move[0],move[1],'\0'}; //getting first two digits of the move
        char toWhere[3] = {move[2],move[3],'\0'}; //geting other two digits of the move
        changePlace(place,toWhere); //the functon that makes the changes of a piece
        
        // system("cls"); 
                }
        
        }
        else if (select == 3){
            printf("Exiting the game...");
            break;
        }
        else{
            printf("Invalid selection please select again");
            
    }
    }


   
    return 0;
}
