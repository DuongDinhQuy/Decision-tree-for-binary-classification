# Decision Tree for Binary Classification Project
## Overview

This project contains C++ libraries and programs to 

- <em>predict</em> (predict the outcome given training data and infomations of the sample)
- <em>getresult</em> (return the model prediction accuracy)

The source code has been updated to modern C++ style and for cross-platform use.


## Requirements / dependencies

On `Unix` (Linux, Mac OS, and Cygwin) and `Windows`, the code compiles using the `g++` compilers (version 7.5.0 or higher) and GNU `make`.
### Unix

#### Update / install g++ compiler
Run the following commands to install `g++`: 
<br/>`sudo apt update`
<br/>`sudo apt install build-essential`

Once the installation is finished, verify the installation of these packages by checking the G++ version on your system with the following command:
 `g++ --version`
### Windows

#### Update / download minGW
To check your `g++` compiler's version, run the following command on `Command Prompt`:
`g++ --version`

Follow this link to update/download `minGW` if `g++` version < 7.5.0:

https://nuwen.net/mingw.html

#### Install Chocolatey

First run `Command Prompt` as administrator, then run the following command:

`@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "[System.Net.ServicePointManager]::SecurityProtocol = 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"`

Wait a few seconds for the command to complete.
If you don't see any errors, you are ready to use Chocolatey! Type `choco` or `choco -?` to check if the installation is complete.

Check this link for more infomation: https://docs.chocolatey.org/en-us/choco/setup

#### Install MAKE

Run `Command Prompt` as administrator and run the following command to install GNU `make`:

`choco install make`

## Code compilation

To build all programs, run `make` command in this project's root directory by either using `Visual Studio Code` or `Command Prompt`.


