# Double-List
Introduction
Multiple data structures are often interlinked or merged to perform complicated tasks. In this assignment, you
will implement such a joint data structure that we call the double list. A double list represents two distinct lists
over the same group of elements. For simplicity, we refer to the first list as the red list and the second list as the
blue list. To be more precise, at any time, you can view a double list D as a pair of ordered sequences:
D = (⟨r1, r2, . . . , rn⟩,⟨b1, b2, . . . , bn⟩)
where the sequences ⟨ri⟩ and ⟨bi⟩ are permutations of each other.
Notice that since the red and the blue lists are defined on the same collection of elements, they are not independent. One cannot update the red list without updating the blue list and vice versa. If an element is removed
from the red list, it should also be removed from the blue list. If an element is inserted into the red list, then it
should also be inserted into the blue list. The position of insertion, however, may differ for each list.
In this assignment, we ask you to complete the implementation of a double list that consists of two non-circular
singly linked lists. Since the values stored in both linked lists are identical, the double list uses a single set of
nodes to represent both lists at the same time. (That is, the double list does not create two nodes for each
element.) To be able to represent two lists with a single copy of nodes, the double list nodes have two separate
next pointers, one for the red list and one for the blue list. Similarly, the main structure maintains two head
pointers, one for each list.
The code below declares the class template for the double list. Note that some member functions are missing;
they will be introduced in the next section.

Task
You are expected to implement the following additional member functions for the DoubleList class.
• DoubleList ( T *a , unsigned n )
Constructs a double list from the given array a of size n. In this construction, both lists are constructed as
identical and contain the elements of a in order.
• DoubleList ( const DoubleList & dl )
Constructs a double list that is a copy of dl. This copy should be a “clone”, that is, it should become
independent from dl once the construction is complete. Note: This is probably the most difficult piece
and we suggest you attempt this the last.
• Node * get ( unsigned index , Color color ) const
Returns the node at the 0-based index in the list whose color is color. If index is larger than or equal to
the size of the list, an InvalidIndexException is thrown.
• Node * insert ( T value , unsigned redIndex , unsigned blueIndex )
Inserts a new value into the double list. The (new) 0-based positions of the value in the individual lists are
given by the redIndex and blueIndex parameters. If either index is larger than the size of the original list,
an InvalidIndexException is thrown. Notice that an index equal to 0 adds the value to the beginning
of the corresponding list. An index equal to the size of the original list adds the value to the end of the
corresponding list. A pointer to the node for the newly inserted element is returned.
• void remove ( unsigned index , Color color )
Removes a node from the double list. The node to remove is identified by its 0-based index in the list
whose color is color. Again, if the index is invalid, an InvalidIndexException is thrown.
• void append ( DoubleList & dl )
Appends dl onto this double list and empties dl. The appending is performed by appending the red and
the blue lists individually.
• ~ DoubleList ()
Destroys this double list instance. All memory associated with the double list should be freed.
Please pay attention to the following:
• Note that we will give a fixed declaration for the DoubleList class. This implies that you cannot add
additional members to class. We expect you to stick to the declared member fields and use them as
described in this document. We may check if the member fields are correctly populated as we defined
them.
• Notice that the list definitions we provide do not have any sentinels. An empty red/blue list is simply a
nullptr. The last element of either list has its corresponding next pointer as nullptr.
• Your code should not create a memory leak. If we detect a memory leak in your implementation, you may
lose a portion of the points.
• The Node pointers returned by the insert() and get() functions should be persistent. That is, the pointer
should remain valid and point to the same element until the element is removed or the corresponding list
is destroyed. The persistence should live through an append operation as well.
• You can assume that the users of your class does not attempt to modify the Nodes and/or delete them
without the involvement of your functions. The users also guarantee not to read a Node that has been
removed
