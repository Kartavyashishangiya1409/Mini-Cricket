#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    cout << "----- Quick Rules -----" << endl;
    cout << "2 player with different names" << endl;
    cout << "Toss decides who bats or bowls" << endl;
    cout << "Number of Overs is set by user" << endl;
    cout << "Batter hits (0–6), opponent predicts (0–6)" << endl;
    cout << "If guess is correct → Batter is OUT" << endl;
    cout << "Runs add up if not OUT" << endl;
    cout << "Second player chases target" << endl;
    cout << "Higher score wins. Draw if equal" << endl << endl;

name:

    string Player1, Player2;

    cout << "Name of Player-1 : ";
    cin >> Player1;

    cout << "Name of Player-2 : ";
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
        cout << "Names of both players should be different" << endl;
        cout << "which would help in differentiating both players" << endl << endl;
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

label1:
    int Toss;

    cout << "Who Wants to Select the Toss? [" << Player1 << " = (1) or " << Player2 << " = (2)] : ";
    cin >> Toss;

    cout << endl;

    char ans;

    char Heads = 'H';
    char Tails = 'T';

    string P1Toss, P2Toss;

    switch (Toss)
    {
    case 1:

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

        break;

    case 2:

    label3:

        cout << Player2 << " Select Heads(H) or Tails(T) : ";
        cin >> ans;

        cout << endl;

        ans = toupper(ans);

        if (ans != 'H' && ans != 'T')
        {
            cout << "Please Select Among 'H' or 'T'" << endl;
            goto label3;
        }

        if (ans == Heads)
        {
            P2Toss = "Heads";
            P1Toss = "Tails";
        }
        else
        {
            P2Toss = "Tails";
            P1Toss = "Heads";
        }

        cout << Player2 << " Has chosen '" << P2Toss << "'" << endl;
        cout << "And So on " << Player1 << " Remains with '" << P1Toss << "'" << endl;

        break;

    default:
        cout << "Please Select Among 1 and 2" << endl;
        goto label1;
    }

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

    int P1Runs, P2Runs;
    int runsOfPlayer1 = 0;
    int runsOfPlayer2 = 0;
    int P1Predict, P2Predict;

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

    label5:

        cout << Player2 << " choose Rather to Bat First or Bowl First : ";
        cin >> decision;

        cout << endl;

        for (char &c : decision)
        {
            c = toupper(c);
        }

        if (decision != "BAT" && decision != "BOWL")
        {
            cout << Player2 << " please select from 'BAT' or 'BOWL'" << endl;
            goto label5;
        }

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
            cout << Player2 << " predict the number (0 to 6) : ";
            cin >> P2Predict;
            if (P2Predict < 0 || P2Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict1;
            }

            if (P1Runs == P2Predict)
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
        run2:
            cout << Player2 << " select the number of runs (0 to 6) : ";
            cin >> P2Runs;
            if (P2Runs < 0 || P2Runs > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run2;
            }

        predict2:
            cout << Player1 << " predict the number (0 to 6) : ";
            cin >> P1Predict;
            if (P1Predict < 0 || P1Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict2;
            }

            if (P2Runs == P1Predict)
            {
                cout << Player2 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer2 += P2Runs;
                cout << Player2 << "'s Score: " << runsOfPlayer2 << " in " << i << " balls" << endl;
            }
        }
    }

    cout << endl << "Second Innings Starts Now..." << endl << endl;

    if (P1BatFirst)
    {
        for (int i = 1; i <= over * 6; i++)
        {
        run3:
            cout << Player2 << " select the number of runs (0 to 6) : ";
            cin >> P2Runs;
            if (P2Runs < 0 || P2Runs > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto run3;
            }

        predict3:
            cout << Player1 << " predict the number (0 to 6) : ";
            cin >> P1Predict;
            if (P1Predict < 0 || P1Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict3;
            }

            if (P2Runs == P1Predict)
            {
                cout << Player2 << " is OUT!" << endl;
                break;
            }
            else
            {
                runsOfPlayer2 += P2Runs;
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
            cout << Player2 << " predict the number (0 to 6) : ";
            cin >> P2Predict;
            if (P2Predict < 0 || P2Predict > 6)
            {
                cout << "Invalid input! Enter again." << endl;
                goto predict4;
            }

            if (P1Runs == P2Predict)
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

    cout << endl << "----- Match Result -----" << endl;

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
