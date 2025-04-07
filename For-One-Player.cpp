#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    cout << "----- Quick Rules -----" << endl;
    cout << "Player and Bot with different names" << endl;
    cout << "Toss decides who bats or bowls" << endl;
    cout << "Number of Overs is set by user" << endl;
    cout << "Batter hits (0 to 6), opponent predicts (0 to 6)" << endl;
    cout << "If guess is correct → Batter is OUT" << endl;
    cout << "Runs add up if not OUT" << endl;
    cout << "Second player chases target" << endl;
    cout << "Higher score wins. Draw if equal" << endl << endl;

name:

    string Player1, Player2;

    cout << "Name of Player-1 : ";
    cin >> Player1;

    cout << "Assign a Name to the Bot : ";
    cin >> Player2;

    cout << endl;

    for (char &c : Player1)
    {
        c = toupper(c);
    }

    for (char &c : Player2)
    {
        c = toupper(c);
    }

    if (Player1 == Player2)
    {
        cout << "Names of Bot should be different" << endl;
        cout << "which would help in differentiating Player and Bot" << endl << endl;
        goto name;
    }

    int over;
    cout << "Enter the Number of Overs : ";
    cin >> over;

    if (over <= 0)
    {
        cout << "Number of Overs must be 1 or Above" << endl;
        return 0;
    }

    cout << endl;

    char ans;

    char Heads = 'H';

    string P1Toss, P2Toss;

    label2:

        cout << Player1 << " Select Heads(H) or Tails(T) : ";
        cin >> ans;

        cout << endl;

        ans = toupper(ans);

        if (ans != 'H' && ans != 'T')
        {
            cout << "Please Select Among 'H' or 'T'" << endl;
            goto label2;
        }

        if (ans == Heads)
        {
            P1Toss = "Heads";
            P2Toss = "Tails";
        }
        else
        {
            P1Toss = "Tails";
            P2Toss = "Heads";
        }

        cout << Player1 << " Has chosen '" << P1Toss << "'" << endl;
        cout << "And So on " << Player2 << " Remains with '" << P2Toss << "'" << endl;

    srand(time(0));
    int RndmNum = 1 + (rand() % 2);

    string coin;

    if (RndmNum == 1)
    {
        coin = "Heads";
    }
    else
    {
        coin = "Tails";
    }

    string decision;

    cout << endl;

    int P1Runs;
    int runsOfPlayer1 = 0;
    int runsOfPlayer2 = 0;
    int P1Predict;

    bool P1BatFirst = false;

    if (P1Toss == coin)
    {
        cout << "The coin is Tossed and it`s " << coin << endl;
        cout << Player1 << " won the Toss" << endl;

    label4:

        cout << Player1 << " choose Rather to Bat First or Bowl First : ";
        cin >> decision;

        cout << endl;

        for (char &c : decision)
        {
            c = toupper(c);
        }

        if (decision != "BAT" && decision != "BOWL")
        {
            cout << Player1 << " please select from 'BAT' or 'BOWL'" << endl;
            goto label4;
        }

        P1BatFirst = (decision == "BAT");
    }
    else
    {
        cout << "The coin is Tossed and it`s " << coin << endl;
        cout << Player2 << " won the Toss" << endl;

        srand(time(0));
        int batball = 1 + (rand() % 2);

        if (batball == 1)
        {
            cout << Player2 << " will Bat First";
            decision = "BAT";
        }
        else if (batball == 2)
        {
            cout << Player2 << " will Bowl First";
            decision = "BOWL";
        }

        cout << endl;

        P1BatFirst = (decision == "BOWL");
    }

    cout << endl << "First Innings Starts Now..." << endl << endl;

    if (P1BatFirst)
    {
        for (int i = 1; i <= over * 6; i++)
        {
        run1:
            cout << Player1 << " select the number of runs (0 to 6) : ";
            cin >> P1Runs;
            if (P1Runs < 0 || P1Runs > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run1;
            }

        predict1:
            
            srand(time(0));
            int BotPredict = rand() % 7;
            cout << Player2 << " predict the number (0 to 6) : " << BotPredict << endl;
            if (BotPredict < 0 || BotPredict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict1;
            }

            if (P1Runs == BotPredict)
            {
                cout << Player1 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer1 += P1Runs;
                cout << Player1 << "'s Score: " << runsOfPlayer1 << " in " << i << " balls" << endl;
            }
        }
    }
    else
    {
        for (int i = 1; i <= over * 6; i++)
        {

            predict2:
            cout << Player1 << " predict the number (0 to 6) : ";
            cin >> P1Predict;
            if (P1Predict < 0 || P1Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict2;
            }

            run2:

            srand(time(0));
            int BotRun = 0 + (rand() % 7);

            cout << Player2 << " select the number of runs (0 to 6) : " << BotRun << endl;

            if (BotRun < 0 || BotRun > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run2;
            }

            if (BotRun == P1Predict)
            {
                cout << Player2 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer2 += BotRun;
                cout << Player2 << "'s Score: " << runsOfPlayer2 << " in " << i << " balls" << endl;
            }

        }
    }

    cout << endl << "Second Innings Starts Now..." << endl << endl;

    if (P1BatFirst)
    {
        for (int i = 1; i <= over * 6; i++)
        {

            predict3:
            cout << Player1 << " predict the number (0 to 6) : ";
            cin >> P1Predict;
            if (P1Predict < 0 || P1Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict3;
            }

            run3:

            srand(time(0));
            int BotR = 0 + (rand() % 7);

            cout << Player2 << " select the number of runs (0 to 6) : " << BotR << endl;

            if (BotR < 0 || BotR > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run3;
            }

        

            if (BotR == P1Predict)
            {
                cout << Player2 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer2 += BotR;
                cout << Player2 << "'s Score: " << runsOfPlayer2 << " in " << i << " balls" << endl;
                if (runsOfPlayer2 > runsOfPlayer1)
                    break;
            }
        }
    }
    else
    {
        for (int i = 1; i <= over * 6; i++)
        {
        run4:
            cout << Player1 << " select the number of runs (0 to 6) : ";
            cin >> P1Runs;
            if (P1Runs < 0 || P1Runs > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run4;
            }

        predict4:
            srand(time(0));
            int BotP = rand() % 7;
            cout << Player2 << " predict the number (0 to 6) : " << BotP << endl;
            if (BotP < 0 || BotP > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict4;
            }

            if (P1Runs == BotP)
            {
                cout << Player1 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer1 += P1Runs;
                cout << Player1 << "'s Score: " << runsOfPlayer1 << " in " << i << " balls" << endl;
                if (runsOfPlayer1 > runsOfPlayer2)
                    break;
            }
        }
    }

    cout << endl
         << "---- Match Result ----" << endl;

    if (runsOfPlayer1 > runsOfPlayer2)
    {
        cout << Player1 << " WON THE MATCH!" << endl;
    }
    else if (runsOfPlayer2 > runsOfPlayer1)
    {
        cout << Player2 << " WON THE MATCH!" << endl;
    }
    else
    {
        cout << "MATCH DRAWN!" << endl;
    }

    return 0;
}
