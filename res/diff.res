--- res/ft.res	2022-04-27 15:12:59.630000000 +0200
+++ res/std.res	2022-04-27 15:12:59.630000000 +0200
@@ -367,55 +367,20 @@
 a => 100
 b => 300
 
-[0myo je suis dans erase
-node arg first	=	c
-curr->_data.first	=	a
-curr->_data.first	=	z
-curr->_data.first	=	b
-prev->_data.first	=	b
-curr.first	=	c
-no child
-before size-- and stuff
-after size-- and stuff
-erase by iterator with key = c
+[0merase by iterator with key = c
 [1;32m
 map : 
 a => 100
 b => 300
 z => 200
 
-[0myo je suis dans erase
-node arg first	=	z
-curr->_data.first	=	a
-prev->_data.first	=	a
-curr.first	=	z
-one child
-end of one child[0m
-before size-- and stuff
-after size-- and stuff
-erase z with key
+[0merase z with key
 [1;32m
 map : 
 a => 100
 b => 300
 
-[0myo je suis dans erase
-node arg first	=	a
-prev->_data.first	=	 
-curr.first	=	a
-one child
-end of one child[0m
-before size-- and stuff
-after size-- and stuff
-yo je suis dans erase
-node arg first	=	b
-prev->_data.first	=	 
-curr.first	=	b
-no child
-egrgeregr
-before size-- and stuff
-after size-- and stuff
-erase range begin to end: all and clear m2
+[0merase range begin to end: all and clear m2
 [1;32m
 map : 
 
