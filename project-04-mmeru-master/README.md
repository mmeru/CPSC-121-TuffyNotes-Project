# TuffyNotes Project Milestone 4

This is milestone 4 of the [TuffyNotes Project](https://docs.google.com/document/d/14qiyhHtXpZOkVqHdUmLjLu1OWcBhQijvqybHtgsEWhI/edit?usp=sharing).

# Requirements
Provide functionality to save and load `Note` objects that were previously created by the program.

Implement the `save_notes` function that takes in the filename of the save file, the array of `Note` objects that will be saved, and the number of `Note` objects in the array that will be saved. The first line of the save file should contain the number of `Note` objects that will be saved. For every `Note` object, the file should add a note marker, `[Note]` followed by the *title* and *body* of the note. Data should be separated by next line characters (`"\n"`). The example below illustrates the file format.

```
2
[Note]
Grocery list
milk, banana, water, turkey sandwich
[Note]
Band mates
Geddy Lee, Alex Lifeson, Neil Peart
```

Implement the `load_notes` function that takes in the filename of the save file, the array of `Note` objects that will store the `Note` objects loaded from the save file, and the number of `Note` objects in the array. Take note that the number of objects is not known before hand. The program will only know the size when it starts loading the file. This means, we need to modify the size inside the function, but reflect the change to the `main` function that calls it. *Hint: What data type should we use so that a function parameter is linked to a variable declared in the function that calls it?*

The `load_notes` function will read the save file and assume it follows the same format used by the `save_notes` function. It should **overwrite** the data in the current array. For example, if there are 5 `Note` objects in the array and the save file contains 3 `Note` objects, the function will overwrite the first three objects and update the number of `Note` objects to 3.

All previously created functions from Milestones 1 to 3 should still work as expected.

Update your menu to support saving and loading notes. Kindly refer to the sample output below and follow it as closely as possible.

```
Welcome to TuffyNotes!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Grocery list
Please enter the note: milk, banana, water, turkey sandwich

Note added!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Band mates
Please enter the note: Geddy Lee, Alex Lifeson, Neil Peart

Note added!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: v

Notes
1. Grocery list
2. Band mates

Please input note index: 2

[Band mates]
Geddy Lee, Alex Lifeson, Neil Peart

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: s

Please enter filename: my_notes.txt
Notes saved!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: c

Please enter the note's title: Enrolled courses
Please enter the note: CPSC 121, CPSC 481

Note added!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates
3. Enrolled courses

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: o

Please enter filename: my_notes.txt
Notes loaded!

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: l

Notes
1. Grocery list
2. Band mates

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: j

Invalid choice. Please try again.

[C] Create a note
[L] List notes
[V] View note
[S] Save notes
[O] Load notes
[E] Exit
Choice: e

Thank you for using TuffyNotes!
```

Place the function prototypes and classes in `notebook.hpp`, the function implementations in `notebook.cpp`, and the main function in `tuffynotes.cpp`.

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Called function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Documentation
See [google's style guide](https://google.github.io/styleguide/cppguide.html#Comments) for more details.

## File comments
Describe the contents of the file on the first line. For example:

```cpp
// This file implements a simple calculator
```

## Function comments
Describe the use of the function and how it is implemented if it is non-obvious. For example:

```cpp
// Displays a greeting based on the time of day on the command line using the name parameter.
void show_greeting(std::string name) {
  ...
}
```

## Implementation comments
Provide comments in tricky, non-obvious, interesting, or important parts of your code.

```cpp
// Compute the distance between two points using the Manhattan distance formula
double dist = sqrt(pow(x1 - x2, 2) + pow(y1-y2, 2));
```

# Code evaluation
Open the terminal and navigate to the folder that contains this milestone. Assuming you have pulled the code inside of `/home/student/project02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd project02-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample commands below shows how you would compile code saved in `tuffynotes.cpp` and `notebook.cpp` and into the executable file `tuffynotes`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 tuffynotes.cpp notebook.cpp -o tuffynotes
./tuffynotes
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly, let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```

1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```

1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```

    When you're done, make sure you type `git commit` again.   

1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.

1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```

1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the project milestone page. Provide a short message in the text area such as "finished milestone" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.
