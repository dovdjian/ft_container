[0;35m--------------- TEST VECTOR ---------------[0m

[0;35m------------------- END -------------------[0m

[1;34m
--------------- TEST STACK ----------------[0m

[1;34m
------------------- END -------------------[0m

[1;32m
---------------- TEST MAP -----------------[0m

[1;33m*** TEST METHODS ***[0m

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

[0myo je suis dans erase
this->_root->_data.first	=	a
root pas nul
root pas nul
root pas nul
curr->_data.first	=	c
no child
before size-- and stuff
after size-- and stuff
erase by iterator with key = c
[1;32m
map : 
a => 100
b => 300
z => 200

[0myo je suis dans erase
this->_root->_data.first	=	a
root pas nul
curr->_data.first	=	z
one child
new curr->_data.first	=	b
curr->_data.first	=	z
prev->_right_child->_data.first	=	z
