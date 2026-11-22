#include<iostream>
using namespace std;

//outputs the current state of the grid
void display_grid(char grid[3][3]){
    cout<<"------------" <<endl;
    for(int i=0;i<3;i++){
        cout<<"| ";
        for(int j=0;j<3;j++){
            cout<<grid[i][j]<<" | ";
        }
        if(i<2){
            cout<<"\n----+---+----" <<endl;
        }
        else{
            cout<<"\n-------------" <<endl;
        }
    }
}

//checks if the move is valid (within bounds and on an empty cell)
bool valid_move(char grid[3][3], int r, int c){
    if(r>=0 && r<3 && c>=0 && c<3 && grid[r][c]=='-'){
        return true;
    }
    return false;
}

//checks if the current player has won
bool is_winner(char grid[3][3], char player){
    // Check rows and columns
    for(int i=0;i<3;i++){
        if((grid[i][0]==player && grid[i][1]==player && grid[i][2]==player) || 
           (grid[0][i]==player && grid[1][i]==player && grid[2][i]==player)){
            return true;
        }
    }
    // Check diagonals
    if((grid[0][0]==player && grid[1][1]==player && grid[2][2]==player) || 
       (grid[0][2]==player && grid[1][1]==player && grid[2][0]==player)){
        return true;
    }
    return false;
}

//checks if the game is a draw (no empty cells left)
bool is_draw(char grid[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[i][j]=='-'){
                return false;
            }
        }
    }
    return true;
}

void score_counter(char grid[3][3], int &x_score, int &o_score, int &draw_score){
    if(is_winner(grid, 'X')){
        x_score++;
    }
    else if(is_winner(grid, 'O')){
        o_score++;
    }
    else if(is_draw(grid)){
        draw_score++;
    }
    cout<<"---------------------"<<endl;
    cout<<"Current Scores:"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Score: Player X: "<<x_score<<", Player O: "<<o_score<<", Draws: "<<draw_score<<endl;
}

void xo_game(char grid[3][3]){
    char player='X';
    int r,c;
    while(true){
        display_grid(grid);
        cout<<"Player "<<player<<", enter your move (row, column): ";
        cin>>r>>c;
        r--; c--; // Adjust for 0-based indexing
        if(valid_move(grid, r, c)){
            grid[r][c]=player;
            if(is_winner(grid, player)){
                display_grid(grid);
                cout<<"Player "<<player<<" wins!"<<endl;
                return;
            }
            else if(is_draw(grid)){
                display_grid(grid);
                cout<<"It's a draw!"<<endl;
                return;
            }
            player = (player=='X') ? 'O' : 'X'; // ternary if to switch player
        }
        else{
            cout<<"Invalid move. Try again."<<endl;
        }
    }
}

int main(){
    int x_score=0, o_score=0, draw_score=0;
    do{
        char grid[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'} };
        xo_game(grid);
        score_counter(grid, x_score, o_score, draw_score);
        char choice;
        cout<<"Do you want to play again? (y/n): ";
        cin>>choice;
        if(choice!='y' && choice!='Y'){
            return 0;
        }
    }while(true);
    return 0;
}