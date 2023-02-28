#include "binary_trees.h"

/**
 * compute_height - Measures the height of the binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if the tree is NULL, otherwise it rturns the height of
 * the tree.
 *
 */

size_t compute_height(const binary_tree_t *tree)
{

	size_t right, left;

	if (tree == NULL)
		return (0);
	left = compute_height(tree->left);
	right = compute_height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: 0 if tree is NULL, otherwise it retursn the measured balance factor.
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (compute_height(tree->left) - compute_height(tree->right));
}
