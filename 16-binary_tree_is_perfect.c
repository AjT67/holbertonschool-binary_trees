#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree (helper)
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_perfect_helper - checks if a non-NULL binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_helper(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	if (tree_height(tree->left) != tree_height(tree->right))
		return (0);

	return (is_perfect_helper(tree->left) && is_perfect_helper(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise (including if tree is NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_perfect_helper(tree));
}
