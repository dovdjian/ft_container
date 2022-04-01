#include <iostream>
#include <string>
#include <memory>  // unique_ptr

template <class pair_type, class key_compare>
class BST
{

private:

    struct TreeNode
    {
		//typedef
		typedef typename std::allocator<TreeNode> allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
        // member vars
		allocator_type alloc;
        pair_type data;
        pointer left;
        pointer right;

		void	destroy_children()
		{
			if (left)
			{
				alloc.destroy(left);
				alloc.deallocate(left, 1);
				left = NULL;
			}
			if (right)
			{
				alloc.destroy(right);
				alloc.deallocate(right, 1);
				right = NULL;
			}
		}
        // constructor
        TreeNode(pair_type data): data(data), left(NULL), right(NULL) {}
		~TreeNode()
		{
			//destroy_children();
		}
    };

public:

	typedef typename std::allocator<TreeNode> allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;

	// var
	pointer root;
	key_compare cmp;
	allocator_type alloc;

    // constructors
    BST(): root(NULL) {}

	// destructor
	~BST()
	{

	}
    // member functions
    void print();
	bool	compare(pair_type const & new_pair, pointer & node)
			{ return (cmp(new_pair.first, node->data.first)); }
	bool Contains(pair_type val) const
	{
    	return Contains(val, this->root);
	}

	bool Contains(pair_type val, pointer & node) const {
	    if (node == NULL){
	        return false;
	    }
		else if(val == node->data){
	        return true;
	    }
		else if(val < node->data){
	        return this->Contains(val, node->left);
	    }
		else{
	        return this-Contains(val, node->right);
	    }
	}

	void erase(pair_type val, pointer & node)
	{
   		if(node == NULL){
   		    // Case: NULL

   		    std::cout << "val not found in tree" << std::endl;

   		} else if(val == node->data){
   		    // Found value

   		    if(node->left == NULL && node->right == NULL){
   		        // Case: node is a leaf

   		        node = NULL;

   		    } else if(node->left != NULL && node->right == NULL){
   		        // Case: node has a left subtree (but not right)
   		        // Point node's parent at node's left subtree

   		        //node = std::move(node->left);
   		        node = node->left;

   		    } else if(node->left == NULL && node->right != NULL){
   		        // Case: node has a right subtree (but not left)

   		        //node = std::move(node->right);
   		        node = node->right;

   		    } else{
   		        // Case: node has left and right subtrees

   		        pointer & minNode = this->FindMin(node->right); // returns a reference to the actual pointer in the tree
   		        node->data = minNode->data;
   		        this->erase(minNode->data, minNode);
   		    }

   		} else if(val < node->data){
   		    // Case: erase val from this node's left subtree
   		    this->erase(val, node->left);
   		} else{
   		    // Case: erase val from this node's right subtree
   		    this->erase(val, node->right);
   		}
	}

	void erase(pair_type val)
	{
    	this->erase(val, this->root);
	}

	pointer create_node(pair_type const & val)
	{
		pointer ret = this->alloc.allocate(1);
		this->alloc.construct(ret, TreeNode(val));
		return (ret);
	}

	void insert(pair_type val)
	{
	    this->insert(val, this->root);
	}

	void insert(pair_type val, pointer & node) {

	    if (node == NULL){
	        // Case: node is a NULL
	        // Make a new TreeNode for it to point to
	        //node = new TreeNode(val);
			node = create_node(val);
	    }
		else {
	        if (compare(val, node)){
	            // Case: val is < node's data
	            this->insert(val, node->left);
	        }
			else
			{
	            // Case: val is > node's data
	            this->insert(val, node->right);
	        }
	    }
	}

    pointer & FindMin(pointer & node) // Helper method for erase(inpair_type val)
	{
    	if(node == NULL){
    	    throw "Min value not found";
    	} else if(node->left == NULL){
    	    return node;
    	} else{
    	    return this->FindMin(node->left);
    	}
	}
};

template <typename pointer>
void utils_print(const std::string & prefix, pointer & node, bool isLeft)
{
	if (node)
	{
		std::cout << prefix;
		std::cout << (isLeft ? "├──" : "└──" );
		// print the value of the node
		std::cout << node->data.first << std::endl;
		// enter the next tree level - left and right branch
		utils_print(prefix + (isLeft ? "│   " : "    "), node->left, true);
		utils_print(prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}

template <typename pair_type, typename key_compare>
void BST<pair_type, key_compare>::print()
{
	utils_print("", this->root, false);
}


int main(void)
{
	typedef std::pair<int, std::string>        pair_type;
	typedef std::less<int>    compare;

	BST<pair_type, compare> *first_bst = new BST<pair_type, compare>;
	BST<pair_type, compare> *second_bst, *third_bst;

	std::cout << "cree un bst avec rien" << std::endl << std::endl;
	first_bst->print();

	std::cout << std::endl << "insert 10, 0, 20"
		<< std::endl << std::endl;
	first_bst->insert(std::make_pair(10, "b"));
	first_bst->insert(std::make_pair(0, "c"));
	first_bst->insert(std::make_pair(20, "b"));
	first_bst->print();

	std::cout << std::endl << "insert 12, 15"
		<< std::endl << std::endl;
	first_bst->insert(std::make_pair(12, "b"));
	first_bst->insert(std::make_pair(15, "b"));
	first_bst->print();

	std::cout << std::endl << "erase 12"
		<< std::endl << std::endl;
	first_bst->erase(std::make_pair(12, "b"));
	//first_bst->insert(std::make_pair(15, "c"));
	//first_bst->insert(std::make_pair(25, "c"));
	//std::cout << "search f bst data = "
		//<< first_bst->search(std::less<43>) << std::endl;
	first_bst->print();
	/* second_bst = first_bst->_left_child;
	std::cout << std::endl << "second = left_child"
		<< std::endl << std::endl;
	print_bst(second_bst);

	std::cout << std::endl << "third = first->right_child"
		<< std::endl << std::endl;

	third_bst = first_bst->_right_child;
	print_bst(third_bst);

	std::cout << std::endl << "first"
		<< std::endl << std::endl;
	print_bst(first_bst); */
	delete first_bst;
}
