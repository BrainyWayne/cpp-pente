#include <iostream>
#include <ctime>
#include <string>
using namespace std;


class Referee{

    Player player;

private:





public:
    string selectedPiece;
    int randomNumber;
    bool cancelled = false;
    string pathwayHolderDown;
    string pathwayHolderTop;
    bool player1turn = true;


    //input piece
    void selectPiece(){
        cin >> selectedPiece;
    }




    //generate a random number between 1 and 6. Serves as dice
    int generateRandomNumber(){
        srand((unsigned)time(0));
        randomNumber = rand() % 6 + 1;
        return randomNumber;
    }

    //Move selected piece
    void movePiece(char nextPlayer, string piece, int moveBy){
        //DEBUG

        string piecePosition;
        int piecePositionInteger;

        //Move piece according to which player's turn it is
        switch (nextPlayer){
            case 'L':{

                //When player L picks the wrong piece
                if(piece == "1" || piece == "2" || piece == "3" || piece == "4" || piece == "5" ){
                    cout << endl << "You picked the wrong piece" << endl;
                    refreshOutPut();
                }

                //check the position of the selected piece
                for(int i = 0; i < 5; i++){
                    if(piece == player.player1[i][1]){

                        piecePosition = player.player1[i][0];
                        cout << endl << "Selected piece is: " << piecePosition << endl;
                    }
                }

                //convert position to integer
                try {
                     piecePositionInteger = std::stoi(piecePosition);
                }
                catch (...) {
                    std::cerr << "L ERROR!\n";
                }

                int moveTo = piecePositionInteger + moveBy;
                cout << endl << "Raw moveTo: " << moveTo;

                if(moveTo > 10){
                    moveTo -= 10;
                }

                cout << endl << "Adjusted moveTo" << moveTo << endl;



                if(moveTo == 6 || moveTo == 7 || moveTo == 8 || moveTo == 9 || moveTo == 10){
                    cout <<endl << "Local zone" << endl;
                    string temp;
                    temp = piece;
                    for(int i = 0; i < 5; i++){
                        if (moveTo == stoi(player.player1[i][0])){
                            if(player.player1[i][1] == " "){
                                cout << endl << "Blank space" << endl;
                                cout << "Piece: " << piece;
                                cout << endl << "To replace: " << player.player1[i][1];
                                for(int i = 0; i < 5; i++){
                                    if(player.player1[i][1] == piece){
                                        player.player1[i][1] = " ";
                                    }
                                }
                                player.player1[i][1] = temp;

                                cout << "New value" << player.player1[i][1];
                                player1turn = false;
                                refreshOutPut();

                            }
                        }
                    }



                    refreshOutPut();
                }

//


                //checking if the space is already occupied
                for(int i = 0; i < 5; i++){
                    if(moveTo == std::stoi(player.player2[i][0])){

                        //Check if piece landed on a sacred line
                        if(player.player2[i][0] == pathwayHolderDown){

                            if(player.player1score == 4){
                                cout << endl << endl << "PLAYER L WINS!!!" << endl;
                            }

                            cout << "Pathway" << endl;
                            string temp;
                            temp = piece;
                            for(int i = 0; i < 5; i++){
                                if(piece == player.player1[i][1]){

                                    //Set selected piece to blank
                                    player.player1[i][1] = " ";


                                    //Add to sacred line
                                  for(int i = 0; i<4; i++){
                                      if(player.lowerSacred[i] == " "){
                                          player.lowerSacred[i] = temp;
                                          player.player1score++;
                                          break;
                                      }
                                  }



                                }
                            }

                            refreshOutPut();
                        }

                        else if(player.player2[i][1] == " "){

                            //placing the piece
                            string temp;
                            temp = piece;
                            cout << endl<< "Placing in foreign" << endl;



                            for(int i = 0; i < 5; i++){
                                if(piece == player.player1[i][1]){


                                   player.player1[i][1] = " ";


                                   player.player2[moveTo][1] = temp;


                                }
                            }



                            refreshOutPut();

                        }


                        else {
                            cout << "This position is already occupied" << endl;

                            //Ability to forfeit
                            cout <<"Do you want to try again? y/n" << endl;
                            string forfeit;
                            cin >> forfeit;

                            if(forfeit == "y" || forfeit == "Y"){
                                refreshOutPut();
                            } else if(forfeit == "n" || forfeit == "N"){
                                //move to player 2
                                player1turn = false;
                                refreshOutPut();
                            }

                        }

                        //break;
                    }


                }


                break;
            }
            case 'N':{
                {

                    for(int i = 0; i < 5; i++){
                        if(piece == player.player2[i][1]){


                            piecePosition = player.player2[i][0];
                        }
                    }

                    //convert position to integer
                    try {
                        cout << "Position: " << piecePosition;
                        piecePositionInteger = std::stoi(piecePosition);
                        std::cout << piecePositionInteger << "\n";
                    }
                    catch (...) {
                      //  std::cerr << "ERROR!\n";
                    }

                    int moveTo = piecePositionInteger + moveBy;


                    if(moveTo > 10){
                        moveTo -= 10;
                    }

                    if(moveTo == 1 || moveTo == 2 || moveTo == 3 || moveTo == 4 || moveTo == 5){
                        cout <<endl << "Local zone" << endl;
                        string temp;
                        temp = piece;
                        for(int i = 0; i < 5; i++){
                            if (moveTo == stoi(player.player2[i][0])){
                                if(player.player2[i][1] == " "){
                                    cout << endl << "Blank space" << endl;
                                    cout << "Piece: " << piece;
                                    cout << endl << "To replace: " << player.player2[i][1];
                                    for(int i = 0; i < 5; i++){
                                        if(player.player2[i][1] == piece){
                                            player.player2[i][1] = " ";
                                        }
                                    }
                                    player.player2[i][1] = temp;

                                    cout << "New value" << player.player2[i][1];
                                    player1turn = true;
                                    refreshOutPut();

                                }
                            }
                        }



                        refreshOutPut();
                    }



                    //checking if the space is already occupied
                    for(int i = 0; i < 5; i++){
                        if(moveTo == std::stoi(player.player1[i][0])){


                            if(player.player1[i][0] == pathwayHolderTop){
                                string temp;
                                temp = piece;
                                for(int i = 0; i < 5; i++){
                                    if(piece == player.player2[i][1]){


                                        player.player2[i][1] = " ";


                                        for(int i = 0; i<4; i++){
                                            if(player.upperSacred[i] == " "){
                                                player.upperSacred[i] = temp;
                                                player.player2score++;
                                                break;
                                            }
                                        }



                                    }
                                }

                                refreshOutPut();
                            }

                            else if(player.player1[i][1] == " "){
                                //will place


                                //placing the piece
                                string temp;
                                temp = piece;



                                for(int i = 0; i < 5; i++){
                                    if(piece == player.player2[i][1]){


                                        player.player2[i][1] = " ";

                                        player.player1[moveTo][1] = temp;



                                    }
                                }



                                refreshOutPut();

                      }
//                            else if(moveTo < 6){
//                                cout << endl << "Localized move" << endl;
//
//                                for(int i = 0; i<5; i++){
//                                    if(player.player2[i][0] == to_string(moveTo)){
//                                        if(player.player2[i][1] == " "){
//
//                                            player.player2[i][1] = piece;
//
//
//                                        } else {
//                                            cout << "This space is occupied" << endl;
//                                            //Ability to forfeit
//                                            cout <<"Do you want to try again? y/n" << endl;
//                                            string forfeit;
//                                            cin >> forfeit;
//
//                                            if(forfeit == "y" || forfeit == "Y"){
//                                                refreshOutPut();
//                                            } else if(forfeit == "n" || forfeit == "N"){
//                                                //move to player 1
//                                                player1turn = true;
//                                                refreshOutPut();
//                                            }
//                                        }
//                                    }
//                                }
//
//                            }
                            else {
                                cout << "This position is already occupied" << endl;

                                //Ability to forfeit
                                cout <<"Do you want to try again? y/n" << endl;
                                string forfeit;
                                cin >> forfeit;

                                if(forfeit == "y" || forfeit == "Y"){
                                    refreshOutPut();
                                } else if(forfeit == "n" || forfeit == "N"){
                                    //move to player 1
                                    player1turn = true;
                                    refreshOutPut();
                                }

                            }

                            //break;
                        }
                    }


                    break;
                }
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


        if(player1turn){
            cout << "Player turn: " << player.player1name << endl;
        } else{
            cout << "Player turn: " << player.player2name << endl;
        }


        cout << endl;
        cout << "ROLL: " << generateRandomNumber()<< endl;
        cout << "Select piece: " ;

        //select piece
        selectPiece();

        if(player1turn){
            movePiece('L', selectedPiece, randomNumber);
        } else {
            movePiece('N', selectedPiece, randomNumber);
        }

    }


    void setCurrentPathwayHolderDown(string holder){
        pathwayHolderDown = holder;
        cout << "Current down path way holder is " << pathwayHolderDown << endl;
    }

    void setCurrentPathwayHolderTop(string holder){
        pathwayHolderTop = holder;
        cout << "Current top path way holder is " << pathwayHolderTop << endl;
    }

};