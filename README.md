CSUF CPSC 121 TuffyNotes Project
# TuffyNotes Project

## Project specifications
The goal of this project is to develop a note-taking application. Users will use a menu-based command-line interface to interact with the software. Its major features are the creation of notes, adding notes to a notebook, and saving and loading notes into text files. 

The software should be designed using the object-oriented programming paradigm so that the code can easily be modified, extended, and scaled by other developers. It is equally important to provide sufficient internal documentation to help other developers understand the code and encourage them to contribute to its development.

The software will be delivered in incremental versions or milestones over the course of the semester. Descriptions of the seven milestones are presented below, but technical details will be provided in your GitHub repositories for each milestone. The deadlines listed for each milestone may change depending on the class’ progress. In such cases, I will announce changes in class and/or through Titanium.

## Milestone 1
Deadline: February 22, 11:55 pm

Create a menu-based command-line interface that asks a user to input a note title and note body until the option to exit is used. The code needs to use functions to retrieve inputs from the user.
## Milestone 2
Deadline: March 8, 11:55 pm

Design and implement a Note object that will store the title of the note, and the body of the note. You need to create a function that returns a Note object containing the user’s input. The returned object should be stored into an array of Note objects. The code should be organized so that class and function prototypes are placed in header files (.hpp) while their implementations are placed in source files (.cpp)
## Milestone 3
Deadline: March 22, 11:55 pm

Implement a function that will display all notes that the user input and another function that displays the content of a specific note.
## Milestone 4
Deadline: April 8, 11:55 pm

Implement a function that loads notes from a text file. Other functionalities such as listing and viewing notes should still work correctly. The text file uses the same format as used in Milestone 3.
## Milestone 5
Deadline: April 19, 11:55 pm

Refactor your code so that it uses an object-oriented design. Refactor is a term that refers to restructuring existing code so that it follows a different design but retains the initial code’s behavior. Specifically, you need to create a Notebook object that will contain all the Note objects added by the user. The functions created from Milestone 4 will be refactored into methods in the appropriate classes. As a result, code that used the refactored functions will now use the Notebook and Note objects’ methods.
## Milestone 6
Deadline: May 3, 11:55 pm

Add a new note type called EncryptedNote. This new note type contains a new data member called password. Whenever an EncryptedNote is displayed, it asks the user for a password before displaying it. If an incorrect password is provided, an authentication error message is displayed instead.

Apply inheritance and polymorphism so that Note and EncryptedNote objects can be stored in the same array. The other functionalities such as display, save, and load should still work as expected.
## Milestone 7 (Extra credit)
Deadline: May 16, 11:55 pm

Create another Note type called SelfDestructNote. It contains a new data member that keeps track of whether the note has already been opened or not. The first time a note is opened, its contents should be displayed. However, when it is opened again, it should display an expired message notification.


