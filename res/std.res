[0;35m--------------- TEST VECTOR ---------------[0m

[0;35m------------------- END -------------------[0m

[1;34m
--------------- TEST STACK ----------------[0m

[1;33m*** TEST CONSTRUCTORS ***[0m


SECOND INIT
[1;32mvec_it     = [ 20 20 20 20 20 ]

[0mDECREMENT END ITERATOR THIRD
FIRST
[1;32mvec_it     = [ ]

[0m
SECOND
[1;32mvec_it     = [ 0 1 2 3 4 5 6 7 8 9 ]

[0m
THIRD
[1;32mvec_it     = [ 0 1 2 3 4 5 6 7 8 ]

[0m
FOURTH
[1;32mvec_it     = [ 0 1 2 3 4 5 6 7 8 ]

[0m
[1;33m*** END ***[0m

[1;33m*** TEST METHODS ***[0m

[1;36m### capacity ###[0m

[1;32mvec_it     = [ ]

[0mv.empty()	=	1
[1;32mvec_it     = [ 2 3 5 8 ]

[0mv.empty()	=	0
v.size()	=	4
v.max_size()	=	4611686018427387903

[1;35mV RESIZED TO 2

[0mv.size()	=	2

[1;35mV RESIZED TO 10

[0mv.size()	=	10

[1;35mV RESERVE TO 100

[0mv.capacity()	=	100

[1;36m### END ###[0m

[1;36m### element access ###[0m

[1;32mvec_index  = [ 2 4 8 16 ]

[0mv.at(0)	=	2

[1;35mV AT(2) TO 3

[0m[1;32mvec_it     = [ 2 4 3 16 ]

[0mv.front()	=	2
v.back()	=	16

[1;36m### END ###[0m

[1;36m### modifiers ###[0m

v
[1;32mvec_it     = [ 100 100 100 100 100 100 100 12 ]

[0mv2 before pop back
[1;32mvec_it     = [ 100 100 100 100 100 ]

[0mv2 after pop back
[1;32mvec_it     = [ 100 100 100 100 ]

[0m[1;31m--------------------------------[0m

v2 insert nombre 1 a position begin + 1
[1;32mvec_it     = [ 100 1 100 100 100 ]

[0mv2 insert 2 fois nombre 300 a position begin + 1
[1;32mvec_it     = [ 100 300 300 1 100 100 100 ]

[0mv2 insert a it pos: begin a end - 1 nbr
[1;32mvec_it     = [ 100 300 300 1 100 100 100 300 300 1 100 100 100 ]

[0mv2 erase le nombre a begin + 3 (1)
[1;32mvec_it     = [ 100 300 300 100 100 100 300 300 1 100 100 100 ]

[0mv2 erase begin + 3 a end (tous les 100)
[1;32mvec_it     = [ 100 300 300 ]

[0m[1;31m--------------------------------[0m

BEFORE SWAP
[1;32mvec_it     = [ 100 100 100 100 100 100 100 12 ]

[0m[1;32mvec_it     = [ 100 300 300 ]

[0mAFTER SWAP V WITH V2 CONTENT
[1;32mvec_it     = [ 100 300 300 ]

[0m[1;32mvec_it     = [ 100 100 100 100 100 100 100 12 ]

[0mAFTER CLEAR
[1;32mvec_it     = [ ]

[0m[1;32mvec_it     = [ ]

[0m
[1;36m### END ###[0m

[1;36m### allocator ###[0m

The allocated array contains: 0 1 2 3 4

[1;36m### END ###[0m


[1;33m*** END ***[0m

[1;34m
------------------- END -------------------[0m

[1;32m
---------------- TEST MAP -----------------[0m

[1;32m
------------------- END -------------------[0m

