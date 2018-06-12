Project for my Data Structures course. It's an implementation of the Huffman's coding algorithm for lossless data compression. The idea 
is to assign variable-lenght codes to input characters. We get the lenghts of the assigned codes from frequencies of corresponding 
characters. In other words, the most frequent character gets the smallest code and the least frequent character gets the largest code.
The two most important parts in building the algorithm are firstly to build a Huffman Tree from input characters, and secondly to traverse 
the Huffman Tree and assign codes to characters. 

For my implementation of Huffman coding algorithm I firstly use a class named FrequencyTable which helps me make the Huffman Tree.
FrequencyTable makes a table from a string which table gives us information for the frequencies of every character in the string.
When the table is created, it also has to be sorted and after that we can continue with the HuffmanTree.

Huffman's Tree is a binary tree. Every node of the tree has the following characteristics: a char for the recent character ana an integer 
for the number of its frequncies. There is also to pointers for the left child and the right child.

The creation of the Tree from the FrequenciesTable happens in function HuffmanTree makeTree(FrequencyTable t); and follows the steps:
1. Create a leaf node for each unique character and build a queue of all leaf nodes. I use an already sorted FrequencyTable, so I can use
   a normal queue.
2. Extract two nodes with the minimum frequency from the queue. I know that they are the first two elements in the queue.
3. Create a new internal node with frequency equal to the sum of the two nodes frequencies. 
   Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the queue. 
   Here I use a helping function to position the new element at the right place of the queue.
4. Repeat steps#2 and #3 until the queue contains only one node. The remaining node is the root node and the tree is complete.


And at the end I had to make a Table such as the frequency table, but this time with the codes of the characters and the characters.

Since my homework was only for demonstration, I am showing how the compressed file should look like and afer the compression I am 
decompressing it to see the original text again.