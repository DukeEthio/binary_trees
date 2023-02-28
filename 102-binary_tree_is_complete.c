#include "binary_trees.h"

/**
 * countNodes - Counts the number of nodes in the binary tree.
 *
 * @root: A pointer to the root node in the tree.
 *
 * Return: The number of nodes in the tree.
 *
 */

int countNodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/**
 * helper - Performs the actual check.
 *
 * @t: A pointer to the root node of the tree to check.
 * @nodes: The number of nodes in the tree.
 * @index: current index.
 *
 * Return: 1 if it is complete, otherwise 0.
 *
 */

int helper(const binary_tree_t *t, int nodes, int index)
{
	if (t == NULL)
		return (1);
	if (index >= nodes)
		return (0);
	return (helper(t->left, nodes, 2 * index + 1) &&
			helper(t->right, nodes, 2 * index + 2));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL or if it is not perfect, otherwise it
 * returns 1.
 *
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree, countNodes(tree), 0));
}
