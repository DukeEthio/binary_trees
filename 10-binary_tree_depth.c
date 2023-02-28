#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of the node in the binary tree.
 *
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: 0 if tree is NULL, otherwise it returns the tree depth.
 *
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->parent == NULL))
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
