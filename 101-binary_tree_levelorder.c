#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: This function goes through a binary tree using
 * level-order traversal and calls the given function for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue = NULL;
    size_t front = 0, back = 0, size = 0;

    if (!tree || !func)
        return;

    queue = malloc(sizeof(*queue) * (binary_tree_size(tree) + 1));
    if (!queue)
        return;

    queue[back++] = (binary_tree_t *)tree;

    while (front < back)
    {
        binary_tree_t *node = queue[front++];

        func(node->n);

        if (node->left)
            queue[back++] = node->left;
        if (node->right)
            queue[back++] = node->right;
    }

    free(queue);
}

