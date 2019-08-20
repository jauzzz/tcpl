/*  Exercise 1-11. 
    How would you test the word count program? 
    What kinds of input are most likely to uncover bugs if there are any? */

/*
    0. input file contains zero words 
    1. input file contains 1 enormous word without any newlines 
    2. input file contains all white space without newlines 
    3. input file contains 66000 newlines 
    4. input file contains word/{huge sequence of whitespace of different kinds}/word 
    5. input file contains 66000 single letter words, 66 to the line 
    6. input file contains 66000 words without any newlines 
    7. input file is /usr/dict contents (or equivalent) 
    8. input file is full collection of moby words 
    9. input file is binary (e.g. its own executable) 
    10. input file is /dev/null (or equivalent) 
 */