def main():
    N = int(input())
    nodes = {}
    for i in range(N - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)
        if direction == "R":
            populateMapForRightNode(parent, child, nodes)
        else:
            populateMapForLeftNode(parent, child, nodes)
    root = nodes[1]
    nodes = {}
    for i in range(N - 1):
        parent, child, direction = input().split()
        parent = int(parent)
        child = int(child)
        if direction == "R":
            populateMapForRightNode(parent, child, nodes)
        else:
            populateMapForLeftNode(parent, child, nodes)
    root1 = nodes[1]
    is_mirror_binary_trees = is_mirror_tree(root, root1)
    if is_mirror_binary_trees:
        print("yes")
    else:
        print("no")
def is_mirror_tree(tree, mirror_tree):
    if tree is None and mirror_tree is None:
        return True
    if tree is None or mirror_tree is None:
        return False
    if tree.item != mirror_tree.item:
        return False
    if not is_mirror_tree(tree.left, mirror_tree.right):
        return False
    if not is_mirror_tree(tree.right, mirror_tree.left):
        return False
    return True
def populateMapForRightNode(parent, child, nodes):
    if nodes.get(parent) is None:
        node = Node(parent)
        node.right = Node(child)
        nodes[parent] = node
        nodes[child] = node.right
    else:
        node = nodes.get(parent)
        node.right = Node(child)
        nodes[child] = node.right
def populateMapForLeftNode(parent, child, nodes):
    if nodes.get(parent) is None:
        node = Node(parent)
        node.left = Node(child)
        nodes[parent] = node
        nodes[child] = node.left
    else:
        node = nodes.get(parent)
        node.left = Node(child)
        nodes[child] = node.left
class Node:
    def __init__(self, item):
        self.item = item
        self.left = None
        self.right = None
main()
