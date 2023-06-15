Data structures

DS is a way to organize data so that it can be done used effecictveliy

abstract dat type vs data structures

ADT provides only the interface to which the dat astructure must adhere.
It does not provide any specific detail how something should be implemneted or in which language

Example:
ADT is for a mode of transportation

specific modes of transportation is anlogous to DS itself.

![Screenshot from 2022-12-17 15-16-25](https://i.imgur.com/pLwy2BY.png)

Computational complexity 

time  , Space for algorithm

Big-O notation
It tells about the worst case.
Upper boun of the complexity in the worst case,helping in quantifying as input sizre becomes arbotarilly large.

![Screenshot from 2022-12-17 15-41-08](https://i.imgur.com/U8Ewz2P.png)![Uploading Screenshot from 2022-12-17 15-55-57.png… (n3w66o74g)]()![Screenshot from 2022-12-17 15-55-57](/assets/Screenshot%20from%202022-12-17%2015-55-57.png)

Arrays 

Ststic array is a fixed length container containing n elements indexable from the range [0,n-1]
 
used - 
    - temporily stroing object
    - by IO routines as buffers - reading small chunks of file which are very big and not reable at onces
    - string and accesing sequnciatila data
    - look up table and its inverse
    -  return multiple values from a function
    - Dynamic programming  to cache answers to subproblmes
    ![Uploading Screenshot from 2022-12-17 16-04-49.png… (psrceeyuq)]()

    DA
Dynamic array can grow and shrink in size     

while adding in dynamic array -initailly we use a static array and there is no space availble for the addionla elment.It will double the size of the array and then add the element into it.

pointer as functional argument 

in the below case the value of ht efunction is not incremented ![Screenshot from 2022-12-19 01-39-42](https://i.imgur.com/gGKUfEi.png)
 while the stack frmae is later created and returns to the main stack frame hence the increment is not done 

 and then the ans is prined otu as ![Screenshot from 2022-12-19 01-41-35](https://i.imgur.com/2wbx9n3.png)
this is because we tried to calling by value since both the variables are different 

TO overcome this problem we use pointer  as ![Screenshot from 2022-12-19 01-44-04](https://i.imgur.com/TtALUST.png)

In this the we create a pointer of that variavle adn then increment the value of this pointer .
Thus changin the value of the variable.

whenever array is called as a functional argument iit just stores its memory address thus the size of array in funtional argument becomes 4 byte while in the main  argument it has its original size.
