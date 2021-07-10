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
in the PATH. Tested with Python 3.9.4 and SWIG 4.0.2 on Arch Linux (2021-07-10).

First, clone this repository to your machine:
```
git clone https://github.com/mikiandh/decision-taking-tools
```

Second, configure and build it using Waf:
```
cd decision-taking-tools
./waf configure build
```
> The [Waf script](https://gitlab.com/ita1024/waf "Waf's GitLab page") provided has been generated via `./waf-light --tools=swig`.

Third, make Python aware of the MDMA module:
```
cd build/py
export PYTHONPATH=$PYTHONPATH:$PWD
```
And that's it.

## Usage
See scripts in the 'examples' folder

## Author
Miquel Herrera | mail@miquelherrera.com

## License
My code is published under BSD 3-clause (see `LICENSE`).
The Waf build system, which I distribute, also uses this type of license (see `waf`).
