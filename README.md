# c_ref
<h3>linkedlist01.c</h3>
<p>Challenge was to buid a linked list of stock prices. Then save them to a file. After that read the file and rebuild the linked list. Only challenge of course
was each element in the list had a new spot in memory so we have to simply read all the fields in the struct and then reset the pointer to the next element
using malloc.</p>

<p>To prove the linked list was created successfully line 49 then resets the list back to the first element and we loop through it again using current->next</p>
<h3>arraychallenge.c</h3>
<p>This challenge was to simply build an array using pointer notation and display it using the same. In C arrays are stored contiguously so 
  the statement char alphabet[26]; is simply a refence to the first block of memory. The statement char *pa = alphabet; sets the pointer pa to the same spot
  allowing us to access our 26 char array using pointer notation. Understaing this is the essence of the challenge.</p>
  <p>In the loop the statement pa++ moves the pointer up one space in memory since this is an array of chars it is a single byte.</p>

<h3>functionpointerarray.c</h3>
Array list of pointers to functions. 
