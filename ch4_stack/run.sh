
if [ -f "a.out" ]; then
	rm a.out
	echo "remove a.out"
fi

clear

if [ "$1" == "" ]; then
	echo "Please type file name.";
else
	g++ $1; ./a.out
fi