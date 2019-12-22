
sudo rfkill unblock 1  &&
sudo hciconfig hci0 reset &&
sudo invoke-rc.d bluetooth restart &&
sleep 1 &&
sudo bt-adapter --set Discoverable 1
