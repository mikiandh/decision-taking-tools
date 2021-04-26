# Decision taking tools

This project implements various project management algorithms useful for
comparing alternatives under a set of common criteria. Methods are
implemented in C++11, but wrapped as Python modules by SWIG; the whole
thing is automatically taken care of using Waf.


## **M**atrix-output **D**ecision **M**aking **A**lgorithms (MDMA)

Module that implements various methods based on generating a comparison
matrix, which is then treated as a concise representation of the solution
space of the decision-taking problem.

Available algorithms:

- **O**rdered **W**eighted **A**verage (OWA)


## Installation

The following simple steps will make the MDMA module available to the
*current* terminal. Assumes Unix OS, with SWIG and Python installed and
in the PATH. Tested with Python 2.7 and SWIG 4.0.2 in MacOS Catalina
10.15.7.

First, clone this repository to your machine:
```
git clone https://github.com/mikiandh/decision-taking-tools
```

Second, configure and build it using WAF (a Python script, included):
```
cd decision-taking-tools
./waf configure build
```

Third, make Python aware of the MDMA module:
```
cd build/py
export PYTHONPATH=$PYTHONPATH:$PWD
```
And that's it.

## Usage
Several examples are provided in the homonymously named folder.

## Author
Miquel Herrera | mail@miquelherrera.com

## License
My code is published under BSD 3-clause (see `LICENSE`).
The Waf build system, which I distribute, also uses this type of license (see `waf`).
