function C = expm1 (G)
%EXPM1 exp(x)-1 of the entries of a GraphBLAS matrix
% C = expm1 (G) computes (e^x)-1 of each entry x of a GraphBLAS matrix G.
%
% See also GrB/exp, GrB/expm1, GrB/exp2, GrB/log, GrB/log10, GrB/log2.

% SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights
% Reserved. http://suitesparse.com.  See GraphBLAS/Doc/License.txt.

G = G.opaque ;
type = gbtype (G) ;

if (~gb_isfloat (gbtype (G)))
    op = 'expm1.double' ;
else
    op = 'expm1' ;
end

C = GrB (gbapply (op, G)) ;
