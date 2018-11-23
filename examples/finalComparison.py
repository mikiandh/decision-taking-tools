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
owa.Append(Criterion("Cushioning",10,"level (1-5)"))
owa.Append(Criterion("Materials",10,"1-3"))
owa.Append(Criterion("Technologies",10,"1-3"))
owa.Append(Criterion("Aesthetics",20,"1-3"))
owa.Append(InverseCriterion("Age",10,"months"))
owa.Append(InverseCriterion("Weight",30,"grams"))
owa.Append(InverseCriterion("Price",10,"euros"))

# --- Specify the alternatives ---
owa.Append(Alternative("New Balance Fresh Foam Beacon", [4, 1, 1, 2, 6, 213, 110]))
owa.Append(Alternative("New Balance Summit K.O.M GTX", [3, 2, 3, 2, 5, 310, 150]))
owa.Append(Alternative("Asics Quantum 360 Knit 2", [5, 3, 3, 2, 3, 357, 200]))

# --- Summary of input data ---
owa.PrintData()

# --- Compute the OWA scores ---
owa.Compute()