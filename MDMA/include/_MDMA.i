%module MDMA

%include "std_string.i"

%include "std_vector.i"
namespace std
{
  %template(VectorDouble) vector<double>;
}

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