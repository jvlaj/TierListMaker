#include <stdio.h>

#include <iostream>

#include "tinyxml2/tinyxml2.cpp"
#include "tinyxml2/tinyxml2.h"

int main(int argc, char *argv[]) {
    std::cout << "Loading Anime List...\n";
    FILE *fp;
    fp = fopen("mylist.xml", "r");
    tinyxml2::XMLPrinter printer(fp);
    printer.OpenElement("foo");
    printer.PushAttribute("foo", "bar");
    printer.CloseElement();
    return 0;
}
