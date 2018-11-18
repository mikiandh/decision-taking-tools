#!/usr/bin/env python2.7
#
# Description:
#
#  Script that compares possible PhD offers, based on a number of criteria, using the OWA approach
# 

# --- Import Python modules ---
import sys, os

# --- Import C++ OWA module ---
from MDMA import Criterion, Alternative, OWA

# --- Define sets of criteria and alternatives ---
criteria = CriteriaVector(2)
criteria[0] = Criterion("Salary", 30.0)
criteria[1] = Criterion("Interest", 70.0)

TUDelft = Alternative("TUDelft", [2700, 5])
DLR = Alternative("DLR", [2000, 7])

alternatives = AlternativesVector(2)
alternatives[0] = TUDelft
alternatives[1] = DLR

# --- Initialize the OWA ---
owa = OWA(criteria, alternatives)

# --- Compute the OWA scores ---