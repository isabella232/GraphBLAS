//------------------------------------------------------------------------------
// GrB_Monoid_new:  create a new monoid
//------------------------------------------------------------------------------

// SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights Reserved.
// http://suitesparse.com   See GraphBLAS/Doc/License.txt for license.

//------------------------------------------------------------------------------

// Create a new monoid with binary operator, z=op(x.y).  The three types of x,
// y, and z must all be the same, and the identity value must also have the
// same type.  No typecasting is done for the identity value.

#include "GB.h"

#define GB_MONOID_NEW(prefix,type,T)                                        \
GrB_Info prefix ## Monoid_new_ ## T       /* create a new monoid */         \
(                                                                           \
    GrB_Monoid *monoid,             /* handle of monoid to create    */     \
    GrB_BinaryOp op,                /* binary operator of the monoid */     \
    type identity                   /* identity value of the monoid  */     \
)                                                                           \
{                                                                           \
    GB_WHERE (GB_STR(prefix) "Monoid_new_" GB_STR(T)                        \
        " (&monoid, op, identity)") ;                                       \
    type id = identity ;                                                    \
    return (GB_Monoid_new (monoid, op, &id, NULL, GB_ ## T ## _code, Context));\
}

GB_MONOID_NEW (GrB_, bool      , BOOL   )
GB_MONOID_NEW (GrB_, int8_t    , INT8   )
GB_MONOID_NEW (GrB_, uint8_t   , UINT8  )
GB_MONOID_NEW (GrB_, int16_t   , INT16  )
GB_MONOID_NEW (GrB_, uint16_t  , UINT16 )
GB_MONOID_NEW (GrB_, int32_t   , INT32  )
GB_MONOID_NEW (GrB_, uint32_t  , UINT32 )
GB_MONOID_NEW (GrB_, int64_t   , INT64  )
GB_MONOID_NEW (GrB_, uint64_t  , UINT64 )
GB_MONOID_NEW (GrB_, float     , FP32   )
GB_MONOID_NEW (GrB_, double    , FP64   )
GB_MONOID_NEW (GxB_, GxB_FC32_t, FC32   )
GB_MONOID_NEW (GxB_, GxB_FC64_t, FC64   )

GrB_Info GrB_Monoid_new_UDT         // create a monoid with a user-defined type
(
    GrB_Monoid *monoid,             // handle of monoid to create
    GrB_BinaryOp op,                // binary operator of the monoid
    void *identity                  // identity value of the monoid
)
{ 
    GB_WHERE ("GrB_Monoid_new_UDT (&monoid, op, identity)") ;
    GB_RETURN_IF_NULL (identity) ;
    return (GB_Monoid_new (monoid, op, identity, NULL, GB_UDT_code, Context)) ;
}

