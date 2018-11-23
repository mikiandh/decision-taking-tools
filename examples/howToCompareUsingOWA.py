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
owa.Append(Criterion("Aesthetics",30,"1-3"))
owa.Append(InverseCriterion("Weight",40,"grams"))
owa.Append(InverseCriterion("Price",5,"euros"))

# --- Specify the alternatives ---
owa.Append(Alternative("Nike Air Zoom Winflo 4", [2, 3, 255, 110]))
owa.Append(Alternative("New Balance Fresh Foam Beacon", [4, 2, 213, 150]))
owa.Append(Alternative("Salomon Sonic RA Max", [5, 2, 265, 160]))
owa.Append(Alternative("Asics Gel Fortitude 8", [5, 3, 349, 179]))
owa.Append(Alternative("Altra Escalante 1.5", [3, 2, 224, 160]))
owa.Append(Alternative("Adidas Adizero Prime Parley", [2, 1, 128, 240]))
owa.Append(Alternative("Asics Roadhawk FF 2", [4, 3, 265, 120]))
owa.Append(Alternative("Asics Metarun", [4, 3, 300.5, 250]))
owa.Append(Alternative("New Balance Summit K.O.M GTX", [4, 3, 245.0, 150]))
owa.Append(Alternative("Merrel All Out Crush 2 GORE-TEX", [2, 2, 252.0, 140]))

# --- Summary of input data ---
owa.PrintData()

# --- Compute the OWA scores ---
owa.Compute()
