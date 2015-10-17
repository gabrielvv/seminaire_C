
typedef struct s_node {
 	    int value;
 		struct s_node * left;
 		struct s_node * right;
 	} t_node;

 	void abr_insert(t_node** root, int value);
    // Display from the example : 1 2 3 4 5 6 7 9 10
    void abr_display_asc(t_node* root);
