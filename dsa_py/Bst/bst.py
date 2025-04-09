class Node():
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None
        
class BStree():
    def __init__(self):
        self.root=None

    def Insert(self,value):
        new_node=Node(value)
        if self.root is None:
            self.root=new_node
            return
        temp=self.root

        while(True):
            if new_node.value>temp.value:
                if temp.right is None:
                    temp.right=new_node
                    return
                temp=temp.right
            else:
                    if temp.left is None:
                        temp.left=new_node
                        return
                    temp=temp.left
my_tree=BStree()
my_tree.Insert(4)
my_tree.Insert(5)
my_tree.Insert(3)

print(my_tree.root.value)
print(my_tree.root.right.value)
print(my_tree.root.left.value)
