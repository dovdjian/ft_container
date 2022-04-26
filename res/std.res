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

it[i]	=	10
it[i]	=	20
it[i]	=	30
it[i]	=	40

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
v.max_size()	=	2305843009213693951

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

[0mv2 erase le nombre a begin + 3 (1)
[1;32mvec_it     = [ 100 300 300 100 100 100 ]

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

[1;33m*** TEST PAIR ***[0m

The price of pineapple is $0.99
The price of shoes is $39.9
The price of tomatoes is $2.3

[1;33m*** END ***[0m

[1;33m*** TEST ITERATOR ***[0m

[1;36m### constructor ###[0m

[1;32m
map : 
a => 10
b => 20
c => 30
d => 40

[0mit : a => 10
copy_constr : a => 10

[1;36m### END ###[0m

[1;36m### arithmetic operators ###[0m

[1;32m
map : 
w => 600
x => 700
y => 800
z => 900

[0mit	=	y => 800
--it	=	x => 700
++it	=	y => 800
it--	=	x => 700
it++	=	y => 800


[1;36m### END ###[0m

[1;36m### relational operators ###[0m

it1 : a => 10
it2 : a => 10
it3 : b => 20

it2 != it3
it1 == it2

[1;36m### END ###[0m


[1;33m*** END ***[0m

[1;33m*** TEST METHODS ***[0m

[1;36m### capacity ###[0m

[1;32m
map : 

[0mm.empty()	=	1
[1;32m
map : 
a => 10
b => 20

[0mm.empty()	=	0
m.size()	=	2
m.max_size()	=	230584300921369395

[1;36m### END ###[0m

[1;36m### element_access ###[0m

m['a'] is 77
m['b'] is 88
m['c'] is 88
m['d'] is 0
m.size()	=	4

[1;36m### END ###[0m

[1;36m### modifiers ###[0m

map1: 
[1;32m
map : 
a => 100
b => 300
c => 400
z => 200

[0mmap2: 
[1;32m
map : 
a => 100
b => 300

[0merase by iterator with key = c
[1;32m
map : 
a => 100
b => 300
z => 200

[0merase z with key
[1;32m
map : 
a => 100
b => 300

[0merase range begin to end: all and clear m2
[1;32m
map : 

[0m[1;32m
map : 
e => 1
f => 2
g => 3

[0m[1;32m
map : 
x => 11
y => 22
z => 33

[0mswap m with m2
map1: 
[1;32m
map : 
x => 11
y => 22
z => 33

[0mmap2: 
[1;32m
map : 
e => 1
f => 2
g => 3

[0mclear m and m2
map1: 
[1;32m
map : 

[0mmap2: 
[1;32m
map : 

[0m
[1;36m### END ###[0m

[1;36m### observers ###[0m

test keycomp with highest char = c
a => 1
b => 2
c => 3

test value comp with pair highest : z => 3003
x => 1001
y => 2002
z => 3003

[1;36m### END ###[0m

[1;36m### observers ###[0m

find b
b => 100

count a = 1
count e = 0

it_low: b => 100
it_up: d => 200

lower bound points to: a => 50
upper bound points to: b => 100

[1;36m### END ###[0m

[1;36m### allocator ###[0m

The allocated array has a size of 40 bytes. (5 * 8)

[1;36m### END ###[0m


[1;33m*** END ***[0m

[1;32m
------------------- END -------------------[0m

