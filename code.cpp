#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

bool IsNum(string x){
    for(int  i = (x[i] == '-'); i < x.size(); ++i){
        if(x[i] > '9' || x[i] < '0')return 0;
    }
    return 1;
}

int toNum(string x){
    int ans = 0;
    for(int i = (x[0] == '-'); i < x.size(); ++i){
        int mnj = 1;
        for(int j = 0; j < x.size() - i - 1; ++j ){
            mnj *= 10;
        }
        ans += mnj*(x[i] - '0');
    }
    return ans - 2 * ans * (x[0] == '-');
}

int main(){
    int n1,n2;
    int score = 0;
    string ans;
    string live = "***";
    char oo[3] = {'+','-','*'};
    string name;
    cout << "Enter your name" << endl;
    cin >> name;
    char b;
    system ("cls");
    cout << "Press any button to start" << endl;
    b = getch();
    system("cls");
    while (true)
    {
        system ("cls");
        if(live == "") {
            system ("cls");
            break;
        }
        srand(time(0));
        n1 = rand() % 16;
        n2 = rand() % 16;
        int rd = rand () % 3;
        cout << "score: " << score << "   life: " <<   live << endl; 
        cout << endl;
        cout << n1 << " "<< oo[rd] << " " << n2 << endl << endl;
        double tm = clock();
        cin >> ans;
        double tmm = (clock() - tm) / CLOCKS_PER_SEC;
        if(tmm <= 5 && IsNum(ans)){
        if(oo[rd] == '*'){
            if(n1 * n2 == toNum(ans)){
                if(tmm <= 2)score += 10;
                else score += 5;
            }   
            else {
                live.erase(0,1);
            }            
        }
        else if(oo[rd] == '+'){
            if(n1 + n2 == toNum(ans)){
                if(tmm <= 2)score += 10;
                else score += 5;
            }
            else {
                live.erase(0,1);
            } 
        }
        else if(oo[rd] == '-'){
            if(n1 - n2 == toNum(ans)){
                if(tmm <= 2)score += 10;
                else score += 5;
            } 
             else {
                live.erase(0,1);
            } 
        }
        }
        else {
            live.erase(0,1);
        }
    }
    freopen("tab.txt","r",stdin);
    int scr;
    string x;
    cin >> x >> scr;
    if(score > scr){
        x = name;
        scr = score;
    }
    freopen("tab.txt","w+",stdout);
    cout << x << ' ' << scr;
    fclose(stdout);
    fclose(stdin);
    freopen("CON","w",stdout);  
    for(int i = 0; i < 4; ++i)cout << endl;
                cout << "GAME IS OVER" << endl;
            cout << "Score: " << score << endl;
            cout << "Best result: " << x << ' ' << scr;
            for(int i = 0; i < 4; ++i)
                cout << endl;
    return 0;
}
