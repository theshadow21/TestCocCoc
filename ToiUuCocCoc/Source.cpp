#include <iostream>
#include<string>

using namespace std;

struct ViTri
{
    double x, y;
};

char map[100][100];
ViTri Robot;

//Duong thang di qua A, B
int lineEquation(ViTri A, ViTri B, double x) {
    return (B.y - A.y) / (B.x - A.x) * (x - A.x) + A.y;
}
//Kiem tra 1 diem co nam tren doan thang AB khong
bool isOnline(ViTri A, ViTri B, ViTri C) {
    double y = lineEquation(A, B, C.x);
    return(y == C.y && C.x >= min(A.x, B.x) && C.x <= max(A.x, B.x));
}


void moveTo(int x, int y) {
    map[x][y] = '+';
    Robot.x = x;
    Robot.y = y;
}
void lineTo(int x, int y, int i, int j) {
    map[x][y] = '+';
    ViTri Check = { i,j };
    ViTri Finish_Cur = { x,y };
    if (isOnline(Robot, Finish_Cur, Check)) {
        map[i][j] = '+';
    }
}

int main() {/*
    FILE* stream;
    freopen_s(&stream, "input.txt", "r", stdin);*/

    char dimension[] = "DIMENSION";
    char move[] = "MOVE_TO";
    char line[] = "LINE_TO";
    char shut[] = "SHUT";

    char command[10];
    double x, y;
    int n;
    bool flag = false;

    while(1) {
        cin >> command;
        if (strcmp(command, dimension)==0)
        {
            flag = true;
            cin >> n;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = '0';
                }
            }
        }
        else if (strcmp(command, move)==0)
        {
            cin >> x;
            cin.ignore();
            cin >> y;
            moveTo(x, y);
        }
        else if (strcmp(command, line)==0)
        {

            cin >> x;
            cin.ignore();
            cin >> y;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    lineTo(x, y, i, j);
                }
            }
            Robot.x = x;
            Robot.y = y;

        }
        else if (strcmp(command, shut) == 0) {
            break;
        }
        else {
            cout << "wrong input, try again" << endl;
            cout << "DIMENSION n      MOVE_TO x,y      LINE_TO x,y      SHUT" << endl;
            cin.clear();
            cin.ignore(10, '\n');  
        }   
    }
    if(flag){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "|" << " " << map[i][j] <<" ";
            }
            cout << "|";
            cout << endl;
        }
    }
    return 0;
}