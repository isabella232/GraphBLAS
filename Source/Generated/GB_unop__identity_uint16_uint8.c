//------------------------------------------------------------------------------
// GB_unop:  hard-coded functions for each built-in unary operator
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// If this file is in the Generated/ folder, do not edit it (auto-generated).

#include "GB.h"
#ifndef GBCOMPACT
#include "GB_control.h"
#include "GB_unop__include.h"

// C=unop(A) is defined by the following types and operators:

// op(A)  function:  GB_unop_apply__identity_uint16_uint8
// op(A') function:  GB_unop_tran__identity_uint16_uint8

// C type:   uint16_t
// A type:   uint8_t
// cast:     uint16_t cij = (uint16_t) aij
// unaryop:  cij = aij

#define GB_ATYPE \
    uint8_t

#define GB_CTYPE \
    uint16_t

// aij = Ax [pA]
#define GB_GETA(aij,Ax,pA) \
    uint8_t aij = Ax [pA]

#define GB_CX(p) Cx [p]

// unary operator
#define GB_OP(z, x) \
    z = x ;

// casting
#define GB_CAST(z, aij) \
    uint16_t z = (uint16_t) aij ;

// cij = op (aij)
#define GB_CAST_OP(pC,pA)           \
{                                   \
    /* aij = Ax [pA] */             \
    uint8_t aij = Ax [pA] ;          \
    /* Cx [pC] = op (cast (aij)) */ \
    uint16_t z = (uint16_t) aij ;               \
    Cx [pC] = z ;        \
}

// disable this operator and use the generic case if these conditions hold
#define GB_DISABLE \
    (GxB_NO_IDENTITY || GxB_NO_UINT16 || GxB_NO_UINT8)

//------------------------------------------------------------------------------
// Cx = op (cast (Ax)): apply a unary operator
//------------------------------------------------------------------------------



GrB_Info GB_unop_apply__identity_uint16_uint8
(
    uint16_t *Cx,       // Cx and Ax may be aliased
    const uint8_t *Ax,
    int64_t anz,
    int nthreads
)
{ 
    #if GB_DISABLE
    return (GrB_NO_VALUE) ;
    #else
    int64_t p ;
    #pragma omp parallel for num_threads(nthreads) schedule(static)
    for (p = 0 ; p < anz ; p++)
    {
        uint8_t aij = Ax [p] ;
        uint16_t z = (uint16_t) aij ;
        Cx [p] = z ;
    }
    return (GrB_SUCCESS) ;
    #endif
}



//------------------------------------------------------------------------------
// C = op (cast (A')): transpose, typecast, and apply a unary operator
//------------------------------------------------------------------------------

GrB_Info GB_unop_tran__identity_uint16_uint8
(
    GrB_Matrix C,
    const GrB_Matrix A,
    int64_t *GB_RESTRICT *Rowcounts,
    GBI_single_iterator Iter,
    const int64_t *GB_RESTRICT A_slice,
    int naslice
)
{ 
    #if GB_DISABLE
    return (GrB_NO_VALUE) ;
    #else
    #define GB_PHASE_2_OF_2
    #include "GB_unop_transpose.c"
    return (GrB_SUCCESS) ;
    #endif
}

#endif

