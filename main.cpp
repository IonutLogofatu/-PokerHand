#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int firstPair, secondPair, firstMax, secondMax, egal1,egal2;
int highCard(string hand[100]){
    int nr, i, max = 0, trans;
    for(i = 1; i <= 5; i++){
        if((int)hand[i][0] - 48 > 10)
        {
            if(hand[i][0] == 'J'){
                trans = 11;
            }else if(hand[i][0] == 'Q'){
                trans = 12;
            }else if(hand[i][0] == 'K'){
                trans = 13;
            }else{
                trans = 14;
            }
        }else{
            trans = (int)hand[i][0] - 48;
        }if( trans > max){
            max = trans;
        }
    }
    return max;
}

int highCardEquality(string hand[100], int maximum){
    int nr, i, max = 0, trans;
    for(i = 1; i <= 5; i++){
        if((int)hand[i][0] - 48 > 10){
            if(hand[i][0] == 'J'){
                trans = 11;
            }else if(hand[i][0] == 'Q'){
                trans = 12;
            }else if(hand[i][0] == 'K'){
                trans = 13;
            }else{
                trans = 14;
            }
        }else{
            trans = (int)hand[i][0] - 48;
        }if( trans > max && trans < maximum){
            max = trans;
        }
    }
    return max;
}

bool flush(string hand[100]){
    int i = 1, rep = 0;;
    for( i = 1; i < 5; i++){
        if(hand[i+1][1] == hand[i][1]){
            rep++;
        }
    }
    if(rep == 4){
        return true;
    }else{
        return false;
    }
}


bool straightFlush(string hand[100]){
    int i = 1, rep = 0;
    for( i = 1; i < 5; i++){
        if(hand[i+1][1] == hand[i][1] && (((int)hand[i+1][0] - 48) - ((int)hand[i][0]-48) == 1)){
            rep++;
        }
    }
    if(rep == 4){
        return true;
    }else{
        return false;
    }
}

bool fourOfAKind(string hand[100]){
    int i = 1, rep = 0;;
    for( i = 1; i < 5; i++){
        if(hand[i+1][0] == hand[i][0] ){
            rep++;
        }
    }
    if(rep == 3){
        return true;
    }else{
        return false;
    }
}

int highPair(string hand[100]){
    int i, j, nr =0;
    for( i =1; i <= 3; i++){
        for( j = 1; j <= 5; j++){
            if( i != j){
                if(hand[i][0] == hand[j][0]){
                    nr++;
                }
            }
        }
        if(nr == 1){
            return (int)hand[i][0] - 48;
        }
        nr = 0;
    }
    return false;
}

bool singlePair(string hand[100]){
    int i, j, nr =0;
    for( i =1; i <= 3; i++){
        for( j = 1; j <= 5; j++){
            if( i != j){
                if(hand[i][0] == hand[j][0]){
                    nr++;
                }
            }
        }
        if(nr == 1){
            return true;
        }
        nr = 0;
    }
    return false;
}

bool pairs(string hand[100]){
    int i, nr = 0, j;
    for( i =1; i <= 3; i++){
        for( j = 1; j <= 5; j++){
            if( i != j){
                if(hand[i][0] == hand[j][0]){
                    nr++;
                }
            }
        }
        if(nr == 2){
            return true;
        }
        nr = 0;
    }
    return false;
}

int maxim(string hand[100])
{
    int i = 1, max =0;
    for( i =1; i <= 5; i++){
        if(max < (int)hand[i][0] - 48){
            max = (int)hand[i][0] - 48;
        }
    }
    return max;
}
bool Straight(string hand[100]){
    int i = 1, rep = 0;;
    for( i = 1; i < 5; i++){
        if(((int)hand[i+1][0] - 48) - ((int)hand[i][0]-48) == 1){
            rep++;
        }
        if(rep == 4){
            return true;
        }
        rep = 0;
    }
    return false;
}

int highThreeofAKind(string hand[100]){
    int i =1, nr = 0, j;
    for( i =1; i <= 3; i++){
        for( j = 1; j <= 5; j++){
            if(i != j){
                if(hand[i][0] == hand[j][0]){
                    nr++;
                }
            }
        }
        if(nr == 2){
            return (int)hand[i][0] - 48;
        }
        nr =0;
    }
}

bool threeOfAKinf( string hand[100]){
    int i =1, nr = 0, j;
    for( i =1; i <= 3; i++){
        for( j = 1; j <= 5; j++){
            if(i != j){
                if(hand[i][0] == hand[j][0]){
                    nr++;
                }
            }
        }
        if(nr == 2){
            return true;
        }
        nr =0;
    }
    return false;
}

void read(string player[100]){
    for(int i= 1; i <= 5; i++){
        cout<<"Cartea "<<i<<" ";
        cin>>player[i];
        if(player[i][1] == '0'){
            if(player[i][2] != 'C' && player[i][2] != 'D' && player[i][2] != 'S' && player[i][2] != 'H' ){
            cout<<"Invalid card ";
            break;
           }
        }else if(player[i][1] != 'C' && player[i][1] != 'D' && player[i][1] != 'S' && player[i][1] != 'H' ){
            cout<<"Invalid card ";
            break;
        }
    }
}

