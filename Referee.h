#include <iostream>
#include <ctime>
#include <string>
using namespace std;


class Referee{

    Player player;

private:

    bool player1turn = true;



public:
    string selectedPiece;
    int randomNumber;
    bool cancelled = false;


    void selectPiece(){
        cin >> selectedPiece;

        //DEBUG
        cout << "Selected piece is: " << selectedPiece << endl;
        //DEBUG
    }

    void isCancelled(int choice){
        if(choice == -1){
            cout << "Exited" << endl;
            cancelled = true;
            exit(0);
        }
    }

    bool isPlayerOneturn(){

        return player1turn;
    }

    int generateRandomNumber(){
        srand((unsigned)time(0));
        randomNumber = rand() % 6 + 1;
        return randomNumber;
    }

    void movePiece(char nextPlayer, string piece, int moveBy){
        //DEBUG
        cout << "Player: " << nextPlayer << ", Piece: " << piece << ", Moveby: " << moveBy << endl;
        //DEBUG

        string piecePosition;
        int piecePositionInteger;

        switch (nextPlayer){
            case 'L':{

                for(int i = 0; i < 5; i++){
                    if(piece == player.player1[i][1]){
                        //DEBUG
                        cout << piece << " is currently at position " << player.player1[i][0] << endl;

                        //DEBUG

                        piecePosition = player.player1[i][0];
                    }
                }

                //convert position to integer
                try {
                     piecePositionInteger = std::stoi(piecePosition);
                    std::cout << piecePositionInteger << "\n";
                }
                catch (...) {
                    std::cerr << "ERROR!\n";
                }

                int moveTo = piecePositionInteger + moveBy;

                if(moveTo > 10){
                    moveTo -= 10;
                }

                //DEBUG
                cout << "Moving to position: " << moveTo << endl;
                //DEBUG

                //checking if the space is already occupied
                for(int i = 0; i < 5; i++){
                    if(moveTo == std::stoi(player.player2[i][0])){

                        if(player.player2[i][1] == " "){
                            //will place
                            //DEBUG
                            cout << "Can be placed" << endl;
                            //DEBUG

                            //placing the piece
                            string temp;
                            temp = piece;



                            for(int i = 0; i < 5; i++){
                                if(piece == player.player1[i][1]){

                                    //
                                    cout << player.player1[i][1] << " is now ";
                                    //
                                   player.player1[i][1] = " ";
                                   //
                                   cout << player.player1[i][1];
                                   //


                                   player.player2[moveTo][1] = temp;
                                   //
                                   cout << "New p2 value: " << player.player2[moveTo][1];
                                   //



                                }
                            }



                            refreshOutPut();

                        } else {
                            cout << "This position is already occupied" << endl;
                        }

                        //break;
                    }
                }


                break;
            }
        }

    }


    void refreshOutPut(){
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
        cout << "L score: " << player.player1score << endl;
        cout << "N score: " << player.player2score << endl;
        cout << "Player turn: " << player.player1name << endl;
        cout << endl;
        cout << "ROLL: " << generateRandomNumber()<< endl;
        cout << "Select piece: " << endl;

        //select piece
        selectPiece();

        if(isPlayerOneturn()){
            movePiece('L', selectedPiece, randomNumber);
        } else {
            movePiece('N', selectedPiece, randomNumber);
        }

    }


};