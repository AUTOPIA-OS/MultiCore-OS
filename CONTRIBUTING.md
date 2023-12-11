# Contribution 
## 🔨 Dependencies 

### GCC

 - For Windows installtion please follow this [guide](https://www.guru99.com/c-gcc-install.html)

- For Linux installtion please follow this [guide](https://www.geeksforgeeks.org/how-to-install-gcc-compiler-on-linux/)

### Make

 - For Windows installtion please follow this [guide](https://www.guru99.com/c-gcc-install.html)

- For Linux installtion please follow this [guide](https://www.geeksforgeeks.org/how-to-install-gcc-compiler-on-linux/)

### Misra C

- Go to the official [Cppcheck GitHub page](https://github.com/danmar/cppcheck) and follow the installation instructions provided on the README file of the GitHub repository to install Cppcheck on your system.

### Clang 

- Linux Installtion:

      sudo apt-get install clang

- Windows installation through [LLVM website](https://releases.llvm.org/download.html)





## ✅ Pull requests

To contribute to this repo, you need to fork the repo and add you changes to your forked version then file a Pull Request to the orginal repo.

### Pull Request Format:

- Signed by: Tom Cruise

- Context: Added documentation for Mission Impossible

- Changes: missionImpossible.h missionImpossible.c

## 🚀 Committing Guidelines

- Each commit should address exactly one objective

- Add precise comments

- Signoff all commits

      git commit --signoff -m "precise comment"

## ✨ Code Formatting

- Follow MisraC standards: Use [cpp checker](https://github.com/danmar/cppcheck) and make sure your code passes MisraC checks before committing

      cppcheck --addon=misra --suppressions-list=suppressions.txt --error-exitcode=1 src

If a certain rule must be violated add a suppression statement to suppressions.txt followed by a brief explanation of why the rule is being suppressed.

- Use CamelCase naming convention

- Don't forget to use Clang-format to lint your code: Run the following commands before committing

      find . -name '*.c' | xargs clang-format -i -style=file
      find . -name '*.h' | xargs clang-format -i -style=file

## 📚 In line docummentation

## 📝 Commenting convention

## 👷 Add Unit Test

When adding a new component, you need to follow the following steps:

- Create a file containing your test cases in ./tests

- Add a prototype of the testcase functions you provided in ./tests/test.h

Your unit test will be checked using GitHub CI. Ensure that the new code passes all test cases; otherwise, the pull request will be rejected.

## 📝 Issue Tracker

If you encounter any issues or bugs, please report them on our [GitHub issue tracker](https://github.com/kanndil/multicoreOS/issues).

## ⚖️ License

Add the following license header to any added file

    //   Copyright 2023 AUC-Siemens Thesis Project
    //
    //   Licensed under the Apache License, Version 2.0 (the "License");
    //   you may not use this file except in compliance with the License.
    //   You may obtain a copy of the License at
    //
    //       http://www.apache.org/licenses/LICENSE-2.0
    //
    //   Unless required by applicable law or agreed to in writing, software
    //   distributed under the License is distributed on an "AS IS" BASIS,
    //   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    //   See the License for the specific language governing permissions and
    //   limitations under the License.
