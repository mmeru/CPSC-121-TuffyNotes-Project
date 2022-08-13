# TuffyNotes Project Milestone 1

This is milestone 1 of the [TuffyNotes Project](https://docs.google.com/document/d/14qiyhHtXpZOkVqHdUmLjLu1OWcBhQijvqybHtgsEWhI/edit?usp=sharing).

# Requirements
Develop a menu-based command-line interface (CLI) that repeatedly asks a user to create a note or exit. If the user decides to create a note, the program will ask for the note's title and note body. If the user provides an invalid choice, the program should display an error message. Kindly refer to the sample runs below and follow the output as closely as possible.

```
Welcome to TuffyNotes!
[C] Create a note
[E] Exit
Choice: c

Please enter the note's title: Grocery list
Please enter the note: milk, banana, water, turkey sandwich

Note added!

[C] Create a note
[E] Exit
Choice: v

Invalid choice. Please try again.

[C] Create a note
[E] Exit
Choice: e

Thank you for using TuffyNotes!
```

Create the `add_note` function that will be responsible for asking the user to input a single note title and note body pair. For now, your code will not store the note. This function is only used to display the instructions and retrieve inputs.

Design your `main` function so that it asks the user to choose between creating a note or exiting the program. It should call the `add_note` function when the user asks to create a question and exits otherwise. Also, display the error message accordingly.

Save your code in the file called `tuffynotes.cpp`.

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
void show_greeting(string name) {
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
Open the terminal and navigate to the folder that contains this milestone. Assuming you have pulled the code inside of `/home/student/project01-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd project01-tuffy
```

Use the `clang++` command to compile your code and the `./` command to run it. The sample commands below shows how you would compile code save in `tuffynotes.cpp` and into the executable file `tuffynotes`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
clang++ -std=c++17 tuffynotes.cpp -o tuffynotes
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
