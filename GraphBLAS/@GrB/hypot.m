function C = hypot (A, B)
%HYPOT robust computation of the square root of sum of squares.
% C = hypot (A,B) computes sqrt (abs (A).^2 + abs (B).^2) accurately.
% If A and B are matrices, the pattern of C is the set union of A and B.
% If one of A or B is a nonzero scalar, the scalar is expanded into a
% dense matrix the size of the other matrix, and the result is a full
% matrix.
%
% The input matrices may be either GraphBLAS and/or MATLAB matrices, in
% any combination.  C is returned as a GraphBLAS matrix.
%
% See also GrB/abs, GrB/norm, GrB/sqrt, GrB/plus, GrB.eadd.

% SuiteSparse:GraphBLAS, Timothy A. Davis, (c) 2017-2020, All Rights
% Reserved. http://suitesparse.com.  See GraphBLAS/Doc/License.txt.

if (isobject (A))
    A = A.opaque ;
end

if (isobject (B))
    B = B.opaque ;
end

atype = gbtype (A) ;
btype = gbtype (B) ;

if (contains (atype, 'complex'))
    A = gbapply ('abs', A) ;
elseif (~gb_isfloat (atype))
    A = gbnew (A, 'double') ;
end

if (contains (btype, 'complex'))
    B = gbapply ('abs', B) ;
elseif (~gb_isfloat (btype))
    B = gbnew (B, 'double') ;
end

C = GrB (gbapply ('abs', gb_eadd (A, 'hypot', B))) ;
