THIS THE ONE, THE ONLY, CHIN___ SIMULATOR!

**TO PLAY!**

IF YOU JUST WANT TO PLAY, GOTO THE ITCH.IO PAGE https://oguhs-cookies.itch.io/

*IF YOU CAN"T BE ASKED*

TO PLAY, DOWNLOAD THE REPO AS A ZIP FILE AND OPEN THE RELEASE (DEBUG IF THERE IS NO RELEASE) AND OPEN THE .exe.

THERE IS NO VIRUS, WINDOWS DEFENDER IS JUST BEING SPED, I AM CURRENTLY TRYING TO FIND A WAY TO COMBAT THIS.

**MODDING**

IF YOU WANT TO EDIT THE CODE, OPEN THE .sln FILE IN VISUAL STUDIO (2022+) AND EDIT THE CODE.

*IF YOU WANT TO ADD LEVELS*

ENTER THE GAMELOOP.h FILE AND ADD A const int * TO THE LIST AT LINE 60 IN ACCENDING ORDER AND RETURN IT IN THE SWITCH STATEMENT

THEN OPEN GAMELOOP.cpp AND ADD THE LEVEL AT THE LIST IN getLevel() USING THE SAME FORMAT AS SHOWN (0 being transparent, 1 being the Wok, 2 being Chocolate, 3 being an input portal, 4 being an output portal, etc)

THEN GOTO THE SWITCH STATEMENT AT LINE 266, AND BEFORE THE DEFAULT, ADD YOUR LEVEL NUMBER YOU SPECIFIED IN THE FIRST STEP AND FOLLOW THE NAMING CONVENTION

THEN GOTO THE IF TREE AT LIE 337 AND ADD YOUR LEVEL NUMBER AND THE NUMBER OF PLACES YOU HAVE

THEN GOTO THE SWITCH STATEMENT AT LINE 411 AND ADD YOUR LEVEL AND LEAVE EVERYTHING THE SAME EXCEPT FOR THE LEVEL SPECIFIER (WHICH YOU ADD THE LEVEL NUMBER YOU MADE)

THEN PLAY THE GAME TO SEE IF EvERYTHING WORKED, IF NOT, LEAVE YOUR PROBLEM AT THE ISSUES TAB.

***CONTACTS***

EMAIL: oguhs.cookies@gmail.com
ITCH.IO https://oguhs-cookies.itch.io/
OLD WEBSITE: https://hslewczak.wixsite.com/oguhs-cookies
