#include <stdio.h>

#include <array>
#include <iostream>

#include "tinyxml2/tinyxml2.cpp"
#include "tinyxml2/tinyxml2.h"

enum Ratings { S, A, B, C, D, E, F };

struct Show {
    const char *name;
    int score;
    Ratings tier;
};

std::array<Show, 1000> parseData(FILE *fp);

int main(int argc, char *argv[]) {
    std::cout << "Loading Anime List.\n";

    tinyxml2::XMLDocument doc;
    FILE *myfile;
    myfile = fopen("/home/jason/Code/TierListMaker/mylist.xml", "r");
    doc.LoadFile(myfile);

    std::array<Show, 1000> arrayOfShows;

    tinyxml2::XMLElement *pEntryElement = doc.FirstChildElement("mylist")
                                              ->FirstChildElement("anime")
                                              ->FirstChildElement("entry");

    for (int count = 0; pEntryElement != nullptr; count++) {
        if (pEntryElement->BoolAttribute("is_watched")) {
            arrayOfShows[count].name =
                pEntryElement->FirstChildElement("name")->GetText();
            arrayOfShows[count].score =
                pEntryElement->IntAttribute("my_rating");
            std::cout << "Name: " << arrayOfShows[count].name << "\n";
            std::cout << "Score: " << arrayOfShows[count].score << "\n";
            switch (arrayOfShows[count].score) {
                case 9:
                    arrayOfShows[count].tier = S;
                    break;
                case 8:
                    arrayOfShows[count].tier = A;
                    break;
                case 7:
                    arrayOfShows[count].tier = B;
                    break;
                case 6:
                    arrayOfShows[count].tier = C;
                    break;
                case 5:
                    arrayOfShows[count].tier = D;
                    break;
                case 4:
                    arrayOfShows[count].tier = E;
                    break;
                case 3:
                    arrayOfShows[count].tier = F;
                    break;
                case 2:
                    arrayOfShows[count].tier = F;
                    break;
                case 1:
                    arrayOfShows[count].tier = F;
                    break;
            }
            std::cout << "tier: " << arrayOfShows[count].tier << "\n";
        }
        pEntryElement = pEntryElement->NextSiblingElement();
    }
    return 0;
}
