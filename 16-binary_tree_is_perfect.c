#include "binary_trees.h"

/**
 * depth - Calculates the depth of a binary tree.
 *
 * @t: A pointet to the root node of the tree to calculate.
 *
 * Return: The depth of the tree.
 *
 */

int depth(const binary_tree_t *t)
{
	int d = 0;

	while (t)
	{
		d++;
		t = t->left;
	}
	return (d);
}

/**
 * assister - Performs the actual check.
 *
 * @t: A pointer to the node of the tree to check.
 * @d: The depth of the tree.
 * @level: The level of the current node.
 *
 * Return: 1 if it is perfect, othrwise 0.
 *
 */

int assister(const binary_tree_t *t, int d, int level)
{
	if (t == NULL)
		return (1);
	if (t->left == NULL && t->right == NULL)
		return (d == level + 1);

	if (t->left == NULL || t->right == NULL)
		return (0);

	return (assister(t->left, d, level + 1) &&
		assister(t->right, d, level + 1));
}

/**
 * helper - Prepares the tree for the actual check with additonal
 * information.
 *
 * @t: A pointer to the root node of the tree to check.
 *
 * Return: 0 if it is not perfect, otherwise it retuns 1.
 *
 */

int helper(const binary_tree_t *t)
{
	return (assister(t, depth(t), 0));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if the tree is NULL or if it is not perfect, otherwise it
 * returns 1.
 *
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree));
}
