[0;35m--------------- TEST VECTOR ---------------[0m

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

[1;33m*** TEST ITERATOR ***[0m

[1;36m### constructor ###[0m

[1;32mvec_it     = [ 500 600 700 800 ]

[0m
[0m*it		=	700
*copy_constr	=	700
*copy_assign	=	700

[0m*it_c		=	700

[1;36m### END ###[0m

[1;36m### arithmetic operators ###[0m

[1;32mvec_it     = [ 10 20 30 40 ]

[0m*it		=	10
*it++		=	10
*it		=	20
*++it		=	30

*it		=	30
*it--		=	30
*it		=	20
*--it		=	10

*it		=	30
*(it + 1)	=	40
*(1 + it)	=	40
*(it - 1)	=	20

*it		=	30
it -= 2		=	10
it += 2		=	30

*it		=	30
--it		=	20
++it		=	30
it--		=	20
it++		=	30

it[i]	=	30
it[i]	=	40
it[i]	=	0
it[i]	=	-2147483648

[1;36m### END ###[0m

[1;36m### relational operators ###[0m

*a	=	6
*b	=	6
*c	=	7

b != c
a == b
b < c
c > b
a <= b
c >= b

[1;36m### END ###[0m


[1;33m*** END ***[0m

[1;33m*** TEST REV ITERATOR ***[0m

[1;36m### constructor ###[0m

[1;32mvec_it     = [ 500 600 700 800 ]

[0m[1;32mvec_rev_it = [ 800 700 600 500 ]

[0m
[1;36m### END ###[0m

[1;36m### arithmetic operators ###[0m

[1;32mvec_rev_it = [ 40 30 20 10 ]

[0m*it		=	40
*it++		=	40
*it		=	30
*++it		=	20

*it		=	20
*it--		=	20
*it		=	30
*--it		=	40

*it		=	20
*(it + 1)	=	10
*(1 + it)	=	10
*(it - 1)	=	30

*it		=	20
it -= 2		=	40
it += 2		=	20

*it		=	20
--it		=	30
++it		=	20
it--		=	30
it++		=	20

it[i]	=	40
it[i]	=	30
it[i]	=	20
it[i]	=	10

[1;36m### END ###[0m

[1;36m### relational operators ###[0m

*a	=	7
*b	=	7
*c	=	6

b != c
a == b
b < c
c > b
a <= b
c >= b

[1;36m### END ###[0m


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

[0;35m------------------- END -------------------[0m

[1;34m
--------------- TEST STACK ----------------[0m

[1;34m
------------------- END -------------------[0m

[1;32m
---------------- TEST MAP -----------------[0m

[1;32m
------------------- END -------------------[0m

