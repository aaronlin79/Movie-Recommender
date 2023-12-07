#include "../header/Input.h"
#include "../header/Output.h"
#include "../header/Random.h"
#include "../header/Movie.h"
#include "../header/Result.h"
#include "../header/Sort.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

Input::Input() {
    choice = '\0';
    similarIn = "";
}

Input::~Input() {}

void Input::getMenu(vector<Movie>& sortedList) {
    char input;

    Random *r = new Random();
    Result *res = new Result();
    Sort *s = new Sort();
    Quiz *q = new Quiz();

    cout << "WELCOME TO THE MOVIE RECOMMENDER!" << endl;
    cout << endl;

    outputMenu();

    do {
        cin >> input;
        while (input != '1' & input != '2' & input != '3' & input != 'q') {
            cout << "Invalid input, please try again." << endl;
            cin >> input;
        }

        if (input == '1') {
            getSearch();
        }
        else if (input == '2') {
            res->quizResult(sortedList);

            cout << endl;
            outputMenu();
        }
        else if (input == '3') {
            res->randomResult(r->randomAlgo(sortedList));

            cout << endl;
            outputMenu();
        }
    }
    while (input != 'q');

    delete r;
    delete res;
    delete s;
    delete q;
}

char Input::getSearch() {
    char input;
    searchChoiceOut();

    do {
        cin >> input;
        cout << endl;
    } while (input != 'a' & input != 'b' & input != 'c');

    if (input == 'a') {
        cout << "Implement similar search option" << endl;
    }
    else if (input == 'b') {
        cout << "Implement filter search option" << endl;
    }
    else if (input == 'c') {
        cout << "Implement return to menu option" << endl;
    }

    return input;
}

string Input::getSimilar() {
    similarOut();

    unsigned int stringLength = this->similarIn.length();

    getline(cin, this->similarIn);

    for (int i = 0; i < stringLength; i++) {
        this->similarIn.at(i) = toupper(this->similarIn.at(i));
    }

    return similarIn;
}

vector<string> Input::getFilter() {
    string genreInput;
    string yearInput;
    string durationInput;
    string ratingInput;
    string popularityInput;

    filterOutGenre();
    do { 
        cin >> genreInput;
    }
    while (genreInput != "1" & genreInput != "2" & genreInput != "3" & genreInput != "4" & genreInput != "5" & 
            genreInput != "6" & genreInput != "7" & genreInput != "8" & genreInput != "9" & genreInput != "10" & 
            genreInput != "11" & genreInput != "12" & genreInput != "13" & genreInput != "14" & genreInput != "15" & 
            genreInput != "16" & genreInput != "17" & genreInput != "18" & genreInput != "19" & genreInput != "20"); 
    
    if (genreInput == "1") {
            genreInput = "Action";
        }
        else if (genreInput == "2") {
            genreInput = "Adventure";
        }
        else if (genreInput == "3") {
            genreInput = "Animation";
        }
        else if (genreInput == "4") {
            genreInput = "Biography";
        }
        else if (genreInput == "5") {
            genreInput = "Comedy";
        }
        else if (genreInput == "6") {
            genreInput = "Crime";
        }
        else if (genreInput == "7") {
            genreInput = "Drama";
        }
        else if (genreInput == "8") {
            genreInput = "Family";
        }
        else if (genreInput == "9") {
            genreInput = "Fantasy";
        }
        else if (genreInput == "10") {
            genreInput = "Film-Noir";
        }
        else if (genreInput == "11") {
            genreInput = "History";
        }
        else if (genreInput == "12") {
            genreInput = "Horror";
        }
        else if (genreInput == "13") {
            genreInput = "Music";
        }
        else if (genreInput == "14") {
            genreInput = "Musical";
        }
        else if (genreInput == "15") {
            genreInput = "Mystery";
        }
        else if (genreInput == "16") {
            genreInput = "Romance";
        }
        else if (genreInput == "17") {
            genreInput = "Sci-Fi";
        }
        else if (genreInput == "18") {
            genreInput = "Thriller";
        }
        else if (genreInput == "19") {
            genreInput = "War";
        }
        else if (genreInput == "20") {
            genreInput = "Western";
        }

    this->filterIn.push_back(genreInput);
    
    filterOutYear();
    do {
        cin >> yearInput;
    }
    while (yearInput != "a" & yearInput != "b" & yearInput != "c" & yearInput != "d" & yearInput != "e");

    this->filterIn.push_back(yearInput);

    filterOutDuration();
    do {
        cin >> durationInput;
    }
    while (durationInput != "a" & durationInput != "b" & durationInput != "c" & durationInput != "d" & durationInput != "e" & durationInput != "f");

    this->filterIn.push_back(durationInput);
    
    filterOutRating();
    do {
        cin >> ratingInput;
    }
    while (ratingInput != "a" & ratingInput != "b" & ratingInput != "c" & ratingInput != "d" & ratingInput != "e" & ratingInput != "f" & ratingInput != "g");

    this->filterIn.push_back(ratingInput);

    filterOutPopularity();
    do {
        cin >> popularityInput;
    }
    while (popularityInput != "a" & popularityInput != "b" & popularityInput != "c" & popularityInput != "d" & popularityInput != "e");

    this->filterIn.push_back(popularityInput);

    return this->filterIn;
}