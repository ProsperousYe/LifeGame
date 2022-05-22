# LifeGame  
URL: https://github.com/ProsperousYe/LifeGame  

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
`  
(1) Run the program and the window will be created:  
![image](https://user-images.githubusercontent.com/93996508/169670894-0b113926-1082-4c13-8d2f-2b8450614d4a.png)  
(2) Then the map of each step will be shown automatically:  
![image](https://user-images.githubusercontent.com/93996508/169670839-bf8f491b-66f7-4d9d-b7f0-d74a4cb44e73.png)  
After 2 seconds:  
![image](https://user-images.githubusercontent.com/93996508/169670843-1c3b36ec-fc3a-4740-af60-e4d9a42e20e5.png)  
(3) Cilck the corss to exit  
![image](https://user-images.githubusercontent.com/93996508/169670643-9d7781f7-1898-43a6-b293-e61e0d7facc6.png)  

`  
$ ./GameofLife 4 game.txt history.txt -i //The game will running in custom mode, the initial map will be decided by cilcking and user can change the cells on each step and the total step number is free custom    
`  
(1) Run the program and input the height and length of map:  
![image](https://user-images.githubusercontent.com/93996508/169670547-76db99fd-a870-488d-8384-f3d2e1c667bd.png)  
(2) Then click the map on the window below:  
![image](https://user-images.githubusercontent.com/93996508/169670570-9350bc11-1f3b-4213-8afa-c7ef5340ad45.png)  
(3) Like this:  
![image](https://user-images.githubusercontent.com/93996508/169670578-346302a1-4d2f-48d8-96c4-d660029df0cc.png)  
(4) Then press any key to continue...  
![image](https://user-images.githubusercontent.com/93996508/169670584-037df816-3111-4ba0-b459-117be47e3257.png)  
(5) Cilck the corss to exit.  
![image](https://user-images.githubusercontent.com/93996508/169670643-9d7781f7-1898-43a6-b293-e61e0d7facc6.png)  


