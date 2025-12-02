# 105. Construct Binary Tree from Preorder and Inorder Traversal

# doing this in python as passing sliced lists in a function is complex in cpp

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def display(root):
    if not root:
        return
    display(root.left)
    print(root.val, end=" ")
    display(root.right)

def buildTree(preorder: list[int], inorder: list[int]) -> TreeNode: # TC: O(n ^ 2), SC: O(n) -> call stack
    if not preorder or not inorder:
        return None

    root = TreeNode(preorder[0])
    mid = inorder.index(preorder[0])

    root.left = buildTree(preorder[1: mid + 1], inorder[:mid])
    root.right = buildTree(preorder[mid + 1:], inorder[mid + 1:])
    return root

def buildTree_map(preorder: list[int], inorder: list[int]) -> TreeNode: # TC: O(n), SC: O(n)
    index_map = {val: i for i, val in enumerate(inorder)}
    pre_index = 0

    def helper(in_left: int, in_right: int) -> TreeNode:
        nonlocal pre_index
        if in_left > in_right:
            return None

        root_val = preorder[pre_index]
        pre_index += 1
        root = TreeNode(root_val)

        mid = index_map[root_val]

        root.left = helper(in_left, mid - 1)
        root.right = helper(mid + 1, in_right)
        return root

    return helper(0, len(inorder) - 1)

if __name__ == "__main__":
    preorder = [3, 9, 20, 15, 7]
    inorder = [9, 3, 15, 20, 7]

    root = buildTree_map(preorder, inorder)
    print('Inorder Traversal: ', end="")
    display(root)

"""
Time Complexity: O(n)
Space Complexity: O(n)
"""