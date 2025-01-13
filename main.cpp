#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>


using namespace std;

int main() {

    // std::cout << "Hello, World!" << std::endl;
    //time(0): This gets the current time.
    //static_cast<unsigned int>: This makes sure the time is in the right format for srand().
    //srand(...): This sets the starting point for the random number generator.

    srand(static_cast<unsigned int>(time(0)));


    ifstream file;
    file.open("words.txt");

    if(file.fail()) {
        cout<<"failed finding file"<<endl;
        return 1;
    }


    //word choice

    const int WORDS_NO = 1142;
    string WORDS[WORDS_NO];

    int lines = 0;
    while(!file.eof())
    {
        getline(file, WORDS[lines]);
        lines++;

        if(lines == WORDS_NO) {
            cout<<"Array filled before all words were taken"<<endl;
            break;
        }

    }
    file.close();

    // for(int i=0; i<lines;i++) {
    //     cout<<WORDS[i]<<endl;
    // }

    int pick = (rand() % WORDS_NO);
    //picks with bounds to word amout

    string wordPickd = WORDS[pick];

    string rearrange = wordPickd;
    for(size_t count = 0;count < rearrange.length();count++)
    {
        //swap letter at index count, with letter at other index
        size_t randomIndex = (rand()%rearrange.length());
        char temp = rearrange[count];
        rearrange[count] = rearrange[randomIndex];
        rearrange[randomIndex] = temp;

    }

    cout<<"WordMix Game"<<endl<< "Guess word form :";
    cout<<endl<<"Q - to quit"<<endl;


    cout<<endl<<rearrange<<endl;

    string guess;
    do {
        cout<<endl<<endl<< "Enter guess:";
        cin>> guess;

        if ((guess!=wordPickd) && (guess!= "Q")) {
            cout<<"Try again nigga";

        }else{cout<<"well done nigga";}

    }while ((guess!=wordPickd) && (guess!= "Q"));

    return 0;
}
