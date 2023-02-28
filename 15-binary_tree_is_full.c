#include "binary_trees.h"

int helper(const binary_tree_t *t);

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 0 if tree is NULL or if it is not full, otherwise it
 * returns 1.
 *
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree));
}

/**
 * helper - Performs the actual check.
 *
 * @t: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL or if it is not full, otherwise it returns 1.
 *
 */

int helper(const binary_tree_t *t)
{
	if (t == NULL)
		return (1);
	if ((t->left != NULL && t->right == NULL) ||
			(t->left == NULL && t->right != NULL) ||
			helper(t->left) == 0 || helper(t->right) == 0)
		return (0);
	return (1);
}
