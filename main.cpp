#include <stdio.h>

#include <array>
#include <iostream>

#include "tinyxml2/tinyxml2.cpp"
#include "tinyxml2/tinyxml2.h"

std::string parseData(FILE *fp);

enum Ratings { S, A, B, C, D, E, F };

struct Show {
    std::string name;
    const char *score;
    Ratings tier;
};

int main(int argc, char *argv[]) {
    std::cout << "Loading Anime List.\n";
    FILE *myfile;
    myfile = fopen("mylist.xml", "r");

    std::string parsedData = parseData(myfile);

    return 0;
}

std::string parseData(FILE *fp) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(fp);  // load the file;
    tinyxml2::XMLDocument watchedAnime;

    std::array<Show, 20> arrayOfShows;  // array of structs

    short count;
    for (count = 0; count < 10; count++) {
        if (doc.NextSiblingElement("anime")
                ->NextSiblingElement("is_watched")
                ->GetText()) {
            arrayOfShows[count].score =
                doc.NextSiblingElement("my_rating")->GetText();
            arrayOfShows[count].name =
                doc.NextSiblingElement("name")->GetText();
            // std::cout << arrayOfShows[count].name << "\n"
            //<< arrayOfShows[count].score << "\n";
        }
        doc.NextSibling();
    }
    std::cout << arrayOfShows[1].score;
    return 0;
}
