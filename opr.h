// operations.h
#include <bits/stdc++.h>
#include "fs.h"
#include <regex>
using namespace std;

InMemoryFileSystem::InMemoryFileSystem() : currentDirectory("/")
{
    fileSystem["/"] = {};
}
void InMemoryFileSystem::mkdir(string &directoryName)
{
    string newDirectoryPath = getAbsolutePath(directoryName);
    cout << newDirectoryPath << endl;
    if (fileSystem.find(newDirectoryPath) != fileSystem.end())
    {
        fileSystem[newDirectoryPath] = {};
    }
    else
    {
        cout << "Directory '" << directoryName << "' already exists." << endl;
    }

    // go on moving to directories until you encounter the path if it exists return it exists else create a new one
    //  int sz = directoryName.length();
    //  for(int i = 0; i < )
}

void InMemoryFileSystem::cd(string &path)
{
    if (path == "/")
    {
        currentDirectory = "/";
    }
    else if (path == "~")
    {
        currentDirectory = "/";
    }
    else if (path == "..")
    {
        if (currentDirectory != "/")
        {
            size_t lastSlash = currentDirectory.find_last_of('/');
            currentDirectory = currentDirectory.substr(0, lastSlash);
        }
    }
    else
    {
        string absPath = getAbsolutePath(path);
        if (fileSystem.find(absPath) != fileSystem.end())
        {
            currentDirectory = absPath;
        }
        else
        {
            cout << "Error: Directory '" << path << "' not found." << endl;
        }
    }
}

void InMemoryFileSystem::ls(string &path)
{
    string absPath = getAbsolutePath(path.empty() ? currentDirectory : path);
    if (fileSystem.find(absPath) != fileSystem.end())
    {
        for (auto it : fileSystem[absPath])
        {
            cout << it.first << endl;
        }
    }
    else
    {
        cout << "Error: Directory '" << path << "' not found." << endl;
    }
}

void InMemoryFileSystem::touch(string &fileName)
{
    string filePath = getAbsolutePath(fileName);
    if (fileSystem.find(filePath) == fileSystem.end())
    {
        fileSystem[filePath] = {};
    }
    else
    {
        cout << "File '" << fileName << "' already exists." << endl;
    }
}

void InMemoryFileSystem::cat(string &fileName)
{
    string filePath = getAbsolutePath(fileName);
    if (fileSystem.find(filePath) != fileSystem.end())
    {
        for (auto &line : fileSystem[filePath])
        {
            cout << line.second << endl;
        }
    }
    else
    {
        cout << "Error: File '" << fileName << "' not found." << endl;
    }
}

void InMemoryFileSystem::echo(string &text, string &fileName)
{
    string filePath = getAbsolutePath(fileName);
    if (fileSystem.find(filePath) != fileSystem.end())
    {
        fileSystem[filePath] = {{"content", text}};
    }
    else
    {
        cout << "Error: File '" << fileName << "' not found." << endl;
    }
}

void InMemoryFileSystem::mv(string &source, string &destination)
{
    string sourcePath = getAbsolutePath(source);
    string destinationPath = getAbsolutePath(destination);

    if (fileSystem.find(sourcePath) != fileSystem.end())
    {
        fileSystem[destinationPath] = fileSystem[sourcePath];
        fileSystem.erase(sourcePath);
    }
    else
    {
        cout << "Error: Source '" << source << "' not found." << endl;
    }
}

void InMemoryFileSystem::cp(string &source, string &destination)
{
    string sourcePath = getAbsolutePath(source);
    string destinationPath = getAbsolutePath(destination);

    if (fileSystem.find(sourcePath) != fileSystem.end())
    {
        fileSystem[destinationPath] = fileSystem[sourcePath];
    }
    else
    {
        cout << "Error: Source '" << source << "' not found." << endl;
    }
}

void InMemoryFileSystem::rm(string &path)
{
    string absPath = getAbsolutePath(path);
    if (fileSystem.find(absPath) != fileSystem.end())
    {
        fileSystem.erase(absPath);
    }
    else
    {
        cout << "Error: '" << path << "' not found." << endl;
    }
}

string InMemoryFileSystem::getAbsolutePath(string &path)
{
    if (path[0] == '/')
        return path;
    return currentDirectory + "/" + path;
}

void InMemoryFileSystem::printFileSystem()
{
    for (auto it : fileSystem)
    {
        cout << "Directory: " << it.first << endl;
        for (auto f : it.second)
        {
            cout << "File: " << f.first << endl;
        }
    }
}

void InMemoryFileSystem::grep(string &pattern, string fileName)
{
    if (fileName == "*")
    {
        // do this
    }
    else
    {
        string path = getAbsolutePath(fileName);

        if (fileSystem.count(path) && fileSystem[path].count("content") > 0)
        {
            string content = fileSystem[path].at("content");
            regex regexPattern(pattern);
            smatch match;

            istringstream iss(content);
            string line;
            int no = 1;

            while (getline(iss, line))
            {
                if (regex_search(line, match, regexPattern))
                {
                    cout << "Found in: " << fileName << " at line: " << no << ": " << line << endl;
                }
                no++;
            }
        }
        else
        {
            cout << "Not found in the file: " << fileName << endl;
        }
    }
}