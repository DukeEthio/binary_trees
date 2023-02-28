#include "binary_trees.h"
#include <limits.h>

/**
 * helper - Performs the actual check.
 *
 * @t: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visite thus far.
 *
 * Return: 1 if it is BST, otherwise 0.
 *
 */

int helper(const binary_tree_t *t, int low, int high)
{
	if (t != NULL)
	{
		if (t->n < low || t->n > high)
			return (0);
		return (helper(t->left, low, t->n - 1) &&
			helper(t->right, t->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if it is invalid or if the tree is NULL, other wise it returns 1.
 *
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
