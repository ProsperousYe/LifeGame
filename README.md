# LifeGame  
## History commit record:  
![image](https://user-images.githubusercontent.com/93996508/169669951-e499e847-7a1e-4097-8e97-ad62c80c0271.png)  

## Instruction  
1. Compile  
`  
$ make //compile the program  
`  
2. Test  
The test suite is in the *test* repository  
The code is in the *test* repository  
The test cases are in the *test/test* repository  
Run the command below to test the basic functions:  
`  
$ ./test  
`  
If there is any error, the test program will abort and show the relative messages  
And if the test can exit normally, that means all the tests passed  
3. Running  
There are two running method:  
`  
$ ./GameofLife 4 game.txt history.txt  //The game will using the initial map stored in the ./data/game.txt and record the history in the ./data/history. The game will run 4 steps  
$ ./GameofLife 4 game.txt history.txt -i //The game will running in custom mode, the initial map will be decided by cilcking and user can change the cells on each step and the total step number is free custom    
`  
