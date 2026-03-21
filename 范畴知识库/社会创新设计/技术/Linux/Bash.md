# Bash

bash 命令的函数，其退出只能返回数字。如果要返回内容的话，是通过 `echo return` 的方式将内容返回的。



[Bash array](https://stackoverflow.com/questions/10586153/how-to-split-a-string-into-an-array-in-bash)

[linux doc for array](https://www.gnu.org/software/bash/manual/html_node/Arrays.html)

```sh
for element in "${array[@]}"
do
    echo "$element"
done
```



[string processing](https://stackoverflow.com/questions/19482123/extract-part-of-a-string-using-bash-cut-split)

```sh
${MYVAR#pattern}     # delete shortest match of pattern from the beginning
${MYVAR##pattern}    # delete longest match of pattern from the beginning
${MYVAR%pattern}     # delete shortest match of pattern from the end
${MYVAR%%pattern}    # delete longest match of pattern from the end

# Source - https://stackoverflow.com/a/19482947
# Posted by beroe, modified by community. See post 'Timeline' for change history
# Retrieved 2025-11-08, License - CC BY-SA 4.0

${MYVAR:3}   # Remove the first three chars (leaving 4..end)
${MYVAR::3}  # Return the first three characters
${MYVAR:3:5} # The next five characters after removing the first 3 (chars 4-9)
```

```sh
#!/bin/bash

# Define a string variable
my_string="Hello, Bash!"

# Get the length of the string
string_length=${#my_string}

# Print the length
echo "The length of the string is: $string_length"
```

