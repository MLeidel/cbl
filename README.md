# cbl
__Console Based note &amp; snip-it Lookup &amp; retrieval__

Uses text files to organize text information by File and Topic.

Binary executable for Linux and Windows.

Run setup.cmd (setup.sh) to create cbl folder where subject  
files can be stored, updated, and deleted.

Setup also copies executable to system directory (admin required)

_tkinter.txt_ is provided for an example of a 'cbl' text file.  
Notice the ^_^ syntax to delimate each topic/title.

## Usage

display all cbl text files:  
> `cbl`

display all topics in paricular text file:  
> `cbl tkinter`

display topic info from particular text file:  
> `cbl tkinter spinbutton`

search all topics in particular text file for some text:  
> `cbl tkinter search "<Control-a"`  
Note: s sea search all the same

edit the cbl text file:  
> `cbl tkinter e`  
launches your text editor with the cbl text file  

The 'cbl' files directory is located at:  
`/home/USER/.config/cbl` for Linux  
and  
`HOME\cbl` for Windows

