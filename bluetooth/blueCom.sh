
sudo rfkill unblock all  &&
sudo hciconfig hci0 reset &&
sudo invoke-rc.d bluetooth restart &&
sleep 1 &&
sudo hciconfig hi0 piscan
