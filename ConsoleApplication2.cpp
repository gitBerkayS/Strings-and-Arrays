#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
/* This program takes in a sentence, mixes up the letters within the word, then adds "ra" at the end of every word.*/
using namespace std;

//Setting up random function to output a random number. This will allow the program to randomize the location of each letter, within a word.
int randomnum(int& size) {
    return rand() % size;
}

int main() {
    //Setting random seed. Initializing variables.
    srand(time(NULL));
    string sentence;
    string temp;
    char check = ' ';

    //Allowing the use to pick out the sentence they want to enter. We use getline() to get a whole line of words instead of the program stopping input when it sees a space.
    cout << "Enter a sentence:";
    getline(cin, sentence);

    //Creating a for loop that checks goes through each character position until the end of the string.
    int sentencesize = sentence.length();
    for (int x = 0; x < sentencesize; x++) {
        check = sentence[x];

        //Using the character position to locate the space.
        if (check == ' ') {
            int tempsize = temp.length();
            vector<int> used_numbers;

            //This time the program goes through each letter of the word one by one.
            for (int y = 0; y < tempsize; y++) {
                bool used;
                int random_num_temp;
                do {
                    //Storing a random number from 0 to the length of the word, to generate a random position in the word.
                    random_num_temp = randomnum(tempsize);
                    used = false;
                    //Making sure the random number position from the word has not been previously used. If it has already been used. The do-while loop does not break, and stores a new number, UNTILL it is a number that has not been used.
                    for (int i = 0; i < used_numbers.size(); i++) {
                        if (random_num_temp == used_numbers[i]) {
                            used = true;
                            break;
                        }
                    }
                } while (used);
                //Enters the used number into a vector to keep track of it. Using cout, prints the result. Doing it this way allows the program to keep the original word, while giving the user a scrambled version.
                used_numbers.push_back(random_num_temp);
                cout << temp[random_num_temp];
            }
            //Adding ra as instructions show.
            cout << "ra";
            cout << endl;
            temp = "";
        }
        //If there is no space entered in the string, then we store the word in temp, which allows us to access it further.
        else {
            temp += check;
        }
    }

    // Processing the last word, since at the end. No space is detected, and temp ends up being full, but the previous code needs to be repeated as theres no other way of proccessing the last word.
    int tempsize = temp.length();
    vector<int> used_numbers;
    for (int y = 0; y < tempsize; y++) {
        bool used;
        int random_num_temp;
        do {
            random_num_temp = randomnum(tempsize);
            used = false;
            for (int i = 0; i < used_numbers.size(); i++) {
                if (random_num_temp == used_numbers[i]) {
                    used = true;
                    break;
                }
            }
        } while (used);

        used_numbers.push_back(random_num_temp);
        cout << temp[random_num_temp];
    }
    cout << "ra";
}
