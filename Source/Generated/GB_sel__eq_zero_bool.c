//------------------------------------------------------------------------------
// GB_sel:  hard-coded functions for selection operators
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// If this file is in the Generated/ folder, do not edit it (auto-generated).

#include "GB_select.h"
#include "GB_ek_slice.h"
#include "GB_sel__include.h"

// The selection is defined by the following types and operators:

// phase1: GB_sel_phase1__eq_zero_bool
// phase2: GB_sel_phase2__eq_zero_bool
// A type: bool

// kind
#define GB_ENTRY_SELECTOR

#define GB_ATYPE \
    bool

// test value of Ax [p]
#define GB_TEST_VALUE_OF_ENTRY(p)                       \
    !(Ax [p])

// get the vector index (user select operators only)
#define GB_GET_J                                        \
    ;

// Cx [pC] = Ax [pA], no typecast
#define GB_SELECT_ENTRY(Cx,pC,Ax,pA)                    \
    /* assignment skipped, Cx already all zero */

//------------------------------------------------------------------------------
// GB_sel_phase1__eq_zero_bool
//------------------------------------------------------------------------------



void GB_sel_phase1__eq_zero_bool
(
    int64_t *GB_RESTRICT Zp,
    int64_t *GB_RESTRICT Cp,
    GB_void *GB_RESTRICT Wfirst_space,
    GB_void *GB_RESTRICT Wlast_space,
    const GrB_Matrix A,
    const int64_t *GB_RESTRICT kfirst_slice,
    const int64_t *GB_RESTRICT klast_slice,
    const int64_t *GB_RESTRICT pstart_slice,
    const bool flipij,
    const int64_t ithunk,
    const bool *GB_RESTRICT xthunk,
    const GxB_select_function user_select,
    const int ntasks,
    const int nthreads
)
{ 
    int64_t *GB_RESTRICT Tx = Cp ;
    ;
    #include "GB_select_phase1.c"
}



//------------------------------------------------------------------------------
// GB_sel_phase2__eq_zero_bool
//------------------------------------------------------------------------------

void GB_sel_phase2__eq_zero_bool
(
    int64_t *GB_RESTRICT Ci,
    bool *GB_RESTRICT Cx,
    const int64_t *GB_RESTRICT Zp,
    const int64_t *GB_RESTRICT Cp,
    const int64_t *GB_RESTRICT C_pstart_slice,
    const GrB_Matrix A,
    const int64_t *GB_RESTRICT kfirst_slice,
    const int64_t *GB_RESTRICT klast_slice,
    const int64_t *GB_RESTRICT pstart_slice,
    const bool flipij,
    const int64_t ithunk,
    const bool *GB_RESTRICT xthunk,
    const GxB_select_function user_select,
    const int ntasks,
    const int nthreads
)
{ 
    ;
    #include "GB_select_phase2.c"
}

