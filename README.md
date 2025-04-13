README.txt

this program is written in C++ and uses data scraped from ufcstats.com and posted to kaggle.com by Rajeev Warrier.

i believe that all code in the program is written by me, but this was originally a school project and there are
dozens of files, so it is possible that small sections of code may have been starter code written by Lisa Dion.

the data was current in 2021, but has not been updated since.

the program uses the data to build Fighter and Fight objects, which are then stored in a vector.

when the program is run, the user is presented with options as detailed below.

summary of program
    main program presents a menu of options:
    option 0 - display fights, prompts for which fights and how many fights
    to be displayed, and displays them
    option 1 - select a fighter, allows user to search for and select a fighter,
    after which they are presented with a new menu of options:
        option 0 - get record
        option 1 - get weight class
        option 2 - get wins by decision, submission, etc...
        option 3 - get record
        option 4 - get fight stats
        option 5 - exit, breaks loop to return to main menu
    option 2 - select a fight, allows user to select a fight, after which they 
    are presented with a new menu of options:
        option 0 - get prediction
        option 1 - display fight
        option 2 - exit, breaks loop to return to main menu
    option 3 - select a referee, allows user to select a referee, after which they
    are presented with a new menu of options:
        option 0 - get name
        option 1 - exit, breaks loop to return to main menu
    option 4 - exit, breaks the main while loop, ends program

