class Node():
    def __init__(self,value):
        self.value=value
        self.next=None
class LinkedList():
    #constructer
    
    def __init__(self,value):
        new_node=Node(value)
        self.head=new_node
        self.tail=new_node
        self.length=1
    #method for printing the linkedlist
    def print_list(self):
        temp=self.head
        while temp is not None:
            print(temp.value)
            temp=temp.next
    #method for appending the list
    def append(self,value):
        new_node=Node(value)
        if self.head is None:   #what if new_node.head?
            self.head=new_node
            self.tail=new_node
        else:
            self.tail.next=new_node
            self.tail=new_node
        self.length+=1
    #removing end of element from the list
    def pop(self):
        if self.length==0:
            return None
        temp=self.head
        pre=self.head  
        while(temp.next):  #traversing the list and keeping track of prev for assigning tail before pop operation
            pre=temp
            temp=temp.next
        self.tail=pre
        self.tail.next=None
        self.length -=1
        if self.length==0:                          #this case is after poping single element the head and tail still referenced to the element
            self.head=None
            self.tail=None
        return temp                               #returning poped value
    
    #method for prependding the element
    def prepend(self,value):
        new_node=Node(value)
        if self.length==0:
            self.head=new_node
            self.tail=new_node
        else:
            new_node.next=self.head
            self.head=new_node
    def pop_first(self):
        temp=self.head
        self.head=temp.next
        temp.next=None
        self.length -=1
        if self.length==0:                          #after decrementing if the ll becomes empty
            self.tail=None
        return temp

    def get(self,index):                            #getting element by index_value
        if index<0 or index>=self.length:
            return None
        #main casey
        temp=self.head 
        for _ in range(index):
         temp=temp.next
        return temp

    #method for changing/set_value
    def set_value(self,index,value):
        temp=self.get(index)                        #return the position of the element based on index_value using method inside method for instance
        if temp:
            temp.value=value
            return True
        return False


    #inserting the element in the middle of the linked list
    def insert(self,index,value):
        #condition for checking valid index number
        if index<0 or index>self.length:
            return False
        # calling exixsting method if index=0
        if index==0:
            return self.prepend(value)
        #calling exisisting method if index=length
        if index==self.length:
            return self.append(value)
        new_node=Node(value)
        temp=self.get(index-1)
        if temp:
            new_node.next=temp.next
            temp.next=new_node
            self.length +=1
        return True
    

    def remove(self,index):
        #conditions for first and last
        if index<0 or index>self.length:
            return None
        if index==0:
            return self.pop_first()
        if index==self.length:
            return self.pop()

        pre=self.get(index-1)
        temp=pre.next
        pre.next=temp.next
        temp.next=None
        self.length -=1
        return temp

        
    def reverse(self):
        #swaping head and tail
        temp=self.head
        self.head=self.tail
        self.tail=temp
    #assignig three variables for the reverse operation
        before=None
        #temp=self.head  //it is wrong to assign the temp to head bcz it points to tail ref to old ll for now temp is very last element in the ll
        # meaning saying same as temp=self.tail
        after=temp.next
        for _ in range(self.length):
            after=temp.next
            temp.next=before
            before=temp
            temp=after
            







#test cases
my_list=LinkedList(5)
my_list.append(4)
my_list.insert(2,3)
my_list.append(2)
my_list.print_list()

print('reverse_list:')
my_list.reverse()
my_list.print_list()
