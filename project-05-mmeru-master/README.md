# TuffyNotes Project Milestone 5

This is milestone 5 of the [TuffyNotes Project](https://docs.google.com/document/d/14qiyhHtXpZOkVqHdUmLjLu1OWcBhQijvqybHtgsEWhI/edit?usp=sharing).

# Requirements
Refactor your Milestone 4 code so that the code will now use the object-oriented design to implement the program. Kindly modify your code so that it follows the design described below. Take note that you already implemented most functionalities in the previous milestones so you can reuse most of your code.

## Note class
### Data members
- `title_` - note title
- `body_` - note body

### Constructors
- `Note()` - initializes the `Note` object by setting its title to `"Untitled"` and body to `""`.
- `Note(const std::string &title, const std::string &body)` - initializes the `Note` object by setting its title and body according to the given parameters

### Member functions
- *accessors and mutators* for `title_` and `body_`
- `display()` - displays the title and body of the `Note` object using the following format: `[title]\nbody\n\n`. For example: `[Grocery list]\nmilk, banana, water, turkey sandwich\n\n`

## Notebook class
### Data members
- `capacity_` - total number of `Note`s that are stored in the `Notebook`
- `size_` - current number of `Note`s in the `Notebook`
- `notes_` - pointer to an array of `Note` objects

### Constructors
- `Notebook()` - initializes the `Notebook` by settings its capacity to `100`, setting its size to `0`, and dynamically creating an array of 100 `Note` objects that `notes_` points to
- `Notebook(int capacity)` - initializes the `Notebook` by settings its capacity to the given parameter, setting its size to `0`, and dynamically creating an array of `Note` objects whose size is based on the given parameter that `notes_` points to

### Destructor
Deletes the `Note` array from memory and sets `notes_` to `nullptr` to avoid *dangling pointers*

### Member functions
- *accessors* for `capacity_` and `size_`
- `void add(Note &new_note)` - adds a `Note` object to the array pointed to by `notes_`; take note that `size_` should increase by one because a `Note` is added
- `Note get(int index) const` - returns a `Note` object from the array pointed to by `notes_` based on the index provided. For example, if `index` is 2, then it will return the object at index 2. Take note that array indices start with 0.
- `void list() const` - same functionality as the `list()` function from Milestone 4, but it no longer uses parameters; instead it uses the `Notebook`'s data members to access the array and size.
- `void view() const` - same functionality as the `view()` function from Milestone 4, but it no longer uses parameters; instead it uses the `Notebook`'s data members to access the array and size.
- `void save(const std::string &filename) const` - same functionality as the `save()` function from Milestone 4, but it only uses one parameter; it uses the `Notebook`'s data members to access the array and size
- `void load(const std::string &filename)` - same functionality as the `load()` function from Milestone 4, but it only uses one parameter; it uses the `Notebook`'s data members to access the array and size.

Take note that the `create_note()` function will remain the same. Optionally, you can replace the code to use constructors to make it more efficient.

# Driver (tuffynotes.cpp)
The driver file that contains the menu should be updated so that it uses `Notebook` and `Note` objects. The menu itself will not change, but the function calls will be replaced by method calls.

All previously created functionalities from Milestones 1 to 4 should still work as expected. Kindly refer to the sample output below and follow it as closely as possible.

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

Place the function prototypes and classes in `notebook.hpp`, the function and method implementations in `notebook.cpp`, and the main function in `tuffynotes.cpp`. Take note that in the case of classes, any method whose body is over 5 lines or uses advanced constructs (e.g., if, switch, for) should have its implementation in `notebook.cpp`.

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
