function C = asec (G)
%ASEC inverse secant.
% C = asec (G) computes the inverse secant of each entry of a GraphBLAS
% matrix G.  Since asec (0) is nonzero, the result is a full matrix.
% C is complex if any (abs(G) < 1).
%
% See also GrB/sec, GrB/sech, GrB/asech.

% SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights
% Reserved. http://suitesparse.com.  See GraphBLAS/Doc/License.txt.

G = G.opaque ;
type = gbtype (G) ;
if (~gb_isfloat (type))
    type = 'double' ;
end

C = GrB (gb_trig ('acos', gbapply ('minv', gbfull (G, type)))) ;
