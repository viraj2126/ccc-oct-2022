class Node:
    def _init_(self, info):
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def _str_(self):
        return str(self.info) 

def preOrder(root):
    if root == None:
        return
    print (root.info, end=" ")
    preOrder(root.left)
    preOrder(root.right)
    
class BinarySearchTree:
    def _init_(self): 
        self.root = None
#Node is defined as
#self.left (the left child of the node)
#self.right (the right child of the node)
#self.info (the value of the node)

    def insert(self, val):  # insert to tree
        #Enter you code here.
        if self.root is None:
            self.root = Node(val)
             
        else:
            self.insert_node(self.root, val)
        return self.root
            
    def insert_node(self, node, val):  # recursive insert node
            if val < node.info:
                if node.left is None:
                    node.left = Node(val)
                    return
                else:
                    self.insert_node(node.left, val)
            else:
                if node.right is None:
                    node.right = Node(val)
                    return
                else:
                    self.insert_node(node.right, val)
tree = BinarySearchTree()
t = int(input())

arr = list(map(int, input().split()))

for i in range(t):
    tree.insert(arr[i])

preOrder(tree.root)
