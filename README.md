# Commands
1. create
2. compile  

**Config**  
1. Compile your C++ code into machine code.  
2. Confgigure command in your bash config file.  
`alias [your custom command name]=[path to your compiled machine code]`  

**For example**  
In your `.zshrc` file, write this:  
`alias create=~/create`

## create
create command generates cpp boiler plate with created date and time.  
  
  
**Usage**  

`> create [filename]`
  
**For example**  

When you write `> create foo` command in your terminal, it generates `foo.cpp` 
file and write boiler plate into your file.
  
## compile
This command compiles cpp file into machine code easily.  

**Usage**  

`> compile [filename] [optional]`  
  
**For example**

When you write `> compile foo[.cpp]` command in your terminal, it compiles your 
`foo.cpp` file into `foo` machine code. In addition, file extension is optional.  
  
Also, you can pass `-e` flag optionally to execute machine code immediately.
