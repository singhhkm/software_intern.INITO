# software_intern.INITO

Latest g++ complier installed

File System Interactions
The in-memory file system supports the following operations:

mkdir: Create a new directory.
cd: Change the current working directory.
ls: List the contents of a directory.
touch: Create a new empty file.
cat: Display the contents of a file.
echo: Write text to a file.
grep: Search for a pattern in a file.
cp: Copy a file or directory to another location.
mv: Move a file or directory to another location.
rm: Remove a file or directory.
Note: The state is not saved between sessions.

Implementation Details

InMemoryFileSystem Class
currentDirectory: Represents the current working directory.
fileSystem: An unordered map representing the file system structure.
Methods
mkdir: Create a directory.
cd: Change directory.
ls: List directory contents.
grep: Search for a pattern in a file.
cat: Display file contents.
touch: Create an empty file.
echo: Write text to a file.
mv: Move a file or directory.
cp: Copy a file or directory.
rm: Remove a file or directory.

Design Decisions

In-Memory Representation: Utilizes a nested unordered map to represent the file system in memory.
Directory Navigation: Supports navigation to the parent directory (..), root directory (/), and specified absolute paths.
Error Handling: Basic error handling for existing directory or file creation.
Content Storage: File contents are stored in-memory; no state is saved.
Containerization: Dockerfile provided for easy containerization.

Conclusion
The in-memory file system offers fundamental file operations and is designed for modularity. Its Docker containerization simplifies deployment.



