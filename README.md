# varchanger
Simple C++ program to replace variables names to random names

Compile code and run with the follow arguments:

./programcompiled <SOURCE_FILE.C> <NEW_FILE.C> -OPTION

Example:

./main main.c newMain.c -of

Try ./main --help for more information.

Empty options will replace every variable

-oi 		Replace only int variables

-of 		Replace only float variables

-od 		Replace only double variables

-oc 		Replace only char variables

-ol 		Replace only long variables

-bi 		Replace everything but int variables

-bf 		Replace everything but float variables

-bd 		Replace everything but double variables

-bc 		Replace everything but char variables

-bl 		Replace everything but long variables
