# Decision Tree for Binary Classification Project
## Overview

* In this project, we use `Decision Tree` to predict whether a patient is having diabetes or not based on a variety of health attributes.

* The algorithm used to build the `Decision Tree` is Iterative Dichotomiser 3 `ID3` - an algorithm invented by Ross Quinlan used to generate a `Decision Tree` from a dataset.  

* This project contains C++ libraries and programs to:

    - Predict the outcome given training data and infomations of the sample - <em>predict</em> 
    - Return the model prediction in `result.txt`, accuracy and precision in terminal - <em>getresult</em>

* The source code has been updated to modern C++ style and for cross-platform use.

## Requirements / dependencies

On `Unix` (Linux, Mac OS, and Cygwin) and `Windows`, the code compiles using the `g++` compilers (version 7.5.0 or higher) and GNU `make`.
### Unix

#### Update / install g++ compiler
* Run the following commands to install `g++`: 
<br/>`sudo apt update`
<br/>`sudo apt install build-essential`

* Once the installation is finished, verify the installation of these packages by checking the G++ version on your system with the following command:
 `g++ --version`
### Windows

#### Update / download minGW
* To check your `g++` compiler's version, run the following command on `Command Prompt`:
`g++ --version`

* Follow the instruction in the link below to update/download `minGW` if `g++` version < 11:

https://nuwen.net/mingw.html

#### Install Chocolatey

* First run `Command Prompt` as administrator, then run the following command:

     `@"%SystemRoot%\System32\WindowsPowerShell\v1.0\powershell.exe" -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "[System.Net.ServicePointManager]::SecurityProtocol = 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))" && SET "PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin"`

* Wait a few seconds for the command to complete.
If you don't see any errors, you are ready to use Chocolatey! Type `choco` or `choco -?` to check if the installation is complete.

* Read the instruction in the following link for more infomation: https://docs.chocolatey.org/en-us/choco/setup

#### Install MAKE

Run `Command Prompt` as administrator and run the following command to install GNU `make`:

`choco install make`

## Code compilation

To build all programs, run `make` command in this project's root directory by either using `Visual Studio Code` or `Command Prompt`.

## Reference

* Data package: https://www.kaggle.com/datasets/mathchi/diabetes-data-set

