% Hospital Management System - Prolog
% Models patients, doctors, appointments, diagnoses, and hospital operations

:- dynamic patient/3.          % patient(ID, Name, Age)
:- dynamic doctor/3.           % doctor(ID, Name, Specialty)
:- dynamic appointment/3.      % appointment(PatientID, DoctorID, Date)
:- dynamic diagnosis/3.        % diagnosis(PatientID, Condition, Treatment)
:- dynamic admitted/1.         % admitted(PatientID)
:- dynamic room/2.             % room(PatientID, RoomNumber)

% Sample doctors
doctor(1, 'Dr. Khairul Sharif', cardiology).
doctor(2, 'Dr. Sourav Korimuddin', surgery).
doctor(3, 'Dr. Solimuddin Faisal', pediatrics).


% Register a new patient
register_patient(ID, Name, Age) :-
    \+ patient(ID, _, _),
    assert(patient(ID, Name, Age)),
    write('Patient registered successfully.'), nl.

register_patient(ID, _, _) :-
    patient(ID, _, _),
    write('Patient already registered.'), nl.


% View patient info
view_patient(ID) :-
    patient(ID, Name, Age),
    format('Patient ID: ~w~nName: ~w~nAge: ~w~n', [ID, Name, Age]),
    ( admitted(ID) -> write('Status: Admitted'), nl ; write('Status: Not admitted'), nl ),
    ( room(ID, Room) -> format('Room: ~w~n', [Room]) ; true ),
    list_diagnosis(ID),
    list_appointments(ID), !.

view_patient(ID) :-
    \+ patient(ID, _, _),
    write('Patient not found.'), nl.


% Admit or discharge a patient
admit_patient(ID) :-
    patient(ID, _, _),
    \+ admitted(ID),
    assert(admitted(ID)),
    write('Patient admitted.'), nl.

admit_patient(ID) :-
    admitted(ID),
    write('Patient is already admitted.'), nl.

discharge_patient(ID) :-
    admitted(ID),
    retract(admitted(ID)),
    retractall(room(ID, _)),
    write('Patient discharged.'), nl.

discharge_patient(ID) :-
    \+ admitted(ID),
    write('Patient is not admitted.'), nl.


% Add diagnosis
add_diagnosis(PID, Condition, Treatment) :-
    patient(PID, _, _),
    assert(diagnosis(PID, Condition, Treatment)),
    write('Diagnosis added.'), nl.


% Assign appointment
book_appointment(PID, DID, Date) :-
    patient(PID, _, _),
    doctor(DID, _, _),
    assert(appointment(PID, DID, Date)),
    write('Appointment booked.'), nl.


% Assign room to admitted patient
assign_room(PID, RoomNo) :-
    patient(PID, _, _),
    admitted(PID),
    \+ room(PID, _),
    assert(room(PID, RoomNo)),
    write('Room assigned.'), nl.

assign_room(PID, _) :-
    \+ admitted(PID),
    write('Patient must be admitted to assign a room.'), nl.

assign_room(PID, _) :-
    room(PID, _),
    write('Patient already has a room.'), nl.

% Delete patient record
delete_patient(ID) :-
    retractall(patient(ID, _, _)),
    retractall(admitted(ID)),
    retractall(appointment(ID, _, _)),
    retractall(diagnosis(ID, _, _)),
    retractall(room(ID, _)),
    write('Patient record deleted.'), nl.


% List diagnosis for a patient
list_diagnosis(PID) :-
    diagnosis(PID, C, T),
    format('Diagnosis: ~w | Treatment: ~w~n', [C, T]),
    fail.
list_diagnosis(_).


% List appointments for a patient
list_appointments(PID) :-
    appointment(PID, DID, Date),
    doctor(DID, Name, Spec),
    format('Appointment on ~w with ~w (~w)~n', [Date, Name, Spec]),
    fail.
list_appointments(_).


% View doctor info
view_doctor(ID) :-
    doctor(ID, Name, Spec),
    format('Doctor ID: ~w~nName: ~w~nSpecialty: ~w~n', [ID, Name, Spec]).

view_doctor(ID) :-
    \+ doctor(ID, _, _),
    write('Doctor not found.'), nl.


% List all patients
list_patients :-
    patient(ID, Name, Age),
    format('ID: ~w | Name: ~w | Age: ~w~n', [ID, Name, Age]),
    fail.
list_patients :-
    \+ patient(_, _, _),
    write('No patients found.'), nl.
list_patients.


% List all doctors
list_doctors :-
    doctor(ID, Name, Specialty),
    format('ID: ~w | Name: ~w | Specialty: ~w~n', [ID, Name, Specialty]),
    fail.
list_doctors :-
    \+ doctor(_, _, _),
    write('No doctors found.'), nl.
list_doctors.


% Search patients by name substring
search_patient_by_name(Substr) :-
    patient(ID, Name, Age),
    sub_atom(Name, _, _, _, Substr),
    format('ID: ~w | Name: ~w | Age: ~w~n', [ID, Name, Age]),
    fail.
search_patient_by_name(_) :-
    write('Search complete.'), nl.


% List admitted patients and their rooms
list_admitted_patients :-
    admitted(ID),
    patient(ID, Name, _),
    ( room(ID, Room) -> format('ID: ~w | Name: ~w | Room: ~w~n', [ID, Name, Room])
    ; format('ID: ~w | Name: ~w | Room: [not assigned]~n', [ID, Name])
    ),
    fail.
list_admitted_patients :-
    \+ admitted(_),
    write('No admitted patients.'), nl.
list_admitted_patients.
