#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;
char user_input(){
    char s;
    cout<<"Enter your move (R for Rock, P for Paper, S for Scissors): ";
    cin>>s;
    s = toupper(s);
    while(s != 'R' && s != 'P' && s != 'S'){
        cout << "Invalid input! Enter R, P, or S: ";
        cin >> s;
        s = toupper(s);
    }
    return s;
}

char computer_move(){
    char moves[3] = {'R', 'P', 'S'};
    int random_num = rand() % 3;
    return moves[random_num];
}

bool is_winner(char user_move, char comp_move){
    if((user_move == 'R' && comp_move == 'S') || 
       (user_move == 'P' && comp_move == 'R') || 
       (user_move == 'S' && comp_move == 'P')){
        return true;
    }
    return false;
}

void display_score(int user_score, int computer_score){
    cout<<"User score: "<<user_score
        <<" Computer score: "<<computer_score<<endl;
}

void display_final_score(int user_score, int computer_score, int draw_score){
    cout<<"======================\n";
    cout<<"Final Scores:"<<endl;
    cout<<"User: "<<user_score<<endl;
    cout<<"Computer: "<<computer_score<<endl;
    cout<<"Draws: "<<draw_score<<endl;

    if(user_score > computer_score){
        cout<<"You are the overall winner!"<<endl;
    }
    else if(computer_score > user_score){
        cout<<"Computer is the overall winner!"<<endl;
    }
    else{
        cout<<"It's a tie overall!"<<endl;
    }
}

int main(){
    srand(time(0));
    int rounds;
    cout<<"Enter number of rounds to play: ";
    cin>>rounds;
    int user_score = 0, computer_score = 0, draw_score = 0;
    int current_round = 1;
    while(rounds--){
        cout<<"=============\n";
        cout<<"Round "<<current_round<<endl;
        cout<<"=============\n";
        char user_move, comp_move;
        user_move = user_input();
        comp_move = computer_move();
        cout<<"User move: "<<user_move<<endl;
        cout<<"Computer move: "<<comp_move<<endl;
        if(is_winner(user_move, comp_move)){
            cout<<"You win!"<<endl;
            user_score++;
            display_score(user_score, computer_score);
        }
        else if(user_move == comp_move){
            cout<<"It's a draw!"<<endl;
            draw_score++;
            display_score(user_score, computer_score);
        }
        else{
            cout<<"Computer wins!"<<endl;
            computer_score++;
            display_score(user_score, computer_score);
        }
        current_round++;
    }
    display_final_score(user_score, computer_score, draw_score);
    return 0;
}