# JDE ROBOT C++ Coding Challenge
## Question
Follow this link
https://drive.google.com/file/d/1GO0GJIi7rNqZXhPEaV8Qf0Ds4qFHczJ2/view?usp=sharing

## My Solution
The source code mentioned in this git repo is my approach for solution.
To solve this challenge, I used a graph-based approach where each hole in the labyrinth represents a vertex in the graph, and edges connect adjacent holes. I then perform a depth-first search (DFS) to find the longest path from the top to the bottom of the labyrinth.

To keep track of the visited holes during the DFS, I used a matrix to represent the labyrinth, where each hole is either a 0 if unvisited or a positive integer indicating the order in which it was visited. We can also keep track of the length of the longest path found so far and update it as we explore the graph.

The code reads the input from a file called input.txt, which should contain the labyrinth in the format specified in the challenge. The output is written to a file called output.txt, where the first line is the length of the longest path found, or -1 if no path was found. 

the above code should compile with the gcc compiler version 4.8 or higher, as it uses only standard libraries of C++11, which are supported by this version of the compiler.

However, if you encounter any compilation errors, you may need to check if your compiler flags and settings are configured correctly. It's also possible that some of the functions or features used in the code are not supported by older versions of the C++ standard, so you may need to update your compiler or modify the code accordingly.
