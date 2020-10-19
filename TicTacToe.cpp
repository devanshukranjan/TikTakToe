#include<iostream>
using namespace std;
string playAgain()
{
    string X;
    cout<<"Would you like to play again?  (Y/N)\n";
    getline(cin,X);
    if(X=="Y"||X=="N")
    {
        return X;
    }
    else
    {
        cout<<X<<" is not a valid answer.";
        playAgain();
    }
}
int main()
{
    string X,O,f,s,c;
    do
    {
        string a[3][3]={".",".",".",".",".",".",".",".","."};
        cout<<"Enter a name of the X player:\n";
        getline(cin,X);
        cout<<"Enter a name of the O player:\n";
        getline(cin,O);
        cout<<"Who plays first, "<<X<<" or "<<O<<"?\n";
        getline(cin,f);
        if(f==X)
        {
            s=O;
            X="X";
            O="O";
        }
        else
        {
            s=X;
            X="O";
            O="X";
        }
        for(int i=1;i<=3;i++)
        {
            cout<<" . . .\n";
        }
        for(int i=0;i<9;i++)
        {
            if(i%2==0)
                cout<<"Player of current turn: "<<f<<endl;
            else
                cout<<"Player of current turn: "<<s<<endl;
            int r=-1,c=-1;
            while(!(r>=0&&r<=2))
            {
                cout<<"Choose a row number (0 to 2):\n";
                cin>>r;
                if(!(r>=0&&r<=2))
                    cout<<r<<" is not a valid row.\n";
            }
            while(!(c>=0&&c<=2))
            {
                cout<<"Choose a column number (0 to 2):\n";
                cin>>c;
                if(!(c>=0&&c<=2))
                    cout<<r<<" is not a valid column.\n";
            }
            if(a[r][c]==".")
            {
                if(i%2==0)
                    a[r][c]=X;
                else
                    a[r][c]=O;
            }
            else
            {
                cout<<"Error!! This grid is full, Enter again.\n";
                i--;
                continue;
            }
            for(int j=0;j<3;j++)
            {
                cout<<" "<<a[j][0]<<" "<<a[j][1]<<" "<<a[j][2]<<"\n";
            }
            if(i>=4)
            {
                if((a[0][0]==X&&a[1][1]==X&&a[2][2]==X)||(a[0][2]==X&&a[1][1]==X&&a[2][0]==X)||(a[0][0]==X&&a[0][1]==X&&a[0][2]==X)
                ||(a[1][0]==X&&a[1][1]==X&&a[1][2]==X)||(a[2][0]==X&&a[2][1]==X&&a[2][2]==X)||(a[0][0]==X&&a[1][0]==X&&a[2][0]==X)
                ||(a[0][1]==X&&a[1][1]==X&&a[2][1]==X)||(a[0][2]==X&&a[1][2]==X&&a[2][2]==X))
                {
                    cout<<"Game is Over:\n"<<f<<" wins!\n";
                    break;
                }
                else if((a[0][0]==O&&a[1][1]==O&&a[2][2]==O)||(a[0][2]==O&&a[1][1]==O&&a[2][0]==O)||(a[0][0]==O&&a[0][1]==O&&a[0][2]==O)
                        ||(a[1][0]==O&&a[1][1]==O&&a[1][2]==O)||(a[2][0]==O&&a[2][1]==O&&a[2][2]==O)||(a[0][0]==O&&a[1][0]==O&&a[2][0]==O)
                        ||(a[0][1]==O&&a[1][1]==O&&a[2][1]==O)||(a[0][2]==O&&a[1][2]==O&&a[2][2]==O))
                {
                    cout<<"Game is Over:\n"<<s<<" wins!\n";
                    break;
                }
                else if(i==9)
                {
                    cout<<"Game is over:\n"<<"it is tie!\n";
                    break;
                }
            }
        }
        c=playAgain();
    }while(c!="N");
    cout<<"Bye!\n";
}
