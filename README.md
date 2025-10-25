# Drone-Application
this repository contains the all the details required for the drone making from failed protypes to successful runs.<br>
**Title and Team Information**:<br>
Title: Delivery Drone Simulator<br>
<br>**Team Members**:<br>
Manal Faisal: Programmer/Team Leader 1<br>
Fatima Faizan: Programmer 2<br>
Minahil Tahir: Logic designer/Git manager/Tester<br>
<br>**Overview/Programme Description**:<br>
This programme backs up the idea for the future where <ins>human delivered parcels</ins> will be <ins>replaced</ins> by machines.
It gives us a direction of how drone delivery service's code might look like and how the code will handle the obstacles that a drone will face during the delivery of the package.We are trying to keep it as user-friendly as possible as it is just a prototype for a real-life drone delivery service.Not only that but we have also included a unique <ins>Coupon System</ins> in our code that will provide the user a discount on his/her next order if the delivery was not satisfactory.The coupon will always be randomly generated.This feature was added to form a bond of trust and empathy with our users.<br>
<br>**Programme/Logic Design**:<br>
Functions Implemented:<br>
1. Muliple if statements used for conditions for example weather conditions,time,battery life etc.<br>
2. bool weather(),bool day() and bool time() has been used.<br>
   -Bool weather(): 3 random weathers are initiated in it like sunny.windy.rainy using modulus.<br>
   -Bool day(): declare time= current_time().It will catch the exact time of the device used.Very useful as time is never the     same twice.<br>
3. Later in the next line of code,bool weight() has been used where user is prompted to write the weight of his/her order which is accompanied by a number of if statements.If weight is more than 30kg limit,Delivery will be cancelled.<br>
4. Bool delivery() used to check each and every one of above conditions to make sure conditions are optimal.<br>
5. bool power() and bool charging() are used to make sure battery is enough for the delivery.If not,drone will return to base for recharging while cancelling the delivery entirely.<br>
6. Bool destination() is present in next line where code of the drone will check the total distance.According to the distance,total price will rise and battery of drone will fall respectively.<br>
7. string coupon() used in case if the delivery was unsatisfactory,user will be awaredec with a randomly generated coupon to use in next order.<br>
   > **Note**:<br>
   >Keep in mind that the loop of deliveries will run until the battery of drone becomes zero and it returns to the base.In the end of the deliveries,it will display a short summary of all deliveries whether successful or failed.The recent coupon will be accepted even if you were given more than 1 coupon due to more than 1 failed delivery.<br>






<br>**Execution Instructions**:<br>
The code has been designed and tested on **Visual Studio/Visual Studio Code** compiler.<br>
>The code might fail to run on online compilers due the complexity between these two compilers.One compiler might be able to debug something successfully while the other compiler fails to do so.<br>

Moreover,code has been pushed on this repository using **Gitbash**.<br>
<br>**Team Collaboration**:<br>
<br>Manal Faisal: 
             Plays a vital role of <ins>forming the base<ins> of the drone's code.Also <ins>leads this team</ins> skillfully by guiding each member with great detail.Has commited the base of the code<br>
<br>Fatima Faizan: <ins>refining and correcting the final code</ins>.This team member is essential for rechecking the code and adding additional features to it in order to keep it updated.Has commited refined code below:<br>
<br>Minahil Tahir: Responsible for maintaining a structured README.md file on <ins>github</ins> including other git files.Moreover,this team member handles <ins>formation of flowchart</ins> of functions for this particular assignment along with <ins>testing</ins> possible outcomes of the code formed by the team.Has commited flowchart document on this repository.<br>


<br>**Ai Tool Reflection**:<br>
Ai used: ChatGPT<br>
Reason: ChatGPT has been used by my team to double-check the code and to confirm if it does not contain any errors or not.
>ChatGPT has not been used to correct the errors, just used for <ins>pin-pointing the errors</ins>.<br>
>W3 school was used to solve error for current_time fucntion by using #define _CRT_SECURE_NO_WARNINGS<br>



No Ai was used for documentation.<br>
No Ai was used for brain-storming ideas for the drone simulator assignment.<br>


<br>**Future Improvements**:<br>
Things that can be improved by my team if we had learnt arrays or any other c++ functions are:<br>
1. Shorter code than the current code.
>Less storage used which is a good programmer practice.<br>
2. Lower case function has not been taught in c++ which could have helped in the "Begin string" in our code so that we wouldn't have to introduce the strings in both uper and lower case again and again.<br>

3. For coupon system,we preferred concatination of strings over arrays as lesser <ins>for loops</ins> were used in it.<br>




