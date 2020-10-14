#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<sstream>
using namespace std;

char testcase[10000];

int Matrix[50][50];
int row, col;


class Block{
public:
    Block(string, int, int);
    ~Block();
    void index(string, int);
    void falling(Block&);
    void moving(Block&, int);
    void delet();
    void replace(int);
    int gameover();
    
private:
    string type;
    int place;
    int move;
    int b1_x, b1_y, b2_x, b2_y, b3_x, b3_y, b4_x, b4_y;
};



Block::Block(string typ, int plac, int mov){
    type = typ;
    place = plac;
    move = mov;
    this -> index(type, place);
}

Block::~Block(){
    
}

void Block::falling(Block &a){
    while(Matrix[a.b1_y+1][a.b1_x] == 0 && Matrix[a.b2_y+1][a.b2_x] == 0 && Matrix[a.b3_y+1][a.b3_x] == 0 && Matrix[a.b4_y+1][a.b4_x] == 0){
        if(a.b1_y+1 >= row+5 || a.b2_y+1 >= row+5 || a.b3_y+1 >= row+5 || a.b4_y+1 >= row+5){
            break;
        }
        a.b1_y += 1;
        a.b2_y += 1;
        a.b3_y += 1;
        a.b4_y += 1;
    }
    
}

void Block::moving(Block &a, int move){
    a.b1_x += move;
    a.b2_x += move;
    a.b3_x += move;
    a.b4_x += move;
    if(Matrix[a.b1_y+1][a.b1_x] == 0 && Matrix[a.b2_y+1][a.b2_x] == 0 && Matrix[a.b3_y+1][a.b3_x] == 0 && Matrix[a.b4_y+1][a.b4_x] == 0){
        a.falling(a);
    }
    Matrix[a.b1_y][a.b1_x] = 1;
    Matrix[a.b2_y][a.b2_x] = 1;
    Matrix[a.b3_y][a.b3_x] = 1;
    Matrix[a.b4_y][a.b4_x] = 1;
    
}

void Block::delet(){
    int row_del;
    int flag;
    for(int i = 5; i <= row + 4; i++){
        flag=0;
        for(int j = 1; j <= col; j++){
            if(Matrix[i][j] == 0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            row_del = i;
            replace(row_del);
        }

    }
}

void Block::replace(int row_del){
    int tmp[15][40];
    for(int i = 1; i < row_del - 4; i++){
        for(int j = 1; j <= col; j++){
            tmp[i][j] = Matrix[i+4][j];
        }
    }
    for(int i = 1; i <= col; i++){
        Matrix[5][i] = 0;
    }
    for(int i = 2; i <= row_del - 4; i++){
        for(int j = 1; j <= col; j++){
            Matrix[i+4][j] = tmp[i - 1][j];
        }
    }
}

int Block::gameover(){
    if(b1_y <= 3 || b2_y <= 3 || b3_y <= 3 || b4_y <= 3){
        return 1;
    }
    return 0;
}


void Block::index(string type, int place){
    if(type == "T1"){
        b1_y = 3;
        b1_x = place;
        b2_y = 3;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 2;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "T2"){
        b1_y = 3;
        b1_x = place;
        b2_y = 2;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "T3"){
        b1_y = 4;
        b1_x = place;
        b2_y = 3;
        b2_x = place + 1;
        b3_y = 4;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 2;
    }
    else if(type == "T4"){
        b1_y = 2;
        b1_x = place;
        b2_y = 3;
        b2_x = place;
        b3_y = 4;
        b3_x = place;
        b4_y = 3;
        b4_x = place + 1;
    }
    else if(type == "L1"){
        b1_y = 2;
        b1_x = place;
        b2_y = 3;
        b2_x = place;
        b3_y = 4;
        b3_x = place;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "L2"){
        b1_y = 3;
        b1_x = place;
        b2_y = 4;
        b2_x = place;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 3;
        b4_x = place + 2;
    }
    else if(type == "L3"){
        b1_y = 2;
        b1_x = place;
        b2_y = 2;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "L4"){
        b1_y = 4;
        b1_x = place;
        b2_y = 4;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 2;
        b4_y = 4;
        b4_x = place + 2;
    }
    else if(type == "J1"){
        b1_y = 4;
        b1_x = place;
        b2_y = 2;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "J2"){
        b1_y = 3;
        b1_x = place;
        b2_y = 4;
        b2_x = place;
        b3_y = 4;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 2;
    }
    else if(type == "J3"){
        b1_y = 2;
        b1_x = place;
        b2_y = 3;
        b2_x = place;
        b3_y = 4;
        b3_x = place;
        b4_y = 2;
        b4_x = place + 1;
    }
    else if(type == "J4"){
        b1_y = 3;
        b1_x = place;
        b2_y = 3;
        b2_x = place + 1;
        b3_y = 3;
        b3_x = place + 2;
        b4_y = 4;
        b4_x = place + 2;
    }
    else if(type == "S1"){
        b1_y = 4;
        b1_x = place;
        b2_y = 3;
        b2_x = place + 1;
        b3_y = 4;
        b3_x = place + 1;
        b4_y = 3;
        b4_x = place + 2;
    }
    else if(type == "S2"){
        b1_y = 2;
        b1_x = place;
        b2_y = 3;
        b2_x = place;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 1;
    }
    else if(type == "Z1"){
        b1_y = 3;
        b1_x = place;
        b2_y = 3;
        b2_x = place + 1;
        b3_y = 4;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 2;
    }
    else if(type == "Z2"){
        b1_y = 3;
        b1_x = place;
        b2_y = 4;
        b2_x = place;
        b3_y = 2;
        b3_x = place + 1;
        b4_y = 3;
        b4_x = place + 1;
    }
    else if(type == "I1"){
        b1_y = 1;
        b1_x = place;
        b2_y = 2;
        b2_x = place;
        b3_y = 3;
        b3_x = place;
        b4_y = 4;
        b4_x = place;
    }
    else if(type == "I2"){
        b1_y = 4;
        b1_x = place;
        b2_y = 4;
        b2_x = place + 1;
        b3_y = 4;
        b3_x = place + 2;
        b4_y = 4;
        b4_x = place + 3;
    }
    else if(type == "O"){
        b1_y = 3;
        b1_x = place;
        b2_y = 4;
        b2_x = place;
        b3_y = 3;
        b3_x = place + 1;
        b4_y = 4;
        b4_x = place + 1;
    }
}


int main(int argc, char* argv[]){

    ifstream file;
    char N[10];
    file.open(argv[1]);
    file.getline(N,10);
    stringstream ss(N);
    ss>>row;
    ss>>col;
    
    string shape;
    int place, move;
    
    //cin >> row >> col;
    for(int i = 1; i <= row + 4; i++){
        for(int j = 1; j <= col; j++){
            Matrix[i][j] = 0;
        }
    }
    
    while(!file.eof()){
        char N[100];
        file.getline(N,10);
        stringstream ss(N);
        ss>>shape;
        ss>>place;
        ss>>move;
        //cin >> shape;
        if(shape == "End"){
            break;
        }
        //cin >> place >> move;
        Block a(shape, place, move);
        a.falling(a);
        a.moving(a, move);
        a.delet();
        
    }
    //列印結果
    for(int i = 5; i <= row + 4; i++){
        for(int j = 1; j <= col; j++){
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


