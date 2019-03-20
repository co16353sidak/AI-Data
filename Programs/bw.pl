
?-op(100,xfy,':').  /* define : as a left-associative operator */

/* The major predicate is

   solve(Current_state, Goal_state, Traversed_path, Solution_path).

   where Traversed_path is a list of moves made so far.
*/


solve(Start, Start, Path, Path).  /* If the current state is the
                 start state, then output the path to the 4th argument */

solve(Current, Start, Path, Solution) :-
      edge(Step, Previous, Current),
      not(marked(node(Previous))),
      solve(Previous, Start, Step:Path, Solution).


edge(moveto(Y), X, Y) :- move(X,Y).
move([X,Y|Z],[Y,X|Z]):- X=' ';Y=' '.
move([X,Y,Z|W],[Z,Y,X|W]):- X=' ';Z=' '.
move([X|Y],[X|Z]):- move(Y,Z).

reset_marked :- retractall(marked(_)),
      asserta( (marked(X) :- asserta((marked(X):- !)), fail) ).

blackWhite(X,Y,Z) :- reset_marked, solve(X,Y,[X],Z).


run(Answer) :- blackWhite(
               [ b,b,b,' ',w,w,w],  /*search backward from goal*/
               [w,w,w,' ',b,b,b], /*to start*/
               Answer), print(Answer),nl.
not(X) :- \+(X).

/* ?- run(X). */
