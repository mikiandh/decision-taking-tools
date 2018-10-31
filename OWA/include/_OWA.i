%module OWA
 
 %include <std_shared_ptr.i>
 %shared_ptr(Alternative)
 %shared_ptr(Criterion)
 %shared_ptr(NCriterion)
 
 %{
 /* Includes the header in the wrapper code */
 #include "OWA.h"
 #include "Alternative.h"
 #include "Criterion.h"
 %}

 /* Parse the header file to generate wrappers */
 %include "OWA.h"
 %include "Alternative.h"
 %include "Criterion.h"