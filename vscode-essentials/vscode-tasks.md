# VS Code Tasks Guide

VS Code Tasks allow you to automate common development workflows, such as compiling and running code, without needing external extensions like "Code Runner".

## 1. What is `tasks.json`?
Located inside the `.vscode` folder of your workspace, this file defines "Tasks" that VS Code can execute. It is the professional way to handle build pipelines in C++.

## 2. The "Compile and Run C++" Task
In this project, we configured a task to automate the C++ build process.

### The Configuration
```json
{
    "label": "Compile and Run C++",
    "type": "shell",
    "command": "g++ \"${file}\" -o \"${fileDirname}/${fileBasenameNoExtension}.exe\"; if ($?) { & \"${fileDirname}/${fileBasenameNoExtension}.exe\" }",
    "group": {
        "kind": "build",
        "isDefault": true
    },
    "presentation": {
        "reveal": "always",
        "panel": "shared",
        "focus": true,
        "clear": true
    },
    "problemMatcher": []
}
```

### How it Works (PowerShell 5.1 Compatibility)
On Windows, the default PowerShell version (5.1) does not support the standard Linux/Mac `&&` operator. Instead, we use:
- **`;`**: Runs the second command regardless of the first.
- **`if ($?)`**: A PowerShell variable that checks if the last command (the compiler) was successful.
- **`{ & ... }`**: The "Call" operator (`&`) is used to execute the generated `.exe`.

## 3. Keyboard Shortcut
Since this task is marked as the "Default Build Task", you can trigger it at any time by pressing:
**`Ctrl + Shift + B`**

## 4. Why use Tasks instead of Extensions?
- **Zero Dependencies**: Works in restricted environments (like Open VSX or offline environments) where specific extensions might be missing.
- **Customizable**: You can add specific compiler flags (like `-Wall` or `-std=c++20`) easily.
- **Team Friendly**: Since the `.vscode` folder can be shared with your team, everyone automatically gets the same "Play Button" behavior.
