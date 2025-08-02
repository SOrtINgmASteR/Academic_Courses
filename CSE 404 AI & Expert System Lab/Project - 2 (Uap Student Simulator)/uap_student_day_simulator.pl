% UAP: A Student Day Simulator
% Simulates a students daily academic life at University of Asia Pacific (CSE)

:- dynamic location/1.
:- dynamic knowledge/1.
:- dynamic marks/1.
:- dynamic happiness/1.
:- dynamic skills/1.

% Initial state
location(home).
knowledge(0).
marks(0).
happiness(50).
skills(0).

% Movement between locations
goto(classroom) :- change_location(classroom).
goto(home)      :- change_location(home).
goto(lab)       :- change_location(lab).

change_location(NewPlace) :-
    retract(location(_)),
    assert(location(NewPlace)),
    write('Moved to '), write(NewPlace), nl.

% Attending class
attend_class :-
    location(classroom),
    gain_knowledge,
    decrease_happiness(5),
    write('You attended class. Gained knowledge but lost some energy.'), nl, !.

attend_class :-
    write('You must be in the classroom to attend class.'), nl.

% Giving test
give_test :-
    location(classroom),
    knowledge(K),
    NewMark is (K * 0.5),
    update_marks(NewMark),
    decrease_happiness(10),
    format('You gave a class test and scored ~d marks.', [NewMark]), nl, !.

give_test :-
    write('Go to the classroom to give the test.'), nl.

% Participating in a contest
participate_contest :-
    location(lab),
    gain_skills,
    increase_happiness(10),
    write('You participated in a programming contest. Gained skills and felt great!'), nl, !.

participate_contest :-
    write('Go to the lab to join a contest.'), nl.

% View current status
status :-
    location(L), knowledge(K), marks(M), happiness(H), skills(S),
    format('~n-- Student Status --~nLocation: ~w~nKnowledge: ~d~nMarks: ~d~nHappiness: ~d~nSkills: ~d~n~n', [L, K, M, H, S]).

% Helper predicates
gain_knowledge :-
    knowledge(K), NK is K + 5,
    retract(knowledge(K)), assert(knowledge(NK)).

gain_skills :-
    skills(S), NS is S + 3,
    retract(skills(S)), assert(skills(NS)).

update_marks(Delta) :-
    marks(M), NM is M + Delta,
    retract(marks(M)), assert(marks(NM)).

decrease_happiness(Amount) :-
    happiness(H), NH is max(0, H - Amount),
    retract(happiness(H)), assert(happiness(NH)).

increase_happiness(Amount) :-
    happiness(H), NH is min(100, H + Amount),
    retract(happiness(H)), assert(happiness(NH)).
