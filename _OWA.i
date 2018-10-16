%module owa
 %{
 /* Includes the header in the wrapper code */
 #include "OWA.h"
 %}

 /* Parse the header file to generate wrappers */
 %include "OWA.h"