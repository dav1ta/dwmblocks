//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
//	                           ☀                       ⏻                   
	{"GPU ", "cat /sys/class/drm/card1/device/gpu_busy_percent | awk '{print $0\"%\"}'", 3,  0},
	{"CPU ", "(grep 'cpu ' /proc/stat;sleep 0.1;grep 'cpu ' /proc/stat)|awk -v RS="" '{print ($13-$2+$15-$4)*100/($13-$2+$15-$4+$16-$5)}'|head -c 2 | tr -d '.'|awk '{print $0\"%\"}'", 3, 0},
//	{" ", "swapon --show | tail -1 | awk '{print $4}'", 30, 10},
	{"RAM ", "free -m | grep Mem | awk '{ print $7\"MB\" }'", 10, 9},
	{" ", "ip=$(ip -br addr | tail -n1 | awk '{print $1, $3}' | cut -d '/' -f1); [[ $(ip -br addr | wc -l) > 3 ]] && echo \" $ip\" || echo \" $ip\"", 30, 5},
//	{" ", "[ $(bluetoothctl show | grep Powered: | cut -d ' ' -f2) == yes ] && echo '' || echo ''", 0, 6},
	{" ", "amixer -c 2 get Capture | awk -F\"[][]\" END'{ print $6 $2 }' | sed -e \"s/on/ /g;s/off/ /g;\"", 0, 7},
	{" ", "amixer -c 2 get Master | awk -F\"[][]\" END'{ print $6 $2 }' | sed -e \"s/on/ /g;s/off/ /g;\"", 0, 2},
//	{" ", "xbacklight | cut -d. -f1", 0, 3},
	 //{" ", "sleep 4 && sudo pacman -Syuw --noconfirm > /dev/null && pacman -Qu | wc -l || echo 'N/A'", 3600, 8},
	{"", "acpi | grep \"Battery 0\" | cut -d \" \" -f3-5 | sed -e \"s/,//g;s/Discharging//;s/Charging//;s/Unknown//;s/Full//;s/ 0*/ /g;s/ :/ /g\"", 60, 4},
//	{"", "[[ $(cat /sys/class/net/wlan0/link_mode) == 1 ]] && echo ' '$(nmcli -t -f name,device connection show --active | grep wlp3s0 | cut -d: -f1) || echo ' Not connected'", 0, 9},
	{" ", "setxkbmap -query | grep layout | awk '{print $2}' | awk '{print toupper($0)}'", 0, 1},
	{" ", "date +'%d %b %R'", 60, 0},

	
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
