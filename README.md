# pyfreopen
A very basic Python module to redirect stderr and stdout to a file

`pyfreopen` is a very **_basic_** and **_limited_** C module for Python which 
uses the C function 'freopen' to redirect _stdout_ and _stderr_ to a file.

## Usage
Right now there is no real installation procedure, but you can compile it by
launching this command:

    gcc -I /usr/include/python2.7/ -shared freopen.c -o freopen.so

There are just two methods, that work the same way:

    freopen.set_stdout(path="stderr.log", append=False)
    freopen.set_stderr(path="stdout.log", append=False)

with `append=True` the output will be appended to the file, if not its contents
will be overwritten; if the file does not exists, it will be created.  
Once the output file is set, **there is no way to restore the stderr/stdout to 
the previous output state**. You can just change the output file and mode.


Keep in mind that, again, this is a very **_basic_** and **_limited_** module,
don't blame me if anything goes wrong and your computer goes crazy...  
I needed this feature and, since I wasn't able to find something similar 
anywhere, I thought it was good to release it. I'm not a programmer, neither I
know a thing about C, this is just "working", and that's good for me.

## Known "issues"
As mentioned before, there is no way to restore the stderr/stdout to the 
previous output state.
The module just launches a freopen function with the given parameters, there
is no thread/process/file control.  
Also, if you use it in a simple script, keep in mind that it will **NOT**
write anything until the script has exited, even if it uses threading.
After, and only after, the main process is finished and exited, the file will
be actually written.

Anyway, if you use modules that autonomously write to stdout/err, their output
will be written immediately, appended to the output you might have been
written using something like `sys.stdout.write('whatever')`.  
That's actually the reason I wrote this module: I had external modules that
keeped writing to stderr, leaving me uncapable of capture it in any (known to 
me) way.
