--- res/ft.res	2022-04-24 01:52:50.043693500 +0200
+++ res/std.res	2022-04-24 01:52:50.043693500 +0200
@@ -15,32 +15,13 @@
 
 [1;36m### modifiers ###[0m
 
-new_pair	=	a
-node_arg->_data.first	=	a
-y->_data.first after insert	=	a
-new_pair	=	z
-node_arg->_data.first	=	z
-y->_data.first after insert	=	a
-new_pair	=	b
-node_arg->_data.first	=	b
-y->_data.first after insert	=	z
-new_pair	=	c
-node_arg->_data.first	=	c
-y->_data.first after insert	=	b
 map1: 
 [1;32m
 map : 
 a => 100
-tree incr
-end of tree incr
 b => 300
-tree incr
-end of tree incr
 c => 400
-tree incr
-new_parent->_data.first	=	b
-node->_data.first	=	c
-end of tree incr
+z => 200
 
 [0m
 [1;36m### END ###[0m