int combination(string player[100]){
    if(straightFlush(player)== true){
        return 1;
    }else if(fourOfAKind(player) == true){
        return 2;
    }else if((threeOfAKinf(player) == true) && singlePair(player) == true){
        return 3;
    }else if(flush(player) == true){
        return 4;
    }else if(Straight(player) == true){
        return 5;
    }else if(threeOfAKinf(player) == true){
        return 6;
    }else if(pairs(player) == true){
        return 7;
    }else if(singlePair(player) == true){
        return 8;
    }else{
        return 9;
    }
}

void afiasare(int option){
    switch(option){
    case 1:
        cout<<" Royal flush";
        break;
    case 2:
        cout<<" Four of a kind";
        break;
    case 3:
        cout<<"Full house";
        break;
    case 4:
        cout<<"Flush ";
        break;
    case 5:
        cout<<"Straight";
        break;
    case 6:
        cout<<"Three of a kind";
        break;
    case 7:
        cout<<"Two Pairs";
        break;
    case 8:
        cout<<"Pair";
        break;
    }
}

void highCardPrint(int option){
    if(option > 10){
        switch(option)
        {
        case 11:
            cout<<": Jalet";
            break;
        case 12:
            cout<<": Quin ";
            break;
        case 13:
            cout<<": King ";
            break;
        case 14:
            cout<<": Ace ";
            break;
        }
    }else{
        cout<<": "<<option;
    }
}




void highPairWinner(string Black[100], string White[100]){
    firstPair = highPair(Black);
    secondPair = highPair(White);
    if(firstPair > secondPair){
        cout<<"Black wins with: "<<firstPair<<" Pair";
    }else if(firstPair < secondPair){
        cout<<"White wins with: "<<secondPair<<" Pair";
    }else{
        cout<<"Tie";
    }
}

void straightWinner(string Black[100], string White[100]){
    firstMax = maxim(Black);
    secondMax = maxim(White);
    if(firstMax < secondMax){
        cout<<"White wins with "<<secondMax<<" Straight";
    }else if(firstMax > secondMax){
        cout<<"Black wins with "<<firstMax<<" Straight";
    }else{
        cout<<"Straight Tie";
    }
}

void threeOfAKindWinner(string Black[100], string White[100]){
    firstMax = highThreeofAKind(Black);
    secondMax = highThreeofAKind(White);
    if(firstMax < secondMax){
        cout<<"White wins with "<<secondMax<<" Three of a kind";
    }else if(firstMax > secondMax){
        cout<<"Black wins with "<<firstMax<<" Three of a kind";
    }
}

void FullHouseWinner(string Black[100], string White[100]){
    firstMax = highThreeofAKind(Black);
    secondMax = highThreeofAKind(White);
    if(firstMax < secondMax){
        cout<<"White wins with "<<secondMax<<" Three of a kind";
    }else if(firstMax > secondMax){
        cout<<"Black wins with "<<firstMax<<" Three of a kind";
    }else{
        firstPair =highPair(Black);
        secondPair =highPair(White);
        if(firstPair < secondPair){
            cout<<"White wins with "<<secondMax<<" And "<<secondPair<<" Full house";
        }else if(firstPair > secondPair){
            cout<<"Black wins with "<<firstMax<<" And "<<firstPair<<" Full house";
        }
    }
}

int main(){
    string black[100];
    string white[100];
    int i, first, second, highFirst, highSecond;
    bool gasit = false;
    cout<<"Black "<<endl;
    read(black);
    cout<<endl<<"White "<<endl;
    read(white);
    first = combination(black);
    second = combination(white);

    if(first < second){
        cout<<endl<<"Black wins with ";
        afiasare(first);
    }else if(first > second){
        cout<<"White wins with ";
        afiasare(second);
    }else if( first == 9 && second == 9){
        highFirst = highCard(black);
        highSecond = highCard(white);
        if(highFirst < highSecond){
            cout<<"White wins with high card";
            highCardPrint(highSecond);
        }else if(highFirst > highSecond){
            cout<<"Black wins with high card";
            highCardPrint(highFirst);
        }else{
            i = 1;
            while( gasit != true && i < 5){
                egal1 = highCardEquality(black,highFirst);
                egal2 = highCardEquality(white, highSecond);
                if(egal1 == egal2){
                    highFirst =egal1;
                    highSecond = egal2;
                    i++;
                }else{
                    gasit = true;
                    highFirst = egal1;
                    highSecond = egal2;
                }
            }
            if( highFirst == highSecond){
                cout<<" Tie";
            }else{
                if(highFirst > highSecond){
                    cout<<"Black wins with high card";
                    highCardPrint(highSecond);
                }else{
                    cout<<"White wins with high card";
                    highCardPrint(highFirst);
                }
            }
        }
    }else if(first == second){

        switch(first){
        case 1:
            straightWinner(black, white);
            break;
        case 2:
            FullHouseWinner(black, white);
            break;
        case 5:
            straightWinner(black, white);
            break;
        case 6:
            threeOfAKindWinner(black, white);
            break;
        case 8:
            highPairWinner(black, white);
            break;
        }
    }
}
