# Bittmax FIle Handling

## Requirements:
-------------
Your program has N Printers and M Sources.
Sources read data from files that are passed on command line.
*Periodically*, Printers ask Sources for data on the basis of some unique identifier, and finally print their responses.

## Input
-----
./program interval_to_ask_for_data_in_secs files[file1.csv, file2.csv, ...]

E.g.:
-----
./program 1 file1.csv file2.csv file3.csv


csv format:
#### unique_identifier, timestamp, price
#### ZEC-AUD,1557151703023977,7717
#### LTC-AUD,1557151785388304,7470
#### LTC-AUD,1557151785388304,0


Your program should read data with unique_identifiers ZEC-AUD, LTC-AUD and BTC-AUD only.


## Result

## This is command line based Mini project on c++

to compile          -> g++  filename.cpp 
to check .exe file  -> dir  

to execute we need to pass the argument in command line itself

to execute          -> filename.exe  interval_to_ask_for_data_in_secs  files[file1.csv, file2.csv, ...]

### result will be obtained in following format:

#### unique_identifier timestamp        price
#### ZEC-AUD           1557151703023977 7717
#### LTC-AUD           1557151785388304 7470
#### LTC-AUD           1557151785388304 0

### description of result
If the file name is repeated while giving input in argument line,
then i first maintain the frequency of all the filename given in input.
Then i print data file wise , (with time interval provided in argument)*frequency of filename inorder to avoid repetation of same values again and again.

shown in output image.














