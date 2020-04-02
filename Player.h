#include <iostream>
#include <array>


using namespace std;


class Player {



public:

    //player allocations
    string player1[5][5] = {{"10","A"},{"9","B"},{"8","C"},{"7","D"},{"6","E"},};
    string player2[5][5] = {{"1","1"},{"2","2"},{"3","3"},{"4","4"},{"5","5"},};

    //Sacred lines
    string upperSacred[4] = {" "," ", " ", " " };
    string lowerSacred[4] = {" "," ", " ", " " };

    //Scores
    int player1score = 0;
    int player2score = 0;

    //Playernames
    string player1name = "L";
    string player2name = "N";





    char playerTurn(bool turn){
        if(turn){
            return 'L';
        } else {
            return 'N';
        }
    }



};