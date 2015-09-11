
device_name=`grep DEVICE_NAME kernel/mychardev.h  | awk -F"DEVICE_NAME" '{ print $2}' | awk -F"\"" '{ print $2}'`
module_name=`grep "obj-m" kernel/Makefile  | awk -F"=" '{ print $2}' | awk -F".o" ' { print $1}'`

echo "$device_name"

module_name=`echo $module_name`
echo "$module_name"


cd kernel
make clean 
make

if [ "$?" != "0" ]; then
	echo "Make failed"
	cd -
	exit 1
fi	
	
cd -

temp=`lsmod | grep -w "^""$module_name"`

if [ "$temp" != "" ]; then
	module_usage=`echo $temp | awk '{ print $3}'`
	if [ "$module_usage" == "0" ]; then
		rmmod $module_name
	else
		echo "Module is in use, could not unload"
		exit 1
	fi
fi


insmod kernel/chardev.ko

if [ "$?" == "0" ]; then
	echo "Module inserted"
fi

