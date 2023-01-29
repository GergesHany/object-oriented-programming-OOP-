## Encapsulation

Encapsulation in C++ is defined as the wrapping up of data and information in a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.

Consider a real-life example of encapsulation, in a company, there are different sections like the accounts section, finance section, sales section, etc. Now,

- The finance section handles all the financial transactions and keeps records of all the data related to finance.
- Similarly, the sales section handles all the sales-related activities and keeps records of all the sales.

Now there may arise a situation when for some reason an official from the finance section needs all the data about sales in a particular month.

In this case, he is not allowed to directly access the data of the sales section. He will first have to contact some other officer in the sales section and then request him to give the particular data.

This is what `Encapsulation` is. Here the data of the sales section and the employees that can manipulate them are wrapped under a single name `sales section`. 

<br>

### Features of Encapsulation
1. We can not access any function from the class directly. We need an object to access that function that is using the member variables of that class.
1. The function which we are making inside the class must use only member variables, only then it is called encapsulation.
1. If we don’t make a function inside the class which is using the member variable of the class then we don’t call it encapsulation.
1. Increase in the security of data
1. It helps to control the modification of our data members.

![encapsulation-image](https://user-images.githubusercontent.com/105644935/215284659-5203cf23-347f-4e95-8ad8-d8141df3a490.jpg)


Encapsulation also leads to `data abstraction`. Using encapsulation also hides the data, as in the above example, the data of the sections like sales, finance, or accounts are hidden from any other section.








