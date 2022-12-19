# Decision Tree for Binary Classification Project
## Overview

This project contains C++ libraries and programs to 

- <em>predict</em> (predict the outcome given training data and infomations of the sample)
- <em>getresult</em> (return the model prediction accuracy)

The source code has been updated to modern C++ style and for cross-platform use.

In this project, by using a decision tree, we can predict whether a patient is having diabetes or not based on a variety of health attributes, normally in a continuous form. 
The main algorithm used to build the decision tree is Iterative Dichotomiser 3 (ID3). Although ID3 is a decision tree algorithm applied to classification problems where all the attributes are in categorical form, but other datasets that use continuous attributes (numeric), we can still use it by posing series of questions based on the thresholds contained in that attribute. 
Please note that the accuracy of this model is only approx. 70%. Because in ID3, we need to determine the order of attributes to be considered at each step. For problems with many attributes and each attribute has many different values, finding the optimal solution is often very difficult. The accuracy of the model is not higher because the ID3 algorithm is more suitable for discrete attributes, not continuous attributes like the dataset in use. Then overfitting may occur in some cases.


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

Follow this link to update/download `minGW` if `g++` version < 11:

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


