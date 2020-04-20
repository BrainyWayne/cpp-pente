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

        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.upperSacred[3] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.upperSacred[2] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.upperSacred[1] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.upperSacred[0]<< "|" << endl;
        cout << "  ---------" << endl;
        cout << "  |" << player.player1[1][1] << "|" <<  "|" << player.player1[2][1]<< "|"  << "|" << player.player1[3][1] << "|" << endl;
        cout << " ------------" << endl;
        cout << "|" << player.player1[0][1] <<"|" << "       " << "|" << player.player1[4][1]<< "|" << endl;
        cout << "--------------" << endl;
        cout << "|" << player.player2[0][1] <<"|" << "       " << "|" << player.player2[4][1] << "|" << endl;
        cout << "--------------" << endl;
        cout << "  |" << player.player2[1][1] << "|" <<  "|" << player.player2[2][1] << "|"  << "|" << player.player2[3][1]  << "|" << endl;
        cout << "  ---------" << endl;
        cout << "  " << "   |" << player.lowerSacred[0] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.lowerSacred[1] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.lowerSacred[2] << "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << "  " << "   |" << player.lowerSacred[3]<< "|" << endl;
        cout << "  " << "   ---" << endl;
        cout << endl << endl;
        referee.setCurrentPathwayHolderDown(player.player2[2][0]);
        referee.setCurrentPathwayHolderTop(player.player1[2][0]);
        cout << "L score: " << player.player1score << endl;
        cout << "N score: " << player.player2score << endl;
        if(referee.player1turn){
            cout << "Player turn: " << player.player1name << endl;
        } else{
            cout << "Player turn: " << player.player2name << endl;
        }
        cout << endl;


        //generate random number between 1 and 6
        cout << "ROLL: " << referee.generateRandomNumber()<< endl;

        cout << "Select piece: " << endl;



        //select piece
        referee.selectPiece();

        //check player turn
        if(referee.player1turn){
            referee.movePiece('L', referee.selectedPiece, referee.randomNumber);
        } else {
            referee.movePiece('N', referee.selectedPiece, referee.randomNumber);
        }


    }

};