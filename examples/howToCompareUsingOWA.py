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
owa.Append(Criterion("Cushioning",25))
owa.Append(InverseCriterion("Weight",50,"grams"))
owa.Append(InverseCriterion("Price",25,"euros"))

# --- Specify the alternatives ---
owa.Append(Alternative("Asics", [10, 350, 180]))
owa.Append(Alternative("QN", [5, 250, 150]))

# --- Summary of input data ---
owa.PrintData()