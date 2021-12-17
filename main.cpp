#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iomanip>

using namespace std;

int answer[4], level = 0, guesses[4];
char progress[12][2][4] = {};
bool continuehelper = true, allowRepeatednumbers = false;

void menu();

void askingForMenu() {
    cout << "\nEnter m to go back to menu\n";
    while (true) {
        char temp;
        cin >> temp;
        if (temp == 'm') {
            menu();
            break;
        } else {
            cout << "Wrong answer try again\n";
        }
    }
}

void playWithComputer();

void playDUO();

void startNewGame();

void allowToUseRepeaetedNumbers(int soloOrDuo) {
    cout << "Allow to use repeted numbers ?\n";
    cout << "1 . Yes          2 . No          3 . Menu\n";
    char temp;
    cin >> temp;
    if (temp == '1') {
        allowRepeatednumbers = true;
        if (soloOrDuo == 1) {
            playWithComputer();
        } else {
            playDUO();
        }
    } else if (temp == '2') {
        allowRepeatednumbers = false;
        if (soloOrDuo == 1) {
            playWithComputer();
        } else {
            playDUO();
        }
    } else if (temp == '3') {
        menu();
    } else {
        cout << "Wrong number try again\n";
        allowToUseRepeaetedNumbers(soloOrDuo);
    }
}

void Continue();

void table();

int tableHelper[12][4] = {}, gameNumber = 0, answers[10][4];

void collectingAnswersForTable() {

    answers[gameNumber][0] = answer[0];
    answers[gameNumber][1] = answer[1];
    answers[gameNumber][2] = answer[2];
    answers[gameNumber][3] = answer[3];
}

void tableInformation() {
    //making tableHelper empty
    for (int w = 0; w < 12; w++) {
        for (int q = 0; q < 4; q++) {
            tableHelper[w][q] = 0;
        }
    }

    int Temp = level;
    while (Temp >= 0) {
        tableHelper[Temp][0] = int(progress[Temp][0][0]) - 48;
        tableHelper[Temp][1] = int(progress[Temp][0][1]) - 48;
        tableHelper[Temp][2] = int(progress[Temp][0][2]) - 48;
        tableHelper[Temp][3] = int(progress[Temp][0][3]) - 48;
        Temp--;
    }
}

void scoreBoard();

vector<int> scoreboardlevel(1, 0);


void game();

void handlerGameNumbers() {
    gameNumber++;
    scoreboardlevel.push_back(0);
}

void makingProgressArrayEmpty() {
    for (int w = 0; w < 12; w++) {
        for (int q = 0; q < 4; q++) {
            progress[w][0][q] = ' ';
            progress[w][1][q] = ' ';
        }
    }
}

void calcultaingScores(char gameResult) {
    if (gameResult == 'W') {
        int Temp = level;

        while (Temp >= 0) {
            for (int r = 0; r < 4; r++) {
                if (progress[Temp][1][r] == 'F') {
                    scoreboardlevel[gameNumber]++;
                }
            }

            Temp--;
        }
    } else {
        scoreboardlevel[gameNumber] = 100;
    }
}

void importgusses() {
    cout << "guess four numbers between 1 and 6 or enter m to go back to menu\n";
    char temp[4] = {};
    int helper = 0;
    for (int i = 0; i < 4; i++) {
        cin >> temp[i];
        if (temp[0] == 'm') {
            helper = 2;
            menu();
            break;
        }
        if (!(temp[i] == '1' || temp[i] == '2' || temp[i] == '3' || temp[i] == '4' || temp[i] == '5' ||
              temp[i] == '6')) {
            helper = 1;
        } else if (i == 3 && helper == 0) {
            if (!allowRepeatednumbers &&
                (temp[0] == temp[1] || temp[0] == temp[2] || temp[0] == temp[3] || temp[1] == temp[2] ||
                 temp[1] == temp[3] ||
                 temp[2] == temp[3])) {
                cout << "Repeated numbers try again\n";
                importgusses();

            } else {
                for (int i = 0; i < 4; i++) {
                    guesses[i] = int(temp[i]) - 48;
                }
            }
        }
        if (level != 0) {
            //checking for repeated guess
            int temp2 = level;
            while (temp2 >= 0) {
                if (progress[temp2 - 1][0][0] == temp[0] && progress[temp2 - 1][0][1] == temp[1] &&
                    progress[temp2 - 1][0][2] == temp[2] && progress[temp2 - 1][0][3] == temp[3]) {
                    cout << "Repeated guess! try again\n";
                    importgusses();
                    helper = 2;
                }
                temp2--;
            }
        }
    }
    if (helper == 1) {
        cout << "Wrong numbers try again\n";
        importgusses();
    }
    if (helper == 0) {
        game();
        //so we don't call game() method if helper== 1 or 2
    }
}

