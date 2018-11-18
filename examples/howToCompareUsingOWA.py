#!/usr/bin/env python2.7
#
# Description:
#
#  Script that compares different sports shoes, based on a number of criteria, using the OWA approach
# 

# --- Import Python modules ---
import sys, os

# --- Import C++ OWA module ---
from MDMA import Criterion, InverseCriterion, Alternative, OWA

# --- Instantiate an OWA analysis ---
owa = OWA()

# --- Specify a set of criteria ---
owa.Append(Criterion("Cushioning",50))
owa.Append(InverseCriterion("Weight",50))

# --- Specify the alternatives ---
owa.Append(Alternative("Asics", [10, 350]))
owa.Append(Alternative("QN", [5, 250]))

# --- Summary of input data ---
owa.CheckData()
owa.PrintData()