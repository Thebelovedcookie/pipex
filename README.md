# pipex

In this project you have to recreat the " | " operation. 

Simple enough right ? no.

I learned so much on this projects, about files descriptors, pipe, shell, fork, process, exit code. 

I started this project like I'll always do in the future. I rewrited the man of the authorized function. This way i'm learning what every function is supposed to do and i've got an idea of when i am supposed to use them. 

The first function I learned was the pipe() one.

![apercu](https://github.com/Thebelovedcookie/pipex/blob/main/screenshot/pipe.png)

At first, i thought the hardest part was to understood the fork function, you know, with the creation of a new process called "son", because I had a MAJOR leaks of process, and my pc was about to explode. 

The fork function is actually pretty simple. 

![apercu](https://github.com/Thebelovedcookie/pipex/blob/main/screenshot/pipex1.png)

In this case you will, at some point, need to kill your son after he complete his tasks. (With execve).

If don't kill your son you will have a zombie process or even worst, a leak of process.



The thing that you have to know about this function, is that the function is creating a new process and copy everything that was in the first.

![apercu](https://github.com/Thebelovedcookie/pipex/blob/main/screenshot/pipex2.png)

So if you allocated some memory or open an FD, you will have to free this memory or close this fd before you kill your son.

Then after I had to use dup2() function...

So this nice function is fooling the pc you are on making him believe that his (let's say) fd 1 (stdout) is the fd of 

But then i found that a leak of fds, wich i didnt understood fastly, all my fd where close at the good timing 

![apercu](https://github.com/Thebelovedcookie/pipex/blob/main/screenshot/use.png)