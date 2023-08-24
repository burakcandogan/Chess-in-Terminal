#include<stdio.h>
#include<stdbool.h>
int playerCount = 0;
bool whitePlays;


void changePlayer(){
if(playerCount%2 == 0){
   
      whitePlays = true;
      playerCount++;
   }else{
      whitePlays = false;
      playerCount++;
            }
}



int board[8][8] = {//soldaki satır sağdaki sütun
       1,2,3,4,5,3,2,1,
       6,6,6,6,6,6,6,6,
       0,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,
       0,0,0,0,0,0,0,0,
       -6,-6,-6,-6,-6,-6,-6,-6,
       -1,-2,-3,-4,-5,-3,-2,-1
       };

void createBoard(int board[8][8]){

   
   
   //if else ile rakamların kodlandığı yerlere unicode sembolleri basılacak
   int i,j;
   int k = 1;
    for(i=0; i<8; i++) {

      for(j=0;j<8;j++) {
         int chessPiece = board[i][j];
         if(chessPiece == 1){
            printf("\u2656 ");
         }
         else if(chessPiece == 2){
            printf("\u2658 ");
         }
         else if(chessPiece == 3){
            printf("\u2657 ");
         }
         else if(chessPiece == 4){
            printf("\u2655 ");
         }
         else if(chessPiece == 5){
            printf("\u2654 ");
         }
         else if(chessPiece == 6){
            printf("\u2659 ");
         }
         else if(chessPiece == 0){
            printf("  ");
         }
         else if(chessPiece == -1){
            printf("\u265C ");
         }
         else if(chessPiece == -2){
            printf("\u265E ");
         }
         else if(chessPiece == -3){
            printf("\u265D ");
         }
         else if(chessPiece == -4){
            printf("\u265B ");
         }
         else if(chessPiece == -5){
            printf("\u265A ");
         }
         else if(chessPiece == -6){
            printf("\u265F ");
         }

        //printed numerical chess pieces
         if(j==7){
            printf("|%d",k++);
            printf("\n");
         };
      };
   };
   printf("________________\n");
   printf("A B C D E F G H\n ");
}

































    
//    for (int k=0;k<8;k++){

//        for (int i = 0; i<8;i++){
//        printf(" _ ");
//    }
//    printf("\n");
//    for (int j = 0; j<8;j++){
//        printf("| |");
//    }
//     printf("\n");
//    }