// main.cpp
#include "fs.h"
#include "operations.h"
#include <bits/stdc++.h>
using namespace std;

// to get the operation type
string getOperation(string &cmd)
{
    string op = "";
    int i = 0;
    while (i < cmd.length() && cmd[i] != ' ')
        op += cmd[i++];
    return op;
}

vector<string> getArgList(string &cmd)
{
    vector<string> argList;
    int sz = cmd.length();
    for (int i = 0; i < sz;)
    {
        string temp = "";
        while (i < sz && cmd[i] != ' ')
            temp += cmd[i++];
        argList.push_back(temp);
        i++; // update i
    }
    return argList;
}
void command(string &cmd, InMemoryFileSystem fs)
{
    // get the operation type
    string op = getOperation(cmd);
    int sz = cmd.length();
    // Now we have to call the methods of the InMemoryFileSystem
    int limit = op.length() + 1;
    vector<string> argList;
    bool empty = false;
    if (limit > cmd.length())
    {
        // arglist = empty
        empty = true;
    }
    else
    {
        string truncated = cmd.substr(limit, sz - limit);
        argList = getArgList(truncated);
    }

    if (op == "mkdir")
    {
        if (empty)
            cout << "Pass a directory name" << endl;
        else
            fs.mkdir(argList[0]);
    }
    else if (op == "ls")
    {
        string em = "";
        empty ? fs.ls(em) : fs.ls(argList[0]);
    }
    else if (op == "cd")
    {
        fs.cd(argList[0]);
    }
    else if (op == "touch")
    {
        fs.touch(argList[0]);
    }
    else if (op == "echo")
    {
        if (argList.size() == 2)
        {
            fs.echo(argList[0], argList[1]);
        }
        else
        {
            cout << "Enter Valid no of arguments!!" << endl;
        }
    }
    else if (op == "cat")
    {
        fs.cat(argList[0]);
    }
    else if (op == "mv")
    {
        fs.mv(argList[0], argList[1]);
    }
    else if (op == "rm")
    {
        fs.rm(argList[0]);
    }
    else if (op == "cp")
    {
        fs.cp(argList[0], argList[1]);
    }
    else if (op == "grep")
    {
        fs.grep(argList[0], argList[1]);
    }
    else if (op == "printFileSystem")
    {
        fs.printFileSystem();
    }
    else
    {
        cout << "Enter a valid operation to perform" << endl;
    }
}

int main()
{
    InMemoryFileSystem fileSystem;

    while (true)
    {
        string cmd;
        getline(cin, cmd);

        if (cmd == "exit")
        {
            cout << "session ended" << endl;
            break;
        }
        // Now we have to parse the command to know what operation to perform
        command(cmd, fileSystem);
    }
    // string path = "data";
    // string fileName = "file1.txt";
    // string echoText = "hello, world!";
    // string root = "/";
    // string dataDir = "/data";
    // // Test your operations here...
    // fileSystem.mkdir(path);
    // fileSystem.cd(path);
    // fileSystem.touch(fileName);
    // fileSystem.echo(echoText, fileName);
    // fileSystem.ls(path);
    // fileSystem.cd(root);
    // fileSystem.ls(dataDir);
    // fileSystem.printFileSystem();

    return 0;
}