void fillProgressArray(int array1[], int array2[]);

void printer();

void printGameLevels() {
    cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - " << answer[3]
         << " - " << "-----------|\n";
    cout << "----------------------------------------\n";
    cout << "----------------------------------------\n\n";
    int gameLevel = 1;
    for (int i = 0; i < 12; i++) {
        if (progress[i][0][0] == ' ') {
            break;
        }
        cout << "[level : " << gameLevel << "] " << progress[i][0][0] << " - " << progress[i][0][1]
             << " - " << progress[i][0][2] << " - " << progress[i][0][3] << "\n";
        cout << "----------- " << progress[i][1][0] << " - " << progress[i][1][1] << " - " << progress[i][1][2]
             << " - "
             << progress[i][1][3] << " --------------\n";
        cout << "----------------------------------------\n\n";
        gameLevel += 1;
    }
}

char castIntToChar(int integer) {
    switch (integer) {
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        default:
            return '0';
    }
}


int main() {

    makingProgressArrayEmpty();
    menu();

    return 0;
}


void menu() {
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 1 ) Start new game\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 2 ) Continue\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 3 ) Table\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 4 ) Scoreboard\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 5 ) Exit\n";
    cout << "----------------------------------------\n";
    char userInput;
    cin >> userInput;

    switch (userInput) {
        case '1':
            startNewGame();
            break;
        case '2':
            Continue();
            break;
        case '3':
            table();
            break;
        case '4':
            scoreBoard();
            break;
        case '5':
            break;

        default:
            cout << "Wrong number try again\n";

            menu();
    }

}

void startNewGame() {
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 1 ) Play with Computer\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 2 ) Play DUO\n";
    cout << "----------------------------------------\n";
    cout << string(10, ' ') << "( 3 ) Go back to menu\n";
    cout << "----------------------------------------\n";
    char userInput;
    cin >> userInput;

    switch (userInput) {
        case '1':
            allowToUseRepeaetedNumbers(1);
            break;
        case '2':
            allowToUseRepeaetedNumbers(2);
            break;
        case '3':
            menu();
            break;
        default:
            cout << "Wrong number try again\n";
            startNewGame();
            break;
    }
}

void playDUO() {
    cout << "Please enter four different numbers between 1 and 6 or enter m to go back to menu\n";
    char num[4];
    bool True = true;
    for (int i = 0; i < 4; i++) {
        cin >> num[i];
        if (num[0] == 'm') {
            menu();
            break;
        }
        if (!(num[i] == '1' || num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '6')) {
            True = false;
        } else if (i == 3 && True) {
            if (!allowRepeatednumbers &&
                (num[0] == num[1] || num[0] == num[2] || num[0] == num[3] || num[1] == num[2] || num[1] == num[3] ||
                 num[2] == num[3])) {
                cout << "Wrong numbers try again\n";
                playDUO();
            } else {
                for (int i = 0; i < 4; i++) {
                    answer[i] = int(num[i]) - 48;
                }
                cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - "
                     << answer[3]
                     << " - " << "-----------|\n";
                cout << "----------------------------------------\n";
                level = 0;
                continuehelper = false;
                collectingAnswersForTable();
                importgusses();

            }
        }
    }

    if (!True) {
        cout << "Wrong numbers try again\n";

        playDUO();

    }
}

