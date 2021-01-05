# TierListMaker

TierListMaker takes and operates on an exported aniDB (xml-mystatus) file, and prints a list of watched anime in their respective tiers based on their score.

### Usage
The program can be compiled with CMake.
```bash
cmake .
make
./app mylist.xml
```
The location of the XML file should be passed as the only argument when starting the program.

