1. download the ch340 drivers on the board
2. then check if it has changed to ch 34x by running dmesg | grep tty
3. check if arduino reads it as a serial port
4. can check by echoing characters to just the channel 340
5. find out how to echo a character into the uart just using a jumper cable

hint: this could work...
stty -F /dev/ttyUSB0 115200 raw -echo   #CONFIGURE SERIAL PORT
exec 3</dev/ttyUSB0                     #REDIRECT SERIAL OUTPUT TO FD 3
  cat <&3 > /tmp/ttyDump.dat &          #REDIRECT SERIAL OUTPUT TO FILE
  PID=$!                                #SAVE PID TO KILL CAT
    echo "R" > /dev/ttyUSB0             #SEND COMMAND STRING TO SERIAL PORT
    sleep 0.2s                          #WAIT FOR RESPONSE
  kill $PID                             #KILL CAT PROCESS
  wait $PID 2>/dev/null                 #SUPRESS "Terminated" output

exec 3<&-                               #FREE FD 3
cat /tmp/ttyDump.dat                    #DUMP CAPTURED DATA
