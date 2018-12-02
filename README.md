# ft_ls

My own implementation of the famous Unix command: ls, using the C programming language.

### Requirements
<br /> - Only work on Mac, for now.
<br /> - Need a GCC compiler

No specific versions, just update them to the latest version if you still can't build the program.

### Building the program

1. Download/Clone the source code
2. `cd` into the root directory
3. Run `make`

### Running the program

It's pretty simple, instead of calling `ls`, call `./ft_ls` from the root directory of the source code after building it.

#### Supported flags

- Long listing display: -l
- Display recursively: -R
- Display all files: -a
- Reverse sort: -r
- Sort by modification date: -t
- Display one entry per line: -1 (Set by defaul)

### Notes

- You can find the project instructions by [clicking here][1]
- The `master` branch has the original code, the `norme` branch has the normed version of it.
- No need to mention the odd spacing in files, I'm using a tab size of 4.
- It's not fast and there are a lot of memory leaks, I'll come back and fix those later.
- I know comments would have been super useful, this is kind of a big code base, but I'm trying to go fast in my school program, I'll make sure to add them later.
- There are probably better ways to implement it, but we are limited by a set of functions at my school (just to make it harder and give us a deeper understanding of what's happening in the back), please, review the [project instructions][1] before you explain how `X` or `Y` would have been a better way to do it ;)

## Sponsors

Enjoy!

[1]: https://github.com/khoab/b_ls/blob/master/b_ls.en.pdf
