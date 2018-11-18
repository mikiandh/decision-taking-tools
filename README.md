Decision-taking-tools
=====================

This project implements various project management algorithms related to comparing alternatives under a set of
common criteria. Methods are implemented in C++11, but wrapped as Python modules by SWIG. Waf is employed as
automatic build tool.


Matrix-output Decision Making Algorithms (MDMA)
-----------------------------------------------

Module that implements various methods based on generating a comparison matrix, which is then treated as a concise representation of the solution space of the decision-taking problem. Available algorithms:

- **O**rdered **W**eighted **A**verage

- **PRESS** method