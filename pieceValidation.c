#include"chessBoard.c" //createBoard function
#include<stdlib.h>
bool rookValidate(int row, int column,int rowTo,int columnTo){
    
    if(row == rowTo && column != columnTo){
        if(column>columnTo){
            for(int i=abs(columnTo-column);i>1;i--){
              int value = column-i+1;
            if(board[row][value] != 0){
                return false;
            }
        }
        }else if(columnTo>column){
            for(int i=abs(columnTo-column);i>1;i--){
              int value = column+i-1;
            if(board[row][value] != 0){
                return false;
            }
        }
        }

        return true;
    }else if(row != rowTo && column == columnTo){
          for(int i=abs(rowTo-row);i>1;i--){
              if(row>rowTo){
                  int value = row-i+1;
            if(board[value][column] != 0){
                return false;
            }
              }else if(rowTo>row){
                  int value = row+i-1;
            if(board[value][column] != 0){
                return false;
            }
              }
        }
        return true;
        }else{
            return false;
    }
}

bool knightValidate(int row, int column,int rowTo,int columnTo){
    
    if(((row+2)==rowTo) && ((column+1) == columnTo)){
        return true;
    }else if(((row+2)==rowTo) && ((column-1) == columnTo)){
        return true; 
    }else if(((row-2)==rowTo) && ((column+1) == columnTo)){
        return true;
    }else if(((row-2)==rowTo) && ((column-1) == columnTo)){
        return true;
    }else if(((row+1)==rowTo) && ((column+2) == columnTo)){
        return true;
    }else if(((row-1)==rowTo) && ((column+2) == columnTo)){
        return true;
    }else if(((row-1)==rowTo) && ((column-2) == columnTo)){
        return true;        
    }else if(((row+1)==rowTo) && ((column-2) == columnTo)){
        return true;
    }
    else{
        return false;
    }
    
}

bool kingValidate(int row, int column,int rowTo,int columnTo){
    if((row+1) == rowTo && (column+1) == columnTo){
        return true;
    }else if((row+1)==rowTo && column == columnTo){
        return true;
    }else if((row+1)==rowTo && (column-1) == columnTo){
        return true;
    }else if(row == rowTo && (column+1) == columnTo){
        return true;
    }else if(row == rowTo && (column-1) == columnTo){
        return true;
    }else if((row-1) == rowTo && (column+1) == columnTo){
        return true;
    }else if((row-1) == rowTo && column == columnTo){
        return true;
    }else if((row-1) == rowTo && (column-1) == columnTo){
        return true;
    }else{
        return false;
    }
}

bool pawnValidate(int row, int column,int piece,int rowTo,int columnTo,int attackedPiece){
    if(piece>0){
        if(row==1){
            if((row+2) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row+1) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row+1) == rowTo && (column+1)==columnTo && attackedPiece != 0){
                return true;
            }else if((row+1) == rowTo && (column-1)==columnTo && attackedPiece != 0){
                return true;
            }else{
                return false;
            }
        }else{
            if((row+1) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row+1) == rowTo && (column+1)==columnTo && attackedPiece != 0){
                return true;
            }else if((row+1) == rowTo && (column-1)==columnTo && attackedPiece != 0){
                return true;
            }else{
                return false;
            }
        }
    }else{
        if(row==6){
            if((row-2) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row-1) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row-1) == rowTo && (column+1)==columnTo && attackedPiece != 0){
                return true;
            }else if((row-1) == rowTo && (column-1)==columnTo && attackedPiece != 0){
                return true;
            }else{
                return false;
            }
        }else{
            if((row-1) == rowTo && column == columnTo && attackedPiece == 0){
                return true;
            }else if((row-1) == rowTo && (column+1)==columnTo && attackedPiece != 0){
                return true;
            }else if((row-1) == rowTo && (column-1)==columnTo && attackedPiece != 0){
                return true;
            }else{
                return false;
            }
        }
    }
}

bool bishopValidate(int row, int column,int rowTo,int columnTo){
    int goRow = abs(rowTo-row);
    int goColumn = abs(columnTo-column);
    if(goColumn==goRow){
        if((rowTo-row) > 0 && (columnTo-column)>0){
             for(int i=1;i<(goRow);i++){
            if((board[row+i][column+i] != 0)){
                return false;
    }
        }
        }else if((rowTo-row) > 0 && (columnTo-column)<0){
            for(int i=1;i<(goRow);i++){
            if((board[row+i][column-i] != 0)){
                return false;
        }
       
    }
    }else if((rowTo-row) < 0 && (columnTo-column)<0){
            for(int i=1;i<(goRow);i++){
            if((board[row-i][column-i] != 0)){
                return false;
            }
        }
       
    }else if((rowTo-row) < 0 && (columnTo-column)>0){
            for(int i=1;i<(goRow);i++){
            if((board[row-i][column+i] != 0)){
                return false;
        }
       
    }
}else{
        return true;
    }
}else{
    return false;
}
}


bool queenValidate(int row, int column,int rowTo, int columnTo){
    int goRow = abs(rowTo-row);
    int goColumn = abs(columnTo-column);
    if(goColumn==goRow){
        if((rowTo-row) > 0 && (columnTo-column)>0){
             for(int i=1;i<(goRow);i++){
            if((board[row+i][column+i] != 0)){
                return false;
    }
        }
        }else if((rowTo-row) > 0 && (columnTo-column)<0){
            for(int i=1;i<(goRow);i++){
            if((board[row+i][column-i] != 0)){
                return false;
        }
       
    }
    }else if((rowTo-row) < 0 && (columnTo-column)<0){
            for(int i=1;i<(goRow);i++){
            if((board[row-i][column-i] != 0)){
                return false;
            }
        }
       
    }else if((rowTo-row) < 0 && (columnTo-column)>0){
            for(int i=1;i<(goRow);i++){
            if((board[row-i][column+i] != 0)){
                return false;
        }
       
    }
}else{
        return true;
    }
}else if(row != rowTo && column == columnTo){
          for(int i=abs(rowTo-row);i>1;i--){
              if(row>rowTo){
                  int value = row-i+1;
            if(board[value][column] != 0){
                return false;
            }
              }else if(rowTo>row){
                  int value = row+i-1;
            if(board[value][column] != 0){
                return false;
            }
              }
        }
        return true;
        }else if(row == rowTo && column != columnTo){
        if(column>columnTo){
            for(int i=abs(columnTo-column);i>1;i--){
              int value = column-i+1;
            if(board[row][value] != 0){
                return false;
            }
        }
        }else if(columnTo>column){
            for(int i=abs(columnTo-column);i>1;i--){
              int value = column+i-1;
            if(board[row][value] != 0){
                return false;
            }
        }
        }

        return true;
    }else{
        return false;
    }
}

void checkMate(){
    
}