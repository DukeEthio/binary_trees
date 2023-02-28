#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: Null if no common anestor was found, otherwise it returns
 * A pointer to the lowest common ancestor node.
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent1, *parent2;

	if (first == NULL || second == NULL)
		return (NULL);

	parent1 = first->parent;
	parent2 = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);

	if (parent1 == parent2)
		return (parent1);

	if (first == parent2 || !parent1 || (!parent1->parent && parent2))
		return (binary_trees_ancestor(first, parent2));
	else if (parent1 == second || !parent2 || (!parent2->parent && parent1))
		return (binary_trees_ancestor(parent1, second));
	return (binary_trees_ancestor(parent1, parent2));
}
