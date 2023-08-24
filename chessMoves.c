#include<stdio.h>
#include"pieceValidation.c"

int rowIndexIntTurner(char place[]){
        int row;
        //making place[1] an int
        char strRow[] = {place[1],'\0'};
        row = atoi(strRow);
        int rowIdx = row-1;
        return rowIdx;
        // printf("row index: %d column index: %d",rowIndex,columnIndex);
    }

void placeDeleter(int row,int column,int rowT,int columnT,int piece){
    //-----------------------------------------------------------------------------
    //VALİDATİONS BEFORE TAKİNG A PIECE
    //checkng that whose move it is
    if(whitePlays){
        if(piece>0){
                printf("Invalid move! You can't move that piece! Please try another!\n");
                playerCount--;//to stay in he white or black
                return;
        }
    }else{
        if(piece<0){
                printf("Invalid move! You can't move that piece! Please try another!\n");
                playerCount--;//to stay in he white or black
                return;
        }
    }
    //checking that could you eat that piece
    int attackedPiece = board[rowT][columnT];
    if(whitePlays){
                if(attackedPiece<0){
                     printf("Invalid move! Cant eat your own piece! Please try another!\n");
                    playerCount--;//to stay in he white or black
                    return;
                }
            }
            else{
                if(attackedPiece>0){
                     printf("Invalid move! Cant eat your own piece! Please try another!\n");
                    playerCount--;//to stay in he white or black
                    return;
            }
            }
            //checking that you choose an empty space
            if(piece == 0){
                printf("Invalid move! Cant choose an empty space! Please try another!\n");
                    playerCount--;//to stay in he white or black
                    return;
            }
//--------------------------------------------------------------------------------------

    //PIECE VALIDATIONS
    //taşı silmeden önce gitmesi gereken yere gitme yetkisi var mı kontrol et
    if (board[row][column] == 1 || board[row][column] == -1){
        if(rookValidate(row,column,rowT,columnT)){

        }else{
            printf("Invalid move rook can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }
    }
    else if (board[row][column] == 2 || board[row][column] == -2){
        if(knightValidate(row,column,rowT,columnT)){
            
        }else{
            printf("Invalid move knight can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }
    }
    else if (board[row][column] == 3 || board[row][column] == -3){
        if(bishopValidate(row,column,rowT,columnT)){

        }else{
            printf("Invalid move bishop can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }
    }
    else if (board[row][column] == 4 || board[row][column] == -4){
        if(queenValidate(row,column,rowT,columnT)){

        }else{
            printf("Invalid move queen can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }
    }
    else if (board[row][column] == 5 || board[row][column] == -5){
        if(kingValidate(row,column,rowT,columnT)){

        }   else{
            printf("Invalid move king can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }     
    }
    else if (board[row][column] == 6 || board[row][column] == -6){
        if(pawnValidate(row,column,piece,rowT,columnT,attackedPiece)){
            

        }else{
            printf("Invalid move pawn can't move that way! Please try another!\n");
            playerCount--;//to stay in he white or black
            return;
        }
    }
    board[row][column] = 0;//Deleting the piece from it's former place


    placePutter(rowT,columnT,piece);//putting it in it's new place
}

void placePutter(int row,int column,int piece){
    board[row][column] = piece;
}


void changePlace(char place[], char toWhere[]){
    int piece; //taşı burada global olarak tanımlıyoruz çünkü if içerisinde tanımlanırsa diğer if döngülerinin içinde kullanılamıyor

    int columnIndexT,rowIndexT;
    if (place[0] == 'a'){
        int columnIndexP = 0;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
        
    }
    else if(place[0] == 'b'){
        int columnIndexP = 1;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);        
    }
    else if(place[0] == 'c'){
        int columnIndexP = 2;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
            }
    else if(place[0] == 'd'){
        int columnIndexP = 3;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
            }
    else if(place[0] == 'e'){
        int columnIndexP = 4;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
            }
    else if(place[0] == 'f'){
        int columnIndexP = 5;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
            }
    else if(place[0] == 'g'){
    int columnIndexP = 6;
    int rowIndexP = rowIndexIntTurner(place);
    if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);

    }

    else if(place[0] == 'h'){
        int columnIndexP = 7;
        int rowIndexP = rowIndexIntTurner(place);
        if (toWhere[0] == 'a'){
        columnIndexT = 0;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'b'){
        columnIndexT = 1;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'c'){
        columnIndexT = 2;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'd'){
        columnIndexT = 3;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'e'){
        columnIndexT = 4;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'f'){
        columnIndexT = 5;
        rowIndexT = rowIndexIntTurner(toWhere);
    }
    else if(toWhere[0] == 'g'){
        columnIndexT = 6;
        rowIndexT = rowIndexIntTurner(toWhere);
        
    }
    else if(toWhere[0] == 'h'){
        columnIndexT = 7;
        rowIndexT = rowIndexIntTurner(toWhere);
    }else if(toWhere[0] == 's' || toWhere[0] == 'm' || toWhere[0] == 'S' || toWhere[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
        piece = board[rowIndexP][columnIndexP];
        placeDeleter(rowIndexP,columnIndexP,rowIndexT,columnIndexT,piece);
            }else if(place[0] == 's' || place[0] == 'm' || place[0] == 'S' || place[0] == 'M'){
        }else{
        printf("Invalid move! You can't move that piece! Please try another!\n");
        playerCount--;
        return;
    }
    
}