
<div align="center">

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
![building workflow](https://github.com/kanndil/multicoreOS/actions/workflows/Test-Cases.yml/badge.svg)
![Cppchecker workflow](https://github.com/kanndil/multicoreOS/actions/workflows/CppChecker.yml/badge.svg)

</div>

<div align="center">

  <a href="">[![Github Pages](https://img.shields.io/badge/github%20pages-121013?style=for-the-badge&logo=github&logoColor=white)](https://kanndil.github.io/multicoreOS/)</a>

</div>

# multicoreOS

An AUTOSAR compliant multicore OS for TriCore

# Table of contents

* [Overview](#-overview)
* [Objective](#-objective)
* [Dependencies](#-dependencies)
* [How to Use](#-how-to-use)
* [File Structure](#-file-structure)
* [How to Contribute](#-how-to-contribute)
* [Issue Tracker](#-issue-tracker)
* [Authors](#-authors)
* [Supervisors](#👨-supervisors)
* [License](#-license)


# 📖 Overview

The automotive industry relies heavily on Realtime operating systems (RTOS) to handle safety-critical applications that require precise timing and responsiveness. The adoption of RTOS has led to increased software quality, reduced development costs, and shorter time-to-market for new products.

Realtime Operating Systems and the Automotive Industry:

 - RTOS is designed to handle specific needs in the automotive industry, such as providing real-time data to the driver in the form of infotainment systems. These systems (RTOS) ensure that critical tasks are executed on time and without delay, providing a reliable and efficient solution for the automotive industry.


OSEK and AUTOSAR Standards:


-  The automotive industry has adopted two standards for RTOS. The OSEK (Open Systems and their Interfaces for Electronics in Motor Vehicles) standard was developed in the 1990s and defines a set of specifications for an RTOS in the automotive industry. AUTOSAR (Automotive Open System Architecture) which follows OSEK's principles, is a newer standard that has been adopted by the industry to create a common platform for the development of automotive software. AUTOSAR provides a standard methodology for designing, implementing, and integrating software components in vehicles.

Our project, which is the design of an AUTOSAR-compliant RTOS for next-generation eMobility, ADAS, automotive E/E architectures, and affordable AI applications, is essential for the automotive industry. By providing an RTOS that complies with the industry-standard AUTOSAR methodology, we ensure that our software is reliable, maintainable, and compatible with other AUTOSAR-compliant software. Additionally, our RTOS supports next-generation hardware accelerators, which are necessary for the efficient and effective functioning of these systems.

# 🙌 Objective

The project aims to support new hardware accelerators, such as the PPU (Parallel Processing Unit) and cDSP (Programmable digital signal processing for the ADC signals). 

# 🔨 Dependencies

### GCC

 - For macOS installtion please follow this [guide](http://cs.millersville.edu/~gzoppetti/InstallingGccMac.html)
 - For Windows installtion please follow this [guide](https://www.guru99.com/c-gcc-install.html)

- For Linux installtion please follow this [guide](https://www.geeksforgeeks.org/how-to-install-gcc-compiler-on-linux/)

### Make

- For macOS installtion please follow this [guide](https://formulae.brew.sh/formula/make)
 - For Windows installtion please follow this [guide](https://www.guru99.com/c-gcc-install.html)

- For Linux installtion please follow this [guide](https://www.geeksforgeeks.org/how-to-install-gcc-compiler-on-linux/)

# 🔍 How to Use

### Simulation

First run make file:

    make

Then run executable:

    ./myprogram


### Hardware Deployment

# 📜 File Structure
```bash
├── CONTRIBUTING.md
├── Doxyfile
├── LICENSE
├── Makefile
├── README.md
├── docsu
├── include
│   ├── EventMechanism.h
│   ├── InterruptHandler.h
│   ├── OSExecutionControl.h
│   ├── ResourceManager.h
│   ├── StatusDefintions.h
│   ├── TaskManager.h
│   ├── data_structure
│   ├── data_structure
│   │   ├── PriorityQueue.h
│   │   └── stack.h
│   └── includes.h
├── license_config
│   ├── LICENSE_HEADER.txt
│   └── config.json
├── myprogram
├── obj
│   ├── EventMechanism.o
│   ├── InterruptHandler.o
│   ├── OSExecutionControl.o
│   ├── PriorityQueue.o
│   ├── ResourceManger.o
│   ├── TaskManager.o
│   ├── main.o
│   ├── stack.o
│   ├── testCommon.o
│   ├── testEM.o
│   ├── testOSEC.o
│   ├── testRM.o
│   └── testTM.o
├── src
│   ├── EventMechanism.c
│   ├── InterruptHandler.c
│   ├── OSExecutionControl.c
│   ├── PriorityQueue.c
│   ├── ResourceManger.c
│   ├── TaskManager.c
│   ├── main.c
│   └── stack.c
├── suppressions.txt
└── tests
    ├── testCommon.c
    ├── testEM.c
    ├── testOSEC.c
    ├── testRM.c
    ├── testTM.c
    └── tests.h
```
# 💪 How to Contribute

You must first install all the needed dependencies and your code must pass all of github actions CIs.

To learn more about contributing to this project please check the  [Contribution Guidelines](https://github.com/kanndil/multicoreOS/blob/main/CONTRIBUTING.md).

# 📝 Issue Tracker

If you encounter any issues or bugs, please report them on our [GitHub issue tracker](https://github.com/kanndil/multicoreOS/issues).

#  🤩 Authors

- Ahmed Hesham

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ahesham900) 
   [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ahmed-dardir-541b32194)

- Ali El Liethy

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/aliellithi712) 
   [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mohamed-nasr-643396231/)

- Andrew Sinout

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/andrewsinout) 
    [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mohamed-nasr-643396231/)



- Mohamed Nasr

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/monassr) 
    [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mohamed-nasr-643396231/)

- Omar Mohey

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/omohey) 
    [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mohamed-nasr-643396231/)

- Yousef Kandil

    [![image](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/kanndil) 
   [![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/youssef-kandil-195638216/)


# 👨‍🏫 Supervisors
* Dr. Mohamed Shalan    (The American University in Cairo)
* Dr. Ahmed Moro        (Siemens)

# ⚖️ License

Licensed under the Apache License, Version 2.0 (the "License"); 
you may not use this file except in compliance with the License. 
You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software 
distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
See the License for the specific language governing permissions and 
limitations under the License.
