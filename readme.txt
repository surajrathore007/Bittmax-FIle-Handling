This is command line based Mini project on c++

to compile          -> g++  filename.cpp 
to check .exe file  -> dir  

to execute we need to pass the argument in command line itself

to execute          -> filename.exe  interval_to_ask_for_data_in_secs  files[file1.csv, file2.csv, ...]

result will be obtained in following format:

unique_identifier timestamp        price
ZEC-AUD           1557151703023977 7717
LTC-AUD           1557151785388304 7470
LTC-AUD           1557151785388304 0


If the file name is repeated while giving input in argument line
then i first maintain the frequency of all the filename given in input.

Then i print data file wise , (with time interval provided in argument)*frequency of filename 

shown in output image.

