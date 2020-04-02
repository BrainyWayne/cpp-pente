#include <iostream>
#include "Referee.h"


using namespace std;

class Board {

public:

    Player player;
    Referee referee;

    Board(){


    }


    void printBoard(){

        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.upperSacred[3] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.upperSacred[2] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.upperSacred[1] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.upperSacred[0]<< "|" << endl;
        cout << "  ---------" << endl;
        cout << "  |" << player.player1[1][1] << "|" <<  "|" << player.player1[2][1]<< "|"  << "|" << player.player1[3][1] << "|" << endl;
        cout << " ------------" << endl;
        cout << "|" << player.player1[0][1] <<"|" << "       " << "|" << player.player1[4][1]<< "|" << endl;
        cout << "--------------" << endl;
        cout << "|" << player.player2[0][1] <<"|" << "       " << "|" << player.player2[4][1] << "|" << endl;
        cout << "--------------" << endl;
        cout << "  |" << player.player2[1][1] << "|" <<  "|" << player.player2[2][1] << "|"  << "|" << player.player2[3][1]  << "|" << endl;
        cout << "  ---------" << endl;
        cout << "  \t" << " |" << player.lowerSacred[0] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.lowerSacred[1] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.lowerSacred[2] << "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << "  \t" << " |" << player.lowerSacred[3]<< "|" << endl;
        cout << "  \t" << " ---" << endl;
        cout << endl << endl;
        referee.setCurrentPathwayHolderDown(player.player2[2][1]);
        referee.setCurrentPathwayHolderTop(player.player1[2][1]);
        cout << "L score: " << player.player1score << endl;
        cout << "N score: " << player.player2score << endl;
        cout << "Player turn: " << player.player1name << endl;
        cout << endl;
        cout << "ROLL: " << referee.generateRandomNumber()<< endl;
        cout << "Select piece: " << endl;



        //select piece
        referee.selectPiece();

        if(referee.isPlayerOneturn()){
            referee.movePiece('L', referee.selectedPiece, referee.randomNumber);
        } else {
            referee.movePiece('N', referee.selectedPiece, referee.randomNumber);
        }


    }

};