void playWithComputer() {
    srand(unsigned(time(0)));
    for (int i = 0; i < 4; i++) {
        answer[i] = (rand() % (6)) + 1;
        if (!allowRepeatednumbers) {
            switch (i) {
                case 1:
                    if (answer[0] == answer[1]) {
                        i = 0;
                    }
                    break;
                case 2:
                    if (answer[0] == answer[1] || answer[0] == answer[2] || answer[1] == answer[2]) {
                        i = 1;
                    }
                    break;
                case 3:
                    if (answer[0] == answer[1] || answer[0] == answer[2] || answer[0] == answer[3] ||
                        answer[1] == answer[2] || answer[1] == answer[3] || answer[2] == answer[3]) {
                        i = 2;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - "
         << answer[3]
         << " - " << "-----------|\n";
    cout << "----------------------------------------\n";
    level = 0;
    collectingAnswersForTable();
    continuehelper = false;
    importgusses();
}

void game() {
    fillProgressArray(guesses, answer);
    tableInformation();
    if (guesses[0] == answer[0] && guesses[1] == answer[1] && guesses[2] == answer[2] && guesses[3] == answer[3]) {

        printGameLevels();
        cout << string(40, '*') << endl;
        cout << string(12, '*') << "    You Won     " << string(12, '*') << endl;
        cout << string(40, '*') << endl;


        calcultaingScores('W');
        handlerGameNumbers();
        makingProgressArrayEmpty();
        continuehelper = true;
        askingForMenu();

    } else if (level == 11) {

        printGameLevels();
        cout << string(20, '>') << string(20, '<') << endl;
        cout << string(12, '!') << "   You Lose     " << string(12, '!') << endl;
        cout << string(20, '>') << string(20, '<') << endl;

        calcultaingScores('L');
        handlerGameNumbers();
        makingProgressArrayEmpty();
        continuehelper = true;
        askingForMenu();

    } else {

        printer();

    }

}

void fillProgressArray(int array1[], int array2[]) {
    for (int i = 0; i < 4; i++) {
        progress[level][0][i] = castIntToChar(array1[i]);
        if (array1[i] == array2[i]) {
            progress[level][1][i] = 'T';
        } else if (array1[i] == array2[0] || array1[i] == array2[1] || array1[i] == array2[2] ||
                   array1[i] == array2[3]) {
            progress[level][1][i] = 'F';
        } else {
            progress[level][1][i] = '0';
        }
    }
}

void printer() {
    cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - " << answer[3]
         << " - " << "-----------|\n";
    cout << "----------------------------------------\n";
    cout << "----------------------------------------\n\n";
    int temp2 = 1;
    for (int i = 0; i < 12; i++) {
        if (progress[i][0][0] == ' ') {
            break;
        }
        cout << "[level :" << setw(2) << temp2 << "] " << progress[i][0][0] << " - " << progress[i][0][1]
             << " - " << progress[i][0][2] << " - " << progress[i][0][3] << "\n";
        cout << "----------- " << progress[i][1][0] << " - " << progress[i][1][1] << " - " << progress[i][1][2]
             << " - "
             << progress[i][1][3] << " --------------\n";
        cout << "----------------------------------------\n\n";
        temp2 += 1;
    }
    level++;
    importgusses();
}

void Continue() {
    if (level == 0 && continuehelper) {
        cout << "please start new game first :\n";
        cout << " 1 . start new game           2 . menu\n";
        char temp;
        cin >> temp;
        if (temp == '1') {
            startNewGame();
        } else if (temp == '2') {
            menu();
        } else {
            cout << "Wrong number try again\n";
            Continue();
        }
    } else {
        cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - " << answer[3]
             << "-------------|\n";
        cout << "----------------------------------------\n";
        cout << "----------------------------------------\n\n";
        if (level != 0) {
            int temp = level + 1, temp2 = 1;
            for (int i = 0; i < 12; i++) {
                if (progress[i][0][0] == ' ') {
                    break;
                }
                cout << "[level : " << temp2 << "] " << progress[i][0][0] << " - " << progress[i][0][1]
                     << " - " << progress[i][0][2] << " - " << progress[i][0][3] << "\n";
                cout << "----------- " << progress[i][1][0] << " - " << progress[i][1][1] << " - " << progress[i][1][2]
                     << " - "
                     << progress[i][1][3] << " --------------\n";
                cout << "----------------------------------------\n\n";
                temp2 += 1;
            }
        }
        importgusses();
    }
}

void table() {
    cout << "----------------------------------------\n";
    cout << "|---------- " << answer[0] << " - " << answer[1] << " - " << answer[2] << " - " << answer[3]
         << " - " << "-----------|\n";
    cout << "----------------------------------------\n";
    cout << "----------------------------------------\n";
    int temp = 12;
    for (int i = 11; i >= 0; i--) {
        if (tableHelper[i][0] == 0) {
            temp--;
            continue;
        }
        cout << "[level :" << setw(2) << temp << "] " << tableHelper[i][0] << " - " << tableHelper[i][1]
             << " - " << tableHelper[i][2] << " - " << tableHelper[i][3] << "\n";
        cout << "----------------------------------------\n";
        temp--;
    }


    askingForMenu();
}

void scoreBoard() {
    int Temp = gameNumber - 1, i = 0;
    while (Temp >= 0) {
        cout << "----------------------------------------\n";
        cout << "  Game [" << setw(2) << i + 1 << "]   ==   " << 100 - scoreboardlevel[i] << '\n';
        i++;
        Temp--;
    }
    askingForMenu();
}