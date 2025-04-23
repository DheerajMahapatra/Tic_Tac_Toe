#include<iostream>
#include<stdlib.h>
using namespace std;

int choice,row,column;
char tic_tac[3][3]={{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
char turn='X';
bool condition=true;
bool draw=false;

void display() {
    system("cls");
    cout << "\t\t\t\t\t_________WELCOME TO TIC TAC TOE GAME !_________" << endl;
    cout << "         PLAYER 1[X]" << endl;
    cout << "         PLAYER 2[0]" << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                " << tic_tac[0][0] << "    |    " << tic_tac[0][1] << "    |    " << tic_tac[0][2] << "     " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t              _______|_________|_______          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                " << tic_tac[1][0] << "    |    " << tic_tac[1][1] << "    |    " << tic_tac[1][2] << "     " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t              _______|_________|_______          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                " << tic_tac[2][0] << "    |    " << tic_tac[2][1] << "    |    " << tic_tac[2][2] << "     " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
    cout << "\t\t\t\t\t                     |         |          " << endl;
}
void player(){
    if (turn == 'X'){
         cout<<"         PLAYER 1[X] turn: ";
    }

    else {
         cout<<"         PLAYER 2[0] turn: ";
    }

    cin>>choice;

    switch(choice){
        case 1:
        row=0; column=0;
        break;

        case 2:
        row=0; column=1;
        break;

        case 3:
        row=0; column=2;
        break;

        case 4:
        row=1; column=0;
        break;

        case 5:
        row=1; column=1;
        break;

        case 6:
        row=1; column=2;
        break;

        case 7:
        row=2; column=0;
        break;

        case 8:
        row=2; column=1;
        break;

        case 9:
        row=2; column=2;
        break;

        default:
        cout<<"INVALID CHOICE !"<<endl;

    }

    if (turn=='X' && tic_tac[row][column]!='X' && tic_tac[row][column]!='0'){
        tic_tac[row][column]='X';
        turn = '0';
    }

    else if (turn=='0'  && tic_tac[row][column]!='X' && tic_tac[row][column]!='0'){
        tic_tac[row][column]='0';
        turn='X';
    }

    else{
        cout<<"Cell already occupied !"<<endl;
        cout<<"Choose a different cell !"<<endl;
        player();
    }

}

int over() {
    for (int i = 0; i < 3; i++) {
        if (tic_tac[i][0] == tic_tac[i][1] && tic_tac[i][0] == tic_tac[i][2]){
            condition = false;
            return 0;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tic_tac[0][j] == tic_tac[1][j] && tic_tac[0][j] == tic_tac[2][j]){
            condition = false;
            return 0;
        }
    }

    if (tic_tac[0][0]==tic_tac[1][1] && tic_tac[0][0]==tic_tac[2][2] || tic_tac[0][2]==tic_tac[1][1] && tic_tac[0][2]==tic_tac[2][0]){
        condition=false;
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tic_tac[i][j] != 'X' && tic_tac[i][j] != '0') {
                return 1; 
            }
        }
    }
    condition = false;
    draw=true;
    return 0;
            
}

int main() {
    system("Color A1");

    while (condition == true) {
        display();
        player();
        display();
        over();

        if (!condition && !draw) {
            if (turn == 'X') {
                cout << "CONGRATULATION....!" << endl;
                cout << "PLAYER 2[0] WON THE MATCH !" << endl;
            } else if (turn == '0') {
                cout << "CONGRATULATION....!" << endl;
                cout << "PLAYER 1[X] WON THE MATCH !" << endl;
            }
        } else if (draw) {
            cout << "YOUR GAME IS DRAW !" << endl;
            cout << "PLEASE PLAY AGAIN !" << endl;
            
        }
    }
}