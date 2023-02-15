- [File Handling](#File-Handling)
- [Streams](#Streams)
- [Classes for File stream operations](#Classes-for-File-stream-operations)
- [ios](#ios:)



File handling is used to store data permanently in a computer. Using file handling we can store our data in secondary memory (Hard disk).
How to achieve the File Handling
For achieving file handling we need to follow the following steps:-
- `STEP 1` Naming a file
- `STEP 2` Opening a file
- `STEP 3` Writing data into the file
- `STEP 4` Reading data from the file
- `STEP 5` Closing a file.


## Streams

We give input to the executing program and the execution program gives back the output. The sequence of bytes given as input to the executing program and the sequence of bytes that comes as output from the executing program are called stream. In other words, streams are nothing but the flow of data in a sequence.

The input and output operation between the executing program and the devices like keyboard and monitor are known as `console I/O operation`. The input and output operation between the executing program and files are known as `disk I/O operation`.



The I/O system of C++ contains a set of classes which define the file handling methods. These include ifstream, ofstream and fstream classes. These classes are derived from fstream and from the corresponding iostream class. These classes, designed to manage the disk files, are declared in fstream and therefore we must include this file in any program that uses files.

1. ## ios:
- ios stands for input output stream.
- This class is the base class for other classes in this class hierarchy.
- This class contains the necessary facilities that are used by all the other derived classes for input and output operations.


2. ## istream:-

- istream stands for input stream.
- This class is derived from the class `ios`.
- This class handle input stream.
- The extraction `operator(>>)` is overloaded in this class to handle input streams from files to the program execution.
- This class declares input functions such as `get()`, `getline()` and `read()`



3. ## ostream:-

- ostream stands for output stream.
- This class is derived from the class `ios`.
- This class handle output stream.
- The insertion `operator(<<)` is overloaded in this class to handle output streams to files from the program execution.
- This class declares output functions such as `put()` and `write()`


4. ## streambuf:-

- This class contains a pointer which points to the buffer which is used to manage the input and output streams.


5. ## fstreambase:-

- This class provides operations common to the file streams. Serves as a base for fstream, ifstream and ofstream class. 
- This class contains `open()` and `close()` function.


6. ## ifstream:-

- This class provides input operations.
- It contains `open()` function with default input mode. 
- Inherits the functions `get()`, `getline()`, `read()`, `seekg()` and `tellg()` functions from the istream.

7. ## ofstream:-

- This class provides output operations.
- It contains `open()` function with default output mode. 
- Inherits the functions `put()`,  `write()`, `seekp()` and `tellp()` functions from the ostream.


8. ## fstream:-

- This class provides support for simultaneous input and output operations.
- Inherits all the functions from istream and ostream classes through iostream.


9. ## . filebuf:-

- Its purpose is to set the file buffers to read and write.
- We can also use file buffer member function to determine the length of the file.


In C++, files are mainly dealt by using three classes fstream, ifstream, ofstream available in fstream headerfile. 
- `ofstream:` Stream class to write on files 
- `ifstream:` Stream class to read from files 
- `fstream:` Stream class to both read and write from/to files. 


![CPP-File-Handling](https://user-images.githubusercontent.com/105644935/218910078-20b26e71-0095-4bf2-a13a-61740f2ce90b.png)

Now the first step to open the particular file for read or write operation. We can open file by 









