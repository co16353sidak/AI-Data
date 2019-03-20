/*                       CRYPTARITHMETIC

    This example demonstrates the use of depth-first backward
chaining with the generate and test strategy.

                        S E N D
                     +  M O R E
                     ___________
                      M O N E Y

where no two digits are the same.                    */


goal([M,O,N,E,Y,S,D,R]) :- M=1,
    digit(S), checkcarry(0,0,S,M,M), M\=S,
    checksum(S,M,O), noton(O,[M,S]),
    checksum(E,O,N), noton(E,[M,S,O]), checkcarry(S,M,E,O,O),
    checksum(N,R,E), noton(R,[M,S,O,E,N]),
         noton(N,[M,S,O,E,R]),  checkcarry(E,O,N,R,N),
    checksum(D,E,Y), noton(Y,[M,S,O,E,R,N,D]),
    noton(D,[M,S,O,E,R,N,Y]), checkcarry(N,R,D,E,E),
    not marked([M,O,N,E,Y,S,D,R]).

checksum(X,Y,Z) :- digit(X), digit(Y),
   (Z is (X+Y) mod 10 ; Z is (X+Y+1) mod 10) .

checkcarry(X,Y,U,V,Sum) :- Sum is (X+Y + (U+V) / 10) mod 10 .
checkcarry(X,Y,U,V,Sum) :- Sum is (X+Y + (U+V+1) / 10) mod 10 .

noton(X,[X|Y]) :- !, fail.
noton(X,[]) :- ! .
noton(X,[Y|Z]) :- noton(X,Z).

marked(X) :- asserta((marked(X):- !)), fail.

digit(0).
digit(1).
digit(2).
digit(3).
digit(4).
digit(5).
digit(6).
digit(7).
digit(8).
digit(9).

/*goal(X)*/
