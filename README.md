-----------------------------------------------------------------------------------------
CAMPAIGN TARGETING - README
-----------------------------------------------------------------------------------------

Within the folder, you will find 5 folders. There are 3 source code folders that have the
uncompiled files used for each of the 3 compiled programs within the "Compiled Solutions"
folder.

Once this program has initialized all segments and campaigns, most functions operate with
O(1) time, but the final step is where it slows down with O(n) time complexity. Through
tests, however, the average time for the output is a little less than 1 ms.


-----------------------------------------------------------------------------------------
HOW TO RUN
-----------------------------------------------------------------------------------------
The code must be run through a linux environment.

example_data.txt and input.txt files can be found in the "Text Files Given." Make sure
your desired compiled solution and appropriate files are in the same directory. Both text
files are needed unless campaign is run (example_data.txt is only needed, then).

User-specified randomly generated text files can be created using the gentext solution 
within "Compiled Solutions." To run it, type:
    - ./gentext
and please follow the prompts given. A more in-depth description is given below.

After the text files are in the same directory as the desired solution, type one of the
three below:
    - ./campaign example_data.txt
    - ./campaign2 example_data.txt input.txt
    - ./campaign3 example_data.txt input.txt
The difference between all three is described below. 


-----------------------------------------------------------------------------------------
FOLDER = "COMPILED SOLUTIONS"
-----------------------------------------------------------------------------------------

files inside:
   - campaign
   - campaign2
   - campaign3
   - gentext


EXPLANATION------------------------------------------------------------------------------
This folder contains 2 compiled solutions of the problem given. The reason behind the 
two solutions is because of the nature of the problem. The instructions state that there 
is a example_data.txt that holds the information of the campaigns and their
associated target IDs. There is also mention of a input.txt file in the "Additional 
Information" section that will contain the input lines given to the program instead of 
user input. This is a contradiction to the example usage given in the document where no
inclusion of input.txt is mentioned.

QUICK FILE DESCRIPTIONS------------------------------------------------------------------
The "campaign" file is only needs example_data.txt like in the example
usage. To exit the program, enter "-1" or "exit"

"campaign2" accepts both example_data.txt and input.txt as required according to
"Additional Information."

"campaign3" takes both text files as inputs and outputs a file called "times.txt" which
contains the times the program takes to process each line of input from "input.txt." 

While the example_data and input text files that reflect the example files shown in the
document are included (folder "Text Files Given"), "gentext" is a simple program that 
will generate the two files after gathering user input on the parameters for file 
creation.

If "gentext" will not be used, copy example_data.txt for "campaign" to work and and both 
for "campaign2" to work.


-----------------------------------------------------------------------------------------
FOLDERS = "CAMPAIGN (SOURCE CODE)", "CAMPAIGN2 (SOURCE CODE)", "CAMPAIGN (SOURCE CODE)"
-----------------------------------------------------------------------------------------

files inside:
    - main.cpp
    - initialization.h
    - initalization.cpp
    - targeting.h 
    - targeting.cpp


EXPLANATION------------------------------------------------------------------------------
These folders are similar in nature as they all contain the required files to compile the
three campaigns located in the "Compiled Solutions" folder. The only file that differs
between the three source codes is the target.cpp and target.h files save the main.cpp in 
campaign as it accepts user input and not a text file.

QUICK FILE DESCRIPTIONS------------------------------------------------------------------
The "main.cpp" file runs the program and has the ad_DB vector which has all available
segements and the respective campaigns associated with each in the form of an ID number
assigned. These IDs are tied back to their campaign names in the camps vector. To combat
a campaign from starving, a starveList vector is created to monitor each campaign and
its selection frequency.
NOTE: The "campaign" version can be exited with either "-1" or "exit"

In order to populate these containers, the initialization files take example_data.txt and
read through the file by line and assign each campaign to a unique indentifier (stored in
camps) which is appended to the correct segment of ad_DB all while checking for any
repeated segments and campaigns and ignoring invalid inputs. These files return the size 
of camps back to main in order for the starveList to be an appropriate size and not take 
more room than it needs.

After the preliminary information is formatted into the correct containers, the targeting
files handle the process of selecting a campaign given the segments -- which is given by
either the user (campaign) or "input.txt" file (campaign2 and campaign3). The functions
of the targeting files first checks each segment in the ad_DB and reads the campaign IDs
associated with the segment and increments a counter. After finishing the line, the
program then selects the appropriate campaign paying attention to if any campaigns target
the same amount of segments and selecting the campaign that has less hits in the 
starveList.
NOTE: In campaign3, a timer is built in which times how long the program takes to process
each line of segments which is then outputted into "times.txt" after finishing.

-----------------------------------------------------------------------------------------
FOLDER = "GENTEXT (SOURCE CODE)
-----------------------------------------------------------------------------------------

files inside:
    - main.cpp


EXPLANATION------------------------------------------------------------------------------
To test the program with a larger dataset, a simple text file generator was created which
creates both "example_data.txt" and "input.txt" according to the user inputs. This is a
fast way to populate segments and ad campaigns to test the program with a more realistic
load than given by the example text. Limited to one file due to its simple function and
no true requirement for the solution.

QUICK FILE DESCRIPTIONS------------------------------------------------------------------
"main.cpp" is the only file which inquires of what parameters the user will want for
things like:
    - Number of potential unique IDs campaigns can have
    - Number of lines for example_data.txt
    - The number of potential target IDs (segments) associated with each line
    - Number of lines produced for input.txt
    - The number of potential target IDs (segements) requested per line.

Some parameters mention the word "potential" because the text file generators choose a
number between 1 and the user specified number, inclusive, to simulate that of a file
of realistic nature. 
